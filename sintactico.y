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
struct tabla_simbolos {
	char nombre[100];
	char tipo[15];
	char valor[100];
	char longitud[10];
};

typedef struct arbol {
	char* nodo;
	const char* tipo;
	struct arbol *izq;
	struct arbol *der;
}arbol;

struct error{
	char* mensaje_error;
	int numero_de_linea;
};

struct pila_para_sentencias { 
    int tope; 
    int* sentencia; 
}; 

struct pila_para_operadores { 
    int tope; 
    char operador[5000][300]; 
}; 

struct pila_para_if_y_repeat {
	int tope;
	char tipo[5000][3000];
};

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
const char* verificar_conflicto_tipos(const char*, const char*);
const char* obtener_tipo_arbol(arbol* id);
const char* obtener_tipo(const char* id);
void mostrar_errores();
struct tabla_simbolos* buscar_en_ts(char* nombre);
void inicializar_assembler();
void insertar_la_tabla_de_simbolos();
void insertar_auxiliares();
void insertar_bloque_de_codigo_inicial();
void recorrer();
void finalizar_assembler();
void escribir_cte();
void insertar_rutinas();
void limpiar_pila();
char* obtener_operador();
int sacar_pila_sentencias();
void poner_pila_sentencias();
char* sacar_pila_operadores();
void meter_pila_operadores();
void procesar_nodo();
void generar_assembler(arbol* a);
char* obtener_operador_contrario(char* op);
void meter_pila_if_repeat();
char* sacar_pila_if_repeat();
int ver_tope_sentencias();
char* invertir_operador(char* operador);
char* remover_comillas();
char* reemplazar_punto_por_(char* a);

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
int cantidad_errores = 0;
struct error vector_errores[100];
FILE *file;
struct pila_para_sentencias* pila_if;
struct pila_para_sentencias* pila_repeat;
struct pila_para_sentencias* pila_else;
struct pila_para_operadores* pila_operadores;
struct pila_para_if_y_repeat* pila_if_repeat;
int contador_etiquetas_if;
int usar_misma_etiqueta_if = 0;
int hubo_or = 0;
int contador_etiquetas_repeat = 0;
int cantidad_if_anidados = -1;
int hubo_and = 0;
int usar_misma_etiqueta_repeat = 0;
int debo_invertir_operador = 0;
int contador_etiqueta_else = 0;
int contador_else = 0;


/********CONSTANTES*******/
const char* STRING = "string";
const char* INT = "int";
const char* FLOAT = "float";
const char* CONSTINT = "constInt";
const char* CONSTFLOAT = "constFloat";
const char* CONSTSTRING = "constString";

%}

