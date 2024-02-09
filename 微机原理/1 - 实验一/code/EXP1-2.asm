DATA SEGMENT
      NUMBERS DW 0001H, 0002H, 0003H, 0004H, 0005H, 0006H, 0007H, 0008H, 0009H, 000AH, 000BH, 000CH, 000DH, 000EH, 000FH, 0010H
      SUM     DW 0FFFFH
DATA ENDS

STACK SEGMENT
            DW 16 DUP(0)
STACK ENDS

CODE SEGMENT
            ASSUME CS:CODE, DS:DATA, SS:STACK
      START:
            MOV    AX, DATA
            MOV    DS, AX
            MOV    AX, STACK
            MOV    SS, AX
            MOV    SP, 20H
            MOV    AX, 0
            MOV    BX, 0
            MOV    CX, 16
      S1:   
            ADD    AX, [BX]
            PUSH   [BX]
            ADD    BX, 2
            LOOP   S1

            MOV    DS:SUM, AX
            MOV    BX, 0
            MOV    CX, 16

      S2:   POP    [BX]
            ADD    BX, 2
            LOOP   S2

            MOV    AH, 4CH
            INT    21H
CODE ENDS
END START 
