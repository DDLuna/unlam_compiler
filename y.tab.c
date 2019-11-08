
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "Sintactico.y"

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



/* Line 189 of yacc.c  */
#line 198 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OP_SUMA = 258,
     OP_RESTA = 259,
     OP_MULT = 260,
     OP_DIV = 261,
     OP_ASIG = 262,
     OP_COMP = 263,
     OP_MAYOR = 264,
     OP_MENOR = 265,
     OP_MAYIG = 266,
     OP_MENIG = 267,
     OP_DIST = 268,
     OP_NEG = 269,
     INI_COM = 270,
     FIN_COM = 271,
     IF = 272,
     ELSE = 273,
     REPEAT = 274,
     PRINT = 275,
     READ = 276,
     DEC_VAR = 277,
     FIN_DECVAR = 278,
     ENTERO = 279,
     FLOTANTE = 280,
     AND = 281,
     OR = 282,
     CONSTANTE = 283,
     MODULO = 284,
     DIV_ENT = 285,
     PAR_A = 286,
     PAR_C = 287,
     COR_A = 288,
     COR_C = 289,
     LLAVE_A = 290,
     LLAVE_C = 291,
     PYC = 292,
     COMA = 293,
     PUNTO = 294,
     DOS_PUNTOS = 295,
     ID = 296,
     CONST_ENT = 297,
     CONST_REAL = 298,
     CONST_STRING = 299
   };
#endif
/* Tokens.  */
#define OP_SUMA 258
#define OP_RESTA 259
#define OP_MULT 260
#define OP_DIV 261
#define OP_ASIG 262
#define OP_COMP 263
#define OP_MAYOR 264
#define OP_MENOR 265
#define OP_MAYIG 266
#define OP_MENIG 267
#define OP_DIST 268
#define OP_NEG 269
#define INI_COM 270
#define FIN_COM 271
#define IF 272
#define ELSE 273
#define REPEAT 274
#define PRINT 275
#define READ 276
#define DEC_VAR 277
#define FIN_DECVAR 278
#define ENTERO 279
#define FLOTANTE 280
#define AND 281
#define OR 282
#define CONSTANTE 283
#define MODULO 284
#define DIV_ENT 285
#define PAR_A 286
#define PAR_C 287
#define COR_A 288
#define COR_C 289
#define LLAVE_A 290
#define LLAVE_C 291
#define PYC 292
#define COMA 293
#define PUNTO 294
#define DOS_PUNTOS 295
#define ID 296
#define CONST_ENT 297
#define CONST_REAL 298
#define CONST_STRING 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 127 "Sintactico.y"

char* id;
char* num;
char* real; 
char* string;
struct arbol *ast;
char* op_log;



