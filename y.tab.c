
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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <string>
#include <iostream>
#include <fstream>
#include "symbolTable.h"
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;

#define YYDEBUG 1

/* prototypes */
int yylex(void);
void yyerror(char *s);
void appendErrorToFile(std::string line);
void addText (std::string myTxt);
void appendLineToFile(std::string line);
symbolTable symbolTableList[MAX_SCOPES];
dataTypeEnum varType;
bool isFunctionParam = false;
bool isBracketScope = false;
bool isClosedBracketScope = false;
bool isForScope = false;
bool isSwitchScope = false;
bool notInitialized = false;
int paramList [5];
int paramListIndex = 0;
int argumentList [5];
int argumentListIndex = 0;
int labelNumber = 0;
dataTypeEnum functionDataType; 
dataTypeEnum switchDataType; 


/* Line 189 of yacc.c  */
#line 112 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

/* Line 214 of yacc.c  */
#line 39 "parser.y"

    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    char * stringValue;
    struct symbolTableEntry * entry;



/* Line 214 of yacc.c  */
#line 243 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 255 "y.tab.c"

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
#define YYLAST   578

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  221

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    51,     2,     2,
      54,    55,    49,    47,    53,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    39,
      42,    40,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      35,    36,    37,    38,    43,    44,    45,    46,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    15,    17,    19,
      21,    23,    27,    28,    30,    31,    36,    37,    40,    45,
      51,    54,    55,    56,    57,    58,    72,    73,    74,    75,
      76,    90,    94,    96,    99,   105,   107,   109,   111,   113,
     115,   117,   119,   121,   123,   125,   127,   133,   141,   145,
     148,   151,   154,   155,   164,   167,   169,   174,   178,   179,
     180,   190,   191,   192,   202,   203,   204,   216,   217,   218,
     229,   230,   239,   241,   244,   248,   250,   252,   255,   256,
     262,   266,   270,   274,   278,   282,   286,   290,   294,   298,
     301,   305,   309,   313,   317,   320,   323,   326,   329,   333,
     337,   341,   345,   349,   351,   353,   355,   357,   359,   361
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    -1,    61,    69,    -1,    61,    66,
      -1,    61,    67,    -1,    -1,     8,    -1,     9,    -1,    10,
      -1,    68,    -1,    68,    53,    63,    -1,    -1,   102,    -1,
      -1,   102,    65,    53,    64,    -1,    -1,    68,    39,    -1,
      68,    40,   102,    39,    -1,    15,    68,    40,   102,    39,
      -1,    62,     5,    -1,    -1,    -1,    -1,    -1,    62,    21,
      29,    70,    54,    71,    63,    55,    72,   106,    73,   101,
     107,    -1,    -1,    -1,    -1,    -1,    11,    21,    29,    74,
      54,    75,    63,    55,    76,   106,    77,   101,   107,    -1,
     106,   101,   107,    -1,    39,    -1,   102,    39,    -1,    32,
      54,   102,    55,    39,    -1,    88,    -1,    94,    -1,    91,
      -1,    83,    -1,    82,    -1,    80,    -1,    78,    -1,    66,
      -1,    67,    -1,    81,    -1,    84,    -1,    31,    54,   102,
      55,    79,    -1,    31,    54,   102,    55,    79,    38,    79,
      -1,    22,   102,    39,    -1,    22,    39,    -1,    35,    39,
      -1,    34,    39,    -1,    -1,    12,    54,   102,    55,   106,
      85,    86,   107,    -1,    87,    86,    -1,    87,    -1,    13,
     102,    56,   101,    -1,    14,    56,   101,    -1,    -1,    -1,
      30,    54,    89,   102,    55,   106,    90,   101,   107,    -1,
      -1,    -1,    33,    54,    92,    97,    55,   106,    93,   101,
     107,    -1,    -1,    -1,    16,   106,    95,   101,   107,    96,
      30,    54,   102,    55,    39,    -1,    -1,    -1,     8,     5,
      98,    40,   102,    39,    99,   102,    39,   102,    -1,    -1,
       5,   100,    40,   102,    39,   102,    39,   102,    -1,    79,
      -1,   101,    79,    -1,   104,    40,   102,    -1,   104,    -1,
     105,    -1,    48,   102,    -1,    -1,    29,   103,    54,    64,
      55,    -1,   102,    47,   102,    -1,   102,    48,   102,    -1,
     102,    49,   102,    -1,   102,    50,   102,    -1,   102,    42,
     102,    -1,   102,    41,   102,    -1,   102,    51,   102,    -1,
     102,    18,   102,    -1,   102,    19,   102,    -1,    20,   102,
      -1,   104,    25,   102,    -1,   104,    26,   102,    -1,   104,
      28,   102,    -1,   104,    27,   102,    -1,   104,    23,    -1,
      23,   104,    -1,   104,    24,    -1,    24,   104,    -1,   102,
      46,   102,    -1,   102,    45,   102,    -1,   102,    43,   102,
      -1,   102,    44,   102,    -1,    54,   102,    55,    -1,     5,
      -1,     4,    -1,     3,    -1,     7,    -1,     6,    -1,    57,
      -1,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,   104,   105,   106,   107,   109,   110,   111,
     115,   116,   117,   120,   130,   130,   141,   144,   156,   178,
     197,   212,   218,   222,   232,   212,   240,   246,   250,   260,
     240,   269,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   287,   288,   291,   296,
     303,   312,   320,   320,   329,   330,   333,   340,   342,   352,
     342,   375,   380,   375,   403,   412,   403,   430,   434,   430,
     442,   442,   456,   457,   460,   476,   488,   492,   507,   507,
     544,   564,   582,   597,   613,   634,   654,   670,   689,   707,
     724,   760,   792,   823,   853,   891,   929,   965,  1000,  1020,
    1040,  1059,  1079,  1081,  1102,  1111,  1119,  1126,  1136,  1143
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "INTEGER", "VARIDENTIFIER",
  "TRUEBOOL", "FALSEBOOL", "INT", "STR", "BOOL", "VOID", "SWITCH", "CASE",
  "DEFAULT", "CONST", "DO", "NIL", "OR", "AND", "NOT", "FUNCTION",
  "RETURN", "INC", "DEC", "INCASSIGNMENT", "DECASSIGNMENT",
  "MULTIPLYASSIGNMENT", "DIVIDEASSIGNMENT", "FUNCIDENTIFIER", "WHILE",
  "IF", "PRINT", "FOR", "CONTINUE", "BREAK", "VARFX", "IFX", "ELSE", "';'",
  "'='", "'>'", "'<'", "NE", "EQ", "LE", "GE", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "','", "'('", "')'", "':'", "'{'", "'}'", "$accept",
  "program", "function", "type", "functionParam", "functionArgs", "$@1",
  "varDeclaration", "constDeclaration", "variable", "functionDeclaration",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "stmtBlock",
  "stmt", "ifStmt", "returnStmt", "breakStmt", "continueStmt",
  "switchStmt", "$@10", "caseStmts", "caseStmt", "whileStmt", "$@11",
  "$@12", "forStmt", "$@13", "$@14", "doStmt", "$@15", "$@16",
  "loopExpression", "$@17", "$@18", "$@19", "stmtList", "expr", "$@20",
  "lValue", "consValues", "openScope", "closeScope", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    59,
      61,    62,    60,   294,   295,   296,   297,    43,    45,    42,
      47,    37,   298,    44,    40,    41,    58,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    61,    62,    62,    62,
      63,    63,    63,    64,    65,    64,    64,    66,    66,    67,
      68,    70,    71,    72,    73,    69,    74,    75,    76,    77,
      69,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    81,    81,
      82,    83,    85,    84,    86,    86,    87,    87,    89,    90,
      88,    92,    93,    91,    95,    96,    94,    98,    99,    97,
     100,    97,   101,   101,   102,   102,   102,   102,   103,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   104,   105,   105,   105,   105,   106,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     1,     1,     1,
       1,     3,     0,     1,     0,     4,     0,     2,     4,     5,
       2,     0,     0,     0,     0,    13,     0,     0,     0,     0,
      13,     3,     1,     2,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     7,     3,     2,
       2,     2,     0,     8,     2,     1,     4,     3,     0,     0,
       9,     0,     0,     9,     0,     0,    11,     0,     0,    10,
       0,     8,     1,     2,     3,     1,     1,     2,     0,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,     7,     8,     9,     0,     0,     0,
       4,     5,     0,     3,     0,     0,     0,    20,     0,    17,
       0,    26,     0,    21,   105,   104,   103,   107,   106,     0,
       0,     0,    78,     0,     0,     0,    75,    76,     0,     0,
       0,    89,    95,    97,     0,    77,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    96,     0,     0,     0,     0,     0,    27,    19,
      22,    16,   102,    87,    88,    85,    84,   100,   101,    99,
      98,    80,    81,    82,    83,    86,    90,    91,    93,    92,
      74,    12,    12,     0,    13,     0,    10,     0,    79,     0,
      28,    12,    23,    16,     0,    11,     0,    15,   108,    29,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    42,    43,    41,    72,    40,    44,    39,
      38,    45,    35,    37,    36,     0,     0,     0,     0,     0,
      64,    49,     0,    58,     0,     0,    61,    51,    50,   109,
      73,    30,    33,     0,    25,     0,     0,    48,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,    70,     0,
       0,    52,    65,     0,    46,    34,     0,    67,     0,     0,
       0,    59,     0,     0,     0,    62,     0,     0,     0,    55,
       0,     0,    47,     0,     0,     0,     0,     0,    53,    54,
       0,     0,     0,     0,     0,     0,    57,     0,    60,     0,
      68,    63,    56,     0,     0,     0,    66,    71,     0,     0,
      69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    15,    95,    93,    99,   123,   124,    12,
      13,    40,    92,   106,   112,    38,    91,   104,   111,   125,
     126,   127,   128,   129,   130,   131,   179,   188,   189,   132,
     158,   191,   133,   161,   195,   134,   156,   180,   170,   184,
     215,   176,   135,   136,    44,    36,    37,   137,   151
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
    -136,     6,    62,  -136,  -136,  -136,  -136,    -9,    40,    -1,
    -136,  -136,    19,  -136,   -13,    21,     1,  -136,    23,  -136,
     152,  -136,   152,  -136,  -136,  -136,  -136,  -136,  -136,   152,
      60,    60,  -136,   152,   152,   391,    89,  -136,    22,   409,
      24,  -136,  -136,  -136,    26,  -136,   271,   152,   152,  -136,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,  -136,  -136,   152,   152,   152,   152,   152,  -136,  -136,
    -136,   152,  -136,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,     5,     5,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
     527,    40,    40,    27,   373,    32,    28,    34,  -136,    38,
    -136,    40,  -136,   152,    33,  -136,    33,  -136,  -136,  -136,
    -136,   237,   237,    39,    33,   144,    43,    44,    45,    47,
      53,    64,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,   181,   425,   237,   181,   152,
    -136,  -136,   443,  -136,   152,   152,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,   181,  -136,   289,   237,  -136,   152,   305,
     323,     3,  -136,    33,   181,   339,   237,    66,  -136,   101,
      52,  -136,  -136,    33,    70,  -136,    69,  -136,    33,    49,
      81,  -136,   237,   152,    78,  -136,   152,    65,    72,    49,
      68,   237,  -136,   459,   152,   237,   255,   237,  -136,  -136,
     152,   181,   152,   477,   181,   237,   237,   357,  -136,   493,
    -136,  -136,   237,    88,   152,   152,  -136,   527,   511,   152,
     527
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   118,   -82,    29,  -136,   129,   131,    -7,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
     -78,  -136,  -136,  -136,  -136,  -136,  -136,   -54,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,   -95,   -20,  -136,    37,  -136,   -99,  -135
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int16 yytable[] =
{
      35,    16,    39,   154,    17,   109,     3,   110,   168,    41,
      97,   169,    14,    45,    46,   140,    21,   138,   162,   105,
      18,    56,    57,    58,    59,    60,    17,    73,    74,   172,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    22,   153,    86,    87,    88,    89,    90,     4,     5,
       6,    94,    23,   198,    58,    59,    60,   150,    19,    20,
     150,   164,   186,   187,   171,    26,   208,    42,    43,   211,
       4,     5,     6,     7,   181,   150,    68,     8,    70,   185,
      71,   101,    98,    94,    96,    96,   150,   100,   174,   102,
     108,   103,   147,   139,    96,   142,   201,   143,   144,   145,
     204,   146,   206,   148,   192,   175,   177,   178,   182,   183,
     212,   190,    61,    62,    63,    64,    65,    66,   194,   155,
       9,   197,   200,   150,   159,   160,   150,   216,   150,    67,
     149,    10,   107,    11,   150,   199,     0,     0,   165,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,     0,     0,     0,    24,    25,    26,    27,    28,
       0,     0,     0,   193,    29,     0,   196,    30,    31,     0,
       0,     0,    29,    32,   203,    30,    31,     0,     0,     0,
     207,    32,   209,   141,    24,    25,    26,    27,    28,     4,
       5,     6,    33,   113,   217,   218,     8,   114,    34,   220,
      33,    29,     0,   115,    30,    31,    34,     0,     0,     0,
      32,   116,   117,   118,   119,   120,   121,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,    34,     0,     0,   108,   149,
      24,    25,    26,    27,    28,     4,     5,     6,     0,   113,
       0,     0,     8,   114,     0,     0,     0,    29,     0,   115,
      30,    31,     0,     0,     0,     0,    32,   116,   117,   118,
     119,   120,   121,    47,    48,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,    47,
      48,    34,     0,     0,   108,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    47,    48,     0,
       0,   205,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    47,    48,     0,    72,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    47,    48,     0,   163,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    47,    48,     0,
     166,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    47,    48,     0,   167,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    47,    48,     0,   173,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    47,
      48,     0,   213,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,   -14,    47,    48,     0,
      49,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    47,    48,     0,     0,     0,    69,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    47,    48,     0,   152,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    47,    48,     0,
       0,     0,   157,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    47,    48,     0,   202,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    47,    48,     0,     0,     0,   210,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    47,
      48,     0,   214,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    47,    48,     0,     0,     0,
     219,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
      20,     8,    22,   138,     5,   104,     0,   106,     5,    29,
      92,     8,    21,    33,    34,   114,    29,   112,   153,   101,
      21,    47,    48,    49,    50,    51,     5,    47,    48,   164,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    40,   137,    63,    64,    65,    66,    67,     8,     9,
      10,    71,    29,   188,    49,    50,    51,   135,    39,    40,
     138,   156,    13,    14,   163,     5,   201,    30,    31,   204,
       8,     9,    10,    11,   173,   153,    54,    15,    54,   178,
      54,    53,    55,   103,    91,    92,   164,    55,   166,    55,
      57,    53,    39,    54,   101,   115,   191,    54,    54,    54,
     195,    54,   197,    39,   182,    39,     5,    55,    38,    40,
     205,    30,    23,    24,    25,    26,    27,    28,    40,   139,
       2,    56,    54,   201,   144,   145,   204,    39,   206,    40,
      58,     2,   103,     2,   212,   189,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   183,    20,    -1,   186,    23,    24,    -1,
      -1,    -1,    20,    29,   194,    23,    24,    -1,    -1,    -1,
     200,    29,   202,    39,     3,     4,     5,     6,     7,     8,
       9,    10,    48,    12,   214,   215,    15,    16,    54,   219,
      48,    20,    -1,    22,    23,    24,    54,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    18,    19,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    18,
      19,    54,    -1,    -1,    57,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    18,    19,    -1,
      -1,    56,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    18,    19,    -1,    55,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    18,    19,    -1,    55,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    18,    19,    -1,
      55,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    18,    19,    -1,    55,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    18,    19,    -1,    55,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    18,
      19,    -1,    55,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    18,    19,    -1,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    18,    19,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    18,    19,    -1,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    18,    19,    -1,
      -1,    -1,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    18,    19,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    18,    19,    -1,    -1,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    18,
      19,    -1,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    18,    19,    -1,    -1,    -1,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,     0,     8,     9,    10,    11,    15,    62,
      66,    67,    68,    69,    21,    62,    68,     5,    21,    39,
      40,    29,    40,    29,     3,     4,     5,     6,     7,    20,
      23,    24,    29,    48,    54,   102,   104,   105,    74,   102,
      70,   102,   104,   104,   103,   102,   102,    18,    19,    39,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    23,    24,    25,    26,    27,    28,    40,    54,    39,
      54,    54,    55,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,    75,    71,    64,   102,    63,    68,    63,    55,    65,
      55,    53,    55,    53,    76,    63,    72,    64,    57,   106,
     106,    77,    73,    12,    16,    22,    30,    31,    32,    33,
      34,    35,    39,    66,    67,    78,    79,    80,    81,    82,
      83,    84,    88,    91,    94,   101,   102,   106,   101,    54,
     106,    39,   102,    54,    54,    54,    54,    39,    39,    58,
      79,   107,    39,   101,   107,   102,    95,    39,    89,   102,
     102,    92,   107,    55,   101,   102,    55,    55,     5,     8,
      97,   106,   107,    55,    79,    39,   100,     5,    55,    85,
      96,   106,    38,    40,    98,   106,    13,    14,    86,    87,
      30,    90,    79,   102,    40,    93,   102,    56,   107,    86,
      54,   101,    39,   102,   101,    56,   101,   102,   107,   102,
      39,   107,   101,    55,    39,    99,    39,   102,   102,    39,
     102
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
#line 81 "parser.y"
    {       
                                        for(int j=0; j<totalNumberOfScopes; j++){
                                                symbolTable symb= symbolTableList[j];
                                                symbolTableEntry* traverser;
                                                for(int i=0; i < MAX_IDENTIFIERS; i++)
                                                {
                                                        traverser = symb.symbolTable[i];
                                                        while( traverser != NULL)
                                                        {
                                                                if(!traverser->isUsed && strcmp(traverser->lexeme,"Main")){
                                                                        printf("The variable/function %s is not used\n", traverser->lexeme);
                                                                        
                                                                }
                                                                traverser = traverser->next;
                                                        }
                                                }
                                        }
                                       
                                        printf("Exiting");
                                }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {varType = dataTypeEnum::typeInt;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {varType = dataTypeEnum::typeString;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    {varType = dataTypeEnum::typeBool;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {       
                                                if((yyvsp[(1) - (1)].entry)!=NULL){

                                                        argumentList[argumentListIndex] = (yyvsp[(1) - (1)].entry)->dataType;
                                                        argumentListIndex++;
                                                }else{
                                                        argumentList[argumentListIndex] = -1;
                                                        argumentListIndex++;      
                                                }
                                        }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {
                                                if((yyvsp[(1) - (1)].entry)!=NULL){

                                                        argumentList[argumentListIndex] = (yyvsp[(1) - (1)].entry)->dataType;
                                                        argumentListIndex++;
                                                }else{
                                                        argumentList[argumentListIndex] = -1;
                                                        argumentListIndex++;      
                                                }
                                        }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {
                                              
                                                if((yyvsp[(1) - (2)].entry) !=NULL){
                                                        (yyvsp[(1) - (2)].entry)->entryType = entryTypeEnum::isVariable;
                                                        (yyval.entry)=(yyvsp[(1) - (2)].entry);

                                                }else{
                                                        (yyval.entry)=NULL;  
                                                }
                                                
                                                
                                        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {

                                                if((yyvsp[(1) - (4)].entry) !=NULL && (yyvsp[(3) - (4)].entry) != NULL){
                                                        (yyvsp[(1) - (4)].entry)->entryType = entryTypeEnum::isVariable;
                                                        if((yyvsp[(1) - (4)].entry)->dataType != (yyvsp[(3) - (4)].entry)->dataType){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                                (yyval.entry)=NULL;
                                                        }else{
                                                                (yyvsp[(1) - (4)].entry)->isInitialized = true;
                                                                std::string  stringToAdd = "pop ";
                                                                stringToAdd += (yyvsp[(1) - (4)].entry)->lexeme;  
                                                                appendLineToFile(stringToAdd);       
                                                                (yyval.entry)=(yyvsp[(1) - (4)].entry);    
                                                        }
                                                        
                                                }else{
                                                        (yyval.entry)=NULL;
                                                } 
                                               
                                        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {
                                                if((yyvsp[(4) - (5)].entry)!=NULL){

                                                        (yyvsp[(2) - (5)].entry)->entryType = entryTypeEnum::isConstantVariable;
                                                        if((yyvsp[(2) - (5)].entry)->dataType != (yyvsp[(4) - (5)].entry)->dataType){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                        }else{
                                                                (yyvsp[(2) - (5)].entry)->isInitialized = true;     
                                                                std::string  stringToAdd = "pop ";
                                                                stringToAdd += (yyvsp[(2) - (5)].entry)->lexeme;  
                                                                appendLineToFile(stringToAdd);       
                                                                (yyval.entry)=(yyvsp[(2) - (5)].entry);         
                                                        }
                                                }
                                               
                                               
                                        }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {
                                               
                                                (yyvsp[(2) - (2)].entry) = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,varType);
                                                
                                                if(isFunctionParam == true){
                                                        (yyvsp[(2) - (2)].entry)->entryType = entryTypeEnum::isParameter;
                                                        paramList[paramListIndex] = varType;
                                                        paramListIndex++;
                                                        (yyvsp[(2) - (2)].entry)->isInitialized = true;
                                                }               
                                                (yyval.entry) = (yyvsp[(2) - (2)].entry);
                                                                                             
                                        }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {
                                                isFunctionParam=true;
                                                (yyvsp[(3) - (3)].entry) = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,varType); 
                                                (yyvsp[(3) - (3)].entry)->entryType = entryTypeEnum::isFunction;     
                                                                                                                           
                                        }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {       
                                                currentScope = createNewScope();
                                                isBracketScope = true;
                                        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {       
                                                int*temp = (int*) malloc(sizeof(int)*(paramListIndex+1));
                                                for(int i=0; i<paramListIndex; i++){
                                                        temp[i] = paramList[i];
                                                }
                                                (yyvsp[(3) - (8)].entry)->functionParametersList=temp;
                                                (yyvsp[(3) - (8)].entry)->functionsParametersNumber=paramListIndex;
                                                isFunctionParam=false;
                                                paramListIndex=0;
                                        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {       
                                                functionDataType = (yyvsp[(3) - (10)].entry)->dataType;
                                                isBracketScope = false;
                                        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {
                                           (yyval.entry) = (yyvsp[(3) - (13)].entry);
                                        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    {        
                                                (yyvsp[(3) - (3)].entry) = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,dataTypeEnum::typeVoid); 
                                                (yyvsp[(3) - (3)].entry)->entryType = entryTypeEnum::isFunction;
                                                isFunctionParam=true;
                                               
                                        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    {
                                                isBracketScope = true;  
                                                currentScope = createNewScope();
                                        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {
                                                int*temp = (int*) malloc(sizeof(int)*(paramListIndex+1));
                                                for(int i=0; i<paramListIndex; i++){
                                                        temp[i] = paramList[i];
                                                }
                                                (yyvsp[(3) - (8)].entry)->functionParametersList=temp;
                                                (yyvsp[(3) - (8)].entry)->functionsParametersNumber=paramListIndex;
                                                isFunctionParam=false;
                                                paramListIndex=0;
                                        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    {       functionDataType = dataTypeEnum::typeVoid;
                                                isBracketScope = false;
                                        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {
                                                (yyval.entry) = (yyvsp[(3) - (13)].entry);
                                        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    { }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    { }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    { }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    { }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 277 "parser.y"
    { }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    { }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    { }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    { }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 281 "parser.y"
    { }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    { }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    { }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    { }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    {/*TODO:CHECK BOOL EXPRESSION*/}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {/*TODO:CHECK BOOL EXPRESSION*/}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    {
                                                         if (functionDataType!=(yyvsp[(2) - (3)].entry)->dataType){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                        }
                                                }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {
                                                         if (functionDataType!=dataTypeEnum::typeVoid){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                        } 
                                                }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 303 "parser.y"
    {
                                                        if(!isForScope && !isSwitchScope){
                                                               
                                                                appendErrorToFile("Break couldn't be called outside the scope of a loop/switch at line "+ to_string(yylineno)); 
                                                                        
                                                        }
                                                }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 312 "parser.y"
    { 
                                                        if(!isForScope){
                                                                appendErrorToFile("Continue couldn't be called outside the scope of a loop/switch at line "+ to_string(yylineno)); 
                                                                
                                                        }
                                                }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {
                                                isSwitchScope = true;
                                                switchDataType = (yyvsp[(3) - (5)].entry)->dataType;
                                        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    {
                                                isSwitchScope = false;
                                        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 333 "parser.y"
    {
                                                if((yyvsp[(2) - (4)].entry)!=NULL){
                                                        if((yyvsp[(2) - (4)].entry)->dataType != switchDataType){
                                                               appendErrorToFile("Type mismatch at line"+ to_string(yylineno));
                                                        }
                                                }
                                        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 340 "parser.y"
    {}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 342 "parser.y"
    {    
                                                                        currentScope = createNewScope();
                                                                        isBracketScope = true;
                                                                        std::string stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;          
                                                                        
                                                                }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 352 "parser.y"
    {
                                                                        isForScope = true;
                                                                        isBracketScope = false;
                                                                        std::string stringToAdd = "JZ ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        appendLineToFile(stringToAdd);
                                                                              
                                                                }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    {
                                                                         isForScope = false;
                                                                        std::string stringToAdd = "JMP ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labelNumber-1);
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;      
                                                                }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 375 "parser.y"
    {       
                                                                       
                                                                        currentScope = createNewScope();
                                                                        isBracketScope = true;
                                                                }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 380 "parser.y"
    {
                                                                        isForScope = true;
                                                                        isBracketScope = false;

                                                                        std::string stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;         
                                                                
                                                                }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 391 "parser.y"
    {       
                                                                        isForScope = false;
                                                                           
                                                                        
                                                                        std::string stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;          
                                                                }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 403 "parser.y"
    {       
                                                                        isClosedBracketScope = true;
                                                                        isForScope = true;
                                                                        std::string stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;          
                                                                }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 412 "parser.y"
    {
                                                                        isClosedBracketScope = false;        
                                                                        isForScope = false;
                                                                }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 416 "parser.y"
    {      
                                                                        std::string stringToAdd = "JNZ ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labelNumber-1);
                                                                        appendLineToFile(stringToAdd);  

                                                                        stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;          
                                                                }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 430 "parser.y"
    {
                                                (yyvsp[(2) - (2)].entry) = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,dataTypeEnum::typeInt);
                                                (yyvsp[(2) - (2)].entry)->isInitialized = true;
                                        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 434 "parser.y"
    {                               
                                                std::string stringToAdd = "L";
                                                stringToAdd += to_string(labelNumber);
                                                stringToAdd += ": ";
                                                appendLineToFile(stringToAdd);  
                                                labelNumber++;         
                                        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 442 "parser.y"
    {
                                                (yyvsp[(1) - (1)].entry) = isAvailable(yylval.stringValue);
                                                if((yyvsp[(1) - (1)].entry)==NULL){
                                        
                                                        
                                                        std::string temp = yylval.stringValue;
                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                        
                                                        (yyvsp[(1) - (1)].entry)->isInitialized = true;
                                                }
                                        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 456 "parser.y"
    { }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 457 "parser.y"
    { }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 460 "parser.y"
    {       
                                                        if((yyvsp[(1) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != (yyvsp[(3) - (3)].entry)->dataType){
                                                                        appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                                }else{
                                                                        (yyvsp[(1) - (3)].entry)->isInitialized = true;
                                                                        std::string stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);                                                                      
                                                                }

                                                        }
                                                        
                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);
                                                        
                                                }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 476 "parser.y"
    {       
                                                        if(!(yyvsp[(1) - (1)].entry)->isInitialized){
                                                                std::string temp= (yyvsp[(1) - (1)].entry)->lexeme; 
                                                                appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                        }else{
                                                                std::string  stringToAdd = "push ";
                                                                stringToAdd += (yyvsp[(1) - (1)].entry)->lexeme;
                                                                appendLineToFile(stringToAdd); 
                                                        }
                                                        //notInitialized=false;
                                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                                }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 488 "parser.y"
    {
                                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                                }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 492 "parser.y"
    {
                                                        if((yyvsp[(2) - (2)].entry)!=NULL){
                                                                if((yyvsp[(2) - (2)].entry)->dataType != dataTypeEnum::typeInt){
                                                                        appendLineToFile("Can't - on a non integer value");
                                                                
                                                                }
                                                        }else{
                                                                std::string  stringToAdd = "neg ";
                                                                appendLineToFile(stringToAdd);  
                                                                (yyvsp[(2) - (2)].entry)->lexeme = '-'+(yyvsp[(2) - (2)].entry)->lexeme;

                                                        }

                                                        (yyval.entry)=(yyvsp[(2) - (2)].entry);    
                                                }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 507 "parser.y"
    { 

                                                        (yyvsp[(1) - (1)].entry) = isAvailable(yylval.stringValue);
                                                        if((yyvsp[(1) - (1)].entry)==NULL)
                                                        {       std::string temp = yylval.stringValue;
                                                                std::string error = "Function" + temp +" not defined at line " + to_string(yylineno);
                                                                appendErrorToFile(error);
                                                                
                                                        }
                                                           
                                                                     
                                                }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 519 "parser.y"
    {
                                                        if((yyvsp[(1) - (5)].entry)->functionsParametersNumber!=argumentListIndex){
                                                                
                                                                std::string error = "Expected" + to_string((yyvsp[(1) - (5)].entry)->functionsParametersNumber) +"arguments, but found" +to_string(argumentListIndex)+ "at line" + to_string(yylineno);
                                                                appendErrorToFile(error);
                                                              
                                                                (yyval.entry)=NULL;
                                                        }else{
                                                                bool flag = false;
                                                                for(int i=0; i<argumentListIndex; i++){
                                                                        if((yyvsp[(1) - (5)].entry)->functionParametersList[i] != argumentList[i]){
                                                                                appendErrorToFile("Calling arguments type are not matching at line "+ to_string(yylineno));
                                                                                flag = true;
                                                                                break;
                                                                                (yyval.entry)=NULL;
                                                                        }
                                                                }
                                                                if(!flag){
                                                                        (yyval.entry)=(yyvsp[(1) - (5)].entry); 
                                                                }
                                                        }   
                                                        
                                                        argumentListIndex=0;
                                                
                                                }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 544 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType==dataTypeEnum::typeBool || (yyvsp[(3) - (3)].entry)->dataType==dataTypeEnum::typeBool){
                                                                        
                                                                        appendErrorToFile("Failed to add bool expression at line "+ to_string(yylineno));
                                                                        (yyval.entry)=NULL;
                                                                }
                                                                else if((yyvsp[(1) - (3)].entry)->dataType != (yyvsp[(3) - (3)].entry)->dataType){
                                                                        appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "add ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        (yyval.entry) = (yyvsp[(1) - (3)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                       
                                                }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 564 "parser.y"
    {        
                                                        
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                        appendErrorToFile("Failed to subtract non integer variables at line "+ to_string(yylineno));
                                                                        (yyval.entry)=NULL;
                                                                }
                                                                else{
                                                                        std::string  stringToAdd = "sub ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "neg ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 582 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                          
                                                                          appendErrorToFile("Failed to multiply non integer variables at line "+ to_string(yylineno));
                                                                          (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "mul ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 597 "parser.y"
    {
                                                         if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                    
                                                                        appendErrorToFile("Failed to divide non integer variables at line "+ to_string(yylineno));    
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "div ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                        
                                                }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 613 "parser.y"
    {
                                                         if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                        appendErrorToFile("Failed to compare non integer variables at line "+ to_string(yylineno));
                                                                        
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        (yyval.entry) = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpLT ";
                                                                        appendLineToFile(stringToAdd); 
                                                                }
                                                        }else{
                                                             (yyval.entry)=NULL;    
                                                        }
                                                       
                                                }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 634 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum::typeInt){
                                                                       
                                                                        appendErrorToFile("Failed to compare non integer variables at line "+ to_string(yylineno));
                                                                        
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        (yyval.entry) = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpGT ";
                                                                        appendLineToFile(stringToAdd); 
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 654 "parser.y"
    {
                                                         if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                        appendErrorToFile("Failed to mod non integer variables at line "+ to_string(yylineno));
                                                                        
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "mod ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);
                                                                        
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 670 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeBool || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeBool){
                                                                        appendErrorToFile("Failed to OR non boolean variables at line "+ to_string(yylineno));
                                                                        
                                                                          (yyval.entry)=NULL;
                                                                }else{  
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        (yyval.entry) = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "or ";
                                                                        appendLineToFile(stringToAdd); 
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 689 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeBool || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeBool){
                                                                        appendErrorToFile("Failed to and non boolean variables at line "+ to_string(yylineno));
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        (yyval.entry) = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "and ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 707 "parser.y"
    {
                                                        if((yyvsp[(2) - (2)].entry)!=NULL){
                                                                if((yyvsp[(2) - (2)].entry)->dataType != dataTypeEnum:: typeBool){
                                                                        
                                                                        appendErrorToFile("Failed to Not non boolean variables at line "+ to_string(yylineno));
                                                                        
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        (yyvsp[(2) - (2)].entry)->dataType = dataTypeEnum::typeBool;
                                                                        (yyval.entry)=(yyvsp[(2) - (2)].entry); 
                                                                        std::string  stringToAdd = "not ";
                                                                        appendLineToFile(stringToAdd); 
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 724 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                if(!(yyvsp[(1) - (3)].entry)->isInitialized){
                                                                       
                                                                        std::string temp = (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendErrorToFile("Variable" +temp +"is used and not initialized at line "+ to_string(yylineno));
                                                                          
                                                                }
                                                                notInitialized=false;
                                                                if((yyvsp[(1) - (3)].entry)->dataType==dataTypeEnum::typeBool || (yyvsp[(3) - (3)].entry)->dataType==dataTypeEnum::typeBool){
                                                                        appendErrorToFile("Failed to add bool expression at line " + to_string(yylineno));
                                                                        (yyval.entry)=NULL;
                                                                }
                                                                else if((yyvsp[(1) - (3)].entry)->dataType != (yyvsp[(3) - (3)].entry)->dataType){
                                                                        
                                                                        appendErrorToFile("Type mismatch at line " + to_string(yylineno));
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "add ";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);      
                                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 760 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!(yyvsp[(1) - (3)].entry)->isInitialized){
                                                                         
                                                                        std::string temp = (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendErrorToFile("Variable " + temp +"is used and not initialized at line"+ to_string(yylineno));
                                                                }
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                        appendErrorToFile("Can't subtract non integer variables at line "+ to_string(yylineno));
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "sub ";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);      
                                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);
                                                                      
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                        
                                                }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 792 "parser.y"
    {
                                                          if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!(yyvsp[(1) - (3)].entry)->isInitialized){
                                                                        
                                                                        std::string temp = (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendErrorToFile("Variable "+temp+ " not Initialized at line"+ to_string(yylineno));  
                                                                }
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                       
                                                                        appendErrorToFile("Can't divide non integer varaibles at line"+ to_string(yylineno));
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "div ";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);     
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 823 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!(yyvsp[(1) - (3)].entry)->isInitialized){
                                                                        std::string temp = (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendErrorToFile("Variable "+temp+ "  is not initialized at line "+ to_string(yylineno));   
                                                                }
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                        appendErrorToFile("Failed to multiply non integer variables at line "+ to_string(yylineno)); 
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "mul ";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);       
                                                                        
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 853 "parser.y"
    {
                                                        if((yyvsp[(1) - (2)].entry)!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!(yyvsp[(1) - (2)].entry)->isInitialized){
                                                                        std::string temp = (yyvsp[(1) - (2)].entry)->lexeme;
                                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                          
                                                                }
                                                                if((yyvsp[(1) - (2)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                         
                                                                          appendErrorToFile("Failed to increment non integer variable at line "+ to_string(yylineno)); 
                                                                        
                                                                          (yyval.entry)=NULL;

                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(1) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "push 1";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(1) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "add";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(1) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                           
                                                                        (yyval.entry)=(yyvsp[(1) - (2)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 891 "parser.y"
    {
                                                        if((yyvsp[(2) - (2)].entry)!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $2->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!(yyvsp[(2) - (2)].entry)->isInitialized){
                                                                      
                                                                        std::string temp = (yyvsp[(2) - (2)].entry)->lexeme;
                                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                          
                                                                }
                                                                if((yyvsp[(2) - (2)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                        appendErrorToFile("Failed to increment non integer variable at line "+ to_string(yylineno)); 
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                      
                                                                        std::string  stringToAdd = "push 1";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(2) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "add";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(2) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(2) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        (yyval.entry)=(yyvsp[(2) - (2)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                       
                                                }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 929 "parser.y"
    {
                                                        if((yyvsp[(1) - (2)].entry)!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                if(!(yyvsp[(1) - (2)].entry)->isInitialized){
                                                                        std::string temp = (yyvsp[(1) - (2)].entry)->lexeme; 
                                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                          
                                                                }
                                                                if((yyvsp[(1) - (2)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                          appendErrorToFile("Failed to decrement non integer variable at line "+ to_string(yylineno)); 
                                                                        
                                                                          (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(1) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "push 1";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(1) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "sub";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(1) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        (yyval.entry)=(yyvsp[(1) - (2)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 965 "parser.y"
    {
                                                        if((yyvsp[(2) - (2)].entry)!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $2->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!(yyvsp[(2) - (2)].entry)->isInitialized){
                                                                        std::string temp = (yyvsp[(2) - (2)].entry)->lexeme;
                                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                          
                                                                }
                                                                if((yyvsp[(2) - (2)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                          appendErrorToFile("Failed to decrement non integer variable at line "+ to_string(yylineno)); 
                                                                        
                                                                          (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "push 1";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(2) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "sub";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(2) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(2) - (2)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        (yyval.entry)=(yyvsp[(2) - (2)].entry);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1000 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                          
                                                                          appendErrorToFile("Failed to compare non integer variables at line "+ to_string(yylineno)); 
                                                                        
                                                                          (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        (yyval.entry) = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpGE ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1020 "parser.y"
    {      
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != dataTypeEnum:: typeInt || (yyvsp[(3) - (3)].entry)->dataType != dataTypeEnum:: typeInt){
                                                                         
                                                                          appendErrorToFile("Failed to compare non integer variables at line "+ to_string(yylineno)); 
                                                                        
                                                                          (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        (yyval.entry) = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpLE ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1040 "parser.y"
    {
                                                       if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != (yyvsp[(3) - (3)].entry)->dataType){
                                                                        appendErrorToFile("Failed to compare variables from different types at line "+ to_string(yylineno)); 
                                                                        
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        (yyval.entry) = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpNE ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;
                                                        }
                                                }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1059 "parser.y"
    {
                                                        if((yyvsp[(1) - (3)].entry)!=NULL && (yyvsp[(3) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != (yyvsp[(3) - (3)].entry)->dataType){
                                                                        appendErrorToFile("Failed to compare variables from different types at line "+ to_string(yylineno)); 
                                                                        
                                                                        (yyval.entry)=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        (yyval.entry) = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpEQ ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                (yyval.entry)=NULL;   
                                                        }
                                                      
                                                }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1079 "parser.y"
    {(yyval.entry)=(yyvsp[(2) - (3)].entry);}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1081 "parser.y"
    {  
                                        (yyvsp[(1) - (1)].entry) = isAvailable(yylval.stringValue);
                                        if((yyvsp[(1) - (1)].entry)==NULL){
                                                
                                                std::string temp = yylval.stringValue;
                                                appendErrorToFile("Variable "+temp+" at line "+ to_string(yylineno)); 
                                                                        
                                                (yyval.entry)=NULL;
                                        }else{
                                               
                                                // if(!$1->isInitialized){
                                                //         notInitialized=true;
                                                // }
                                                (yyval.entry) = (yyvsp[(1) - (1)].entry);     
                                        }

                                        
                                        
                                }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1102 "parser.y"
    { 

                                        (yyvsp[(1) - (1)].entry) = createEntry(yylval.stringValue, dataTypeEnum::typeInt);
                                        (yyvsp[(1) - (1)].entry)->entryType = entryTypeEnum::isConstant;
                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                        std::string stringToAdd = "push ";
                                        stringToAdd += yylval.stringValue;
                                        appendLineToFile(stringToAdd);
                                }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1111 "parser.y"
    {
                                        (yyvsp[(1) - (1)].entry) = createEntry(yylval.stringValue, dataTypeEnum::typeString);
                                        (yyvsp[(1) - (1)].entry)->entryType = entryTypeEnum::isConstant;
                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                        std::string stringToAdd = "push ";
                                        stringToAdd += yylval.stringValue ;
                                        appendLineToFile(stringToAdd);
                                }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1119 "parser.y"
    {
                                        (yyvsp[(1) - (1)].entry) = createEntry(yylval.stringValue, dataTypeEnum::typeBool);
                                        (yyvsp[(1) - (1)].entry)->entryType = entryTypeEnum::isConstant;
                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                        std::string stringToAdd = "push 0";
                                        appendLineToFile(stringToAdd);
                                }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1126 "parser.y"
    {
                                        (yyvsp[(1) - (1)].entry) = createEntry(yylval.stringValue, dataTypeEnum::typeBool);
                                        (yyvsp[(1) - (1)].entry)->entryType = entryTypeEnum::isConstant;
                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                        std::string stringToAdd = "push 1";
                                        appendLineToFile(stringToAdd);
                                }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1136 "parser.y"
    {
                                       
                                        if(!isBracketScope){
                                                currentScope = createNewScope();
                                        }
                                      
                                }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1143 "parser.y"
    {
                                        if(!isClosedBracketScope){
                                             currentScope = exitScope();   
                                        }
                                        
                                }
    break;



/* Line 1455 of yacc.c  */
#line 3290 "y.tab.c"
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
#line 1149 "parser.y"


void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

#define LEN 256
void addText (std::string myTxt)
{
   FILE * fp;
   /* open the file for writing*/
   fp = fopen ("./output.txt","wt");

   /* write 10 lines of text into the file stream*/
   fprintf(fp, "%s\n", myTxt);

   /* close the file*/  
   fclose (fp);
}

void appendLineToFile(std::string line)
{
    std::ofstream file;
    file.open ("./output.txt", std::ios::out | std::ios::app );
    file << line << std::endl;
}



void appendErrorToFile(std::string line)
{
    std::ofstream file;
    file.open ("./error.txt", std::ios::out | std::ios::app );
    file << line << std::endl;
}

int main (int argc, char *argv[]){
	// parsing
        symbolTableList[0].symbolTable = createTable();
        symbolTableList[0].parent = -1;
	yyin = fopen(argv[1], "r");
        // yyparse();
        if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
		printf("\nPARSING FAILED!\n\n\n");
	}
	fclose(yyin);
        display_symbol_table(symbolTableList[2].symbolTable);

}
