#include "def.h"
#include <fstream>

#define YYSTYPE int   //此行是为了包含parser.tab.hpp不引起错误而加,可以在后面使用相关常量

#include "parser.tab.hpp"

string LoadFromMem(const string& Reg1, const Opn& opn, string Reg2) {
    string load;
    if (!(Reg2 != "$sp" || (Reg2 == "$sp" && opn.isGolbal == 0)))
        Reg2 = "$gp";
    load = "  lw " + Reg1 + ",  " + to_string(opn.Offset) + "(" + Reg2 + ")";
    return load;
}

string LoadFromMem(const string& Reg1, const Opn& opn1, const Opn& opn2, string Reg2) {
    string load;
    if (!(Reg2 != "$sp" || (Reg2 == "$sp" && opn1.isGolbal == 0)))
        Reg2 = "$gp";
    load = "  lw $t4,  " + to_string(opn2.Offset) + "(" + "$sp" + ")\n" +
           "  add " + Reg2 + ", " + Reg2 + ", " + "$t4\n" +
           "  lw " + Reg1 + ",  " + to_string(opn1.Offset) + "(" + Reg2 + ")\n" +
           "  sub " + Reg2 + ", " + Reg2 + ", $t4";
    return load;
}

string StoreToMem(const string& Reg1, const Opn& opn, string Reg2) {
    string store;
    if (!(Reg2 != "$sp" || (Reg2 == "$sp" && opn.isGolbal == 0)))
        Reg2 = "$gp";
    store = "  sw " + Reg1 + ",  " + to_string(opn.Offset) + "(" + Reg2 + ")";
    return store;
}

string StoreToMem(const string& Reg1, const Opn& opn1, const Opn& opn2, string Reg2) {
    string store;
    if (!(Reg2 != "$sp" || (Reg2 == "$sp" && opn1.isGolbal == 0)))
        Reg2 = "$gp";
    store = "  lw $t4,  " + to_string(opn2.Offset) + "(" + "$sp" + ")\n" +
            "  add " + Reg2 + ", " + Reg2 + ", " + "$t4\n" +
            "  sw " + Reg1 + ",  " + to_string(opn1.Offset) + "(" + Reg2 + ")\n" +
            "  sub " + Reg2 + ", " + Reg2 + ", $t4";
    return store;
}

