DATA SEGMENT
    PROMPT    DB 'Please enter the degree (0,30,60,90,120,150,180): $'
    OUTPUT    DB 'sin(', 3 DUP(' '), ')=','$'
    DEGREES   DW 0, 30, 60, 90, 120, 150, 180
    VALUES    DB '0    $', '0.5  $', '0.866$', '1    $', '0.866$', '0.5  $', '0    $'
    CHANGEROW DB 0DH, 0AH, '$',
DATA ENDS

STACK SEGMENT
          DW 128 DUP(0)
STACK ENDS

CODE SEGMENT
                  ASSUME CS:CODE, DS:DATA, SS:STACK

    START:        
                  MOV    AX, DATA
                  MOV    DS, AX
                  MOV    AX, STACK
                  MOV    SS, AX
                  MOV    SP, 256

    ; Display prompt
                  MOV    AH, 09H
                  LEA    DX, PROMPT
                  INT    21H

    ; Read input
                  MOV    AH, 01H
                  INT    21H
                  MOV    [OUTPUT+4], AL
                  CMP    AL, '9'
                  JA     SINGLE_DIGIT
                  INT    21H
                  MOV    [OUTPUT+5], AL

    SINGLE_DIGIT: 
    ; Convert input to number
                  MOV    AH, 0
                  MOV    AL, [OUTPUT+4]
                  SUB    AL, '0'
                  MOV    BH, 10
                  MUL    BH
                  MOV    BH, [OUTPUT+5]
                  SUB    BH, '0'
                  ADD    AL, BH
                  MOV    AH, 0

    ; Find sin value
                  LEA    BX, DEGREES
                  LEA    SI, VALUES
                  MOV    CX, 7

    FIND_VALUE:   
                  CMP    AX, [BX]
                  JE     DISPLAY_VALUE
                  ADD    BX, 2
                  ADD    SI, 6
                  DEC    CX
                  JNZ    FIND_VALUE

    ; Degree not found
                  INT    20H

    DISPLAY_VALUE:

                  MOV    DX,OFFSET CHANGEROW
                  MOV    AH,09H
                  INT    21H

                  MOV    AH, 09H
                  LEA    DX, OUTPUT
                  INT    21H
                  MOV    AH, 09H
                  MOV    DX, SI
                  INT    21H

    ; End program
                  MOV    AH, 4CH
                  INT    21H

CODE ENDS
END START
