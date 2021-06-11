
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
     STRING = 258,
     INTEGER = 259,
     VARIDENTIFIER = 260,
     TRUEBOOL = 261,
     FALSEBOOL = 262,
     INT = 263,
     STR = 264,
     BOOL = 265,
     VOID = 266,
     SWITCH = 267,
     CASE = 268,
     DEFAULT = 269,
     CONST = 270,
     DO = 271,
     NIL = 272,
     OR = 273,
     AND = 274,
     NOT = 275,
     FUNCTION = 276,
     RETURN = 277,
     INC = 278,
     DEC = 279,
     INCASSIGNMENT = 280,
     DECASSIGNMENT = 281,
     MULTIPLYASSIGNMENT = 282,
     DIVIDEASSIGNMENT = 283,
     FUNCIDENTIFIER = 284,
     WHILE = 285,
     IF = 286,
     PRINT = 287,
     FOR = 288,
     CONTINUE = 289,
     BREAK = 290,
     VARFX = 291,
     IFX = 292,
     ELSE = 293,
     NE = 294,
     EQ = 295,
     LE = 296,
     GE = 297,
     UMINUS = 298
   };
#endif
/* Tokens.  */
#define STRING 258
#define INTEGER 259
#define VARIDENTIFIER 260
#define TRUEBOOL 261
#define FALSEBOOL 262
#define INT 263
#define STR 264
#define BOOL 265
#define VOID 266
#define SWITCH 267
#define CASE 268
#define DEFAULT 269
#define CONST 270
#define DO 271
#define NIL 272
#define OR 273
#define AND 274
#define NOT 275
#define FUNCTION 276
#define RETURN 277
#define INC 278
#define DEC 279
#define INCASSIGNMENT 280
#define DECASSIGNMENT 281
#define MULTIPLYASSIGNMENT 282
#define DIVIDEASSIGNMENT 283
#define FUNCIDENTIFIER 284
#define WHILE 285
#define IF 286
#define PRINT 287
#define FOR 288
#define CONTINUE 289
#define BREAK 290
#define VARFX 291
#define IFX 292
#define ELSE 293
#define NE 294
#define EQ 295
#define LE 296
#define GE 297
#define UMINUS 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 39 "parser.y"

    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    char * stringValue;
    struct symbolTableEntry * entry;



/* Line 1676 of yacc.c  */
#line 147 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