%union {
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
programaStart: programa {mostrar_errores(); escribir_tabla_de_simbolos(); printf("Compilación exitosa\n"); $$ = $1; a = $$;}
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

sentencia: asignacion {$$ = $1;}
| iteracion {$$ = $1;}
| seleccion {$$ = $1;}
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
	if (contador_variables > 0) {
		guardar_tabla_de_simbolos($3, vector_tipo_de_dato[contador_tipo_dato_leer], ES_ID);
		contador_tipo_dato_leer++;
		contador_variables--;
	}
}
| ID {
	if (contador_variables > 0) {
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
	verificar_conflicto_tipos(obtener_tipo($1), obtener_tipo_arbol($3));
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

comparacion: expresion comparador expresion {$$ = crear_nodo($2, verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
;

comparador: OP_COMP {$$ = "==";}
| OP_MAYOR {$$ = ">";}
| OP_MENOR {$$ = "<";}
| OP_MAYIG {$$ = ">=";}
| OP_MENIG {$$ = "<=";}
| OP_DIST {$$ = "!=";}
;

expresion: expresion OP_SUMA termino {$$ = crear_nodo("+", verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
| expresion OP_RESTA termino {$$ = crear_nodo("-", verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
| termino {$$ = $1;}
;

termino: termino OP_MULT factor {$$ = crear_nodo("*", verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
| termino OP_DIV factor {$$ = crear_nodo("/", verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
| termino DIV_ENT factor {$$ = crear_nodo("DIV", verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3);}
| termino MODULO factor {$$ = crear_nodo("-", verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, crear_nodo("*", verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $3, crear_nodo("/", verificar_conflicto_tipos(obtener_tipo_arbol($1), obtener_tipo_arbol($3)), $1, $3)));} //perdon
| factor {$$ = $1;}
;

factor: PAR_A expresion PAR_C {$$ = $2;}
| ID  {$$ = crear_hoja($1, obtener_tipo($1));}		
| CONST_ENT {guardar_tabla_de_simbolos($1, INT, !ES_ID); $$ = crear_hoja(tabla_simbolos_s[puntero_tabla_simbolos-1].nombre, INT);}
| CONST_REAL {guardar_tabla_de_simbolos($1,FLOAT, !ES_ID); $$ = crear_hoja(tabla_simbolos_s[puntero_tabla_simbolos-1].nombre, FLOAT);}
;				  

%%

/******SECCION CODIGO******/

void mostrar_errores(){
	if (cantidad_errores == 0){
		return;
	}
	printf("Se han encontrado los siguientes errores: \n");
	int i;
	for (i = 0; i < cantidad_errores; i++){
		printf("Cerca de la linea: %d\tError: %s\n", vector_errores[i].numero_de_linea, vector_errores[i].mensaje_error);
	}
	exit(1);
}

void establecer_error(char* error){
	extern int numero_de_linea;
	if (cantidad_errores != 0 && vector_errores[cantidad_errores - 1].numero_de_linea == numero_de_linea){
		return;
	}
	vector_errores[cantidad_errores].mensaje_error = error;
	vector_errores[cantidad_errores].numero_de_linea = numero_de_linea;
	cantidad_errores++;
}

/*
* Dado un id, retorna su tipo
*/
const char* obtener_tipo_arbol(arbol* id) {
	if (id) { 
		return id->tipo;	
	}
}

const char* obtener_tipo(const char* id) {
	int i;
	for (i = 0; i < puntero_tabla_simbolos; i++) {
		if (strcmp(id, tabla_simbolos_s[i].nombre) == 0) {
			if (strcasecmp(tabla_simbolos_s[i].tipo, INT) == 0 || strcasecmp(tabla_simbolos_s[i].tipo, CONSTINT) == 0) {
				return INT;
			}
			return (strcasecmp(tabla_simbolos_s[i].tipo, FLOAT) == 0 || strcasecmp(tabla_simbolos_s[i].tipo, CONSTFLOAT) == 0) ? FLOAT : STRING;
		}
	}
	establecer_error("Id no hallado");
	return FLOAT; //retorno un generico para que no pinche y continue recolectando errores
}

/*
* Dado dos tipos de dato, determina si son compatibles (mismo tipo) 
*/
const char* verificar_conflicto_tipos(const char* a, const char* b) {
	if (strcmp(a, b) == 0){
		return a;
	} 	
	establecer_error("Conflicto de tipos");
	return FLOAT; //retorno un generico para que no pinche y continue recolectando errores
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
	if (!ast) {
		return;
	}
		
	recorrer_arbol_inorden(pfi, ast->izq);
	fprintf(pfi, "%s\t", ast->nodo);
	recorrer_arbol_inorden(pfi, ast->der);
}

// Funcion para printear el arbol en 2d inorden. NO TOCAR. 
void print2DUtil(struct arbol *raiz, int espacio) { 
    // Caso base
    if (raiz == NULL) {
        return;
	}
  
    // Incrementa la distancia entre niveles
    espacio += 10; 
  
    // Procede al hijo derecho 
    print2DUtil(raiz->der, espacio); 
  
    // Printea el nodo actual dsp del espacio
    printf("\n"); 
	int i;
    for (i = 10; i < espacio; i++) {
        printf(" "); 
	}
    printf("%s %s\n", raiz->nodo, raiz->tipo); 
  
    // Procede al hijo izquierdo
    print2DUtil(raiz->izq, espacio); 
} 

void print2D(struct arbol *raiz) { 
   // Pasa el espacio como 0
   print2DUtil(raiz, 0); 
} 

void guardar_tabla_de_simbolos(char* nombre, char* tipo, int es_id) {
	int i;
	char cad[10];
	char guion[30] = "_";
	for (i = 0; i < puntero_tabla_simbolos; i++) {
		if (strcmp(tabla_simbolos_s[i].nombre, nombre) == 0) { //verifico que el nombre del ID sea único
			establecer_error("ID con nombre repetido. Error de compilación");
			return;
			}
	}	



	if (es_id) {
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].nombre, nombre);
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].tipo, tipo); //agrego los datos. Un underscore en tipo represta una const.
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].valor,"-");
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].longitud,"-");
	} else {
		if (strcmp(tipo, STRING) == 0) { //si es un string y no es un id (algo como "hello hello hello"), guardo su longitud en la tabla.
			nombre = remover_comillas(nombre);
			itoa(strlen(nombre), cad, 10);
			strcpy(tabla_simbolos_s[puntero_tabla_simbolos].longitud, cad); 
		} else {
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].longitud, "-");
		}
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].nombre, strcat(guion, nombre));
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].valor, nombre);
		if(strcmp(tipo, FLOAT) == 0) {
			strcpy(tabla_simbolos_s[puntero_tabla_simbolos].nombre, reemplazar_punto_por_(tabla_simbolos_s[puntero_tabla_simbolos].nombre));
		}
	}
	
	puntero_tabla_simbolos++; //incremento la variable global del puntero para señalizar que agregué un elemento a la lista
}

