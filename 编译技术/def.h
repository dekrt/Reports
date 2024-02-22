#ifndef AST_H
#define AST_H

#include <cstdlib>
#include <cctype>
#include <string>
#include <memory>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <map>

using namespace std;

class AST;

class ProgAST;

class TypeAST;

class ExtDefAST;

class VarDecAST;

class ParamAST;

class CompStmAST;

class ExpAST;

class VarSymbol;

class FuncSymbol;

class SymbolsInAScope;

class Opn;

extern map<int, string> SymbolMap;
extern map<int, int> TypeWidth;

enum BasicTypes {
    T_CHAR,
    T_INT,
    T_FLOAT,
    T_VOID
};

typedef struct {
    int Line, Column;
    string ErrMsg;
} Error;

class Errors            //用来记录语法、语义错误
{
public:
    static vector <Error> Errs;

    static void ErrorAdd(int Line, int Column, string ErrMsg);

    static void ErrorsDisplay();

    static inline bool IsEmpty() { return Errs.empty(); }
};

/**************函数调用表定义*******************/

class FunctionCall {
public:
    int Line{};
    int Column{};
    string Name;

    FunctionCall(int Line, int Column, string Name) : Line(Line), Column(Column), Name(std::move(Name)) {};

    FunctionCall() = default;
};

class FunctionCallTable {
public:
    vector <FunctionCall> FuncCalls;

    void addFuncCalls(int Line, int Column, string Name);

    void deleteFuncCalls(string Name);
};

/**************符号表定义**********************/
class Symbol {
public:
    string Name;
    BasicTypes Type;        //符号类型，目前仅基本类型T_CHAR,T_INT,T_FLOAT，T_VOID
    char Kind;       //符号种类：基本变量V，函数名F，参数P，数组A等
};

class VarSymbol : public Symbol {
public:
    string Alias;   //别名，为解决中间代码中，作用域嵌套变量同名的显示时的二义性问题
    int Offset;     //变量在对应AR中的偏移量
    int isGolbal = 0;
    vector<int> Dims;
};

class FuncSymbol : public Symbol {
public:
    int ARSize;       //函数AR的大小，作为调用时分配单元的依据
    int ParamNum;     //形式参数个数
    SymbolsInAScope *ParamPtr;  //指向参数的符号表
    int Declaration;   //目前在符号表中的是否已经定义，0表示已经定义
    vector<ParamAST *> Params;  //定义时指出参数类型和参数数目，声明时指出参数类型和参数数目，在定义时参考

};

class SymbolsInAScope {    //单一作用域的符号名，每个复合语句对应一个符号表
public:
    vector<Symbol *> Symbols;
};

class SymbolStackDef {//符号表类定义,栈结构栈底为全局变量和函数定义，每个复合语句对应一张局部符号表
public:
    vector<SymbolsInAScope *> Symbols;

    Symbol *LocateNameCurrent(const string& Name);//在当前作用域中查找该符号是否有定义
    Symbol *LocateNameGlobal(const string& Name); //由内向外，在全部作用域中查找该符号是否有定义
};

/**************中间代码（四元式）定义**********************/

class Opn {
public:
    string Name;       //变量别名（为空时表示常量）或函数名
    int Type{};
    int isGolbal = 0;
    union {
        int Offset{};     //AR中的偏移量
        void *SymPtr;    //符号表指针
        char constCHAR;
        int constINT;
        float constFLOAT;
    };

    Opn(string Name, int Type, int Offset, int isGolbal) : Name(std::move(Name)), Type(Type), Offset(Offset),
                                                           isGolbal(isGolbal) {};

    Opn() {};
};

class IRCode       //四元式结构
{
public:
    int Op;
    Opn Opn1;
    Opn Opn2;
    Opn Result;

    IRCode(int Op, Opn Opn1, Opn Opn2, Opn Result) : Op(Op), Opn1(std::move(Opn1)), Opn2(std::move(Opn2)), Result(std::move(Result)) {}
};