/* Line 214 of yacc.c  */
#line 333 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 345 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  106

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    16,    19,    21,
      23,    25,    27,    30,    33,    36,    38,    47,    55,    59,
      61,    63,    65,    69,    71,    76,    78,    80,    82,    86,
      96,   102,   106,   112,   114,   118,   122,   127,   131,   133,
     135,   137,   139,   141,   143,   147,   151,   153,   157,   161,
     165,   169,   171,   175,   177,   179
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    49,    -1,    49,    -1,
      48,    -1,    22,    51,    23,    -1,    49,    50,    -1,    50,
      -1,    57,    -1,    59,    -1,    58,    -1,    20,    44,    -1,
      20,    41,    -1,    21,    41,    -1,    55,    -1,    51,    33,
      52,    34,    40,    33,    54,    34,    -1,    33,    52,    34,
      40,    33,    54,    34,    -1,    52,    38,    53,    -1,    53,
      -1,    24,    -1,    25,    -1,    54,    38,    41,    -1,    41,
      -1,    28,    41,     7,    56,    -1,    44,    -1,    42,    -1,
      43,    -1,    41,     7,    63,    -1,    17,    60,    35,    49,
      36,    18,    35,    49,    36,    -1,    17,    60,    35,    49,
      36,    -1,    17,    60,    50,    -1,    19,    60,    35,    49,
      36,    -1,    61,    -1,    61,    26,    61,    -1,    61,    27,
      61,    -1,    14,    31,    61,    32,    -1,    63,    62,    63,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    63,     3,    64,    -1,    63,     4,    64,
      -1,    64,    -1,    64,     5,    65,    -1,    64,     6,    65,
      -1,    64,    30,    65,    -1,    64,    29,    65,    -1,    65,
      -1,    31,    63,    32,    -1,    41,    -1,    42,    -1,    43,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   201,   201,   204,   205,   206,   209,   212,   213,   216,
     217,   218,   219,   223,   224,   225,   229,   230,   233,   234,
     237,   242,   249,   256,   265,   271,   276,   281,   288,   294,
     297,   298,   301,   304,   305,   306,   307,   310,   313,   314,
     315,   316,   317,   318,   321,   322,   323,   326,   327,   328,
     329,   330,   333,   334,   335,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OP_SUMA", "OP_RESTA", "OP_MULT",
  "OP_DIV", "OP_ASIG", "OP_COMP", "OP_MAYOR", "OP_MENOR", "OP_MAYIG",
  "OP_MENIG", "OP_DIST", "OP_NEG", "INI_COM", "FIN_COM", "IF", "ELSE",
  "REPEAT", "PRINT", "READ", "DEC_VAR", "FIN_DECVAR", "ENTERO", "FLOTANTE",
  "AND", "OR", "CONSTANTE", "MODULO", "DIV_ENT", "PAR_A", "PAR_C", "COR_A",
  "COR_C", "LLAVE_A", "LLAVE_C", "PYC", "COMA", "PUNTO", "DOS_PUNTOS",
  "ID", "CONST_ENT", "CONST_REAL", "CONST_STRING", "$accept",
  "programaStart", "programa", "inicioVariables", "cuerpoPrograma",
  "sentencia", "declaracion", "listaTipos", "tipo", "listaVar",
  "declaracionConstante", "tipoCte", "asignacion", "seleccion",
  "iteracion", "condicion", "comparacion", "comparador", "expresion",
  "termino", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    56,    56,    56,    57,    58,
      58,    58,    59,    60,    60,    60,    60,    61,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    65,    65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     2,     1,     1,
       1,     1,     2,     2,     2,     1,     8,     7,     3,     1,
       1,     1,     3,     1,     4,     1,     1,     1,     3,     9,
       5,     3,     5,     1,     3,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       5,     4,     8,    15,     9,    11,    10,     0,     0,    53,
      54,    55,     0,    33,     0,    46,    51,     0,    13,    12,
      14,     0,     0,     0,     0,     1,     3,     7,     0,     0,
       0,    31,     0,     0,     0,     0,    38,    39,    40,    41,
      42,    43,     0,     0,     0,     0,     0,     0,    20,    21,
       0,    19,     6,     0,     0,    28,     0,    52,     0,    34,
      35,    44,    45,    37,    47,    48,    50,    49,     0,     0,
       0,     0,    26,    27,    25,    24,    36,    30,    32,     0,
      18,     0,     0,     0,     0,     0,    23,     0,     0,     0,
      17,     0,     0,    29,    22,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,    32,    60,    61,    97,
      13,    85,    14,    15,    16,    22,    23,    52,    24,    25,
      26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -30
static const yytype_int8 yypact[] =
{
     -12,    -8,    -8,     5,   -29,    -7,    -2,    40,    30,   -30,
      79,    79,   -30,   -30,   -30,   -30,   -30,    35,    34,   -30,
     -30,   -30,    23,    -5,   100,     8,   -30,    60,   -30,   -30,
     -30,    38,    -6,    66,    34,   -30,    79,   -30,    34,     0,
      79,   -30,    34,    34,    34,    34,   -30,   -30,   -30,   -30,
     -30,   -30,    34,    34,    34,    34,    34,    79,   -30,   -30,
     -10,   -30,   -30,    38,    41,    87,    69,   -30,    33,   -30,
     -30,     8,     8,    87,   -30,   -30,   -30,   -30,    51,    65,
      38,     7,   -30,   -30,   -30,   -30,   -30,    88,   -30,    81,
     -30,    82,    84,    80,    90,    79,   -30,    21,    80,    61,
     -30,    83,    22,   -30,   -30,   -30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,   -30,    -9,   -11,   -30,    63,    45,    29,
     -30,   -30,   -30,   -30,   -30,   126,   -23,   -30,   -16,    49,
      62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      37,    36,    39,    44,    45,     1,    17,     2,     3,     4,
       5,    41,    30,    53,    54,    66,     6,    62,    65,    69,
      70,    42,    43,    18,    79,    37,    31,    63,    80,     7,
      35,    68,    67,    19,    20,    21,    73,    55,    56,    33,
       1,    91,     2,     3,     4,    80,    28,    34,    78,    29,
       1,     6,     2,     3,     4,   100,   105,    37,    40,   101,
     101,     6,    58,    59,     7,    18,    38,    37,     1,    87,
       2,     3,     4,    64,     7,    19,    20,    21,     1,     6,
       2,     3,     4,    82,    83,    84,    99,    88,    37,     6,
      44,    45,     7,    71,    72,    57,     1,   103,     2,     3,
       4,    86,     7,    44,    45,    89,    92,     6,    46,    47,
      48,    49,    50,    51,    93,    74,    75,    76,    77,    95,
       7,    96,    94,    98,   104,    90,    81,   102,    27
};

