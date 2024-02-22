#include <iostream>
#include <cstdlib>
#include <chrono>

#define size 4
using namespace std;

// 通过宏定义确定启发函数
//#define HAMMING
//#define MANHATTAN
#define LINEAR

// 是否打印中间状态
#define DEBUG

//定义二维数组来存储数据表示某一个特定状态
typedef int status[size][size];
struct SpringLink;

//定义状态图中的结点数据结构
typedef struct Node {
    status data;                //结点所存储的状态
    struct Node *parent;        //指向结点的父亲结点
    struct SpringLink *child;   //指向结点的后继结点
    struct Node *next;          //指向open或者closed表中的后一个结点
    int f_value;                //结点的总的路径
    int g_value;                //结点的实际路径
    int h_value;                //结点的估计成本值
} NNode, *PNode;


//定义存储指向结点后继结点的指针的地址
typedef struct SpringLink {
    struct Node *pointData;     //指向结点的指针
    struct SpringLink *next;    //指向兄第结点
} SPLink, *PSPLink;


PNode open;
PNode closed;


//开始状态与目标状态
status start = {};
status target = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};


//初始化一个空链表
void initLink(PNode &Head) {
    Head = (PNode) malloc(sizeof(NNode));
    Head->next = nullptr;
}


//判断链表是否为空
bool isEmpty(PNode Head) {
    if (Head->next == nullptr)
        return true;
    else
        return false;
}


//从链表中拿出一个数据
void popNode(PNode &Head, PNode &FNode) {
    if (isEmpty(Head)) {
        FNode = nullptr;
        return;
    }
    FNode = Head->next;
    Head->next = Head->next->next;
    FNode->next = nullptr;
}


//向结点的最终后继结点链表中添加新的子结点
void addSpringNode(PNode &Head, PNode newData) {
    auto newNode = (PSPLink) malloc(sizeof(SPLink));
    newNode->pointData = newData;
    newNode->next = Head->child;
    Head->child = newNode;
}


//释放状态图中存放结点后继结点地址的空间
void freeSpringLink(PSPLink &Head) {
    PSPLink tmm;

    while (Head != nullptr) {
        tmm = Head;
        Head = Head->next;
        free(tmm);
    }
}


//释放open表与closed表中的资源
void freeLink(PNode &Head) {
    PNode tmn;

    tmn = Head;
    Head = Head->next;
    free(tmn);

    while (Head != nullptr) {
        //首先释放存放结点后继结点地址的空间
        freeSpringLink(Head->child);
        tmn = Head;
        Head = Head->next;
        free(tmn);
    }
}


//向普通链表中添加一个结点
void addNode(PNode &Head, PNode &newNode) {
    newNode->next = Head->next;
    Head->next = newNode;
}


//向非递减排列的链表中添加一个结点
void addAscNode(PNode &Head, PNode &newNode) {
    PNode P;
    PNode Q;

    P = Head->next;
    Q = Head;
    while (P != nullptr && P->f_value < newNode->f_value) {
        Q = P;
        P = P->next;
    }
    //上面判断好位置之后，下面就是简单的插入了
    newNode->next = Q->next;
    Q->next = newNode;
}


// 汉明距离
int hammingDistance(PNode theNode) {
    int num = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (theNode->data[i][j] != target[i][j])
                num++;
        }
    }
    return num;
}

// 曼哈顿距离
int manhattanDistance(PNode theNode) {
    int distance = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int value = theNode->data[i][j];
            if (value) {
                int targetX = (value - 1) / 4;
                int targetY = (value - 1) % 4;
                distance += abs(i - targetX) + abs(j - targetY);
            }
        }
    }
    return distance;
}

int linearConflict(PNode theNode) {
    int distance = manhattanDistance(theNode);
    // 在行方向检查
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                int currentValue = theNode->data[i][j];
                int compareValue = theNode->data[i][k];
                if (currentValue != 0 && compareValue != 0 &&
                    (currentValue - 1) / 4 == i &&
                    (compareValue - 1) / 4 == i &&
                    (currentValue - 1) % 4 > (compareValue - 1) % 4) {
                    distance += 2;
                }
            }
        }
    }
    // 在列方向检查
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            for (int l = i + 1; l < 4; ++l) {
                int currentValue = theNode->data[i][j];
                int compareValue = theNode->data[l][j];
                if (currentValue != 0 && compareValue != 0 &&
                    (currentValue - 1) % 4 == j &&
                    (compareValue - 1) % 4 == j &&
                    (currentValue - 1) / 4 > (compareValue - 1) / 4) {
                    distance += 2;
                }
            }
        }
    }
    return distance;
}

//计算结点h值
int computeHValue(PNode theNode) {
#ifdef HAMMING
    return hammingDistance(theNode);
#elifdef MANHATTAN
    return manhattanDistance(theNode);
#elifdef LINEAR
    return linearConflict(theNode);
#else
    cout << "错误：请先定义启发函数方式！" << endl;
#endif
}