void guardar_cte_tabla_de_simbolos(char* nombre, char* tipo, char* valor_const) {
	int i;
	char cad[30];
	char guion[30] = "_";
	for (i = 0; i < puntero_tabla_simbolos; i++) {
		if (strcmp(tabla_simbolos_s[i].nombre, nombre) == 0) { //verifico que el nombre del ID sea único
			establecer_error("ID con nombre repetido. Error de compilación");
			return;
		}
	}
	if (strcmp(tipo, CONSTSTRING) == 0) { //si es un const string
		valor_const = remover_comillas(valor_const);
		itoa(strlen(valor_const),cad,10);
		strcpy(tabla_simbolos_s[puntero_tabla_simbolos].longitud, cad); 
	}
	strcpy(tabla_simbolos_s[puntero_tabla_simbolos].nombre, nombre);
	strcpy(tabla_simbolos_s[puntero_tabla_simbolos].tipo, tipo); //agrego los datos. 
	strcpy(tabla_simbolos_s[puntero_tabla_simbolos].valor, valor_const);	
	puntero_tabla_simbolos++; //incremento la variable global del puntero para señalizar que agregué un elemento a la lista
}

char* reemplazar_punto_por_(char* a){
	char* aux = a;
	printf("%s\n", a);
	while(*a != '.' && *a != '\0'){
		a++;	
	}
	if(*a == '.'){
		*a = '_';
	}
	return aux;
}

char* remover_comillas(char* s){
	char* aux = s;
	while(*(s+1) != '"'){
		*s = *(s+1);
		s++;
	}
	*s = '\0';
	return aux;
}

struct tabla_simbolos* buscar_en_ts(char* nombre){
	int i;
	for(i = 0; i < puntero_tabla_simbolos; i++){
		if(strcmp(tabla_simbolos_s[i].nombre,nombre) == 0){
			return &tabla_simbolos_s[i];
		}
	}
	return NULL;
}

void verificar_existencia(char* id) {
	int i;
	for (i = 0; i < puntero_tabla_simbolos; i++) {
		if(strcmp(tabla_simbolos_s[i].nombre, id) == 0) //Si el id existe en mi tabla, salgo.
			return;
	}
	printf("ID no declarado. Error de compilación");
	exit(1);
}

void escribir_tabla_de_simbolos() {
	FILE *pf; 
	int i;
	pf = fopen("ts.txt", "w"); 

	if (!pf) {
		printf("Error al crear el archivo de tabla de simbolos\n");
		exit(1);
	}

	fprintf(pf, "Nombre\t\t\tTipo\t\t\tValor\t\t\tLongitud\n");
	for (i = 0; i < puntero_tabla_simbolos; i++) {
		fprintf(pf,"%s\t\t\t%s\t\t\t%s\t\t\t%s\n", tabla_simbolos_s[i].nombre, tabla_simbolos_s[i].tipo, tabla_simbolos_s[i].valor, tabla_simbolos_s[i].longitud);	
	}
	fclose(pf); 
}

/****SECCIÓN ASSEMBLER****/