static const yytype_uint8 yycheck[] =
{
      11,    10,    18,     3,     4,    17,    14,    19,    20,    21,
      22,    22,    41,     5,     6,    38,    28,    23,    34,    42,
      43,    26,    27,    31,    34,    36,    33,    33,    38,    41,
       0,    40,    32,    41,    42,    43,    52,    29,    30,    41,
      17,    34,    19,    20,    21,    38,    41,     7,    57,    44,
      17,    28,    19,    20,    21,    34,    34,    68,    35,    38,
      38,    28,    24,    25,    41,    31,    31,    78,    17,    36,
      19,    20,    21,     7,    41,    41,    42,    43,    17,    28,
      19,    20,    21,    42,    43,    44,    95,    36,    99,    28,
       3,     4,    41,    44,    45,    35,    17,    36,    19,    20,
      21,    32,    41,     3,     4,    40,    18,    28,     8,     9,
      10,    11,    12,    13,    33,    53,    54,    55,    56,    35,
      41,    41,    40,    33,    41,    80,    63,    98,     2
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    19,    20,    21,    22,    28,    41,    46,    47,
      48,    49,    50,    55,    57,    58,    59,    14,    31,    41,
      42,    43,    60,    61,    63,    64,    65,    60,    41,    44,
      41,    33,    51,    41,     7,     0,    49,    50,    31,    63,
      35,    50,    26,    27,     3,     4,     8,     9,    10,    11,
      12,    13,    62,     5,     6,    29,    30,    35,    24,    25,
      52,    53,    23,    33,     7,    63,    61,    32,    49,    61,
      61,    64,    64,    63,    65,    65,    65,    65,    49,    34,
      38,    52,    42,    43,    44,    56,    32,    36,    36,    40,
      53,    34,    18,    33,    40,    35,    41,    54,    33,    49,
      34,    38,    54,    36,    41,    34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 201 "Sintactico.y"
    {mostrar_errores(); escribir_tabla_de_simbolos(); printf("Compilación exitosa\n"); (yyval.ast) = (yyvsp[(1) - (1)].ast); a = (yyval.ast);}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 204 "Sintactico.y"
    {(yyval.ast) = crear_nodo("PROG", NULL, NULL, (yyvsp[(2) - (2)].ast));}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 205 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 212 "Sintactico.y"
    {(yyval.ast) = crear_nodo("CUERPO_PROG", NULL, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast));}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 213 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 216 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 217 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 218 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 219 "Sintactico.y"
    {
	guardar_tabla_de_simbolos((yyvsp[(2) - (2)].string), STRING, !ES_ID); 
	(yyval.ast) = crear_nodo("PRINT", STRING, NULL, crear_hoja((yyvsp[(2) - (2)].string), NULL));
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 223 "Sintactico.y"
    {(yyval.ast) = crear_nodo("PRINT", obtener_tipo((yyvsp[(2) - (2)].id)), NULL, crear_hoja((yyvsp[(2) - (2)].id), NULL));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 224 "Sintactico.y"
    {(yyval.ast) = crear_nodo("READ", obtener_tipo((yyvsp[(2) - (2)].id)), NULL, crear_hoja((yyvsp[(2) - (2)].id), NULL));}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 237 "Sintactico.y"
    {
	strcpy(vector_tipo_de_dato[contador_tipo_dato_escribir], INT);
	contador_tipo_dato_escribir++;
	contador_variables++;
}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 242 "Sintactico.y"
    {
	strcpy(vector_tipo_de_dato[contador_tipo_dato_escribir],FLOAT);
	contador_tipo_dato_escribir++;
	contador_variables++;
}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 249 "Sintactico.y"
    {
	if (contador_variables > 0) {
		guardar_tabla_de_simbolos((yyvsp[(3) - (3)].id), vector_tipo_de_dato[contador_tipo_dato_leer], ES_ID);
		contador_tipo_dato_leer++;
		contador_variables--;
	}
}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 256 "Sintactico.y"
    {
	if (contador_variables > 0) {
		guardar_tabla_de_simbolos((yyvsp[(1) - (1)].id), vector_tipo_de_dato[contador_tipo_dato_leer], ES_ID);
		contador_tipo_dato_leer++;
		contador_variables--;
	}
}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 265 "Sintactico.y"
    {
	guardar_cte_tabla_de_simbolos((yyvsp[(2) - (4)].id), tipo_dato, valor_const);
	(yyval.ast) = crear_nodo("=", obtener_tipo((yyvsp[(2) - (4)].id)), crear_hoja((yyvsp[(2) - (4)].id), obtener_tipo((yyvsp[(2) - (4)].id))), (yyvsp[(4) - (4)].ast));  	
}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 271 "Sintactico.y"
    {
	tipo_dato = CONSTSTRING;
	valor_const = (yyvsp[(1) - (1)].string); 
	(yyval.ast) = crear_hoja((yyvsp[(1) - (1)].string), STRING);
}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 276 "Sintactico.y"
    {
	tipo_dato = CONSTINT;
	valor_const = (yyvsp[(1) - (1)].num);   
	(yyval.ast) = crear_hoja((yyvsp[(1) - (1)].num), INT);
}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 281 "Sintactico.y"
    {
	tipo_dato = CONSTFLOAT;
	valor_const = (yyvsp[(1) - (1)].real); 
	(yyval.ast) = crear_hoja((yyvsp[(1) - (1)].real), FLOAT);
}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 288 "Sintactico.y"
    {
	verificar_existencia((yyvsp[(1) - (3)].id));
	verificar_conflicto_tipos(obtener_tipo((yyvsp[(1) - (3)].id)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast)));
	(yyval.ast) = crear_nodo("=", obtener_tipo((yyvsp[(1) - (3)].id)), crear_hoja((yyvsp[(1) - (3)].id), obtener_tipo((yyvsp[(1) - (3)].id))), (yyvsp[(3) - (3)].ast));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 294 "Sintactico.y"
    {
	(yyval.ast) = crear_nodo("IF", NULL, (yyvsp[(2) - (9)].ast), crear_nodo("CUERPO_IF", NULL, (yyvsp[(4) - (9)].ast), (yyvsp[(8) - (9)].ast)));
}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 297 "Sintactico.y"
    {(yyval.ast) = crear_nodo("IF", NULL, (yyvsp[(2) - (5)].ast), (yyvsp[(4) - (5)].ast));}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 298 "Sintactico.y"
    {(yyval.ast) = crear_nodo("IF", NULL, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 301 "Sintactico.y"
    {(yyval.ast) = crear_nodo("REPEAT", NULL, (yyvsp[(2) - (5)].ast), (yyvsp[(4) - (5)].ast));}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 305 "Sintactico.y"
    {(yyval.ast) = crear_nodo("AND", NULL, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 306 "Sintactico.y"
    {(yyval.ast) = crear_nodo("OR", NULL, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 307 "Sintactico.y"
    {(yyval.ast) = crear_nodo("!", NULL, (yyvsp[(3) - (4)].ast), NULL);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 310 "Sintactico.y"
    {(yyval.ast) = crear_nodo((yyvsp[(2) - (3)].op_log), verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 313 "Sintactico.y"
    {(yyval.op_log) = "==";}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 314 "Sintactico.y"
    {(yyval.op_log) = ">";}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 315 "Sintactico.y"
    {(yyval.op_log) = "<";}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 316 "Sintactico.y"
    {(yyval.op_log) = ">=";}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 317 "Sintactico.y"
    {(yyval.op_log) = "<=";}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 318 "Sintactico.y"
    {(yyval.op_log) = "!=";}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 321 "Sintactico.y"
    {(yyval.ast) = crear_nodo("+", verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 322 "Sintactico.y"
    {(yyval.ast) = crear_nodo("-", verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 323 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 326 "Sintactico.y"
    {(yyval.ast) = crear_nodo("*", verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 327 "Sintactico.y"
    {(yyval.ast) = crear_nodo("/", verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 328 "Sintactico.y"
    {(yyval.ast) = crear_nodo("DIV", verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 329 "Sintactico.y"
    {(yyval.ast) = crear_nodo("-", verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(1) - (3)].ast), crear_nodo("*", verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(3) - (3)].ast), crear_nodo("/", verificar_conflicto_tipos(obtener_tipo_arbol((yyvsp[(1) - (3)].ast)), obtener_tipo_arbol((yyvsp[(3) - (3)].ast))), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast))));}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 330 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 333 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(2) - (3)].ast);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 334 "Sintactico.y"
    {(yyval.ast) = crear_hoja((yyvsp[(1) - (1)].id), obtener_tipo((yyvsp[(1) - (1)].id)));}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 335 "Sintactico.y"
    {guardar_tabla_de_simbolos((yyvsp[(1) - (1)].num), INT, !ES_ID); (yyval.ast) = crear_hoja(tabla_simbolos_s[puntero_tabla_simbolos-1].nombre, INT);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 336 "Sintactico.y"
    {guardar_tabla_de_simbolos((yyvsp[(1) - (1)].real),FLOAT, !ES_ID); (yyval.ast) = crear_hoja(tabla_simbolos_s[puntero_tabla_simbolos-1].nombre, FLOAT);}
    break;



/* Line 1455 of yacc.c  */
#line 2001 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 339 "Sintactico.y"


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
		fprintf(file,"\n\tJMP ETIQUETA_IF_%d:\n", ver_tope_sentencias(pila_if));
		fprintf(file, "ETIQUETA_ELSE_%d\n", sacar_pila_sentencias(pila_else));
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
            return "JL";
    }

    if (strcmp(op, ">") == 0) {
            return "JLE";
    }

    if (strcmp(op, "<=") == 0) {
            return "JG";
    }

    if (strcmp(op, "<") == 0) {
            return "JGE";
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
        fprintf(file,"\n\t; ASIGNACION \n");
        if (strcmp(a->der->nodo, "@SUMA") != 0 && strcmp(a->der->nodo, "@MENOS") != 0 && strcmp(a->der->nodo, "@MULTIPLAR") != 0 && strcmp(a->der->nodo, "@DIVIDIR") != 0) {
            struct tabla_simbolos* simbolo = buscar_en_ts(a->der->nodo);
            if(simbolo != NULL && strcmp(simbolo->longitud, "-") == 0)  {
                fprintf(file,"\tLEA SI, %s\n", a->der->nodo); 
                fprintf(file,"\tLEA DI,%s\n", a->izq->nodo);
                fprintf(file,"\tCALL COPY\n");
                return;
            }
        }    

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
        fprintf(file,"\tFCOM");
        meter_pila_operadores(">=");        
    }

	    if (strcmp(a->nodo, "<=") == 0) {
        fprintf(file,"\n\t; <= \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFCOM");
        meter_pila_operadores("<=");        
    }

	    if (strcmp(a->nodo, ">") == 0) {
        fprintf(file,"\n\t; > \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFCOM");
        meter_pila_operadores(">");
    }

	    if (strcmp(a->nodo, "<") == 0) {
        fprintf(file,"\n\t; < \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFCOM");
        meter_pila_operadores("<");        
    }

	    if (strcmp(a->nodo, "==") == 0) {
        fprintf(file,"\n\t; == \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFCOM");
        meter_pila_operadores("==");        
    }

	    if (strcmp(a->nodo, "!=") == 0) {
        fprintf(file,"\n\t; != \n");
        fprintf(file,"\tFLD %s\n", a->izq->nodo);
        fprintf(file,"\tFLD %s\n", a->der->nodo);
        fprintf(file,"\tFCOM");
        meter_pila_operadores("!=");        
    }

	    if (strcmp(a->nodo, "IF") == 0) {
        fprintf(file,"ETIQUETA_IF_%d:\n", sacar_pila_sentencias(pila_if));
        contador_etiquetas_if++;
        limpiar_pila();	
    }

	    if (strcmp(a->nodo, "PRINT") == 0) {
        fprintf(file,"\n\t; DISPLAY\n");
        fprintf(file,"\tdisplayString _%s\n", a->der->nodo); //acá puede haber error xq trato todo como string
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