//计算结点的f，g，h值
void computeAllValue(PNode &theNode, PNode parentNode) {
    if (parentNode == nullptr)
        theNode->g_value = 0;
    else
        theNode->g_value = parentNode->g_value + 1;

    theNode->h_value = computeHValue(theNode);
    theNode->f_value = theNode->g_value + theNode->h_value;
}


//初始化函数，进行算法初始条件的设置
void initial() {
    //初始化open以及closed表
    initLink(open);
    initLink(closed);

    //初始化起始结点，令初始结点的父节点为空结点
    PNode nullptrNode = nullptr;
    auto Start = (PNode) malloc(sizeof(NNode));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Start->data[i][j] = start[i][j];
        }
    }
    Start->parent = nullptr;
    Start->child = nullptr;
    Start->next = nullptr;
    computeAllValue(Start, nullptrNode);

    //起始结点进入open表
    addAscNode(open, Start);
}


//将B节点的状态赋值给A结点
void statusAEB(PNode &ANode, PNode BNode) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ANode->data[i][j] = BNode->data[i][j];
        }
    }
}


//两个结点是否有相同的状态
bool hasSameStatus(PNode ANode, PNode BNode) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (ANode->data[i][j] != BNode->data[i][j])
                return false;
        }
    }
    return true;
}


//结点与其祖先结点是否有相同的状态
bool hasAnceSameStatus(PNode OriginNode, PNode AncientNode) {
    while (AncientNode != nullptr) {
        if (hasSameStatus(OriginNode, AncientNode))
            return true;
        AncientNode = AncientNode->parent;
    }
    return false;
}


//取得方格中空的格子的位置
void getPosition(PNode theNode, int &row, int &col) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (theNode->data[i][j] == 0) {
                row = i;
                col = j;
                return;
            }
        }
    }
}


//交换两个数字的值
void swap(int &A, int &B) {
    int C; C = B; B = A; A = C;
}


//检查相应的状态是否在某一个链表中
bool inLink(PNode specificNode, PNode theLink, PNode &theNodeLink, PNode &preNode) {
    preNode = theLink;
    theLink = theLink->next;

    while (theLink != nullptr) {
        if (hasSameStatus(specificNode, theLink)) {
            theNodeLink = theLink;
            return true;
        }
        preNode = theLink;
        theLink = theLink->next;
    }
    return false;
}


//产生结点的后继结点(与祖先状态不同)链表
void SpringLink(PNode theNode, PNode &spring) {
    int row;
    int col;

    getPosition(theNode, row, col);

    //空的格子右边的格子向左移动
    if (col != 3) {
        auto rlNewNode = (PNode) malloc(sizeof(NNode));
        statusAEB(rlNewNode, theNode);
        swap(rlNewNode->data[row][col], rlNewNode->data[row][col + 1]);
        if (hasAnceSameStatus(rlNewNode, theNode->parent)) {
            free(rlNewNode);//与父辈相同，丢弃本结点
        } else {
            rlNewNode->parent = theNode;
            rlNewNode->child = nullptr;
            rlNewNode->next = nullptr;
            computeAllValue(rlNewNode, theNode);
            //将本结点加入后继结点链表
            addNode(spring, rlNewNode);
        }
    }
    //空的格子左边的格子向右移动
    if (col != 0) {
        auto lrNewNode = (PNode) malloc(sizeof(NNode));
        statusAEB(lrNewNode, theNode);
        swap(lrNewNode->data[row][col], lrNewNode->data[row][col - 1]);
        if (hasAnceSameStatus(lrNewNode, theNode->parent)) {
            free(lrNewNode);//与父辈相同，丢弃本结点
        } else {
            lrNewNode->parent = theNode;
            lrNewNode->child = nullptr;
            lrNewNode->next = nullptr;
            computeAllValue(lrNewNode, theNode);
            //将本结点加入后继结点链表
            addNode(spring, lrNewNode);
        }
    }
    //空的格子上边的格子向下移动
    if (row != 0) {
        auto udNewNode = (PNode) malloc(sizeof(NNode));
        statusAEB(udNewNode, theNode);
        swap(udNewNode->data[row][col], udNewNode->data[row - 1][col]);
        if (hasAnceSameStatus(udNewNode, theNode->parent)) {
            free(udNewNode);//与父辈相同，丢弃本结点
        } else {
            udNewNode->parent = theNode;
            udNewNode->child = nullptr;
            udNewNode->next = nullptr;
            computeAllValue(udNewNode, theNode);
            //将本结点加入后继结点链表
            addNode(spring, udNewNode);
        }
    }
    //空的格子下边的格子向上移动
    if (row != 3) {
        auto duNewNode = (PNode) malloc(sizeof(NNode));
        statusAEB(duNewNode, theNode);
        swap(duNewNode->data[row][col], duNewNode->data[row + 1][col]);
        if (hasAnceSameStatus(duNewNode, theNode->parent)) {
            free(duNewNode);//与父辈相同，丢弃本结点
        } else {
            duNewNode->parent = theNode;
            duNewNode->child = nullptr;
            duNewNode->next = nullptr;
            computeAllValue(duNewNode, theNode);
            //将本结点加入后继结点链表
            addNode(spring, duNewNode);
        }
    }
}