/**************抽象语法树结点类型定义**********************/
class AST {                          //所有结点的基类
public:
    int Line, Column;   //源程序中，语法单位所在位置
    //     int Offset;
    list <IRCode> IRCodes;

    virtual void DisplayAST(int indent) {}

    virtual void Semantics(int &Offset) {}  //静态语义检查，
    virtual void GenIR() {};               //生成中间代码

    static int MaxVarSize;
    static int MaxTempVarOffset;          //表达式求值时临时变量需要的最大空间
    static SymbolStackDef SymbolStack;     //符号表
    static FunctionCallTable functionCallTable;
};

class ProgAST : public AST {                     //程序结点，程序由多个外部定义组成
public:
    vector<ExtDefAST *> ExtDefs;            //外部定义序列

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    void Semantics0();

    void GenIR() override;

    //semantic attributes
    SymbolsInAScope *GlobalSymbolTable; //全局符号表
};

/*外部定义：外部变量和函数*/
class ExtDefAST : public AST {
};   //外部变量，函数的父类

/*外部变量类定义*/
class ExtVarDefAST : public ExtDefAST {     //外部变量定义
public:
    TypeAST *Type;         //外部变量类型
    vector<VarDecAST *> ExtVars;       //外部变量列表

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    void GenIR() override;
};

class TypeAST : public AST {
};

class BasicTypeAST : public TypeAST {  //用对象存储基本数据类型
public:
    BasicTypes Type;

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    void GenIR() override;
};


class VarDecAST : public AST {  //简单变量（标识符）、数组的定义
public:
    string Name;
    vector<int> Dims;              //数组各维大小，dims.size()为0表示非数组变量
    ExpAST *Exp = nullptr;      //初始化表达式
    VarSymbol *VarDefPtr;        //符号项的指针，如果有初始化表达式时，生成IR时起作用


    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override {};

    void Semantics(int &Offset, int &GolbalOffset, TypeAST *Type);

    void Semantics(int &Offset, TypeAST *Type);

    void GenIR() override;
};

/*函数类定义*/
class FuncDefAST : public ExtDefAST {
public:
    TypeAST *Type;        //返回类型
    string Name;                    //函数名
    vector<ParamAST *> Params;       //参数列表，为空时为无参函数
    CompStmAST *Body;        //函数体
    FuncSymbol *FuncDefPtr;  //指向符号表中函数定义项

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    void GenIR() override;
};

class ParamAST : public AST {             //形参
public:
    TypeAST *Type;              //形参类型
    VarDecAST *ParamName;         //形参名，这里考虑到形参是数组的扩展

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    void GenIR() override;
};


/*局部变量说明类定义*/
class DefAST : public AST {
public:
    TypeAST *Type;     //局部变量类型
    vector<VarDecAST *> LocVars;   //局部变量名称序列

    void DisplayAST(int l) override;

    void Semantics(int &Offset) override;

    void GenIR() override;
};


/*语句结点类定义*/
class StmAST : public AST {      //所有语句的父类
public:
    void Semantics(int &Offset) override {};

    void GenIR() override {};

    virtual void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) {};

    virtual void GenIR(string lableCase, string lableBreak, string lableContinue) {};
};

class CompStmAST : public StmAST {     //复合语句
public:
    vector<DefAST *> Decls;
    vector<StmAST *> Stms;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string labelBreak, string lableContinue) override;

    //semantic attributes
    SymbolsInAScope *LocalSymbolTable;//每个复合语句对应一个作用域（局部变量）
};


class ExprStmAST : public StmAST {     //表达式语句
public:
    ExpAST *Exp;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string lableBreak, string lableContinue) override;
};

class IfStmAST : public StmAST {     //条件语句if-then
public:
    ExpAST *Cond;
    StmAST *ThenStm;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string labelCase, string lableBreak, string lableContinue) override;
};

