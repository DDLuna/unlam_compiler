/******SECCION DEFINICIONES******/
%{
	#include <float.h>
	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include "y.tab.h"
	#include <limits.h>

	int yyleng;	
	int numero_de_linea = 1;

	void verificarNivelComentario();
	void verificarRangoEnt();
	void verificarRangoReal();
	void verificarTamanioString();
%}

/******SECCION CONJUNTOS Y EXPRESIONES REGULARES******/

%option noyywrap

DIGITO			[0-9]
LETRA			[a-zA-Z]
ESPACIO			" "
SIMBOLO			[!|@|·|#|$|~|%|&|¬|¿|?]
ID              ({LETRA}({LETRA}|{DIGITO})*)
CONST_REAL		({DIGITO})+"."({DIGITO})+
CONST_ENT		({DIGITO})+
CONST_STRING	"\""({LETRA}|{DIGITO}|{SIMBOLO}|{ESPACIO})*"\""
COMENTARIO		"--/"(.*|\n|\r)"/--"

/******SECCION REGLAS******/

%%
"+"         { return OP_SUMA; }
"-"         { return OP_RESTA; }
"*"         { return OP_MULT; }
"/"         { return OP_DIV; }
"="         { return OP_ASIG; }
"=="         { return OP_COMP; }
">"         { return OP_MAYOR; }
"<"         { return OP_MENOR; }
">="         { return OP_MAYIG; }
"<="         { return OP_MENIG; }
"<>"         { return OP_DIST; }
"!"         { return OP_NEG; }
"--/"         { return INI_COM; }
"/--"         { return FIN_COM; }
"if"         { return IF; }
"else"         { return ELSE; }
"repeat"         { return REPEAT; }
"print"         { return PRINT; }
"read"         { return READ; }
"var"         { return DEC_VAR; }
"endvar"         { return FIN_DECVAR; }
"integer"         { return ENTERO; }
"float"         { return FLOTANTE; }
"&&"         { return AND; }
"||"         { return OR; }
"const"         { return CONSTANTE; }
"mod"         { return MODULO; }
"div"         { return DIV_ENT; }
"("         { return PAR_A; }
")"         { return PAR_C; }
"["         { return COR_A; }
"]"         { return COR_C; }
"{"         { return LLAVE_A; }
"}"         { return LLAVE_C; }
";"         { return PYC; }
","         { return COMA; }
"."         { return PUNTO; }
":"         { return DOS_PUNTOS; }
{ID}            { yylval.id=strdup(yytext); return ID; }
{CONST_ENT}		{ verificarRangoEnt(); yylval.num=strdup(yytext); return CONST_ENT; }
{CONST_REAL}	{ verificarRangoReal(); yylval.real=strdup(yytext); return CONST_REAL; }
{CONST_STRING}	{ verificarTamanioString(); yylval.string=strdup(yytext); return CONST_STRING; }
{COMENTARIO}	{verificarNivelComentario(); }

"\n"		{ numero_de_linea++; }
"\t"
%%

/******SECCION CODIGO******/

void verificarRangoEnt() {
	if (atoi(yytext) > 32767 || atoi(yytext) < -32768){
		printf("Se ha excedido el valor máximo de las constantes enteras");
		exit(1);
	}
}

void verificarRangoReal() {
	if (atof(yytext) > 8388608 || yyleng > 20 || atof(yytext) < -8388608) {
		printf("Se ha excedido el valor máximo de las constantes reales");
		exit(1);
	}
}

void verificarTamanioString() {
	if(yyleng > 30){
		printf("Se ha excedido el tamaño máximo de string");
		exit(1);
	}
}

void verificarNivelComentario() {

	int i;
	int nivelComentario = 1;
	int nivelMaximo = 1;
	int longitudCom = strlen(yytext);

	for(i=3;i<longitudCom;i++){
		if(yytext[i] == '-' && yytext[i+1] == '-' && yytext[i+2] == '/'){
			nivelComentario++;
		} else {
			if(yytext[i] == '/' && yytext[i+1] == '-' && yytext[i+2] == '-'){

				if(nivelComentario>nivelMaximo)nivelMaximo=nivelComentario;

				nivelComentario--;
			}
		}

		if(nivelComentario < 0) {
				printf("\n Sintax error, faltan delimitadores de apertura de comentario");
				exit(1);
			}
	}

		if(nivelComentario > 0) {
				printf("\n Sintax error, faltan delimitadores de cierre de comentario");
				exit(1);
		}

		if(nivelMaximo - nivelComentario > 2) {
			printf("\nHa introducido un comentario de mas de 2 niveles");
			exit(1);
		}

	printf("\nHa introducido un comentario de nivel %d",nivelMaximo-nivelComentario);
}