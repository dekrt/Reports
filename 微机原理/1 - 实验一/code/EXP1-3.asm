DATA SEGMENT
        MaxLength    DB 100
        ActualLength DB ?
        STRING       DB 100 DUP(?)
        ChangeRow    DB 0DH,0AH,'$'
        UpperCase    DB 100 DUP(?)
DATA ENDS


STACK SEGMENT
        DW 128 DUP(0)
STACK ENDS

CODE SEGMENT
                     ASSUME CS: CODE, DS: DATA, SS: STACK
        MAIN:        
                     MOV    AX, DATA
                     MOV    DS, AX
        INPUT:       
                     MOV    DX,OFFSET MaxLength
                     MOV    AH,10
                     INT    21H

        ;转换为大写
                     MOV    BX,OFFSET STRING
                     MOV    DI,OFFSET UpperCase
                     MOV    CH,0
                     MOV    CL,ActualLength                      
        ;CX=ACTUALLENGTH
        TO_UPPER:    
                     MOV    AL,[BX]
                     CALL   TurnCapital
                     MOV    [DI],AL
                     INC    BX
                     INC    DI
                     LOOP   TO_UPPER

        ; 添加终止字符到UpperCase
                     MOV    BYTE PTR [DI], 24H

        ; 输出大写字符串
        OUTPUT_UPPER:
                     MOV    DX,OFFSET ChangeRow
                     MOV    AH,9
                     INT    21H
                
                     MOV    DX,OFFSET UpperCase
                     MOV    AH,9
                     INT    21H
        
        ;转换为小写, CX=ACTUALLENGTH
                     MOV    BX,OFFSET STRING
                     MOV    CH,0
                     MOV    CL,ActualLength                      
        TO_LOWER:    
                     MOV    AL,[BX]
                     CALL   TurnSmall
                     MOV    [BX],AL
                     INC    BX
                     LOOP   TO_LOWER

        ; 添加终止字符到STRING
                     MOV    BYTE PTR [BX], 24H

        ; 输出小写字符串
        OUTPUT_LOWER:
                     MOV    DX,OFFSET ChangeRow
                     MOV    AH,9
                     INT    21H
                
                     MOV    DX,OFFSET STRING
                     MOV    AH,9
                     INT    21H

        END_MAIN:    MOV    AH,4CH
                     INT    21H

        
TurnCapital PROC
        ;AL中的字符转为大写
                     CMP    AL,'a'
                     JL     DONE_CAP
                     CMP    AL,'z'
                     JG     DONE_CAP
                     SUB    AL,20H                               
        ; 大写=小写-20H
        DONE_CAP:    
                     RET
TurnCapital ENDP

TurnSmall PROC
        ;AL中的字符作大小写转换
                     CMP    AL,'A'
                     JL     DONE_SMALL
                     CMP    AL,'Z'
                     JG     DONE_SMALL
                     ADD    AL,20H
        DONE_SMALL:  
                     RET
TurnSmall ENDP

CSEG ENDS
        END MAIN