void generar_assembler(arbol* a){
	file = fopen("final.asm", "w");
	if(!file){
		printf("Error al crear el archivo asembler\n");
		exit(1);
	}
	contador_etiquetas_if = 0;
    contador_etiquetas_repeat = 0;
    pila_if = (struct pila_para_sentencias*) malloc(sizeof(struct pila_para_sentencias)); 
    pila_if->sentencia = (int*) malloc(5000* sizeof(int));
	pila_if->tope = 0; 
	pila_else = (struct pila_para_sentencias*) malloc(sizeof(struct pila_para_sentencias));
	pila_else->sentencia = (int*) malloc(5000* sizeof(int));
	pila_else->tope = 0;
    pila_repeat = (struct pila_para_sentencias*) malloc(sizeof(struct pila_para_sentencias)); 
    pila_repeat->sentencia = (int*) malloc(5000* sizeof(int)); 
	pila_repeat->tope = 0;
    pila_operadores = (struct pila_para_operadores*) malloc(sizeof(struct pila_para_operadores));
	pila_operadores->tope = 0;
	pila_if_repeat = (struct pila_para_if_y_repeat*) malloc(sizeof(struct pila_para_if_y_repeat));
	pila_if_repeat->tope = 0; 
	inicializar_assembler();
	insertar_la_tabla_de_simbolos();
	insertar_auxiliares();
	insertar_bloque_de_codigo_inicial();
	recorrer(a);
	finalizar_assembler();
	fclose(file);
}

/*
* Inicializo el archivo assembler con los comandos requeridos
*/
void inicializar_assembler() {
	fprintf(file,"include macros2.asm \n");
	fprintf(file, "include number.asm \n\n\n");
    fprintf(file,".MODEL LARGE\n");
    fprintf(file,".386\n");
    fprintf(file,".STACK 200h\n\n");
    fprintf(file,"MAXTEXTSIZE equ 40\n\n");
    fprintf(file,".DATA\n");
}

/*
* Inserta los valores de la tabla de simbolos en el archivo asm. 
*/
void insertar_la_tabla_de_simbolos() {
	int i;
	for(i = 0; i < puntero_tabla_simbolos; i++) {

		if(strcmp(tabla_simbolos_s[i].tipo, INT) == 0 || strcmp(tabla_simbolos_s[i].tipo, FLOAT) == 0) {
			fprintf(file,"\t%s dd ?\n", tabla_simbolos_s[i].nombre);
		}

		if (strcmp(tabla_simbolos_s[i].tipo, CONSTSTRING) == 0) {	
           fprintf(file,"\t%s db \"%s\",'$', %s dup (?)\n", tabla_simbolos_s[i].nombre, tabla_simbolos_s[i].valor, tabla_simbolos_s[i].longitud);
        }

		 if (strcmp(tabla_simbolos_s[i].tipo, CONSTINT) == 0) {
            fprintf(file,"\t%s dd %s.0\n", tabla_simbolos_s[i].nombre, tabla_simbolos_s[i].valor);
        }

        if (strcmp(tabla_simbolos_s[i].tipo, "CONSTFLOAT") == 0) {
            fprintf(file,"\t%s dd %s\n", tabla_simbolos_s[i].nombre, tabla_simbolos_s[i].valor);
        }

		if(tabla_simbolos_s[i].nombre[0] == '_') {
			escribir_cte(tabla_simbolos_s[i]);
		}
	}
}

void escribir_cte(struct tabla_simbolos ts) {
	if(strcmp(ts.longitud,"-") != 0){
		fprintf(file,"\t%s db \"%s\",'$', %s dup (?)\n", ts.nombre, ts.valor, ts.longitud);
		return;
	}

	if(contiene_punto(ts.nombre)){
		fprintf(file,"\t%s dd %s\n", ts.nombre, ts.valor);
		return;
	}

	fprintf(file,"\t%s dd %s.0\n", ts.nombre, ts.valor);
	return;
}

int contiene_punto(const char* a){
	while(*a != '\0' && *a != '.'){
		a++;
	}	
	return (*a == '.') ? 1 : 0;

}

void insertar_bloque_de_codigo_inicial() {
	    fprintf(file,"\n\n");
    fprintf(file,".code\n");
	insertar_rutinas();
    fprintf(file,"\n\n");
}

