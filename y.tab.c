
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
int startLabel=0;
int endLabel = 1;
int paramList [5];
int paramListIndex = 0;
int argumentList [5];
typedef enum   {whileLabel,doLabel, forLabel, ifLabel, switchLabel}  labelType;
void createLabel(labelType type);
int getNextCaseLabel();
int getCurrentCaseLabel();
void deleteLabel();
struct label{
        labelType type;
        int labelsNames[20];
        int currentSwitchLabel = 0;
        int hasDefault = 0;
        dataTypeEnum switchType;
};
struct labelsController {
        int currentIndex = -1;
        label * labelBlocks[100];      
};
labelsController labels;
int argumentListIndex = 0;
int labelNumber = 0;
dataTypeEnum functionDataType; 
dataTypeEnum switchDataType; 


/* Line 189 of yacc.c  */
#line 131 "y.tab.c"

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
#line 58 "parser.y"

    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    char * stringValue;
    struct symbolTableEntry * entry;



/* Line 214 of yacc.c  */
#line 262 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 274 "y.tab.c"

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
#define YYLAST   542

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  232

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
      21,    23,    24,    29,    30,    32,    33,    38,    39,    42,
      47,    53,    56,    57,    58,    59,    60,    74,    75,    76,
      77,    78,    92,    96,    98,   101,   107,   109,   111,   113,
     115,   117,   119,   121,   123,   125,   127,   129,   130,   138,
     139,   140,   144,   148,   151,   154,   157,   158,   167,   170,
     172,   173,   174,   175,   183,   184,   189,   190,   191,   201,
     202,   203,   213,   214,   215,   227,   228,   229,   230,   242,
     243,   244,   245,   256,   258,   261,   265,   267,   269,   272,
     273,   279,   283,   287,   291,   295,   299,   303,   307,   311,
     315,   318,   322,   326,   330,   334,   337,   340,   343,   346,
     350,   354,   358,   362,   366,   368,   370,   372,   374,   376,
     378
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    -1,    61,    70,    -1,    61,    67,
      -1,    61,    68,    -1,    -1,     8,    -1,     9,    -1,    10,
      -1,    69,    -1,    -1,    69,    64,    53,    63,    -1,    -1,
     113,    -1,    -1,   113,    66,    53,    65,    -1,    -1,    69,
      39,    -1,    69,    40,   113,    39,    -1,    15,    69,    40,
     113,    39,    -1,    62,     5,    -1,    -1,    -1,    -1,    -1,
      62,    21,    29,    71,    54,    72,    63,    55,    73,   117,
      74,   112,   118,    -1,    -1,    -1,    -1,    -1,    11,    21,
      29,    75,    54,    76,    63,    55,    77,   117,    78,   112,
     118,    -1,   117,   112,   118,    -1,    39,    -1,   113,    39,
      -1,    32,    54,   113,    55,    39,    -1,    96,    -1,   102,
      -1,    99,    -1,    87,    -1,    86,    -1,    81,    -1,    79,
      -1,    67,    -1,    68,    -1,    85,    -1,    88,    -1,    -1,
      31,    54,   113,    55,    82,    80,    83,    -1,    -1,    -1,
      38,    84,    80,    -1,    22,   113,    39,    -1,    22,    39,
      -1,    35,    39,    -1,    34,    39,    -1,    -1,    12,    54,
     113,    55,   117,    89,    90,   118,    -1,    91,    90,    -1,
      91,    -1,    -1,    -1,    -1,    13,    92,   113,    93,    56,
      94,   112,    -1,    -1,    14,    95,    56,   112,    -1,    -1,
      -1,    30,    54,    97,   113,    55,   117,    98,   112,   118,
      -1,    -1,    -1,    33,    54,   100,   105,    55,   117,   101,
     112,   118,    -1,    -1,    -1,    16,   117,   103,   112,   118,
     104,    30,    54,   113,    55,    39,    -1,    -1,    -1,    -1,
       8,     5,   106,    40,   113,   107,    39,   113,   108,    39,
     113,    -1,    -1,    -1,    -1,     5,   109,    40,   113,   110,
      39,   113,   111,    39,   113,    -1,    80,    -1,   112,    80,
      -1,   115,    40,   113,    -1,   115,    -1,   116,    -1,    48,
     113,    -1,    -1,    29,   114,    54,    65,    55,    -1,   113,
      47,   113,    -1,   113,    48,   113,    -1,   113,    49,   113,
      -1,   113,    50,   113,    -1,   113,    42,   113,    -1,   113,
      41,   113,    -1,   113,    51,   113,    -1,   113,    18,   113,
      -1,   113,    19,   113,    -1,    20,   113,    -1,   115,    25,
     113,    -1,   115,    26,   113,    -1,   115,    28,   113,    -1,
     115,    27,   113,    -1,   115,    23,    -1,    23,   115,    -1,
     115,    24,    -1,    24,   115,    -1,   113,    46,   113,    -1,
     113,    45,   113,    -1,   113,    43,   113,    -1,   113,    44,
     113,    -1,    54,   113,    55,    -1,     5,    -1,     4,    -1,
       3,    -1,     7,    -1,     6,    -1,    57,    -1,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   124,   125,   126,   127,   129,   130,   131,
     135,   138,   138,   142,   145,   158,   158,   172,   175,   187,
     209,   228,   248,   257,   261,   271,   248,   279,   288,   292,
     302,   279,   311,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   330,   330,   348,
     356,   356,   367,   387,   397,   416,   428,   428,   458,   459,
     462,   470,   488,   462,   494,   494,   510,   520,   510,   543,
     551,   543,   572,   581,   572,   599,   605,   617,   599,   637,
     650,   664,   637,   687,   688,   691,   710,   722,   726,   741,
     741,   780,   800,   818,   833,   849,   870,   890,   906,   925,
     943,   960,   996,  1028,  1062,  1092,  1130,  1168,  1204,  1239,
    1259,  1279,  1298,  1318,  1320,  1341,  1350,  1358,  1365,  1375,
    1382
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
  "program", "function", "type", "functionParam", "$@1", "functionArgs",
  "$@2", "varDeclaration", "constDeclaration", "variable",
  "functionDeclaration", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "$@10", "stmtBlock", "stmt", "ifStmt", "$@11", "ifContinue", "$@12",
  "returnStmt", "breakStmt", "continueStmt", "switchStmt", "$@13",
  "caseStmts", "caseStmt", "$@14", "$@15", "$@16", "$@17", "whileStmt",
  "$@18", "$@19", "forStmt", "$@20", "$@21", "doStmt", "$@22", "$@23",
  "loopExpression", "$@24", "$@25", "$@26", "$@27", "$@28", "$@29",
  "stmtList", "expr", "$@30", "lValue", "consValues", "openScope",
  "closeScope", 0
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
      63,    64,    63,    63,    65,    66,    65,    65,    67,    67,
      68,    69,    71,    72,    73,    74,    70,    75,    76,    77,
      78,    70,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    82,    81,    83,
      84,    83,    85,    85,    86,    87,    89,    88,    90,    90,
      92,    93,    94,    91,    95,    91,    97,    98,    96,   100,
     101,    99,   103,   104,   102,   106,   107,   108,   105,   109,
     110,   111,   105,   112,   112,   113,   113,   113,   113,   114,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   115,   116,   116,   116,   116,   117,
     118
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     1,     1,     1,
       1,     0,     4,     0,     1,     0,     4,     0,     2,     4,
       5,     2,     0,     0,     0,     0,    13,     0,     0,     0,
       0,    13,     3,     1,     2,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     7,     0,
       0,     3,     3,     2,     2,     2,     0,     8,     2,     1,
       0,     0,     0,     7,     0,     4,     0,     0,     9,     0,
       0,     9,     0,     0,    11,     0,     0,     0,    11,     0,
       0,     0,    10,     1,     2,     3,     1,     1,     2,     0,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,     7,     8,     9,     0,     0,     0,
       4,     5,     0,     3,     0,     0,     0,    21,     0,    18,
       0,    27,     0,    22,   116,   115,   114,   118,   117,     0,
       0,     0,    89,     0,     0,     0,    86,    87,     0,     0,
       0,   100,   106,   108,     0,    88,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   107,     0,     0,     0,     0,     0,    28,    20,
      23,    17,   113,    98,    99,    96,    95,   111,   112,   110,
     109,    91,    92,    93,    94,    97,   101,   102,   104,   103,
      85,    13,    13,     0,    14,     0,    10,     0,    90,     0,
      29,     0,    24,    17,     0,    13,     0,    16,   119,    30,
      12,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    43,    44,    42,    83,    41,    45,
      40,    39,    46,    36,    38,    37,     0,     0,     0,     0,
       0,    72,    53,     0,    66,     0,     0,    69,    55,    54,
     120,    84,    31,    34,     0,    26,     0,     0,    52,     0,
       0,     0,     0,    32,     0,     0,     0,    47,     0,    79,
       0,     0,    56,    73,     0,     0,    35,     0,    75,     0,
       0,     0,    67,    49,     0,     0,    70,    60,    64,     0,
      59,     0,     0,    50,    48,    80,     0,     0,     0,     0,
      57,    58,     0,     0,     0,     0,    76,     0,    61,     0,
       0,    68,    51,     0,     0,    71,     0,    65,     0,    81,
       0,    62,    74,     0,    77,     0,     0,     0,    63,    82,
       0,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    15,    95,   101,    93,    99,   124,   125,
      12,    13,    40,    92,   106,   113,    38,    91,   104,   112,
     126,   127,   128,   175,   194,   204,   129,   130,   131,   132,
     180,   189,   190,   198,   216,   225,   199,   133,   159,   192,
     134,   162,   197,   135,   157,   181,   171,   185,   214,   227,
     177,   205,   223,   136,   137,    44,    36,    37,   138,   152
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
     -99,    15,    14,   -99,   -99,   -99,   -99,     5,     2,    -2,
     -99,   -99,   -19,   -99,    13,    47,    24,   -99,    38,   -99,
     142,   -99,   142,   -99,   -99,   -99,   -99,   -99,   -99,   142,
      67,    67,   -99,   142,   142,   399,    31,   -99,    19,   433,
      20,   -99,   -99,   -99,    21,   -99,   282,   142,   142,   -99,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   -99,   -99,   142,   142,   142,   142,   142,   -99,   -99,
     -99,   142,   -99,    54,    54,    54,    54,    54,    54,    54,
      54,    12,    12,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     491,     2,     2,    22,   384,    23,    29,    32,   -99,    33,
     -99,    37,   -99,   142,    36,     2,    36,   -99,   -99,   -99,
     -99,   -99,   264,   264,    34,    36,   131,    40,    43,    45,
      52,    53,    68,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   208,   446,   264,   208,
     142,   -99,   -99,   480,   -99,   142,   142,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   208,   -99,   297,   264,   -99,   142,
     316,   331,    -1,   -99,    36,   208,   350,   -99,    69,   -99,
     104,    55,   -99,   -99,    36,   264,   -99,    71,   -99,    36,
      35,    83,   -99,    76,   142,    79,   -99,   -99,   -99,    58,
      35,    70,   264,   -99,   -99,   491,   142,   264,   142,    66,
     -99,   -99,   142,   208,   264,    84,   491,   208,   491,   264,
     365,   -99,   -99,   142,    88,   -99,    74,   264,    93,   491,
     142,   -99,   -99,   101,   491,   264,   142,   102,   264,   491,
     142,   491
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   141,   -87,   -99,    41,   -99,   148,   150,
      -7,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -86,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -37,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -97,   -20,   -99,    39,   -99,   -98,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -16
