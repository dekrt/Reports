DATA SEGMENT
    PROMPT    DB 'Please enter a sentence: $'
    INPUT     DB 80, ?, 80 DUP(' ')
    OUTPUT    DB 80 DUP(' '), '$'
    CHANGEROW DB 0DH, 0AH, '$'
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

    ; Read input sentence
                    LEA    DX, INPUT
                    MOV    AH, 0AH
                    INT    21H

    ; Process the sentence
                    LEA    SI, INPUT + 2                 ; Skip the length byte
                    LEA    DI, OUTPUT
                    MOV    BL, ' '                       ; Initialize BL with space character

    PROCESS_LOOP:   
                    MOV    AL, [SI]

    ; Convert to uppercase if previous character is space
                    CMP    BL, ' '
                    JNE    CHECK_LOWERCASE
                    CMP    AL, 'a'
                    JB     STORE_CHAR
                    CMP    AL, 'z'
                    JA     STORE_CHAR
                    SUB    AL, 20H
                    JMP    STORE_CHAR

    CHECK_LOWERCASE:
    ; Convert to lowercase
                    CMP    AL, 'A'
                    JB     STORE_CHAR
                    CMP    AL, 'Z'
                    JA     STORE_CHAR
                    ADD    AL, 20H

    STORE_CHAR:     
                    MOV    [DI], AL
                    INC    DI
                    MOV    BL, AL
                    INC    SI
                    DEC    BYTE PTR [INPUT+1]            ; Decrement the length counter
                    JNZ    PROCESS_LOOP

    ; Terminate the output string
                    MOV    BYTE PTR [DI], '$'
    
                    MOV    DX,OFFSET CHANGEROW
                    MOV    AH,09H
                    INT    21H

    ; Display the processed sentence
                    MOV    AH, 09H
                    LEA    DX, OUTPUT
                    INT    21H

    ; End program
                    MOV    AH, 4CH
                    INT    21H

CODE ENDS
END START
