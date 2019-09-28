
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
struct struct_tablaSimbolos{
	char nombre[100];
	char tipo[15];
	char valor[100];
	char longitud[10];
};

/***** FUNCIONES ****/
void guardar_TS();
void verificarExistencia();
void escribirTS();
void guardarCte_TS();

/********VARIABLES*********/
struct struct_tablaSimbolos tablaSimbolos[1000];
int punteroTablaSimbolos = 0;
char* tipo_dato;
char vectorTipoDato[1000][10];
int contadorTipoDatoEscribir = 0;
int contadorTipoDatoLeer = 0;
char valorConst[31];

int contador_variables = 0;



/* Line 189 of yacc.c  */
#line 112 "y.tab.c"

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
#line 86 "Sintactico.y"

char* id;
char* num;
char* real; 
char* string;



/* Line 214 of yacc.c  */
#line 245 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 257 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

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
       0,     0,     3,     4,     7,     8,    12,    13,    16,    18,
      19,    24,    25,    29,    30,    33,    35,    36,    39,    40,
      43,    46,    49,    52,    54,    55,    56,    67,    68,    69,
      79,    83,    85,    87,    89,    93,    95,    96,   102,   104,
     106,   108,   109,   110,   116,   117,   128,   134,   135,   140,
     146,   148,   149,   154,   155,   160,   164,   165,   173,   175,
     177,   179,   181,   183,   185,   186,   191,   192,   197,   199,
     200,   205,   206,   211,   212,   217,   218,   223,   225,   226,
     231,   233,   235
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    -1,    47,    48,    -1,    -1,    51,    49,
      53,    -1,    -1,    50,    53,    -1,    51,    -1,    -1,    52,
      22,    59,    23,    -1,    -1,    53,    54,    56,    -1,    -1,
      55,    56,    -1,    70,    -1,    -1,    57,    76,    -1,    -1,
      58,    73,    -1,    20,    44,    -1,    20,    41,    -1,    21,
      41,    -1,    67,    -1,    -1,    -1,    59,    33,    60,    64,
      34,    40,    33,    61,    66,    34,    -1,    -1,    -1,    33,
      62,    64,    34,    40,    33,    63,    66,    34,    -1,    64,
      38,    65,    -1,    65,    -1,    24,    -1,    25,    -1,    66,
      38,    41,    -1,    41,    -1,    -1,    28,    41,     7,    68,
      69,    -1,    44,    -1,    42,    -1,    43,    -1,    -1,    -1,
      41,    71,     7,    72,    83,    -1,    -1,    17,    77,    35,
      53,    36,    74,    18,    35,    53,    36,    -1,    17,    77,
      35,    53,    36,    -1,    -1,    17,    77,    75,    56,    -1,
      19,    77,    35,    53,    36,    -1,    80,    -1,    -1,    80,
      78,    26,    80,    -1,    -1,    80,    79,    27,    80,    -1,
      83,    82,    83,    -1,    -1,    14,    81,    31,    83,    82,
      83,    32,    -1,     8,    -1,     9,    -1,    10,    -1,    11,
      -1,    12,    -1,    13,    -1,    -1,    83,    84,     3,    86,
      -1,    -1,    83,    85,     4,    86,    -1,    86,    -1,    -1,
      86,    87,     5,    91,    -1,    -1,    86,    88,     6,    91,
      -1,    -1,    86,    89,    30,    91,    -1,    -1,    86,    90,
      29,    91,    -1,    91,    -1,    -1,    92,    31,    83,    32,
      -1,    41,    -1,    42,    -1,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    96,    99,    99,   100,   100,   101,   104,
     104,   107,   107,   108,   108,   111,   112,   112,   113,   113,
     114,   115,   116,   117,   121,   121,   121,   122,   122,   122,
     125,   126,   129,   130,   133,   134,   137,   137,   140,   141,
     142,   145,   146,   145,   149,   149,   150,   151,   151,   154,
     157,   158,   158,   159,   159,   162,   163,   163,   166,   167,
     168,   169,   170,   171,   174,   174,   175,   175,   176,   179,
     179,   180,   180,   181,   181,   182,   182,   183,   186,   186,
     187,   188,   189
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
  "programaStart", "$@1", "programa", "$@2", "$@3", "inicioVariables",
  "$@4", "cuerpoPrograma", "$@5", "$@6", "sentencia", "$@7", "$@8",
  "declaracion", "$@9", "$@10", "$@11", "$@12", "listaTipos", "tipo",
  "listaVar", "declaracionConstante", "$@13", "tipoCte", "asignacion",
  "$@14", "$@15", "seleccion", "$@16", "$@17", "iteracion", "condicion",
  "$@18", "$@19", "comparacion", "$@20", "comparador", "expresion", "$@21",
  "$@22", "termino", "$@23", "$@24", "$@25", "$@26", "factor", "$@27", 0
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
       0,    45,    47,    46,    49,    48,    50,    48,    48,    52,
      51,    54,    53,    55,    53,    56,    57,    56,    58,    56,
      56,    56,    56,    56,    60,    61,    59,    62,    63,    59,
      64,    64,    65,    65,    66,    66,    68,    67,    69,    69,
      69,    71,    72,    70,    74,    73,    73,    75,    73,    76,
      77,    78,    77,    79,    77,    80,    81,    80,    82,    82,
      82,    82,    82,    82,    84,    83,    85,    83,    83,    87,
      86,    88,    86,    89,    86,    90,    86,    86,    92,    91,
      91,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     3,     0,     2,     1,     0,
       4,     0,     3,     0,     2,     1,     0,     2,     0,     2,
       2,     2,     2,     1,     0,     0,    10,     0,     0,     9,
       3,     1,     1,     1,     3,     1,     0,     5,     1,     1,
       1,     0,     0,     5,     0,    10,     5,     0,     4,     5,
       1,     0,     4,     0,     4,     3,     0,     7,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     1,     0,     4,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     3,    13,     4,     0,    11,    16,
      13,     0,    16,     0,     0,     0,    41,    14,     0,     0,
      23,    15,    11,    27,     0,    12,    21,    20,    22,     0,
       0,    78,    17,    78,    19,     0,    10,    24,    36,    42,
      56,    80,    81,    82,     0,    50,    64,    68,    77,     0,
      47,    32,    33,     0,    31,     0,     0,    78,     0,    13,
       0,     0,    58,    59,    60,    61,    62,    63,    78,     0,
       0,     0,     0,     0,     0,    78,    13,    16,     0,     0,
       0,    39,    40,    38,    37,    43,    78,    11,    78,    78,
      55,    78,    78,    78,    78,    78,    78,    64,    11,    48,
       0,    30,     0,    64,    49,    52,    54,    65,    67,    70,
      72,    74,    76,    79,    46,    28,     0,    78,     0,     0,
      25,    64,     0,    35,     0,     0,    57,    13,    29,     0,
       0,    11,    34,    26,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     4,    10,     5,     6,     7,     8,    12,
       9,    17,    18,    19,    24,    55,   125,    35,   119,    53,
      54,   124,    20,    56,    84,    21,    30,    57,    34,   118,
      77,    32,    44,    60,    61,    45,    58,    68,    46,    69,
      70,    47,    71,    72,    73,    74,    48,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int8 yypact[] =
{
     -57,     2,    43,   -57,   -57,   -57,    26,    45,    31,     1,
     -57,    38,     1,   -16,    32,    33,   -57,   -57,    53,    58,
     -57,   -57,    76,   -57,   -18,   -57,   -57,   -57,   -57,    70,
      71,    -8,   -57,    -8,   -57,   -15,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,    44,    14,    35,     8,   -57,    49,
      46,   -57,   -57,   -27,   -57,   -15,     9,    21,    51,   -57,
      57,    59,   -57,   -57,   -57,   -57,   -57,   -57,    21,    81,
      83,    80,    82,    60,    62,    21,   -57,     1,    52,   -15,
     -14,   -57,   -57,   -57,   -57,    13,    21,    61,    -8,    -8,
      13,    21,    21,    21,    21,    21,    21,     0,    63,   -57,
      56,   -57,    54,    35,   -57,   -57,   -57,     8,     8,   -57,
     -57,   -57,   -57,   -57,    75,   -57,    65,    21,    77,    55,
     -57,     4,    66,   -57,   -11,    55,   -57,   -57,   -57,    64,
      16,    67,   -57,   -57,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -10,   -57,
     -57,    -9,   -57,   -57,   -57,   -57,   -57,   -57,   -57,    47,
      25,   -25,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,    73,   -57,   -57,   -29,   -57,     5,   -56,   -57,
     -57,   -22,   -57,   -57,   -57,   -57,   -38,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -76
static const yytype_int16 yytable[] =
{
      22,    85,     3,    25,   -66,    36,    40,    78,   -66,    51,
      52,    79,    90,   -69,   -71,    37,   -64,   -66,   -18,    97,
     102,    13,    14,   128,    79,    26,    -8,   129,    27,    15,
     103,    -7,   113,    41,    42,    43,   126,   -75,   -73,   -66,
     -51,   -53,    16,    62,    63,    64,    65,    66,    67,    87,
     133,    81,    82,    83,   129,   109,   110,   111,   112,   105,
     106,   121,    41,    42,    43,    -9,    98,    11,    99,   107,
     108,    23,    31,    28,    29,    33,    -5,    38,    39,    59,
      75,    76,    86,    88,    91,    93,    89,    92,    94,   115,
      95,    96,   100,   -44,   116,   122,   123,   104,   120,   114,
     130,   127,    80,   134,   101,   132,    50,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,   131
};

static const yytype_int8 yycheck[] =
{
      10,    57,     0,    12,     4,    23,    14,    34,     4,    24,
      25,    38,    68,     5,     6,    33,     3,     4,    17,    75,
      34,    20,    21,    34,    38,    41,     0,    38,    44,    28,
      86,     0,    32,    41,    42,    43,    32,    29,    30,     4,
      26,    27,    41,     8,     9,    10,    11,    12,    13,    59,
      34,    42,    43,    44,    38,    93,    94,    95,    96,    88,
      89,   117,    41,    42,    43,    22,    76,    22,    77,    91,
      92,    33,    19,    41,    41,    17,     0,     7,     7,    35,
      31,    35,    31,    26,     3,     5,    27,     4,     6,    33,
      30,    29,    40,    18,    40,    18,    41,    36,    33,    36,
     125,    35,    55,    36,    79,    41,    33,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,    48,    50,    51,    52,    53,    55,
      49,    22,    54,    20,    21,    28,    41,    56,    57,    58,
      67,    70,    53,    33,    59,    56,    41,    44,    41,    41,
      71,    19,    76,    17,    73,    62,    23,    33,     7,     7,
      14,    41,    42,    43,    77,    80,    83,    86,    91,    92,
      77,    24,    25,    64,    65,    60,    68,    72,    81,    35,
      78,    79,     8,     9,    10,    11,    12,    13,    82,    84,
      85,    87,    88,    89,    90,    31,    35,    75,    34,    38,
      64,    42,    43,    44,    69,    83,    31,    53,    26,    27,
      83,     3,     4,     5,     6,    30,    29,    83,    53,    56,
      40,    65,    34,    83,    36,    80,    80,    86,    86,    91,
      91,    91,    91,    32,    36,    33,    40,    82,    74,    63,
      33,    83,    18,    41,    66,    61,    32,    35,    34,    38,
      66,    53,    41,    34,    36
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
#line 96 "Sintactico.y"
    {printf("\nInicio compilacion\n-----------------------------------\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 96 "Sintactico.y"
    {escribirTS(); printf ("\n-----------------------------------\nCompilacion OK\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 99 "Sintactico.y"
    {printf("\n\nSeccion cuerpo programa\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 99 "Sintactico.y"
    {printf("\n\nFin cuerpo programa");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 100 "Sintactico.y"
    {printf("\n\nSeccion cuerpo programa\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 100 "Sintactico.y"
    {printf("\n\nFin cuerpo programa");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 104 "Sintactico.y"
    {printf("Seccion declaracion de variables\n\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 104 "Sintactico.y"
    {printf ("\n\nFin declaracion de variables\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 107 "Sintactico.y"
    {printf ("\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 108 "Sintactico.y"
    {printf ("\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 112 "Sintactico.y"
    {printf ("\n\tRepeat mientras ");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 113 "Sintactico.y"
    {printf ("\n\t If ");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 114 "Sintactico.y"
    {guardar_TS((yyvsp[(2) - (2)].string), "string", !ES_ID); printf ("\t\tPrint %s",(yyvsp[(2) - (2)].string));}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 115 "Sintactico.y"
    {printf ("\t\tPrint %s",(yyvsp[(2) - (2)].id));}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 116 "Sintactico.y"
    {printf ("\t\tRead %s",(yyvsp[(2) - (2)].id));}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 121 "Sintactico.y"
    {printf ("\ttipos: ");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 121 "Sintactico.y"
    {printf ("\n\tvariables: ");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 122 "Sintactico.y"
    {printf ("\ttipos: ");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 122 "Sintactico.y"
    {printf ("\n\tvariables: ");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 129 "Sintactico.y"
    {strcpy(vectorTipoDato[contadorTipoDatoEscribir],"int"); contadorTipoDatoEscribir++; contador_variables++; printf ("Entero "); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 130 "Sintactico.y"
    {strcpy(vectorTipoDato[contadorTipoDatoEscribir],"float"); contadorTipoDatoEscribir++; contador_variables++; printf ("Flotante ");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 133 "Sintactico.y"
    {if(contador_variables > 0){guardar_TS((yyvsp[(3) - (3)].id),vectorTipoDato[contadorTipoDatoLeer], ES_ID); contadorTipoDatoLeer++; contador_variables--;} printf ("%s ",(yyvsp[(3) - (3)].id));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 134 "Sintactico.y"
    {if(contador_variables > 0){guardar_TS((yyvsp[(1) - (1)].id),vectorTipoDato[contadorTipoDatoLeer], ES_ID); contadorTipoDatoLeer++; contador_variables--;} printf ("%s ",(yyvsp[(1) - (1)].id));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 137 "Sintactico.y"
    {printf ("\tDeclaraste una constante de tipo");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 137 "Sintactico.y"
    {guardarCte_TS((yyvsp[(2) - (5)].id),tipo_dato);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 140 "Sintactico.y"
    {tipo_dato = "constString"; strcpy(valorConst, (yyvsp[(1) - (1)].string)); printf ("String");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {tipo_dato = "constInt"; strcpy(valorConst, (yyvsp[(1) - (1)].num)); printf ("Entera");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 142 "Sintactico.y"
    {tipo_dato = "constFloat"; strcpy(valorConst, (yyvsp[(1) - (1)].real)); printf ("Flotante");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 145 "Sintactico.y"
    {verificarExistencia((yyvsp[(1) - (1)].id));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 146 "Sintactico.y"
    {printf ("\tAsignaste ");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 146 "Sintactico.y"
    {printf (" a '%s'",(yyvsp[(1) - (5)].id));}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 149 "Sintactico.y"
    {printf ("\n\tElse ");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 149 "Sintactico.y"
    {printf ("\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 150 "Sintactico.y"
    {printf ("\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 151 "Sintactico.y"
    {printf ("\n\t");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 151 "Sintactico.y"
    {printf ("\n");}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    {printf ("\n");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 158 "Sintactico.y"
    {printf ("And\n");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 159 "Sintactico.y"
    {printf ("Or\n");}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 163 "Sintactico.y"
    {printf ("Negado");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 166 "Sintactico.y"
    {printf (" Igual ");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 167 "Sintactico.y"
    {printf (" Mayor ");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 168 "Sintactico.y"
    {printf (" Menor ");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 169 "Sintactico.y"
    {printf (" Mayor O Igual ");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 170 "Sintactico.y"
    {printf (" Menor O Igual ");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 171 "Sintactico.y"
    {printf (" Distinto ");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 174 "Sintactico.y"
    {printf (" Suma ");}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 175 "Sintactico.y"
    {printf (" Resta ");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 179 "Sintactico.y"
    {printf (" Multiplicacion ");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {printf (" Division ");}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 181 "Sintactico.y"
    {printf (" Division Entera ");}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 182 "Sintactico.y"
    {printf (" Modulo ");}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 186 "Sintactico.y"
    {printf (" Parentesis abierto ");}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 186 "Sintactico.y"
    {printf (" Parentesis cerrado ");}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 187 "Sintactico.y"
    {printf ("'%s'",(yyvsp[(1) - (1)].id));}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 188 "Sintactico.y"
    {guardar_TS((yyvsp[(1) - (1)].num),"int", !ES_ID); printf ("'%s'",(yyvsp[(1) - (1)].num));}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 189 "Sintactico.y"
    {guardar_TS((yyvsp[(1) - (1)].real),"float", !ES_ID); printf ("'%s'",(yyvsp[(1) - (1)].real));}
    break;



/* Line 1455 of yacc.c  */
#line 1977 "y.tab.c"
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
#line 192 "Sintactico.y"


/******SECCION CODIGO******/


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


