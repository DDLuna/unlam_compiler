include macros2.asm 
include number.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	a dd ?
	b dd ?
	j db "hols",'$', 4 dup (?)
	@SUMA dd ?
	@MENOS dd ?
	@DIVIDIR dd ?
	@MULTIPLAR dd ?
	@AUXILIAR dd ?


.code


	; ROUTINES
STRLEN PROC
	mov bx,0
STRL01:
	cmp BYTE PTR [SI+BX],'$'
	je STREND
	inc BX
	cmp BX, MAXTEXTSIZE
	jl STRL01
STREND:
	ret
STRLEN ENDP

COPY PROC
	call STRLEN
	cmp bx,MAXTEXTSIZE
	jle COPYSIZEOK
	mov bx,MAXTEXTSIZE
COPYSIZEOK:
	mov cx,bx
	cld
	rep movsb
	mov al,'$'
	mov BYTE PTR [DI],al
	ret
COPY ENDP

START:
	mov AX,@DATA
	mov DS,AX
	mov ES,AX
	finit




	; ASIGNACION 
	FLD hols
	FSTP j

	; DISPLAY
	displayString _j



	; END PROGRAM 

	mov AX, 4C00h
	int 21h
END START
