DATA SEGMENT
    NUMBERS   DW 0001H, 0002H, 0003H, 0004H, 0005H, 0006H, 0007H, 0008H, 0009H, 000AH, 000BH, 000CH, 000DH, 000EH, 000FH, 0010H,0011H, 0012H, 0013H, 0014H, 0015H, 0016H, 0017H, 0018H,0019H, 001AH, 001BH, 001CH, 001DH, 001EH, 001FH, 0020H
    ChangeRow DB 0DH,0AH,'$'
    MAXVAL    DW ?
DATA ENDS

STACK SEGMENT
          DW 16 DUP(0)
STACK ENDS

CODE SEGMENT
                 ASSUME CS:CODE, DS:DATA, SS:STACK
    MINVAL       DW     ?                             ; Store MINVAL at the beginning of the code segment

    START:       
                 MOV    AX, DATA
                 MOV    DS, AX
                 MOV    AX, STACK
                 MOV    SS, AX
                 MOV    SP, 20H
          
    ; Initialize BX to point to the start of the array
                 MOV    BX, OFFSET NUMBERS
          
    ; Load the first number into AX to initialize MAXVAL and MINVAL
                 MOV    AX, [BX]
                 MOV    DS:MAXVAL, AX
                 MOV    CS:MINVAL, AX
          
    ; Set CX to 32 (4*8) for loop count
                 MOV    CX, 32

    FIND_MIN_MAX:
    ; Compare current number with MAXVAL
                 CMP    AX, DS:MAXVAL
                 JLE    NOT_MAX
                 MOV    DS:MAXVAL, AX
    NOT_MAX:     
    ; Compare current number with MINVAL
                 CMP    AX, CS:MINVAL
                 JGE    NOT_MIN
                 MOV    CS:MINVAL, AX
    NOT_MIN:     
    ; Move to the next number in the array
                 ADD    BX, 2
                 MOV    AX, [BX]
                 LOOP   FIND_MIN_MAX

    ; Output MAXVAL and MINVAL
                 MOV    DX, DS:MAXVAL
                ;  CALL   OUTPUT
                 MOV    DX, CS:MINVAL
                ;  CALL   OUTPUT

    ; End the program
                 MOV    AH, 4CH
                 INT    21H


CODE ENDS
END START 
