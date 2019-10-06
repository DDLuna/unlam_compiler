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
struct tabla_simbolos{
	char nombre[100];
	char tipo[15];
	char valor[100];
	char longitud[10];
};

typedef struct arbol{
	char* nodo;
	char* tipo;
	struct arbol *izq;
	struct arbol *der;
}arbol;

/***** FUNCIONES ****/
void guardar_tabla_de_simbolos();
void verificar_existencia();
void escribir_tabla_de_simbolos(:);
void guardar_cte_tabla_de_simbolos();
arbol* crear_nodo(char* elemento, char* tipo, arbol *izq, arbol *der);
arbol* crear_hoja(char* elemento, char* tipo);
void recorrer_arbol_inorden(arbol* ast);

/********VARIABLES*********/
struct tabla_simbolos tabla_simbolos_s[1000];
int puntero_tabla_simbolos = 0;
char* tipo_dato;
char vector_tipo_de_dato[1000][10];
int contador_tipo_dato_escribir = 0;
int contador_tipo_dato_leer = 0;
char valor_const[31];

int contador_variables = 0;
%}

%union{
char* id;
char* num;
char* real; 
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
programaStart: programa {escribir_tabla_de_simbolos(); printf("Compilación exitosa\n"); $$ = $1;}
	;

programa: inicioVariables  cuerpoPrograma { $$ = crear_nodo("PROG", NULL, $1, $2);}
	| cuerpoPrograma { $$ = $1;}
	| inicioVariables { $$ = $1;}
	;

inicioVariables: DEC_VAR declaracion FIN_DECVAR {$$ = $2;}
	;

cuerpoPrograma: cuerpoPrograma {printf ("\n");} sentencia { $$ = crear_nodo("CUERPO_PROG", NULL, $1, $2);}
	| {printf ("\n");} sentencia { $$ = $1;}
	;

sentencia: asignacion { $$ = $1;}
	| iteracion { $$ = $1;}
	| seleccion { $$ = $1;}
	| PRINT CONST_STRING {guardar_tabla_de_simbolos($2, "string", !ES_ID); printf ("\t\tPrint %s",$2);} //NO SE COMO PONERLO
	| PRINT ID {printf ("\t\tPrint %s",$2);} //NO SE COMO PONERLO
	| READ ID {printf ("\t\tRead %s",$2);} //NO SE COMO PONERLO
	| declaracionConstante { $$ = $1;}
	;


declaracion: declaracion COR_A {printf ("\ttipos: ");} listaTipos COR_C DOS_PUNTOS COR_A {printf ("\n\tvariables: ");} listaVar COR_C {
		$$ = crear_nodo("CUERPO_DECL", NULL, $1, crear_nodo(":", NULL, $3, $7));
	}
	| COR_A {printf ("\ttipos: ");} listaTipos COR_C DOS_PUNTOS COR_A {printf ("\n\tvariables: ");} listaVar COR_C {
		$$ = crear_nodo(":", NULL, $2, $6);
	}
	;

listaTipos: listaTipos COMA tipo {$$ = crear_nodo(",", NULL, $1, crear_hoja($3, NULL))}
	| tipo {$$ = $1}
	;

tipo: ENTERO {
		strcpy(vector_tipo_de_dato[contador_tipo_dato_escribir],"int");
		contador_tipo_dato_escribir++;
		contador_variables++;
		printf ("Entero ");
		$$ = crear_hoja($1, "int");
	}
	| FLOTANTE {
		strcpy(vector_tipo_de_dato[contador_tipo_dato_escribir],"float");
		contador_tipo_dato_escribir++;
		contador_variables++;
		printf("Flotante ");
		$$ = crear_hoja($1, "float")
	}
	; // no se que poner aca como hoja, fijensen si esta bien

listaVar: listaVar COMA ID {
		if(contador_variables > 0) {
			guardar_tabla_de_simbolos($3,vector_tipo_de_dato[contador_tipo_dato_leer], ES_ID);
			contador_tipo_dato_leer++;
			contador_variables--;
		}
		printf ("%s ",$3);
		$$ = crear_nodo(",", NULL, $1, crear_hoja($3, NULL));
	}
	| ID {
		if(contador_variables > 0) {
			guardar_tabla_de_simbolos($1,vector_tipo_de_dato[contador_tipo_dato_leer], ES_ID);
			contador_tipo_dato_leer++;
			contador_variables--;
		}
		printf("%s ",$1);
		$$ = crear_hoja($1, NULL);
	}
	;

declaracionConstante: CONSTANTE ID OP_ASIG { printf("\tDeclaraste una constante de tipo");} tipoCte {$$ = crear_nodo("=", NULL, crear_hoja($2, NULL), $4); guardar_cte_tabla_de_simbolos($2,tipo_dato);}
	; // No inclui el termino "CONSTANTE" al arbol, se deberia agregar?

tipoCte: CONST_STRING {tipo_dato = "constString"; strcpy(valor_const, $1); printf ("String"); $$ = crear_hoja($1, "string");} //si queremos que guarde por separado la cte, agregar guardar_tabla_de_simbolos($1,tipo_dato, !ES_ID
	| CONST_ENT {tipo_dato = "constInt"; itoa($1, valor_const, 10); printf("Entera"); $$ = crear_hoja($1, "int");}
	| CONST_REAL {tipo_dato = "constFloat"; ftoa($1, valor_const, 10); printf("Flotante"); $$ = crear_hoja($1, "float");}
	;

asignacion: ID {verificar_existencia($1);} OP_ASIG {printf ("\tAsignaste ");} expresion {printf (" a '%s'",$1); $$ = crear_nodo("=", NULL, crear_hoja($1, NULL), $3);} 
	;

seleccion:  IF condicion LLAVE_A cuerpoPrograma LLAVE_C {printf ("\n\tElse ");} ELSE LLAVE_A cuerpoPrograma LLAVE_C {printf ("\n"); $$ = crear_nodo("IF", NULL, $2, crear_nodo("CUERPO_IF", $4, $8));} //El ELSE ira?
	| IF condicion LLAVE_A cuerpoPrograma LLAVE_C {printf ("\n"); $$ = crear_nodo("IF", NULL, $2, $4);}
	| IF condicion {printf ("\n\t");} sentencia {printf ("\n"); $$ = crear_nodo("IF", NULL, $2, $3);} 
	;

iteracion: REPEAT condicion LLAVE_A cuerpoPrograma LLAVE_C {printf ("\n"); $$ = crear_nodo("REPEAT", NULL, $2, $4);}
   ;

condicion: comparacion
	| comparacion {printf ("And\n");} AND comparacion {$$ = crear_nodo("AND", NULL, $1, $3);}
	| comparacion {printf ("Or\n");} OR comparacion {$$ = crear_nodo("OR", NULL, $1, $3);}
	| OP_NEG {printf ("Negado");} PAR_A comparacion PAR_C {$$ = crear_nodo("!", NULL, $3, NULL);} //Se ignoran los parentesis?
	;

comparacion: expresion comparador expresion {$$ = crear_nodo($2, NULL, $1, $3);}
	;

comparador: OP_COMP {printf (" Igual "); $$ = "==";}
	| OP_MAYOR {printf (" Mayor "); $$ = ">";}
	| OP_MENOR {printf (" Menor "); $$ = "<";}
	| OP_MAYIG {printf (" Mayor O Igual "); $$ = ">=";}
	| OP_MENIG {printf (" Menor O Igual "); $$ = "<=";}
	| OP_DIST {printf (" Distinto "); $$ = "!=";}
	;

expresion: expresion OP_SUMA termino {$$ = crear_nodo("+", NULL, $1, $3);}
	| expresion OP_RESTA termino {$$ = crear_nodo("-", NULL, $1, $3);}
	| termino{$$ = $1;}
	;

termino: termino OP_MULT factor {$$ = crear_nodo("*", NULL, $1, $3);}
	| termino OP_DIV factor {$$ = crear_nodo("/", NULL, $1, $3);}
	| termino DIV_ENT factor {$$ = crear_nodo("DIV", NULL, $1, $3);}
	| termino MODULO factor {$$ = crear_nodo("MOD", NULL, $1, $3);}
	| factor {$$ = $1;}
	;

factor: PAR_A expresion PAR_C {$$ = $2;}
	| ID {printf("'%s'",$1); $$ = crear_hoja($1, NULL);}		// no deberia guardar $$ en la TS?
	| CONST_ENT {guardar_tabla_de_simbolos($1,"int", !ES_ID); printf ("'%s'",$1); $$ = crear_hoja($1, "int");}
	| CONST_REAL {guardar_tabla_de_simbolos($1,"float", !ES_ID); printf ("'%s'",$1); $$ = crear_hoja($1, "real");}
	;				  

%%

/******SECCION CODIGO******/

arbol* crear_nodo(char* elemento, char* tipo, arbol *izq, arbol *der) {
	arbol *a = malloc(sizeof(arbol));
	if (!a) {
		yyerror("No hay memoria");
		exit(0);
	}
	a->nodo = elemento;
	a->tipo = tipo;
	a->izq = izq;
	a->der = der;
	return a;
}

arbol* crear_hoja(char* elemento, char* tipo) {
	return crear_nodo(elemento, tipo, NULL, NULL);
}

void recorrer_arbol_inorden(arbol* ast) {
	if (!ast) {
		return
	}
	recorrer_arbol_inorden(ast->izq);
	printf("%s", ast->nodo);
	recorrer_arbol_inorden(ast->der);
}
void guardar_tabla_de_simbolos(char* nombre, char* tipo, int es_id){
	int i;
	char cad[10];
	char guion[30] = "_";
	for(i = 0; i < puntero_tabla_simbolos; i++){
		if(strcmp(tabla_simbolos_s[i].nombre, nombre) == 0){ //verifico que el nombre del ID sea único
			printf("ID con nombre repetido. Error de compilación");
			exit(1);
		}
	}

	if(es_id){
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].nombre, nombre);
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].tipo, tipo); //agrego los datos. Un underscore en tipo represta una const.
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].valor,"-");
	}else{
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].nombre,strcat(guion,nombre));
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].valor,nombre);
	}
	
	if(strcmp(tipo,"string") == 0 && !es_id){ //si es un string y no es un id (algo como "hello hello hello"), guardo su longitud en la tabla.
		itoa(strlen(nombre),cad,10);
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].longitud,cad); 
	}
	puntero_tabla_simbolos++; //incremento la variable global del puntero para señalizar que agregué un elemento a la lista
}

