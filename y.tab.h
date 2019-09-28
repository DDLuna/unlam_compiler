
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 86 "Sintactico.y"

char* id;
char* num;
char* real; 
char* string;



/* Line 1676 of yacc.c  */
#line 149 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