void insertar_auxiliares(){
	fprintf(file,"\t@SUMA dd ?\n");
    fprintf(file,"\t@MENOS dd ?\n");
    fprintf(file,"\t@DIVIDIR dd ?\n");
    fprintf(file,"\t@MULTIPLAR dd ?\n");
    fprintf(file,"\t@AUXILIAR dd ?\n");
}

void insertar_rutinas(){
    fprintf(file, "\n\n\t; ROUTINES\n");
    fprintf(file, "STRLEN PROC\n");
    fprintf(file, "\tmov bx,0\n");
    fprintf(file, "STRL01:\n");
    fprintf(file, "\tcmp BYTE PTR [SI+BX],'$'\n");
    fprintf(file, "\tje STREND\n");
    fprintf(file, "\tinc BX\n");
    fprintf(file, "\tcmp BX, MAXTEXTSIZE\n");
    fprintf(file, "\tjl STRL01\n");
    fprintf(file, "STREND:\n");
    fprintf(file, "\tret\n");
    fprintf(file, "STRLEN ENDP\n\n");


    fprintf(file, "COPY PROC\n");
    fprintf(file, "\tcall STRLEN\n");
    fprintf(file, "\tcmp bx,MAXTEXTSIZE\n");
    fprintf(file, "\tjle COPYSIZEOK\n");
    fprintf(file, "\tmov bx,MAXTEXTSIZE\n");
    fprintf(file, "COPYSIZEOK:\n");
    fprintf(file, "\tmov cx,bx\n");
    fprintf(file, "\tcld\n");
    fprintf(file, "\trep movsb\n");
    fprintf(file, "\tmov al,'$'\n");
    fprintf(file, "\tmov BYTE PTR [DI],al\n");
    fprintf(file, "\tret\n");
    fprintf(file, "COPY ENDP\n\n");
	fprintf(file, "START:\n");

	fprintf(file,"\tmov AX,@DATA\n");
    fprintf(file,"\tmov DS,AX\n");
    fprintf(file,"\tmov ES,AX\n");
    fprintf(file,"\tfinit\n\n");
}

void finalizar_assembler(){
    fprintf(file,"\n\n\n\t; END PROGRAM \n\n");
    fprintf(file,"\tmov AX, 4C00h\n");
    fprintf(file,"\tint 21h\n");
   
    fprintf(file,"END START\n");
}

