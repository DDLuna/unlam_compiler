/******SECCION DEFINICIONES******/

%{
//Includes y defines
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
FILE  *yyin;
#define ES_ID 1
#define NO_ENCONTRADO -1

//Structs
	//TS
struct struct_tablaSimbolos{
	char nombre[100];
	char tipo[15];
	char valor[100];
	char longitud[10];
};

typedef struct arbol{
	int nodo;
	struct arbol *izq;
	struct arbol *der;
}arbol;

/***** FUNCIONES ****/
void guardar_TS();
void verificarExistencia();
void escribirTS();
void guardarCte_TS();
arbol *crear_nodo(int nodetype, arbol *izq, arbol *der);
arbol *crear_hoja(int nodetype);

/********VARIABLES*********/
struct struct_tablaSimbolos tablaSimbolos[1000];
int punteroTablaSimbolos = 0;
char* tipo_dato;
char vectorTipoDato[1000][10];
int contadorTipoDatoEscribir = 0;
int contadorTipoDatoLeer = 0;
char valorConst[31];

int contador_variables = 0;
%}

%union{
char* id;
int num;
double real; 
char* string;
struct arbol *ast;
}
/******SECCION TOKENS******/

%token OP_SUMA
%token OP_RESTA
%token OP_MULT
%token OP_DIV
%token OP_ASIG
%token OP_COMP
%token OP_MAYOR
%token OP_MENOR
%token OP_MAYIG
%token OP_MENIG
%token OP_DIST
%token OP_NEG
%token INI_COM
%token FIN_COM
%token IF
%token ELSE
%token REPEAT
%token PRINT
%token READ
%token DEC_VAR
%token FIN_DECVAR
%token ENTERO
%token FLOTANTE
%token AND
%token OR
%token CONSTANTE
%token MODULO
%token DIV_ENT
%token PAR_A
%token PAR_C
%token COR_A
%token COR_C
%token LLAVE_A
%token LLAVE_C
%token PYC
%token COMA
%token PUNTO
%token DOS_PUNTOS

%token <id> ID
%token <num> CONST_ENT
%token <real> CONST_REAL
%token <string> CONST_STRING
%type <ast> expresion
%type <ast> termino
%type <ast> factor
%type <ast> asignacion

/******SECCION DEFINICION DE REGLAS******/

%%
programaStart: programa {escribirTS(); printf("Compilación exitosa\n");}
	;

programa: inicioVariables  cuerpoPrograma
	| cuerpoPrograma
	| inicioVariables
	;

inicioVariables: DEC_VAR declaracion FIN_DECVAR 
	;

cuerpoPrograma: cuerpoPrograma {printf ("\n");} sentencia 
	| {printf ("\n");} sentencia
	;

sentencia: asignacion
	| iteracion
	| seleccion
	| PRINT CONST_STRING {guardar_TS($2, "string", !ES_ID); printf ("\t\tPrint %s",$2);}
	| PRINT ID {printf ("\t\tPrint %s",$2);}
	| READ ID {printf ("\t\tRead %s",$2);}
	| declaracionConstante
	;


declaracion: declaracion COR_A {printf ("\ttipos: ");} listaTipos COR_C DOS_PUNTOS COR_A {printf ("\n\tvariables: ");} listaVar COR_C 
	| COR_A {printf ("\ttipos: ");} listaTipos COR_C DOS_PUNTOS COR_A {printf ("\n\tvariables: ");} listaVar COR_C
	;

listaTipos: listaTipos COMA tipo
	| tipo
	;

tipo: ENTERO {
		strcpy(vectorTipoDato[contadorTipoDatoEscribir],"int");
		contadorTipoDatoEscribir++;
		contador_variables++;
		printf ("Entero ");
	}
	| FLOTANTE {
		strcpy(vectorTipoDato[contadorTipoDatoEscribir],"float");
		contadorTipoDatoEscribir++;
		contador_variables++;
		printf("Flotante ");
	}
	;

