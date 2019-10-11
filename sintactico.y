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
	const char* tipo;
	struct arbol *izq;
	struct arbol *der;
}arbol;

/***** FUNCIONES ****/
void guardar_tabla_de_simbolos();
void verificar_existencia();
void escribir_tabla_de_simbolos();
void guardar_cte_tabla_de_simbolos();
arbol* crear_nodo(char* elemento, const char* tipo, arbol *izq, arbol *der);
arbol* crear_hoja(char* elemento, const char* tipo);
void recorrer_arbol_inorden(FILE * pfi, arbol* ast);
void print2DUtil(struct arbol *raiz, int espacio); 
void print2D(struct arbol *raiz); 
const char* calcular_resultante(const char*, const char*);
const char* obtener_tipo_arbol(arbol* id);
const char* obtener_tipo(char* id);


/********VARIABLES*********/
struct tabla_simbolos tabla_simbolos_s[1000];
int puntero_tabla_simbolos = 0;
const char* tipo_dato;
char vector_tipo_de_dato[1000][10];
int contador_tipo_dato_escribir = 0;
int contador_tipo_dato_leer = 0;
const char* valor_const;
int contador_variables = 0;
arbol* a;

/********CONSTANTES*******/
const char* STRING = "string";
const char* INT = "int";
const char* FLOAT = "float";
const char* CONSTINT = "constInt";
const char* CONSTFLOAT = "constFloat";
const char* CONSTSTRING = "constString";

%}