void recorrer(arbol* a) {
	if(!a){
		return;
	}

	    if (strcmp(a->nodo, "REPEAT") == 0) {
        fprintf(file,"\nETIQUETA_REPEAT_%d:\n", contador_etiquetas_repeat);
        poner_pila_sentencias(pila_repeat, contador_etiquetas_repeat);
        poner_pila_sentencias(pila_repeat, contador_etiquetas_repeat);
        contador_etiquetas_repeat++;
		meter_pila_if_repeat("REPEAT");
    }

	    if (strcmp(a->nodo, "IF") == 0) {
        contador_etiquetas_if++;
		meter_pila_if_repeat("IF");
		if(strcmp(a->der->nodo, "CUERPO_IF") == 0) {
				contador_else++;
		}
    }	

		if(strcmp(a->nodo, "!") == 0){
		debo_invertir_operador = 1;
	}
	
	recorrer(a->izq);
	    if (strcmp(a->nodo, "AND") == 0) {
				char* op = sacar_pila_operadores();
			if(strcmp(sacar_pila_if_repeat(),"IF") == 0){
				usar_misma_etiqueta_if = 1;
				if(contador_else == 0){
					fprintf(file, "\n\t%s ETIQUETA_IF_%d\n", obtener_operador(op),contador_etiquetas_if);
				} else {
					fprintf(file, "\n\t%s ETIQUETA_ELSE_%d\n", obtener_operador(op), contador_etiqueta_else);
					contador_else--;
				}
				poner_pila_sentencias(pila_if, contador_etiquetas_if);
		} else {
			usar_misma_etiqueta_repeat = 1;
			fprintf(file, "\n\t%s ETIQUETA_REPEAT_FUERA_%d\n", obtener_operador(op),ver_tope_sentencias(pila_repeat));
		}
		limpiar_pila();
		hubo_and = 1;
    }

	    if (strcmp(a->nodo, "OR") == 0) {
			char* op = sacar_pila_operadores();
			if(strcmp(sacar_pila_if_repeat(),"IF") == 0){
			usar_misma_etiqueta_if = 0;  
				if(contador_else == 0){
				fprintf(file, "\n\t%s ETIQUETA_IF_%d\n", obtener_operador_contrario(op), contador_etiquetas_if); //Si en el OR la primera me da verdadera, salto (por el operador posta, si tengo > salto por mayor) al then.
				poner_pila_sentencias(pila_if, contador_etiquetas_if);
				} else {
				fprintf(file, "\n\t%s ETIQUETA_IF_ADENTRO_%d\n", obtener_operador_contrario(op), contador_etiqueta_else);	
				poner_pila_sentencias(pila_else, contador_etiqueta_else);
				contador_else--;
				}
			} else {
				fprintf(file, "\n\t%s ETIQUETA_REPEAT_DENTRO_%d\n", obtener_operador_contrario(op), ver_tope_sentencias(pila_repeat));
			}
        limpiar_pila();
        hubo_or = 1;
    }
		
	    if (strcmp(a->nodo, "IF") == 0) {
			char* op = sacar_pila_operadores();
			if(strcmp(a->der->nodo, "CUERPO_IF") != 0){
				if (usar_misma_etiqueta_if != 1) {
					contador_etiquetas_if++;
				} else {
					usar_misma_etiqueta_if = 0;
				}
				fprintf(file, "\n\t%s ETIQUETA_IF_%d\n", obtener_operador(op),contador_etiquetas_if);

				if (hubo_or) {
					fprintf(file,"ETIQUETA_IF_%d:\n", sacar_pila_sentencias(pila_if));
					hubo_or = 0;
				}
			} else {
				fprintf(file, "\n\t%s ETIQUETA_ELSE_%d\n", obtener_operador(op),contador_etiqueta_else);
				if(hubo_or){
					fprintf(file, "ETIQUETA_IF_ADENTRO_%d\n", sacar_pila_sentencias(pila_else));
					hubo_or = 0;
				}
				poner_pila_sentencias(pila_else, contador_etiqueta_else);
				contador_etiqueta_else++;
			}
			if(!hubo_and) {
					poner_pila_sentencias(pila_if, contador_etiquetas_if);
				}
			hubo_and = 0;
    }

	if(strcmp(a->nodo, "CUERPO_IF") == 0){
		fprintf(file,"\n\tJMP ETIQUETA_IF_%d\n", ver_tope_sentencias(pila_if));
		fprintf(file, "ETIQUETA_ELSE_%d:\n", sacar_pila_sentencias(pila_else));
	}

   if (strcmp(a->nodo, "REPEAT") == 0) {
        char* op = sacar_pila_operadores();		
		int valor = sacar_pila_sentencias(pila_repeat);
        fprintf(file,"\n\t%s ETIQUETA_REPEAT_FUERA_%d\n", obtener_operador(op), valor);
		if(hubo_or) {
			fprintf(file, "ETIQUETA_REPEAT_DENTRO_%d:\n", valor);
			hubo_or = 0;
		}
    }

	recorrer(a->der);

	if (strcmp(a->nodo, "REPEAT") == 0) {
        int valor = sacar_pila_sentencias(pila_repeat);
        fprintf(file,"\n\t%JMP ETIQUETA_REPEAT_%d\n", valor);
        fprintf(file,"ETIQUETA_REPEAT_FUERA_%d:\n", valor);
    }
	//printf("%s ", a->nodo);
	procesar_nodo(a);
	//printf("Soy %s y termine de procesarme \n", a->nodo);

}

char* obtener_operador(char* op) {
	if (strcmp(op, ">=") == 0) {
            return "JB";
    }

    if (strcmp(op, ">") == 0) {
            return "JBE";
    }

    if (strcmp(op, "<=") == 0) {
            return "JA";
    }

    if (strcmp(op, "<") == 0) {
            return "JAE";
    }

    if (strcmp(op, "==") == 0) {
            return "JNE";
    }

    if (strcmp(op, "!=") == 0) {
            return "JE";
    }
}