static const yytype_int16 yytable[] =
{
      35,    16,    39,    17,   169,    97,   109,   170,   111,    41,
       4,     5,     6,    45,    46,     3,   139,   141,   110,    18,
      19,    20,     4,     5,     6,     7,    14,    73,    74,     8,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   154,    21,    86,    87,    88,    89,    90,   187,   188,
     151,    94,    17,   151,    61,    62,    63,    64,    65,    66,
     165,    58,    59,    60,    22,   155,   172,    23,   151,    42,
      43,    67,    26,    68,    70,    71,   182,    98,   100,   151,
     163,   186,   -11,    94,    96,    96,   103,   102,   140,   183,
     105,   173,   148,   108,   144,   203,   143,   145,    96,   146,
     207,    56,    57,    58,    59,    60,   147,   149,   176,   178,
     179,   184,   217,   191,   193,   200,   150,   151,   212,   196,
     156,   151,   209,   213,   202,   160,   161,   220,   228,   211,
     221,   151,   222,   215,    24,    25,    26,    27,    28,   166,
     226,   230,   151,     9,   107,    24,    25,    26,    27,    28,
      10,    29,    11,   201,    30,    31,     0,     0,     0,     0,
      32,     0,    29,     0,   195,    30,    31,     0,     0,     0,
     142,    32,     0,     0,     0,     0,   206,     0,   208,    33,
       0,     0,   210,     0,     0,    34,     0,     0,     0,     0,
      33,     0,     0,   219,     0,     0,    34,     0,     0,     0,
     224,     0,     0,     0,     0,     0,   229,     0,     0,     0,
     231,    24,    25,    26,    27,    28,     4,     5,     6,     0,
     114,     0,     0,     8,   115,     0,     0,     0,    29,     0,
     116,    30,    31,     0,     0,     0,     0,    32,   117,   118,
     119,   120,   121,   122,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,    34,     0,     0,   108,   150,    24,    25,    26,
      27,    28,     4,     5,     6,     0,   114,     0,     0,     8,
     115,     0,     0,     0,    29,     0,   116,    30,    31,     0,
       0,     0,     0,    32,   117,   118,   119,   120,   121,   122,
      47,    48,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,    47,    48,     0,    34,     0,
       0,   108,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    47,    48,     0,    72,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    47,
      48,     0,   164,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    47,    48,
       0,   167,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    47,    48,     0,   168,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    47,    48,     0,   174,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    47,    48,     0,
     218,     0,     0,     0,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,   -15,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
       0,     0,    69,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   153,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,   158,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60
};