%union{
char* id;
char* num;
char* real; 
char* string;
struct arbol *ast;
char* op_log;
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

%type <ast> programaStart
%type <ast> programa
%type <ast> cuerpoPrograma
%type <ast> sentencia
%type <ast> declaracionConstante
%type <ast> tipoCte
%type <ast> asignacion
%type <ast> seleccion
%type <ast> iteracion
%type <ast> condicion
%type <ast> comparacion
%type <op_log> comparador
%type <ast> expresion
%type <ast> termino
%type <ast> factor


/******SECCION DEFINICION DE REGLAS******/

%%
programaStart: programa {escribir_tabla_de_simbolos(); printf("Compilación exitosa\n"); $$ = $1; a = $$;}
	;

programa: inicioVariables cuerpoPrograma {$$ = crear_nodo("PROG", NULL, NULL, $2);}
	| cuerpoPrograma {$$ = $1;}
	| inicioVariables
	;

inicioVariables: DEC_VAR declaracion FIN_DECVAR
	;

cuerpoPrograma: cuerpoPrograma sentencia {$$ = crear_nodo("CUERPO_PROG", NULL, $1, $2);}
	| sentencia {$$ = $1;}
	;

sentencia: asignacion { $$ = $1;}
	| iteracion { $$ = $1;}
	| seleccion { $$ = $1;}
	| PRINT CONST_STRING {
		guardar_tabla_de_simbolos($2, STRING, !ES_ID); 
		$$ = crear_nodo("PRINT", STRING, NULL, crear_hoja($2, NULL));
		}
	| PRINT ID {$$ = crear_nodo("PRINT", obtener_tipo($2), NULL, crear_hoja($2, NULL));}
	| READ ID {$$ = crear_nodo("READ", obtener_tipo($2), NULL, crear_hoja($2, NULL));}
	| declaracionConstante
	;


declaracion: declaracion COR_A listaTipos COR_C DOS_PUNTOS COR_A listaVar COR_C
	| COR_A listaTipos COR_C DOS_PUNTOS COR_A listaVar COR_C
	;

listaTipos: listaTipos COMA tipo
	| tipo
	;

tipo: ENTERO {
		strcpy(vector_tipo_de_dato[contador_tipo_dato_escribir], INT);
		contador_tipo_dato_escribir++;
		contador_variables++;
	}
	| FLOTANTE {
		strcpy(vector_tipo_de_dato[contador_tipo_dato_escribir],FLOAT);
		contador_tipo_dato_escribir++;
		contador_variables++;
	}
	;

listaVar: listaVar COMA ID {
		if(contador_variables > 0) {
			guardar_tabla_de_simbolos($3, vector_tipo_de_dato[contador_tipo_dato_leer], ES_ID);
			contador_tipo_dato_leer++;
			contador_variables--;
		}
	}
	| ID {
		if(contador_variables > 0) {
			guardar_tabla_de_simbolos($1, vector_tipo_de_dato[contador_tipo_dato_leer], ES_ID);
			contador_tipo_dato_leer++;
			contador_variables--;
		}
	}
	;

declaracionConstante: CONSTANTE ID OP_ASIG tipoCte {
		guardar_cte_tabla_de_simbolos($2, tipo_dato, valor_const);
		$$ = crear_nodo("=", obtener_tipo($2), crear_hoja($2, obtener_tipo($2)), $4);  	
		}
	; 

tipoCte: CONST_STRING {
		tipo_dato = CONSTSTRING;
		valor_const = $1; 
		$$ = crear_hoja($1, STRING);
		}
	| CONST_ENT {
		tipo_dato = CONSTINT;
		valor_const = $1;   
		$$ = crear_hoja($1, INT);
		}
	| CONST_REAL {
		tipo_dato = CONSTFLOAT;
		valor_const = $1; 
		$$ = crear_hoja($1, FLOAT);
		}
	;

asignacion: ID OP_ASIG expresion {
		verificar_existencia($1);
		$$ = crear_nodo("=", obtener_tipo($1), crear_hoja($1, obtener_tipo($1)), $3);} 
	;

seleccion:  IF condicion LLAVE_A cuerpoPrograma LLAVE_C ELSE LLAVE_A cuerpoPrograma LLAVE_C {
			$$ = crear_nodo("IF", NULL, $2, crear_nodo("CUERPO_IF", NULL, $4, $8));
			}
	| IF condicion LLAVE_A cuerpoPrograma LLAVE_C {$$ = crear_nodo("IF", NULL, $2, $4);}
	| IF condicion sentencia {$$ = crear_nodo("IF", NULL, $2, $3);} 
	;

iteracion: REPEAT condicion LLAVE_A cuerpoPrograma LLAVE_C {$$ = crear_nodo("REPEAT", NULL, $2, $4);}
   ;

condicion: comparacion
	| comparacion AND comparacion {$$ = crear_nodo("AND", NULL, $1, $3);}
	| comparacion OR comparacion {$$ = crear_nodo("OR", NULL, $1, $3);}
	| OP_NEG PAR_A comparacion PAR_C {$$ = crear_nodo("!", NULL, $3, NULL);} 
 	;

comparacion: expresion comparador expresion {$$ = crear_nodo($2, calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
	;

comparador: OP_COMP {$$ = "==";}
	| OP_MAYOR {$$ = ">";}
	| OP_MENOR {$$ = "<";}
	| OP_MAYIG {$$ = ">=";}
	| OP_MENIG {$$ = "<=";}
	| OP_DIST {$$ = "!=";}
	;

expresion: expresion OP_SUMA termino {$$ = crear_nodo("+", calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
	| expresion OP_RESTA termino {$$ = crear_nodo("-", calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
	| termino {$$ = $1;}
	;

termino: termino OP_MULT factor {$$ = crear_nodo("*", calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
	| termino OP_DIV factor {$$ = crear_nodo("/", calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
	| termino DIV_ENT factor {$$ = crear_nodo("DIV", calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
	| termino MODULO factor {$$ = crear_nodo("-", calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, crear_nodo("*", calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $3, crear_nodo("/", calcular_resultante(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3)));} //perdon
	| factor {$$ = $1;}
	;

factor: PAR_A expresion PAR_C {$$ = $2;}
	| ID  {$$ = crear_hoja($1, obtener_tipo($1));}		
	| CONST_ENT {guardar_tabla_de_simbolos($1,INT, !ES_ID); $$ = crear_hoja($1, INT);}
	| CONST_REAL {guardar_tabla_de_simbolos($1,FLOAT, !ES_ID); $$ = crear_hoja($1, FLOAT);}
	;				  

%%

/******SECCION CODIGO******/

/*
* Dado un id, retorna su tipo
*/
const char* obtener_tipo_arbol(arbol* id){
	if(id){ 
		return id->tipo;	
	}
}

const char* obtener_tipo(char* id){
	int i;
	for(i = 0; i < puntero_tabla_simbolos; i++){
		if(strcmp(id, tabla_simbolos_s[i].nombre) == 0){
			if(strcasecmp(tabla_simbolos_s[i].tipo, INT) == 0|| strcasecmp(tabla_simbolos_s[i].tipo, CONSTINT) == 0){
				return INT;
			}
			return (strcasecmp(tabla_simbolos_s[i].tipo, FLOAT) == 0 || strcasecmp(tabla_simbolos_s[i].tipo, CONSTFLOAT) == 0) ? FLOAT : STRING;
		}
	}
	printf("Error, id no hallado");
	exit(1);
}

/*
* Dado dos tipos de dato, retorna el resultante 
* int, int -> int, float, float -> float, int, float -> float
*/
const char* calcular_resultante(const char* a, const char* b){
	return strcmp(a, FLOAT) == 0 ? a : b;
}


arbol* crear_nodo(char* elemento, const char* tipo, arbol *izq, arbol *der) {
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

arbol* crear_hoja(char* elemento, const char* tipo) {
	return crear_nodo(elemento, tipo, NULL, NULL);
}

void recorrer_arbol_inorden(FILE * pfi, arbol* ast) {
	if (!ast)
		return;
		
	recorrer_arbol_inorden(pfi, ast->izq);
	fprintf(pfi, "%s\t", ast->nodo);
	recorrer_arbol_inorden(pfi, ast->der);
}

// Funcion para printear el arbol en 2d inorden. NO TOCAR. 
void print2DUtil(struct arbol *raiz, int espacio) 
{ 
    // Caso base
    if (raiz == NULL) 
        return; 
  
    // Incrementa la distancia entre niveles
    espacio += 10; 
  
    // Procede al hijo derecho 
    print2DUtil(raiz->der, espacio); 
  
    // Printea el nodo actual dsp del espacio
    printf("\n"); 
	int i;
    for (i = 10; i < espacio; i++) 
        printf(" "); 
    printf("%s %s\n", raiz->nodo, raiz->tipo); 
  
    // Procede al hijo izquierdo
    print2DUtil(raiz->izq, espacio); 
} 

void print2D(struct arbol *raiz) 
{ 
   // Pasa el espacio como 0
   print2DUtil(raiz, 0); 
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
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].nombre, strcat(guion, nombre));
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].valor, nombre);
	}
	
	if(strcmp(tipo, STRING) == 0 && !es_id){ //si es un string y no es un id (algo como "hello hello hello"), guardo su longitud en la tabla.
		itoa(strlen(nombre) - 2, cad, 10);
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].longitud, cad); 
	}
	puntero_tabla_simbolos++; //incremento la variable global del puntero para señalizar que agregué un elemento a la lista
}

void guardar_cte_tabla_de_simbolos(char* nombre, char* tipo, char* valor_const){
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
	strcpy(tabla_simbolos_s[puntero_tabla_simbolos].tipo, tipo); //agrego los datos. 
	strcpy(tabla_simbolos_s[puntero_tabla_simbolos].valor, valor_const);	
	if(strcmp(tipo, CONSTSTRING) == 0){ //si es un const string
		itoa(strlen(nombre),cad,10);
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].longitud, cad); 
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
	pf = fopen("ts.txt", "w"); 

	if (!pf)
	{
		printf("Error al crear el archivo de tabla de simbolos\n");
		exit(1);
	}

	fprintf(pf, "Nombre\t\t\tTipo\t\t\tValor\t\t\tLongitud\n");
	for (i = 0; i < puntero_tabla_simbolos; i++)
		fprintf(pf,"%s\t\t\t%s\t\t\t%s\t\t\t%s\n", tabla_simbolos_s[i].nombre, tabla_simbolos_s[i].tipo, tabla_simbolos_s[i].valor, tabla_simbolos_s[i].longitud);	
	
	fclose(pf); 
}

/***MAIN***/
int main(int argc,char *argv[]){
	
	if ((yyin = fopen(argv[1], "rt")) == NULL){
		printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
	}else{
		yyparse();
	}

	FILE * pfi;
	pfi = fopen("intermedia.txt","w"); 
	if (!pfi){
		printf("Error al crear el archivo de tabla de simbolos\n");
		exit(1);
	}
	print2D(a); 
	recorrer_arbol_inorden(pfi,a);

  	fclose(yyin);
  	return 0;
}

int yyerror(void){
	printf("Syntax Error\n");
	system("Pause");
	exit (1);
}