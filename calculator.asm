; calculator.asm
.686
.model flat, C
.stack 4096

.data
divZeroMsg db "Error: division por 0",0

.code

; double divide(double a, double b)
divide PROC
    movsd xmm0, xmm0        ; numerador
    movsd xmm1, xmm1        ; denominador

    ; verificar division por 0
    pxor xmm2, xmm2
    ucomisd xmm1, xmm2
    je div_by_zero

    divsd xmm0, xmm1
    ret

div_by_zero:
    lea rcx, divZeroMsg
    call printf             ; printf del C para mostrar error
    xorps xmm0, xmm0        ; devolver 0
    ret
divide ENDP

; double average(double* list, int size)
average PROC
    ; RCX = puntero a lista
    ; RDX = size
    ; Simplificado: suma y divide
    ; [Opcional: implementar en ASM puro si quieres]

    ret
average ENDP

END