class IfElseStmAST : public StmAST {//条件语句if-then-else
public:
    ExpAST *Cond;
    StmAST *ThenStm;
    StmAST *ElseStm;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string lableBreak, string lableContinue) override;
};

class WhileStmAST : public StmAST {     //while语句
public:
    ExpAST *Cond;
    StmAST *Body;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string lableBreak, string lableContinue) override;
};

class ForStmAST : public StmAST {     //for语句
public:
    ExpAST *SinExp, *Cond, *EndExp;
    StmAST *Body;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string lableBreak, string lableContinue) override;
};

class CaseStmAST : public StmAST {     //for语句
public:
    ExpAST *Cond;
    vector<StmAST *> Body;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string lableBreak, string lableContinue) override;
};

class SwitchStmAST : public StmAST {     //for语句
public:
    ExpAST *Exp;
    vector<CaseStmAST *> Cases;
    int containDefault;
    vector<StmAST *> Default;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string lableBreak, string lableContinue) override;
};


class ReturnStmAST : public StmAST {
public:
    ExpAST *Exp;

    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string labelBreak, string lableContinue) override;
};

class BreakStmAST : public StmAST {
public:
    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string lableBreak, string lableContinue) override;
};

class ContinueStmAST : public StmAST {
public:
    void DisplayAST(int l) override;

    void Semantics(int &Offset, int canBreak, int canContinue, int &isReturn, BasicTypes returnType) override;

    void GenIR(string lableCase, string lableBreak, string lableContinue) override;
};


/*表示式结点类定义*/
class ExpAST : public AST {//所有表达式的父类
public:
    BasicTypes Type;

    void GenIR() override {};

    virtual Opn GenIR(int &TempOffset) = 0;                   //算术表达式，返回运算结果
    virtual void GenIR(int &TempVarOffset, string LabelTrue, string LabelFalse) {}  //布尔表达式生成短路语句
};

class ConstAST : public ExpAST {
public:
    union ConstVal {
        char constCHAR;
        int constINT;
        float constFLOAT;
    } ConstVal;

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    Opn GenIR(int &TempOffset) override;

    void GenIR(int &TempVarOffset, string LabelTrue, string LabelFalse) override;
};

class VarAST : public ExpAST {        //标识符变量
public:
    string Name;
    VarSymbol *VarRef;        //指向该变量对应的符号表项
    vector<ExpAST *> index;    //数组的下标变量，须在文法处定义各维下标为整型表达式

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    Opn GenIR(int &TempOffset) override;

    void GenIR(int &TempVarOffset, string LabelTrue, string LabelFalse) override;
};

class AssignAST : public ExpAST {   //赋值表达式
public:
    int Op;            //=，+=。。。
    ExpAST *LeftValExp, *RightValExp;

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    Opn GenIR(int &TempOffset) override;

    void GenIR(int &TempVarOffset, string LabelTrue, string LabelFalse) override;
};

class BinaryExprAST : public ExpAST {   //二元运算符
public:
    int Op;
    ExpAST *LeftExp, *RightExp;

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    Opn GenIR(int &TempOffset) override;

    void GenIR(int &TempVarOffset, string LabelTrue, string LabelFalse) override;
};

class UnaryExprAST : public ExpAST {   //单目运算符
public:
    int Op;
    ExpAST *Exp;

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    Opn GenIR(int &TempOffset) override;

    void GenIR(int &TempVarOffset, string LabelTrue, string LabelFalse) override;
};

class FuncCallAST : public ExpAST {   //函数调用
public:
    string Name;     //函数名
    vector<ExpAST *> Params;   //实际参数表达式序列
    FuncSymbol *FuncRef; //指向该函数对应的符号表项

    void DisplayAST(int indent) override;

    void Semantics(int &Offset) override;

    Opn GenIR(int &TempOffset) override;

    void GenIR(int &TempVarOffset, string LabelTrue, string LabelFalse) override;
};

#endif // AST_H 在遍历语法树