//输出给定结点的状态
void outputStatus(PNode stat) {
    putchar('\n');
    for (int i = 0; i < 4; i++, putchar('\n')) {
        for (int j = 0; j < 4; j++) {
            printf("%-2d ", stat->data[i][j]);
        }
    }
    putchar('\n');

/* // 这部分代码用于输出格式化的数据，便于使用Python进行数据可视化
 * putchar('\n');
 *     for (int i = 0; i < 4; i++) {
        printf("], [");
        for (int j = 0; j < 4; j++) {
            printf("%d, ", stat->data[i][j]);

        }
    }
*/

}


//输出最佳的路径
void outputBestRoad(PNode goal) {
    int depth = goal->g_value;

    if (goal->parent != nullptr) {
        outputBestRoad(goal->parent);
    }
    cout << "第" << depth-- << "步的状态:" << endl;
    outputStatus(goal);
}


void AStar() {
    PNode tmpNode;          //指向从open表中拿出并放到closed表中的结点的指针
    PNode spring;           //tmpNode的后继结点链
    PNode tmpLNode;         //tmpNode的某一个后继结点
    PNode tmpChartNode;
    PNode thePreNode;       //指向将要从closed表中移到open表中的结点的前一个结点的指针
    bool getGoal = false;   //标识是否达到目标状态
    long numCount = 1;      //记录从open表中拿出结点的序号

    //记录开始时间
    auto start = chrono::high_resolution_clock::now();

    initial();              //对函数进行初始化
    initLink(spring);    //对后继链表的初始化
    tmpChartNode = nullptr;

    while (!isEmpty(open)) {
        //从open表中拿出f值最小的元素,并将拿出的元素放入closed表中
        popNode(open, tmpNode);
        addNode(closed, tmpNode);
#ifdef DEBUG
        //打印中间状态
        printf("第%ld个状态是：", numCount++);
        outputStatus(tmpNode);
        printf("f值: %-2d; g值: %-2d; h值: %-2d\n\n",
               tmpNode->f_value, tmpNode->g_value, tmpNode->h_value);
#else
        numCount++;
#endif
        //如果拿出的元素是目标状态则跳出循环
        if (computeHValue(tmpNode) == 0) {
            getGoal = true;
            break;
        }

        //产生当前检测结点的后继(与祖先不同)结点列表，产生的后继结点的parent属性指向当前检测的结点
        SpringLink(tmpNode, spring);

        //遍历检测结点的后继结点链表
        while (!isEmpty(spring)) {
            popNode(spring, tmpLNode);
            //状态在open表中已经存在，thePreNode参数在这里并不起作用
            if (inLink(tmpLNode, open, tmpChartNode, thePreNode)) {
                addSpringNode(tmpNode, tmpChartNode);
                if (tmpLNode->g_value < tmpChartNode->g_value) {
                    tmpChartNode->parent = tmpLNode->parent;
                    tmpChartNode->g_value = tmpLNode->g_value;
                    tmpChartNode->f_value = tmpLNode->f_value;
                }
                free(tmpLNode);
            }
                //状态在closed表中已经存在
            else if (inLink(tmpLNode, closed, tmpChartNode, thePreNode)) {
                addSpringNode(tmpNode, tmpChartNode);
                if (tmpLNode->g_value < tmpChartNode->g_value) {
                    PNode tempNode;
                    tmpChartNode->parent = tmpLNode->parent;
                    tmpChartNode->g_value = tmpLNode->g_value;
                    tmpChartNode->f_value = tmpLNode->f_value;
                    freeSpringLink(tmpChartNode->child);
                    tmpChartNode->child = nullptr;
                    popNode(thePreNode, tempNode);
                    addAscNode(open, tempNode);
                }
                free(tmpLNode);
            }
                //新的状态即此状态既不在open表中也不在closed表中
            else {
                addSpringNode(tmpNode, tmpLNode);
                addAscNode(open, tmpLNode);
            }
        }
    }

    //目标可达的话，输出最佳的路径
    if (getGoal) {
        cout << endl;
        cout << "路径长度为：" << tmpNode->g_value << endl;
        outputBestRoad(tmpNode);
    }

    //释放结点所占的内存
    freeLink(open);
    freeLink(closed);

    //计算结束时间
    auto end = chrono::high_resolution_clock::now();

    // 计算并输出求解时间
    chrono::duration<double> elapsed = end - start;
    cout << "求解时间: " << elapsed.count() << "秒" << endl;


    // 输出状态数
    cout << "中间状态数：" << numCount << endl;

    // 输出步数
    if (getGoal) {
        cout << "步数: " << tmpNode->g_value + 1  << endl;
    }

    getchar();
    
    
}


int main() {
    for (auto &i: start)
        for (int & j : i) {
            cin >> j;
        }
    AStar();
    return 0;
}