listaVar: listaVar COMA ID {
		if(contador_variables > 0) {
			guardar_TS($3,vectorTipoDato[contadorTipoDatoLeer], ES_ID);
			contadorTipoDatoLeer++;
			contador_variables--;
		}
		printf ("%s ",$3);
	}
	| ID {
		if(contador_variables > 0) {
			guardar_TS($1,vectorTipoDato[contadorTipoDatoLeer], ES_ID);
			contadorTipoDatoLeer++;
			contador_variables--;
		}
		printf("%s ",$1);
	}
	;

declaracionConstante: CONSTANTE ID OP_ASIG {
		printf("\tDeclaraste una constante de tipo");
	} tipoCte {
		guardarCte_TS($2,tipo_dato);
	}
	;

tipoCte: CONST_STRING {
		tipo_dato = "constString";
		strcpy(valorConst, $1);
		printf ("String");
	} //si queremos que guarde por separado la cte, agregar guardar_TS($1,tipo_dato, !ES_ID
	| CONST_ENT {tipo_dato = "constInt"; itoa($1, valorConst, 10); printf("Entera");}
	| CONST_REAL {tipo_dato = "constFloat"; ftoa($1, valorConst, 10); printf("Flotante");}
	;

asignacion: ID {verificarExistencia($1);} OP_ASIG {printf ("\tAsignaste ");} expresion {printf (" a '%s'",$1);} 
	;

seleccion:  IF condicion LLAVE_A cuerpoPrograma LLAVE_C {printf ("\n\tElse ");} ELSE LLAVE_A cuerpoPrograma LLAVE_C {printf ("\n");}
	| IF condicion LLAVE_A cuerpoPrograma LLAVE_C {printf ("\n");}
	| IF condicion {printf ("\n\t");} sentencia {printf ("\n");} 
	;

iteracion: REPEAT condicion LLAVE_A cuerpoPrograma LLAVE_C {printf ("\n");}
   ;

condicion: comparacion
	| comparacion {printf ("And\n");} AND comparacion
	| comparacion {printf ("Or\n");} OR comparacion 
	;

comparacion: expresion comparador expresion
	| OP_NEG {printf ("Negado");} PAR_A expresion comparador expresion PAR_C
	;

comparador: OP_COMP {printf (" Igual ");}
	| OP_MAYOR {printf (" Mayor ");}
	| OP_MENOR {printf (" Menor ");}
	| OP_MAYIG {printf (" Mayor O Igual ");}
	| OP_MENIG {printf (" Menor O Igual ");}
	| OP_DIST {printf (" Distinto ");}
	;

expresion: expresion OP_SUMA termino {$$ = crear_nodo('+', $1, $3);}
	| expresion OP_RESTA termino {$$ = crear_nodo('-', $1, $3);}
	| termino
	;

termino: termino OP_MULT factor {$$ = crear_nodo('*', $1, $3);}
	| termino OP_DIV factor {$$ = crear_nodo('/', $1, $3);}
	| termino DIV_ENT factor {$$ = crear_nodo('D', $1, $3);}
	| termino MODULO factor {$$ = crear_nodo('M', $1, $3);}
	| factor {$$ = $1;}
	;

factor: PAR_A expresion PAR_C {$$ = $2;}
	| ID {printf("'%s'",$1); $$ = crear_hoja($1);}		// no deberia guardar $$ en la TS?
	| CONST_ENT {guardar_TS($1,"int", !ES_ID); printf ("'%s'",$1); $$ = crear_hoja($1);}
	| CONST_REAL {guardar_TS($1,"float", !ES_ID); printf ("'%s'",$1); $$ = crear_hoja($1);}
	;				  

%%

/******SECCION CODIGO******/

arbol *crear_nodo(int nodetype, arbol *izq, arbol *der) {
	arbol *a = malloc(sizeof(arbol));
	if (!a) {
		yyerror("No hay memoria");
		exit(0);
	}
	a->nodo = nodetype;
	a->izq = izq;
	a->der = der;
	return a;
}

