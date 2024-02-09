DATA SEGMENT
    COUNT   DW 8                                                          ; 8 words follow
    NUMBERS DW 1234H, 5678H, 9ABCH, 0DEF0H, 1111H, 2222H, 3333H, 4444H
    ENDNUM  DW ?                                                          ; Placeholder for the end of the numbers
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
          
    ; Initialize BX to point to the start of the array
              MOV    BX, OFFSET NUMBERS
              ADD    BX, 2                         ; Skip the count
          
    ; Load the count into CX
              MOV    CX, [OFFSET NUMBERS]
          
    ; Initialize DI to point to the end of the array
              LEA    DI, ENDNUM

    PROCESS:  
    ; Load the current number into AX
              MOV    AX, [BX]
          
    ; Check if D3 and D4 bits are set
              TEST   AX, 0018H                     ; D3 and D4 bits
              JZ     SKIP_MOVE                     ; If not set, skip

    ; Move the number to the end
              MOV    [DI], AX
              ADD    DI, 2

    ; Clear D3 and D4 bits
              AND    AX, 0FFE7H
              MOV    [BX], AX

    SKIP_MOVE:
    ; Move to the next number in the array
              ADD    BX, 2
              LOOP   PROCESS

    ; End the program
              MOV    AH, 4CH
              INT    21H

CODE ENDS
END START 
