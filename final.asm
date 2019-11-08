include macros2.asm 
include number.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	a dd ?
	b dd ?
	c dd ?
	d dd ?
	_3 dd 3
	_4 dd 4
	l dd 4
	_entre_al_primer_then db "entre al primer then",'$', 20 dup (?)
	_10 dd 10
	_repeat_del_primer_if db "repeat del primer if",'$', 20 dup (?)
	_2 dd 2
	_5 dd 5
	_entre_al_primer_else db "entre al primer else",'$', 20 dup (?)
	_0 dd 0
	_a_es_par db "a es par",'$', 8 dup (?)
	_a_es_impar db "a es impar",'$', 10 dup (?)
	_1 dd 1
	_10_0 dd 10.0
	_3_12 dd 3.12
	_6 dd 6
	_7 dd 7
	_8 dd 8
	_9 dd 9
	_11 dd 11
	@SUMA dd ?
	@MENOS dd ?
	@DIVIDIR dd ?
	@MULTIPLICAR dd ?
	@AUXILIAR dd ?


.code


	; RUTINAS
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
	FILD _3
	FISTP a

	; ASIGNACION 
	FILD _4
	FISTP b

	; != 
	FILD a
	FILD _3
	FXCH
	FCOM
	FSTSW AX
	SAHF

	JE ETIQUETA_ELSE_0

	; printeo
	displayInteger l
 	newLine 1

	; printeo
	displayString _entre_al_primer_then
 	 newLine 1

ETIQUETA_REPEAT_0:

	; < 
	FILD b
	FILD _10
	FXCH
	FCOM
	FSTSW AX
	SAHF

	JAE ETIQUETA_REPEAT_FUERA_0

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; < 
	FILD a
	FILD _10
	FXCH
	FCOM
	FSTSW AX
	SAHF

	JAE ETIQUETA_REPEAT_FUERA_0

	; printeo
	displayString _repeat_del_primer_if
 	 newLine 1

	; SUMA 
	FILD b
	FILD _2
	FADD
	FISTP @SUMA

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @SUMA
	FISTP b

	; ASIGNACION 
	FILD b
	FISTP a

	JMP ETIQUETA_REPEAT_0
ETIQUETA_REPEAT_FUERA_0:

	; printeo
	displayInteger a
 	newLine 1

	; printeo
	displayInteger b
 	newLine 1

	JMP ETIQUETA_IF_1
ETIQUETA_ELSE_0:

	; ASIGNACION 
	FILD _5
	FISTP a

	; printeo
	displayString _entre_al_primer_else
 	 newLine 1

ETIQUETA_REPEAT_1:

	; < 
	FILD a
	FILD _10
	FXCH
	FCOM
	FSTSW AX
	SAHF

	JAE ETIQUETA_REPEAT_FUERA_1

	;RESIDUO
	FILD _2
	FILD a
	FPREM
	FISTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; == 
	FILD @DIVIDIR
	FILD _0
	FXCH
	FCOM
	FSTSW AX
	SAHF

	JNE ETIQUETA_ELSE_1

	; printeo
	displayString _a_es_par
 	 newLine 1

	; printeo
	displayInteger a
 	newLine 1

	JMP ETIQUETA_IF_1
ETIQUETA_ELSE_1:

	; printeo
	displayString _a_es_impar
 	 newLine 1

	; printeo
	displayInteger a
 	newLine 1
ETIQUETA_IF_1:

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; SUMA 
	FILD a
	FILD _1
	FADD
	FISTP @SUMA

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @SUMA
	FISTP a

	JMP ETIQUETA_REPEAT_1
ETIQUETA_REPEAT_FUERA_1:
ETIQUETA_IF_11206848:

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; DIVIDE 
	FILD _10
	FIDIV _3
	FISTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @DIVIDIR
	FISTP a

	; printeo
	displayInteger a
 	newLine 1

	;RESIDUO
	FLD _3_12
	FLD _10_0
	FPREM
	FSTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FLD @DIVIDIR
	FSTP c

	; printeo
	displayFloat c,3
 	newLine 1

	;RESIDUO
	FILD _6
	FILD _6
	FPREM
	FISTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @DIVIDIR
	FISTP a

	; printeo
	displayInteger a
 	newLine 1

	;RESIDUO
	FILD _6
	FILD _7
	FPREM
	FISTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @DIVIDIR
	FISTP a

	; printeo
	displayInteger a
 	newLine 1

	;RESIDUO
	FILD _6
	FILD _8
	FPREM
	FISTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @DIVIDIR
	FISTP a

	; printeo
	displayInteger a
 	newLine 1

	;RESIDUO
	FILD _6
	FILD _9
	FPREM
	FISTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @DIVIDIR
	FISTP a

	; printeo
	displayInteger a
 	newLine 1

	;RESIDUO
	FILD _6
	FILD _10
	FPREM
	FISTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @DIVIDIR
	FISTP a

	; printeo
	displayInteger a
 	newLine 1

	;RESIDUO
	FILD _6
	FILD _11
	FPREM
	FISTP @DIVIDIR

	; Limpar_pila
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FILD @DIVIDIR
	FISTP a

	; printeo
	displayInteger a
 	newLine 1



	; FIN PROGRAMA 

	mov AX, 4C00h
	int 21h
END START