arbol *crear_hoja(int nodetype) {
	return crear_nodo(nodetype, NULL, NULL);
}

void guardar_TS(char* nombre, char* tipo, int es_id){
	int i;
	char cad[10];
	char guion[30] = "_";
	for(i = 0; i < punteroTablaSimbolos; i++){
		if(strcmp(tablaSimbolos[i].nombre, nombre) == 0){ //verifico que el nombre del ID sea único
			printf("ID con nombre repetido. Error de compilación");
			exit(1);
		}
	}

	if(es_id){
		strcpy(tablaSimbolos[punteroTablaSimbolos].nombre, nombre);
		strcpy(tablaSimbolos[punteroTablaSimbolos].tipo, tipo); //agrego los datos. Un underscore en tipo represta una const.
		strcpy(tablaSimbolos[punteroTablaSimbolos].valor,"-");
	}else{
		strcpy(tablaSimbolos[punteroTablaSimbolos].nombre,strcat(guion,nombre));
		strcpy(tablaSimbolos[punteroTablaSimbolos].valor,nombre);
	}
	
	if(strcmp(tipo,"string") == 0 && !es_id){ //si es un string y no es un id (algo como "hello hello hello"), guardo su longitud en la tabla.
		itoa(strlen(nombre),cad,10);
		strcpy(tablaSimbolos[punteroTablaSimbolos].longitud,cad); 
	}
	punteroTablaSimbolos++; //incremento la variable global del puntero para señalizar que agregué un elemento a la lista
}

void guardarCte_TS(char* nombre, char* tipo){
	int i;
	char cad[30];
	char guion[30] = "_";
	for(i = 0; i < punteroTablaSimbolos; i++){
		if(strcmp(tablaSimbolos[i].nombre, nombre) == 0){ //verifico que el nombre del ID sea único
			printf("ID con nombre repetido. Error de compilación");
			exit(1);
		}
	}
	strcpy(tablaSimbolos[punteroTablaSimbolos].nombre, nombre);
	strcpy(tablaSimbolos[punteroTablaSimbolos].tipo, tipo); //agrego los datos. Un underscore en tipo represta una const.
	strcpy(tablaSimbolos[punteroTablaSimbolos].valor, valorConst);	
	if(strcmp(tipo,"constString") == 0){ //si es un const string
		itoa(strlen(nombre),cad,10);
		strcpy(tablaSimbolos[punteroTablaSimbolos].longitud,cad); 
	}
	punteroTablaSimbolos++; //incremento la variable global del puntero para señalizar que agregué un elemento a la lista
}

void verificarExistencia(char* id){
	int i;
	for(i = 0; i < punteroTablaSimbolos; i++){
		if(strcmp(tablaSimbolos[i].nombre, id) == 0) //Si el id existe en mi tabla, salgo.
			return;
	}
	printf("ID no declarado. Error de compilación");
	exit(1);
}

void escribirTS(){
	FILE *pf; 
	int i;
	pf = fopen("ts.txt","w"); 

	if (!pf)
	{
		printf("Error al crear el archivo de tabla de simbolos\n");
		exit(1);
	}

	fprintf(pf, "Nombre\t\t\tTipo\t\t\tValor\t\t\tLongitud\n");
	for (i = 0; i < punteroTablaSimbolos; i++)
		fprintf(pf,"%s\t\t\t%s\t\t\t%s\t\t\t%s\n", tablaSimbolos[i].nombre,tablaSimbolos[i].tipo,tablaSimbolos[i].valor,tablaSimbolos[i].longitud);	
	
	fclose(pf); 
}

/***MAIN***/
int main(int argc,char *argv[]){
	
	if ((yyin = fopen(argv[1], "rt")) == NULL){
		printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
	}else{
		yyparse();
	}
  	fclose(yyin);
  	return 0;
}

int yyerror(void){
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}