void guardar_cte_tabla_de_simbolos(char* nombre, char* tipo){
	int i;
	char cad[30];
	char guion[30] = "_";
	for(i = 0; i < puntero_tabla_simbolos; i++){
		if(strcmp(tabla_simbolos_s[i].nombre, nombre) == 0){ //verifico que el nombre del ID sea único
			printf("ID con nombre repetido. Error de compilación");
			exit(1);
		}
	}
	strcpy(tabla_simbolos_s[puntero_tabla_simbolos].nombre, nombre);
	strcpy(tabla_simbolos_s[puntero_tabla_simbolos].tipo, tipo); //agrego los datos. Un underscore en tipo represta una const.
	strcpy(tabla_simbolos_s[puntero_tabla_simbolos].valor, valor_const);	
	if(strcmp(tipo,"constString") == 0){ //si es un const string
		itoa(strlen(nombre),cad,10);
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].longitud,cad); 
	}
	puntero_tabla_simbolos++; //incremento la variable global del puntero para señalizar que agregué un elemento a la lista
}

void verificar_existencia(char* id){
	int i;
	for(i = 0; i < puntero_tabla_simbolos; i++){
		if(strcmp(tabla_simbolos_s[i].nombre, id) == 0) //Si el id existe en mi tabla, salgo.
			return;
	}
	printf("ID no declarado. Error de compilación");
	exit(1);
}

void escribir_tabla_de_simbolos(){
	FILE *pf; 
	int i;
	pf = fopen("ts.txt","w"); 

	if (!pf)
	{
		printf("Error al crear el archivo de tabla de simbolos\n");
		exit(1);
	}

	fprintf(pf, "Nombre\t\t\tTipo\t\t\tValor\t\t\tLongitud\n");
	for (i = 0; i < puntero_tabla_simbolos; i++)
		fprintf(pf,"%s\t\t\t%s\t\t\t%s\t\t\t%s\n", tabla_simbolos_s[i].nombre,tablaSimbolos[i].tipo,tablaSimbolos[i].valor,tablaSimbolos[i].longitud);	
	
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
	system("Pause");
	exit (1);
}