static const yytype_int16 yycheck[] =
{
      20,     8,    22,     5,     5,    92,   104,     8,   106,    29,
       8,     9,    10,    33,    34,     0,   113,   115,   105,    21,
      39,    40,     8,     9,    10,    11,    21,    47,    48,    15,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   138,    29,    63,    64,    65,    66,    67,    13,    14,
     136,    71,     5,   139,    23,    24,    25,    26,    27,    28,
     157,    49,    50,    51,    40,   139,   164,    29,   154,    30,
      31,    40,     5,    54,    54,    54,   174,    55,    55,   165,
     154,   179,    53,   103,    91,    92,    53,    55,    54,   175,
      53,   165,    39,    57,    54,   192,   116,    54,   105,    54,
     197,    47,    48,    49,    50,    51,    54,    39,    39,     5,
      55,    40,   209,    30,    38,   189,    58,   203,   204,    40,
     140,   207,    56,    39,    54,   145,   146,    39,   225,   203,
      56,   217,    39,   207,     3,     4,     5,     6,     7,   159,
      39,    39,   228,     2,   103,     3,     4,     5,     6,     7,
       2,    20,     2,   190,    23,    24,    -1,    -1,    -1,    -1,
      29,    -1,    20,    -1,   184,    23,    24,    -1,    -1,    -1,
      39,    29,    -1,    -1,    -1,    -1,   196,    -1,   198,    48,
      -1,    -1,   202,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      48,    -1,    -1,   213,    -1,    -1,    54,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
     230,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      18,    19,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    18,    19,    -1,    54,    -1,
      -1,    57,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    18,    19,    -1,    55,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    18,
      19,    -1,    55,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    18,    19,
      -1,    55,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    18,    19,    -1,    55,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    18,    19,    -1,    55,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    18,    19,    -1,
      55,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,     0,     8,     9,    10,    11,    15,    62,
      67,    68,    69,    70,    21,    62,    69,     5,    21,    39,
      40,    29,    40,    29,     3,     4,     5,     6,     7,    20,
      23,    24,    29,    48,    54,   113,   115,   116,    75,   113,
      71,   113,   115,   115,   114,   113,   113,    18,    19,    39,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    23,    24,    25,    26,    27,    28,    40,    54,    39,
      54,    54,    55,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,    76,    72,    65,   113,    63,    69,    63,    55,    66,
      55,    64,    55,    53,    77,    53,    73,    65,    57,   117,
      63,   117,    78,    74,    12,    16,    22,    30,    31,    32,
      33,    34,    35,    39,    67,    68,    79,    80,    81,    85,
      86,    87,    88,    96,    99,   102,   112,   113,   117,   112,
      54,   117,    39,   113,    54,    54,    54,    54,    39,    39,
      58,    80,   118,    39,   112,   118,   113,   103,    39,    97,
     113,   113,   100,   118,    55,   112,   113,    55,    55,     5,
       8,   105,   117,   118,    55,    82,    39,   109,     5,    55,
      89,   104,   117,    80,    40,   106,   117,    13,    14,    90,
      91,    30,    98,    38,    83,   113,    40,   101,    92,    95,
     118,    90,    54,   112,    84,   110,   113,   112,   113,    56,
     113,   118,    80,    39,   107,   118,    93,   112,    55,   113,
      39,    56,    39,   111,   113,    94,    39,   108,   112,   113,
      39,   113
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
#line 100 "parser.y"
    {       
                                        for(int j=0; j<totalNumberOfScopes; j++){
                                                symbolTable symb= symbolTableList[j];
                                                symbolTableEntry* traverser;
                                                display_symbol_table(j,symb.symbolTable);
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
#line 124 "parser.y"
    { }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {varType = dataTypeEnum::typeInt;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {varType = dataTypeEnum::typeString;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {varType = dataTypeEnum::typeBool;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {
                                                  
                                        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {
                                                 
                                        }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {       
                                                if((yyvsp[(1) - (1)].entry)!=NULL){

                                                        argumentList[argumentListIndex] = (yyvsp[(1) - (1)].entry)->dataType;
                                                         std::string  stringToAdd = "pop r";
                                                         stringToAdd += to_string(argumentListIndex);  
                                                         appendLineToFile(stringToAdd);  
                                                        argumentListIndex++;
                                                }else{
                                                        argumentList[argumentListIndex] = -1;
                                                        argumentListIndex++;      
                                                }
                                        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {
                                                if((yyvsp[(1) - (1)].entry)!=NULL){

                                                        argumentList[argumentListIndex] = (yyvsp[(1) - (1)].entry)->dataType;
                                                        std::string  stringToAdd = "pop r";
                                                         stringToAdd += to_string(argumentListIndex);  
                                                         appendLineToFile(stringToAdd);  
                                                        argumentListIndex++;
                                                }else{
                                                        argumentList[argumentListIndex] = -1;
                                                        argumentListIndex++;      
                                                }
                                        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {
                                              
                                                if((yyvsp[(1) - (2)].entry) !=NULL){
                                                        (yyvsp[(1) - (2)].entry)->entryType = entryTypeEnum::isVariable;
                                                        (yyval.entry)=(yyvsp[(1) - (2)].entry);

                                                }else{
                                                        (yyval.entry)=NULL;  
                                                }
                                                
                                                
                                        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
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

  case 20:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
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

  case 21:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {
                                               
                                                (yyvsp[(2) - (2)].entry) = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,varType);
                                                
                                                if(isFunctionParam == true){
                                                        (yyvsp[(2) - (2)].entry)->entryType = entryTypeEnum::isParameter;
                                                        paramList[paramListIndex] = varType;
                                                        std::string  stringToAdd = "mov r";
                                                        stringToAdd +=  to_string(paramListIndex);
                                                        stringToAdd += " , ";  
                                                        stringToAdd += (yyvsp[(2) - (2)].entry)->lexeme;
                                                        appendLineToFile(stringToAdd); 
                                                        paramListIndex++;
                                                        (yyvsp[(2) - (2)].entry)->isInitialized = true;
                                                }               
                                                (yyval.entry) = (yyvsp[(2) - (2)].entry);
                                                                                             
                                        }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {
                                                isFunctionParam=true;
                                                (yyvsp[(3) - (3)].entry) = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,varType); 
                                                (yyvsp[(3) - (3)].entry)->entryType = entryTypeEnum::isFunction; 
                                                std::string temp = (yyvsp[(3) - (3)].entry)->lexeme;
                                                temp+=":";
                                                appendLineToFile(temp);    
                                                                                                                           
                                        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {       
                                                currentScope = createNewScope();
                                                isBracketScope = true;
                                        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
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

  case 25:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    {       
                                                functionDataType = (yyvsp[(3) - (10)].entry)->dataType;
                                                isBracketScope = false;
                                        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    {
                                           (yyval.entry) = (yyvsp[(3) - (13)].entry);
                                        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {        
                                                (yyvsp[(3) - (3)].entry) = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,dataTypeEnum::typeVoid); 
                                                (yyvsp[(3) - (3)].entry)->entryType = entryTypeEnum::isFunction;
                                                isFunctionParam=true;
                                                std::string temp = (yyvsp[(3) - (3)].entry)->lexeme;
                                                temp+=":";
                                                appendLineToFile(temp);  
                                               
                                        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {
                                                isBracketScope = true;  
                                                currentScope = createNewScope();
                                        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
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

  case 30:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    {       functionDataType = dataTypeEnum::typeVoid;
                                                isBracketScope = false;
                                        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {
                                                (yyval.entry) = (yyvsp[(3) - (13)].entry);
                                        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    { }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    { }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    { }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 317 "parser.y"
    { }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    { }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    { }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    { }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 322 "parser.y"
    { }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    { }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    { }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 327 "parser.y"
    { }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 330 "parser.y"
    {       
                                                        createLabel(labelType::ifLabel);
                                                        std::string temp = "JNZ L";
                                                        temp+= to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                        appendLineToFile(temp);
                                                        temp = "JMP L";
                                                        temp+= to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                        appendLineToFile(temp);
                                                        temp = "L";
                                                        temp+= to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                        temp+=':';
                                                        appendLineToFile(temp);  
                                                }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 343 "parser.y"
    {
                                                        deleteLabel();
                                                }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 348 "parser.y"
    {
                                                        /*TODO:CHECK BOOL EXPRESSION*/
                                                        std::string temp = "L";
                                                        temp+= to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                        temp+=':';
                                                        appendLineToFile(temp);
                                                }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {
                                                        /*TODO:CHECK BOOL EXPRESSION*/
                                                        std::string temp = "L";
                                                        temp+= to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                        temp+=':';
                                                        appendLineToFile(temp);
                                                }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 363 "parser.y"
    {/*TODO:CHECK BOOL EXPRESSION*/}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
    {
                                                         if (functionDataType!=(yyvsp[(2) - (3)].entry)->dataType){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                        }

                                                        std::string stringToAdd = "pop ";
                                                        stringToAdd += "R0";
                                                        appendLineToFile(stringToAdd);
                                                        stringToAdd = "pop ";
                                                        stringToAdd += "R1";
                                                        appendLineToFile(stringToAdd); 
                                                        stringToAdd = "push ";
                                                        stringToAdd += "R0";
                                                        appendLineToFile(stringToAdd); 
                                                        stringToAdd = "push ";
                                                        stringToAdd += "R1";
                                                        appendLineToFile(stringToAdd); 
                                                        stringToAdd = "ret ";
                                                        appendLineToFile(stringToAdd); 
                                                }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 387 "parser.y"
    {
                                                        if (functionDataType!=dataTypeEnum::typeVoid){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                        }else{
                                                                std::string stringToAdd = "ret ";
                                                                appendLineToFile(stringToAdd);
                                                        } 
                                                }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 397 "parser.y"
    {
                                                        if(!isForScope && !isSwitchScope){
                                                               
                                                                appendErrorToFile("Break couldn't be called outside the scope of a loop/switch at line "+ to_string(yylineno)); 
                                                                        
                                                        }else{
                                                                std::string temp = "JMP L";
                                                                if(labels.labelBlocks[labels.currentIndex]->type == labelType::forLabel){
                                                                        temp += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[3]);
                                                                }else if(labels.labelBlocks[labels.currentIndex]->type == labelType::switchLabel){
                                                                        temp += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[19]);
                                                                }else{
                                                                         temp += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                                }
                                                                appendLineToFile(temp);
                                                        }
                                                }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 416 "parser.y"
    { 
                                                        if(!isForScope){
                                                                appendErrorToFile("Continue couldn't be called outside the scope of a loop/switch at line "+ to_string(yylineno)); 
                                                                
                                                        }else{
                                                                std::string temp = "JMP L";
                                                                temp+= to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                                appendLineToFile(temp);
                                                        }
                                                }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 428 "parser.y"
    {
                                                
                                                if((yyvsp[(3) - (5)].entry)->entryType != entryTypeEnum::isVariable){
                                                        
                                                        appendErrorToFile("Switch must take a variable at line "+ to_string(yylineno)); 
                                                }
                                                
                                                createLabel(labelType::switchLabel);
                                               
                                                labels.labelBlocks[labels.currentIndex]->switchType = (yyvsp[(3) - (5)].entry)->dataType;
                                                isSwitchScope = true;
                                                switchDataType = (yyvsp[(3) - (5)].entry)->dataType;
                                                
                                        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 442 "parser.y"
    {
                                                int caseNumer = getCurrentCaseLabel();
                                
                                                std::string stringToAdd = "L";
                                                stringToAdd+=to_string(caseNumer);
                                                stringToAdd+=":";
                                                appendLineToFile(stringToAdd);
                                                stringToAdd = "L";
                                                stringToAdd+=to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[19]);
                                                stringToAdd+=":";
                                                appendLineToFile(stringToAdd);
                                                deleteLabel();
                                                isSwitchScope = false;
                                        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 462 "parser.y"
    { 
                                                int caseNumer = getCurrentCaseLabel();
                                
                                                std::string stringToAdd = "L";
                                                stringToAdd+=to_string(caseNumer);
                                                stringToAdd+=":";
                                                appendLineToFile(stringToAdd);
                                        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 470 "parser.y"
    {
     
                                                if((yyvsp[(3) - (3)].entry)!=NULL &&(yyvsp[(3) - (3)].entry)->dataType != labels.labelBlocks[labels.currentIndex]->switchType){
                                                        appendErrorToFile("Type mismatch at line "+ to_string(yylineno)); 

                                                }else{

                                                int nextCaseNumber = getNextCaseLabel();
                                                
                                                std::string stringToAdd = "cmpEQ ";
                                                appendLineToFile(stringToAdd);
                                                stringToAdd = "JZ L";
                                                stringToAdd+= to_string(nextCaseNumber);
                                                appendLineToFile(stringToAdd);
                                                }
                                        
  
                                      }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 488 "parser.y"
    {
                                       
                                  }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 491 "parser.y"
    {
                                        
                                  }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 494 "parser.y"
    {
                                                if(labels.labelBlocks[labels.currentIndex]->hasDefault==0){
                                                        std::string stringToAdd = "L";
                                                        int caseNumer = getCurrentCaseLabel();
                                                        stringToAdd+=to_string(caseNumer);
                                                        stringToAdd+=":";
                                                        appendLineToFile(stringToAdd);
                                                        labels.labelBlocks[labels.currentIndex]->hasDefault=1;
                                                }else{
                                                        appendErrorToFile("Switch can't have more than one default at line "+ to_string(yylineno)); 
                                                }
                                        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 508 "parser.y"
    {}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 510 "parser.y"
    {    
                                                                        createLabel(labelType::whileLabel);
                                                                        currentScope = createNewScope();
                                                                        isBracketScope = true;
                                                                        std::string stringToAdd = "L";
                                                                        stringToAdd += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                                        startLabel = labelNumber;
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 520 "parser.y"
    {
                                                                        isForScope = true;
                                                                        isBracketScope = false;
                                                                        std::string stringToAdd = "JZ ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                                        appendLineToFile(stringToAdd);
                                                                              
                                                                }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 529 "parser.y"
    {
                                                                        std::string stringToAdd = "JMP ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "L";
                                                                        stringToAdd += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        deleteLabel();
                                                                              
                                                                }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 543 "parser.y"
    {       
                                                                        createLabel(labelType::forLabel);
                                                                        
                                                                        currentScope = createNewScope();
                                                                        isBracketScope = true;
                                                                         
                                                                        
                                                                }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 551 "parser.y"
    {
                                                                
                                                                        std::string temp ="L"+ to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[2]);
                                                                        temp+=":";
                                                                        appendLineToFile(temp); 
                                                                        isForScope = true;
                                                                        isBracketScope = false;   
                                                                        endLabel = labelNumber;
                                                                }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 560 "parser.y"
    {       
                                                                        
                                                                        std::string stringToAdd = "JMP ";
                                                                        stringToAdd +="L"+to_string( labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                                        appendLineToFile(stringToAdd);
                                                                        std::string temp = "L"+to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[3]);
                                                                        temp+=":";
                                                                        appendLineToFile(temp);   
                                                                        deleteLabel();
                                                                }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 572 "parser.y"
    {       createLabel(labelType::doLabel);
                                                                        isClosedBracketScope = true;
                                                                        isForScope = true;
                                                                        startLabel = labelNumber;
                                                                        std::string stringToAdd = "L";
                                                                        stringToAdd += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);            
                                                                }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 581 "parser.y"
    {
                                                                        isClosedBracketScope = false;        
                                                                        
                                                                }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 585 "parser.y"
    {      
                                                                        std::string stringToAdd = "JNZ ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                                        appendLineToFile(stringToAdd);  

                                                                        stringToAdd = "L";
                                                                        stringToAdd += to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        deleteLabel();          
                                                                }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 599 "parser.y"
    {
                                                (yyvsp[(2) - (2)].entry) = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,dataTypeEnum::typeInt);
                                                (yyvsp[(2) - (2)].entry)->isInitialized = true;
                                                
                                                
                                       }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 605 "parser.y"
    {
                                                std::string stringToAdd = "pop ";
                                                stringToAdd += (yyvsp[(2) - (5)].entry)->lexeme;
                                                appendLineToFile(stringToAdd); 
                                                // stringToAdd = "JMP L";
                                                // stringToAdd += to_string(labelNumber+1);
                                                // appendLineToFile(stringToAdd); 
                                                std::string temp = "L"+to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                temp+=":";
                                                appendLineToFile(temp);  

                                        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 617 "parser.y"
    {
                                                
                                                std::string stringToAdd = "JNZ ";
                                                stringToAdd +="L"+ to_string( labels.labelBlocks[labels.currentIndex]->labelsNames[2]);
                                                appendLineToFile(stringToAdd); 
                                                stringToAdd = "JMP ";
                                                stringToAdd +="L"+ to_string( labels.labelBlocks[labels.currentIndex]->labelsNames[3]);
                                                appendLineToFile(stringToAdd); 
                                                std::string temp = "L"+to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                temp+=":";
                                                appendLineToFile(temp);  
                                                
                                        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 631 "parser.y"
    {
                                                std::string stringToAdd = "JMP ";
                                                stringToAdd += "L"+to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                appendLineToFile(stringToAdd);
                                                
                                        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 637 "parser.y"
    {
                                                (yyvsp[(1) - (1)].entry) = isAvailable(yylval.stringValue);
                                                if((yyvsp[(1) - (1)].entry)==NULL){
                                                        std::string temp = yylval.stringValue;
                                                        appendErrorToFile("Variable"+temp+ " not declared, at line "+ to_string(yylineno));
          
                                                }else if((yyvsp[(1) - (1)].entry)->entryType != entryTypeEnum::isVariable){
                                                       std::string temp = yylval.stringValue;
                                                        appendErrorToFile("Variable"+temp+ " is const, cant be assigned, at line "+ to_string(yylineno));
                                                }else{
                                                          (yyvsp[(1) - (1)].entry)->isInitialized = true;
                                                }
                                        }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 650 "parser.y"
    {
                                                std::string stringToAdd = "pop ";
                                                stringToAdd += (yyvsp[(1) - (4)].entry)->lexeme;
                                                appendLineToFile(stringToAdd); 
                                                // stringToAdd = "JMP L";
                                                // stringToAdd += to_string(labelNumber+1);
                                                // appendLineToFile(stringToAdd); 
                                                std::string temp = "L"+to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                temp+=":";
                                                appendLineToFile(temp);  
                                        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 664 "parser.y"
    {
                
                                                
                                                std::string stringToAdd = "JNZ ";
                                                stringToAdd +="L"+ to_string( labels.labelBlocks[labels.currentIndex]->labelsNames[2]);
                                                appendLineToFile(stringToAdd); 
                                                stringToAdd = "JMP ";
                                                stringToAdd +="L"+ to_string( labels.labelBlocks[labels.currentIndex]->labelsNames[3]);
                                                appendLineToFile(stringToAdd); 
                                                std::string temp = "L"+to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[1]);
                                                temp+=":";
                                                appendLineToFile(temp);  
                                                
                                        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 680 "parser.y"
    {
                                                std::string stringToAdd = "JMP ";
                                                stringToAdd += "L"+to_string(labels.labelBlocks[labels.currentIndex]->labelsNames[0]);
                                                appendLineToFile(stringToAdd);
                                        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 687 "parser.y"
    { }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 688 "parser.y"
    { }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 691 "parser.y"
    {       
                                                        if((yyvsp[(1) - (3)].entry)!=NULL){
                                                                if((yyvsp[(1) - (3)].entry)->dataType != (yyvsp[(3) - (3)].entry)->dataType){
                                                                        appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                                }else if((yyvsp[(1) - (3)].entry)->entryType != entryTypeEnum::isVariable){
                                                                                std::string temp = yylval.stringValue;
                                                                                appendErrorToFile("Variable"+temp+ " is const, cant be assigned, at line "+ to_string(yylineno));
                                                                }else {
                                                                        (yyvsp[(1) - (3)].entry)->isInitialized = true;
                                                                        std::string stringToAdd = "pop ";
                                                                        stringToAdd += (yyvsp[(1) - (3)].entry)->lexeme;
                                                                        appendLineToFile(stringToAdd);                                                                      
                                                                }

                                                        }
                                                        
                                                        (yyval.entry)=(yyvsp[(1) - (3)].entry);
                                                        
                                                }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 710 "parser.y"
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

  case 87:

/* Line 1455 of yacc.c  */
#line 722 "parser.y"
    {
                                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                                }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 726 "parser.y"
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

  case 89:

/* Line 1455 of yacc.c  */
#line 741 "parser.y"
    { 

                                                        (yyvsp[(1) - (1)].entry) = isAvailable(yylval.stringValue);
                                                        if((yyvsp[(1) - (1)].entry)==NULL)
                                                        {       std::string temp = yylval.stringValue;
                                                                std::string error = "Function" + temp +" not defined at line " + to_string(yylineno);
                                                                appendErrorToFile(error);
                                                                
                                                        }
                                                           
                                                                     
                                                }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 753 "parser.y"
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
                                                        std::string  stringToAdd = "call ";
                                                         stringToAdd += (yyvsp[(1) - (5)].entry)->lexeme;  
                                                         appendLineToFile(stringToAdd);  
                                                        argumentListIndex=0;
                                                
                                                }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 780 "parser.y"
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

  case 92:

/* Line 1455 of yacc.c  */
#line 800 "parser.y"
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

  case 93:

/* Line 1455 of yacc.c  */
#line 818 "parser.y"
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

  case 94:

/* Line 1455 of yacc.c  */
#line 833 "parser.y"
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

  case 95:

/* Line 1455 of yacc.c  */
#line 849 "parser.y"
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

  case 96:

/* Line 1455 of yacc.c  */
#line 870 "parser.y"
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

  case 97:

/* Line 1455 of yacc.c  */
#line 890 "parser.y"
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

  case 98:

/* Line 1455 of yacc.c  */
#line 906 "parser.y"
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

  case 99:

/* Line 1455 of yacc.c  */
#line 925 "parser.y"
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

  case 100:

/* Line 1455 of yacc.c  */
#line 943 "parser.y"
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

  case 101:

/* Line 1455 of yacc.c  */
#line 960 "parser.y"
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

  case 102:

/* Line 1455 of yacc.c  */
#line 996 "parser.y"
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

  case 103:

/* Line 1455 of yacc.c  */
#line 1028 "parser.y"
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
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += (yyvsp[(3) - (3)].entry)->lexeme;
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

  case 104:

/* Line 1455 of yacc.c  */
#line 1062 "parser.y"
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

  case 105:

/* Line 1455 of yacc.c  */
#line 1092 "parser.y"
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

  case 106:

/* Line 1455 of yacc.c  */
#line 1130 "parser.y"
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

  case 107:

/* Line 1455 of yacc.c  */
#line 1168 "parser.y"
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

  case 108:

/* Line 1455 of yacc.c  */
#line 1204 "parser.y"
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

  case 109:

/* Line 1455 of yacc.c  */
#line 1239 "parser.y"
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

  case 110:

/* Line 1455 of yacc.c  */
#line 1259 "parser.y"
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

  case 111:

/* Line 1455 of yacc.c  */
#line 1279 "parser.y"
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

  case 112:

/* Line 1455 of yacc.c  */
#line 1298 "parser.y"
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

  case 113:

/* Line 1455 of yacc.c  */
#line 1318 "parser.y"
    {(yyval.entry)=(yyvsp[(2) - (3)].entry);}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1320 "parser.y"
    {  
                                        (yyvsp[(1) - (1)].entry) = isAvailable(yylval.stringValue);
                                        if((yyvsp[(1) - (1)].entry)==NULL){
                                                
                                                std::string temp = yylval.stringValue;
                                                appendErrorToFile("Variable "+temp+" not declared in scope at line "+ to_string(yylineno)); 
                                                                        
                                                (yyval.entry)=NULL;
                                        }else{
                                               
                                                // if(!$1->isInitialized){
                                                //         notInitialized=true;
                                                // }
                                                (yyval.entry) = (yyvsp[(1) - (1)].entry);     
                                        }

                                        
                                        
                                }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1341 "parser.y"
    { 

                                        (yyvsp[(1) - (1)].entry) = createEntry(yylval.stringValue, dataTypeEnum::typeInt);
                                        (yyvsp[(1) - (1)].entry)->entryType = entryTypeEnum::isConstant;
                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                        std::string stringToAdd = "push ";
                                        stringToAdd += yylval.stringValue;
                                        appendLineToFile(stringToAdd);
                                }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1350 "parser.y"
    {
                                        (yyvsp[(1) - (1)].entry) = createEntry(yylval.stringValue, dataTypeEnum::typeString);
                                        (yyvsp[(1) - (1)].entry)->entryType = entryTypeEnum::isConstant;
                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                        std::string stringToAdd = "push ";
                                        stringToAdd += yylval.stringValue ;
                                        appendLineToFile(stringToAdd);
                                }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1358 "parser.y"
    {
                                        (yyvsp[(1) - (1)].entry) = createEntry(yylval.stringValue, dataTypeEnum::typeBool);
                                        (yyvsp[(1) - (1)].entry)->entryType = entryTypeEnum::isConstant;
                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                        std::string stringToAdd = "push 0";
                                        appendLineToFile(stringToAdd);
                                }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1365 "parser.y"
    {
                                        (yyvsp[(1) - (1)].entry) = createEntry(yylval.stringValue, dataTypeEnum::typeBool);
                                        (yyvsp[(1) - (1)].entry)->entryType = entryTypeEnum::isConstant;
                                        (yyval.entry)=(yyvsp[(1) - (1)].entry);
                                        std::string stringToAdd = "push 1";
                                        appendLineToFile(stringToAdd);
                                }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1375 "parser.y"
    {
                                       
                                        if(!isBracketScope){
                                                currentScope = createNewScope();
                                        }
                                      
                                }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1382 "parser.y"
    {
                                        if(!isClosedBracketScope){
                                             currentScope = exitScope();   
                                        }
                                        
                                }
    break;



/* Line 1455 of yacc.c  */
#line 3613 "y.tab.c"
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
#line 1388 "parser.y"


void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

#define LEN 256
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
void createLabel(labelType type){
        labels.currentIndex++;
        labels.labelBlocks[labels.currentIndex] =  (label*) malloc(sizeof(label));
        labels.labelBlocks[labels.currentIndex]->type = type;
        
        if(type == labelType::forLabel){

                for(int i =0; i< 4;i++){
                        
                        labels.labelBlocks[labels.currentIndex]->labelsNames[i] = labelNumber; 
                        labelNumber++;
                }
        }else if(type == labelType::switchLabel){
                for(int i =0; i< 20;i++){
                        labels.labelBlocks[labels.currentIndex]->labelsNames[i] = labelNumber; 
                        labelNumber++;
                        
                }
        }
        else if(type == labelType::ifLabel){
                for(int i =0; i< 2;i++){
                        labels.labelBlocks[labels.currentIndex]->labelsNames[i] = labelNumber; 
                        labelNumber++;
                }
        }else if(type == labelType::whileLabel){
                for(int i =0; i< 2;i++){
                        labels.labelBlocks[labels.currentIndex]->labelsNames[i] = labelNumber; 
                        labelNumber++; 
                }
        }else{
                for(int i =0; i< 2;i++){
                        labels.labelBlocks[labels.currentIndex]->labelsNames[i] = labelNumber; 
                        labelNumber++; 
                }
        }
}
int getNextCaseLabel(){
        if(labels.labelBlocks[labels.currentIndex]->type !=  labelType::switchLabel)
                return -1;
     
        return labels.labelBlocks[labels.currentIndex]->labelsNames[++labels.labelBlocks[labels.currentIndex]->currentSwitchLabel];

}
int getCurrentCaseLabel(){
        if(labels.labelBlocks[labels.currentIndex]->type !=  labelType::switchLabel)
                return -1;
        return labels.labelBlocks[labels.currentIndex]->labelsNames[labels.labelBlocks[labels.currentIndex]->currentSwitchLabel];

}
void deleteLabel(){
        free(labels.labelBlocks[labels.currentIndex]);
        labels.labelBlocks[labels.currentIndex] = NULL;
        labels.currentIndex--;
        if(labels.currentIndex==-1)
                isForScope = false;
        
}
int main (int argc, char *argv[]){
	// parsing
        std::ofstream file1;
        file1.open ("./error.txt", std::ios::out);
        file1<<"";
        std::ofstream file2;
        file2.open ("./output.txt", std::ios::out);
        file2<<"";
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
        //display_symbol_table(symbolTableList[2].symbolTable);

}
