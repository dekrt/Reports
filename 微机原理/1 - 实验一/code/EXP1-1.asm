DATA SEGMENT

DATA ENDS

STACK SEGMENT
          DW 128 DUP(0)
STACK ENDS

CODE SEGMENT
          ASSUME CS:CODE, DS:DATA, SS:STACK
    START:
          MOV    AX, 1234H
          MOV    BX, 5678H
          MOV    CX, 9ABCH
          MOV    DX, 0DEFFH

    ; 交换 AX 和 BX 的值
          PUSH   AX
          PUSH   BX
          POP    AX
          POP    BX

    ; 交换 CX 和 DX 的值
          PUSH   CX
          PUSH   DX
          POP    CX
          POP    DX

    ; 交换 AX 的高 8 位 (AH) 和 DX 的低 8 位 (DL)
          PUSH   AX
          POP    CX
          MOV    AL, AH
          MOV    AH, DL
          MOV    DL, AL
          MOV    AX, 4C00H
          INT    21H
CODE ENDS
END START 
