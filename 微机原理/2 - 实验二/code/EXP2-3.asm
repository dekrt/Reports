DATA SEGMENT
        DIWEI      DW 0
        GAOWEI     DW 0
        COUNT      DW 0
        SAVE       DW 5 DUP(0)
        SAVE2      DW 5 DUP(0)
        INPUTWARN  DB 'INPUT YOUR NUMBER,END WITH ENTER: ','$'
        OUTPUTWARN DB 'TRANSFORED NUMBER: ','$'
        ERRORWARN  DB 'INPUT ERROR!','$'
        SHUWEI     DW 0,1,10,100,1000,10000
        MOD        DW 16
DATA ENDS
 
STACK SEGMENT
              DW 100 DUP(0)
STACK ENDS
 
CODE SEGMENT
                 ASSUME CS:CODE,DS:DATA,ES:DATA
        START:   
                 MOV    AX,DATA
                 MOV    DS,AX
                 MOV    ES,AX
                 MOV    AX,STACK
                 MOV    SS,AX
 
                 LEA    SI,SAVE
                 LEA    DX,INPUTWARN
                 MOV    AH,9H
                 INT    21H
 
        ;调用子程序进行处理
                 CALL   NumToHex
 
        OVER:    
                 MOV    AH, 4CH
                 INT    21H


NumToHex PROC
        L0:      
                 MOV    AH,1H
                 INT    21H
                 CMP    AL,0DH
                 JZ     L1                             ;输入回车，输入过程结束
                 CMP    AL,30H
                 JB     L2                             ;不是数字字符提示输入错误
                 CMP    AL,39H
                 JA     L2
                 JMP    L3                             ;输入为数字字符
 
        L1:      
                 MOV    DL,0AH                         ;结束输入，令下一次输出换行
                 MOV    AH,02H
                 INT    21H
                 JMP    L4
 
        L2:      
                 LEA    DX,ERRORWARN                   ;错误警告，结束程序
                 MOV    AH, 9H
                 INT    21H
                 JMP    OVER
        L3:      
                 SUB    AL,30H                         ;转换为数字
                 MOV    AH,0
                 MOV    [SI],AX                        ;将每一位数字存储在SAVE中
                 INC    SI
                 INC    SI
                 INC    COUNT                          ;统计输入数字的位数
                 JMP    L0
 
        L4:      
                 LEA    SI,SAVE
                 MOV    CX,COUNT
                 MOV    DI,COUNT
                 ADD    DI,COUNT
 
        L5:                                            ;将输入的数字按位乘以1，10，100，1000，10000，并相加放入GAOWEI,DIWEI中
                 MOV    AX,[SI]
                 MUL    SHUWEI[DI]
                 INC    SI
                 INC    SI
                 DEC    DI
                 DEC    DI
                 ADD    DIWEI,AX
                 ADC    GAOWEI,DX
                 MOV    DX,0
                 LOOP   L5
 
                 LEA    SI ,SAVE2                      ;对16取余，得到十六进制数
                 MOV    COUNT,0
                 MOV    AX,DIWEI
                 MOV    DX,GAOWEI
        L6:      
                 DIV    MOD
                 MOV    [SI],DX
                 INC    COUNT
                 INC    SI
                 INC    SI
                 MOV    DX,0
                 CMP    AX,0
                 JNZ    L6
 
                 LEA    DX,OUTPUTWARN
                 MOV    AH,9H
                 INT    21H
        ;SAVE2中存储单元地址从低到高存储数据的高位到低位
                 LEA    SI,SAVE2                       ;从高位到低位检索，直至第一个不为0的数
                 ADD    SI,8
        L7:      
                 LEA    DI, SAVE2
                 CMP    SI,DI                          ;检查当前SI的指向是否越界，越界输出0
                 JB     ZERO
                 CMP    [SI],0
                 JNZ    L9                             ;找到不为零的数
 
        L8:      
                 DEC    SI
                 DEC    SI
                 JMP    L7
 
        L9:      
                 LEA    DI, SAVE2
                 CMP    SI,DI
                 JB     OUTPUTH                        ;检查当前SI的指向是否越界，越界输出H
                 CMP    [SI],9                         ;与9比较，若为数字，加30H，为字母，加37H，转换为ASCII码
                 JA     L10
                 MOV    AX,[SI]
                 ADD    AL,30H
                 MOV    DL,AL
                 MOV    AH,02H
                 INT    21H                            ;直接输出显示为十六进制位
                 DEC    SI
                 DEC    SI
                 JMP    L9
 
        L10:     
                 MOV    AX,[SI]
                 ADD    AL,37H
                 MOV    AH,02H
                 MOV    DL,AL
                 INT    21H
                 DEC    SI
                 DEC    SI
                 JMP    L9
 
        ZERO:    
                 MOV    DL,'0'
                 MOV    AH,02H
                 INT    21H
 
        OUTPUTH:                                       ;H结尾，说明16进制
                 MOV    DL,'H'
                 MOV    AH,02H
                 INT    21H
                 RET
NumToHex ENDP
CODE ENDS
END START