include macros2.asm 
include number.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	a dd ?
	b dd ?
	_3 dd 3.0
	_4 dd 4.0
	_true db "true",'$', 4 dup (?)
	_false db "false",'$', 5 dup (?)
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
	FLD _3
	FSTP a

	; < 
	FLD a
	FLD _4
	FXCH
	FCOM
	FSTSW AX
	SAHF

	JAE ETIQUETA_ELSE_0

	; DISPLAY
	displayString _true

	JMP ETIQUETA_IF_1
ETIQUETA_ELSE_0:

	; DISPLAY
	displayString _false
ETIQUETA_IF_1:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)




	; END PROGRAM 

	mov AX, 4C00h
	int 21h
END START