void GenObject(list <IRCode> IRCodes) {
    fstream ObjectFile;
    ObjectFile.open("ObjectFile.s", ios::out);

    /*预先给出read和write的目标代码*/
    ObjectFile << ".data\n";
    ObjectFile << "_Prompt: .asciiz \"Enter an integer:  \"\n";
    ObjectFile << "_ret: .asciiz \"\\n\"\n";
    ObjectFile << ".globl main\n";
    ObjectFile << ".text\n\n";
    ObjectFile << "read:\n";
    ObjectFile << "  li $v0,4\n";
    ObjectFile << "  la $a0,_Prompt\n";
    ObjectFile << "  syscall\n";
    ObjectFile << "  li $v0,5\n";
    ObjectFile << "  syscall\n";
    ObjectFile << "  jr $ra\n\n";
    ObjectFile << "write:\n";
    ObjectFile << "  li $v0,1\n";
    ObjectFile << "  syscall\n";
    ObjectFile << "  li $v0,4\n";
    ObjectFile << "  la $a0,_ret\n";
    ObjectFile << "  syscall\n";
    ObjectFile << "  move $v0,$0\n";
    ObjectFile << "  jr $ra\n";

    for (auto it = IRCodes.begin(); it != IRCodes.end(); it++) {
        switch (it->Op) {
            case ASSIGN:
                if (it->Opn1.Name == string("_CONST"))  //这里只考虑了整常数
                    ObjectFile << "  li $t1, " << it->Opn1.constINT << endl;
                else       //这里只考虑了简单变量，数组则需要扩充
                    ObjectFile << LoadFromMem("$t1", it->Opn1, "$sp") << endl;
                ObjectFile << StoreToMem("$t1", it->Result, "$sp") << endl;
                break;
            case ARRLOAD:
                ObjectFile << LoadFromMem("$t1", it->Opn1, it->Opn2, "$sp") << endl;
                ObjectFile << StoreToMem("$t1", it->Result, "$sp") << endl;
                break;
            case ARRASSIGN:
                ObjectFile << LoadFromMem("$t1", it->Opn2, "$sp") << endl;
                ObjectFile << StoreToMem("$t1", it->Result, it->Opn1, "$sp") << endl;
                break;
            case PLUS:
            case MINUS:
            case STAR:
            case DIV:
            case MOD:
                ObjectFile << LoadFromMem("$t1", it->Opn1, "$sp") << endl;
                ObjectFile << LoadFromMem("$t2", it->Opn2, "$sp") << endl;
                if (it->Op == PLUS) ObjectFile << "  add $t3,$t1,$t2" << endl;
                else if (it->Op == MINUS) ObjectFile << "  sub $t3,$t1,$t2" << endl;
                else if (it->Op == STAR) ObjectFile << "  mul $t3,$t1,$t2" << endl;
                else if (it->Op == DIV) {
                    ObjectFile << "  div $t1, $t2" << endl;
                    ObjectFile << "  mflo $t3" << endl;
                } else {
                    ObjectFile << "  div $t1, $t2" << endl;
                    ObjectFile << "  mfhi $t3" << endl;
                }
                ObjectFile << StoreToMem("$t3", it->Result, "$sp") << endl;
                break;

            case AND:
            case OR:
                ObjectFile << LoadFromMem("$t1", it->Opn1, "$sp") << endl;
                ObjectFile << "  sne $t1, $t1, $zero" << endl;
                ObjectFile << LoadFromMem("$t2", it->Opn2, "$sp") << endl;
                ObjectFile << "  sne $t2, $t2, $zero" << endl;
                if (it->Op == AND) ObjectFile << "  and $t3,$t1,$t2" << endl;
                else if (it->Op == OR) ObjectFile << "  or $t3,$t1,$t2" << endl;
                ObjectFile << StoreToMem("$t3", it->Result, "$sp") << endl;
                break;

            case NOT:
                ObjectFile << LoadFromMem("$t1", it->Opn1, "$sp") << endl;
                ObjectFile << "  sne $t1, $t1, $zero" << endl;
                ObjectFile << "  seq $t1, $t1, $zero" << endl;
                ObjectFile << StoreToMem("$t1", it->Result, "$sp") << endl;
                break;
            case DPLUS:
            case DMINUS:
                ObjectFile << LoadFromMem("$t1", it->Opn1, "$sp") << endl;
                if (it->Op == DPLUS) ObjectFile << "  addi $t3,$t1,1" << endl;
                else if (it->Op == DMINUS) ObjectFile << "  addi $t3,$t1,-1" << endl;
                ObjectFile << StoreToMem("$t3", it->Opn1, "$sp") << endl;
                ObjectFile << StoreToMem("$t3", it->Result, "$sp") << endl;
                break;

            case PLUSD:
            case MINUSD:
                ObjectFile << LoadFromMem("$t1", it->Opn1, "$sp") << endl;
                ObjectFile << StoreToMem("$t1", it->Result, "$sp") << endl;
                if (it->Op == PLUSD) ObjectFile << "  addi $t3,$t1,1" << endl;
                else if (it->Op == MINUSD) ObjectFile << "  addi $t3,$t1,-1" << endl;
                ObjectFile << StoreToMem("$t3", it->Opn1, "$sp") << endl;
                break;

            case UMINUS:
                ObjectFile << LoadFromMem("$t1", it->Opn1, "$sp") << endl;
                ObjectFile << "  li $t2,-1" << endl;
                ObjectFile << "  mul $t3,$t1,$t2" << endl;
                ObjectFile << StoreToMem("$t3", it->Result, "$sp") << endl;
                break;


            case ARRDPLUS:
            case ARRDMINUS:
                ObjectFile << LoadFromMem("$t1", it->Opn1, it->Opn2, "$sp") << endl;
                if (it->Op == ARRDPLUS) ObjectFile << "  addi $t3,$t1,1" << endl;
                else if (it->Op == ARRDMINUS) ObjectFile << "  addi $t3,$t1,-1" << endl;
                ObjectFile << StoreToMem("$t3", it->Opn1, it->Opn2, "$sp") << endl;
                ObjectFile << StoreToMem("$t3", it->Result, "$sp") << endl;
                break;

            case ARRPLUSD:
            case ARRMINUSD:
                ObjectFile << LoadFromMem("$t1", it->Opn1, it->Opn2, "$sp") << endl;
                ObjectFile << StoreToMem("$t1", it->Result, "$sp") << endl;
                if (it->Op == ARRPLUSD) ObjectFile << "  addi $t3,$t1,1" << endl;
                else if (it->Op == ARRMINUSD) ObjectFile << "  addi $t3,$t1,-1" << endl;
                ObjectFile << StoreToMem("$t3", it->Opn1, it->Opn2, "$sp") << endl;
                break;


            case RETURN:
                ObjectFile << LoadFromMem("$v0", it->Result, "$sp") << endl;
                ObjectFile << "  jr $ra" << endl;
                break;

            case FUNCTION:
                ObjectFile << "\n" << it->Result.Name << ":\n";
                if (it->Result.Name == string("main")) //特殊处理main
                    ObjectFile << "  addi $sp, $sp, -" << it->Result.Offset << endl;
                break;
            case PARAM:
                break; //直接跳到后面一条
            case ARG:
                break; //直接跳到后面一条,直到函数调用，回头提取实参值，传送到形参单元。
            case LABEL:
                ObjectFile << it->Result.Name << ":" << endl;
                break;
            case GOTO:
                ObjectFile << "  j " << it->Result.Name << endl;
                break;
            case END:
                ObjectFile << "  li $v0,10\n  syscall" << endl;
                break;
            case JLE:
            case JLT:
            case JGE:
            case JGT:
            case JEQ:
            case JNE:
                ObjectFile << LoadFromMem("$t1", it->Opn1, "$sp") << endl;
                ObjectFile << LoadFromMem("$t2", it->Opn2, "$sp") << endl;
                if (it->Op == JLE) ObjectFile << "  ble $t1,$t2," << it->Result.Name << endl;
                else if (it->Op == JLT) ObjectFile << "  blt $t1,$t2," << it->Result.Name << endl;
                else if (it->Op == JGE) ObjectFile << "  bge $t1,$t2," << it->Result.Name << endl;
                else if (it->Op == JGT) ObjectFile << "  bgt $t1,$t2," << it->Result.Name << endl;
                else if (it->Op == JEQ) ObjectFile << "  beq $t1,$t2," << it->Result.Name << endl;
                else ObjectFile << "  bne $t1,$t2," << it->Result.Name << endl;
                break;

            case CALL:
            case CALL0:
                auto it0 = it;
                it0--;  //it0指向前面可能的ARG
                if (it->Opn1.Name == string("read"))//特殊处理read
                {
                    ObjectFile << "  addi $sp, $sp, -4\n";
                    ObjectFile << "  sw $ra,0($sp)\n";      //保留返回地址
                    ObjectFile << "  jal read\n";           //保留返回地址
                    ObjectFile << "  lw $ra,0($sp)\n";      //恢复返回地址
                    ObjectFile << "  addi $sp, $sp, 4\n";
                    ObjectFile << StoreToMem("$v0", it->Result, "$sp") << endl;
                    break;
                }
                if (it->Opn1.Name == string("write"))//特殊处理write
                {
                    ObjectFile << LoadFromMem("$a0", it0->Result, "$sp") << endl; //前面ARG的偏移量
                    ObjectFile << "  addi $sp, $sp, -4\n";
                    ObjectFile << "  sw $ra,0($sp)\n";
                    ObjectFile << "  jal write\n";
                    ObjectFile << "  lw $ra,0($sp)\n";
                    ObjectFile << "  addi $sp, $sp, 4\n";
                    break;
                }
                ObjectFile << "  move $t0,$sp" << endl; //保存当前函数的sp到$t0中，为了取实参表达式的值


                ObjectFile << "  addi $sp, $sp, -" << static_cast <FuncSymbol *>(it->Opn1.SymPtr)->ARSize
                           << endl;  //开活动记录空间
                ObjectFile << "  sw $ra,0($sp)" << endl;                      //保留返回地址
                while (it0->Op == ARG)                       //依次取参数值传递到形参单元中
                {
                    //将原栈帧的偏移it0->Result.Offset数据取出，送到新栈帧的it0->Opn1.Offset
                    ObjectFile << LoadFromMem("$t1", it0->Result, "$t0") << endl;
                    ObjectFile << StoreToMem("$t1", it0->Opn1, "$sp") << endl;
                    it0--;
                }
                ObjectFile << "  jal " << it->Opn1.Name << endl;      //跳转到被调用函数
                ObjectFile << "  lw $ra,0($sp)" << endl;            //恢复返回地址
                ObjectFile << "  addi $sp,$sp," << ((FuncSymbol *) (it->Opn1.SymPtr))->ARSize << endl; //释放活动记录空间
                ObjectFile << StoreToMem("$v0", it->Result, "$sp") << endl;    //取返回值,如void函数，不需要取值
                break;
        }
    }
    ObjectFile.close();
}