char* obtener_operador_contrario(char* op) {
	if (strcmp(op, ">=") == 0) {
            return "JGE";
    }

    if (strcmp(op, ">") == 0) {
            return "JG";
    }

    if (strcmp(op, "<=") == 0) {
            return "JLE";
    }

    if (strcmp(op, "<") == 0) {
            return "JL";
    }

    if (strcmp(op, "==") == 0) {
            return "JE";
    }

    if (strcmp(op, "!=") == 0) {
            return "JNE";
    }
}

void limpiar_pila() {
     fprintf(file, "\n\t; STACK CLENUP\n"); 
     fprintf(file, "\tFFREE st(0)\n");
     fprintf(file, "\tFFREE st(1)\n");
     fprintf(file, "\tFFREE st(2)\n");
     fprintf(file, "\tFFREE st(3)\n");
     fprintf(file, "\tFFREE st(4)\n");
     fprintf(file, "\tFFREE st(5)\n");
     fprintf(file, "\tFFREE st(6)\n");
     fprintf(file, "\tFFREE st(7)\n");
     fprintf(file, "\n");
}

void procesar_nodo(arbol* a){
	if (strcmp(a->nodo, "=") == 0) {
        if (strcmp(a->der->nodo, "@SUMA") != 0 && strcmp(a->der->nodo, "@MENOS") != 0 && strcmp(a->der->nodo, "@MULTIPLAR") != 0 && strcmp(a->der->nodo, "@DIVIDIR") != 0) {
            struct tabla_simbolos* simbolo = buscar_en_ts(a->izq->nodo);
            if(simbolo != NULL && strcmp(simbolo->longitud, "-") != 0)  {
                return;
            }
        }    
        fprintf(file,"\n\t; ASIGNACION \n");
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFSTP %s\n", a->izq->nodo);
    } 

    if (strcmp(a->nodo, "+") == 0) {
        fprintf(file,"\n\t; SUMA \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFADD\n");
        a->nodo = "@SUM";
        fprintf(file,"\tFSTP %s\n", a->nodo);
        limpiar_pila();
    }

    if (strcmp(a->nodo, "-") == 0) {
        fprintf(file,"\n\t; RESTA \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFSUB\n");
        a->nodo = "@MENOS";
        fprintf(file,"\tFSTP %s\n", a->nodo);
        limpiar_pila();
    }

    if (strcmp(a->nodo, "*") == 0) {
        fprintf(file,"\n\t; MULTIPLICA \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFMUL\n");
        a->nodo = "@MULTIPLICAR";
        fprintf(file,"\tFSTP %s\n", a->nodo);
        limpiar_pila();
    }

    if (strcmp(a->nodo, "/") == 0) {
        fprintf(file,"\n\t; DIVIDE \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFDIV\n");
        a->nodo = "@DIVIDIR";
        fprintf(file,"\tFSTP %s\n", a->nodo);
        limpiar_pila();
    }

	if(debo_invertir_operador){
		char* aux = invertir_operador(a->nodo);
		if(aux){
			a->nodo = aux;
			debo_invertir_operador = 0;
		}
	}

	    if (strcmp(a->nodo, ">=") == 0) {
        fprintf(file,"\n\t; >= \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFXCH\n");
        fprintf(file,"\tFCOM\n");
        fprintf(file,"\tFSTSW AX\n");
        fprintf(file,"\tSAHF\n");
        meter_pila_operadores(">=");        
    }

	    if (strcmp(a->nodo, "<=") == 0) {
        fprintf(file,"\n\t; <= \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
		fprintf(file,"\tFXCH\n");
        fprintf(file,"\tFCOM\n");
        fprintf(file,"\tFSTSW AX\n");
        fprintf(file,"\tSAHF\n");
        meter_pila_operadores("<=");        
    }

	    if (strcmp(a->nodo, ">") == 0) {
        fprintf(file,"\n\t; > \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
		fprintf(file,"\tFXCH\n");
        fprintf(file,"\tFCOM\n");
        fprintf(file,"\tFSTSW AX\n");
        fprintf(file,"\tSAHF\n");
        meter_pila_operadores(">");
    }

	    if (strcmp(a->nodo, "<") == 0) {
        fprintf(file,"\n\t; < \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
		fprintf(file,"\tFXCH\n");
        fprintf(file,"\tFCOM\n");
        fprintf(file,"\tFSTSW AX\n");
        fprintf(file,"\tSAHF\n");
        meter_pila_operadores("<");        
    }

	    if (strcmp(a->nodo, "==") == 0) {
        fprintf(file,"\n\t; == \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
		fprintf(file,"\tFXCH\n");
        fprintf(file,"\tFCOM\n");
        fprintf(file,"\tFSTSW AX\n");
        fprintf(file,"\tSAHF\n");
        meter_pila_operadores("==");        
    }

	    if (strcmp(a->nodo, "!=") == 0) {
        fprintf(file,"\n\t; != \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
		fprintf(file,"\tFXCH\n");
        fprintf(file,"\tFCOM\n");
        fprintf(file,"\tFSTSW AX\n");
        fprintf(file,"\tSAHF\n");
        meter_pila_operadores("!=");        
    }

	    if (strcmp(a->nodo, "IF") == 0) {
        fprintf(file,"ETIQUETA_IF_%d:\n", sacar_pila_sentencias(pila_if));
        contador_etiquetas_if++;
        limpiar_pila();	
    }

	    if (strcmp(a->nodo, "PRINT") == 0) {
        fprintf(file,"\n\t; DISPLAY\n");
		printf("%s\n", a->tipo);
		if(strcmp(a->tipo, INT) == 0 || strcmp(a->tipo, CONSTINT) == 0){
			fprintf(file,"\tdisplayInteger %s,3\n \tnewLine 1\n", a->der->nodo);
			return;
		}
		if(strcmp(a->tipo, FLOAT) == 0 || strcmp(a->tipo, CONSTFLOAT) == 0){
			fprintf(file, "\tdisplayFloat %s,3\n \tnewLine 1\n", a->der->nodo);
			return;
		}
        fprintf(file,"\tdisplayString %s\n \t newLine 1\n", a->der->nodo); 
    }

	    if (strcmp(a->nodo, "READ") == 0) {
        fprintf(file,"\n\t; GET\n");
        fprintf(file, "\tgetString %s\n", a->der->nodo);
    }
}

char* invertir_operador(char* operador){
	if(strcmp(operador, ">") == 0){
		return "<=";
	}

	if(strcmp(operador, "<") == 0){
		return ">=";
	}

	if(strcmp(operador, "<=") == 0){
		return ">";
	}

	if(strcmp(operador, ">=") == 0){
		return "<";
	}

	if(strcmp(operador, "==") == 0){
		return "!=";
	}

	if(strcmp(operador, "!=") == 0){
		return "==";
	}

	return NULL;

}

int sacar_pila_sentencias(struct pila_para_sentencias* pila) { 
    
    return pila->sentencia[pila->tope--];
}


void poner_pila_sentencias(struct pila_para_sentencias* pila, int item) { 
    pila->tope++;
	pila->sentencia[pila->tope] = item; 

} 

char* sacar_pila_operadores() { 
    return pila_operadores->operador[pila_operadores->tope--]; 
}

void meter_pila_operadores(char* item) { 
	pila_operadores->tope++;
    strcpy(pila_operadores->operador[pila_operadores->tope],item); 
}

int ver_tope_sentencias(struct pila_para_sentencias* pila){
	return pila->sentencia[pila->tope];
}

void meter_pila_if_repeat(char* tipo){
	pila_if_repeat->tope++;
	strcpy(pila_if_repeat->tipo[pila_if_repeat->tope],tipo);
}

char* sacar_pila_if_repeat(){
	return pila_if_repeat->tipo[pila_if_repeat->tope--];
}

/***MAIN***/
int main(int argc, char *argv[]) {
	
	if ((yyin = fopen(argv[1], "rt")) == NULL) {
		printf("No se puede abrir el archivo: %s\n", argv[1]);
	} else {
		yyparse();
	}

	FILE * pfi;
	pfi = fopen("intermedia.txt","w"); 
	if (!pfi) {
		printf("Error al crear el archivo de tabla de simbolos\n");
		exit(1);
	}
	//print2D(a); 
	recorrer_arbol_inorden(pfi,a);
	generar_assembler(a);
	printf("Todo ok\n");

  	fclose(yyin);
  	return 0;
}

int yyerror(void) {
	printf("Syntax Error\n");
	system("Pause");
	exit (1);
}

