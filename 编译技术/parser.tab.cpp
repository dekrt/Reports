/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     ID = 259,
     TYPE = 260,
     FLOAT = 261,
     DPLUS = 262,
     DMINUS = 263,
     PLUSD = 264,
     MINUSD = 265,
     LP = 266,
     RP = 267,
     LB = 268,
     RB = 269,
     LC = 270,
     RC = 271,
     SEMI = 272,
     COMMA = 273,
     PLUS = 274,
     MINUS = 275,
     STAR = 276,
     DIV = 277,
     MOD = 278,
     GE = 279,
     GT = 280,
     LE = 281,
     LT = 282,
     NE = 283,
     EQ = 284,
     ASSIGN = 285,
     AND = 286,
     OR = 287,
     NOT = 288,
     IF = 289,
     ELSE = 290,
     WHILE = 291,
     RETURN = 292,
     FOR = 293,
     BREAK = 294,
     CONTINUE = 295,
     SWITCH = 296,
     CASE = 297,
     DEFAULT = 298,
     COLON = 299,
     ARRPRO = 300,
     EXT_DEF_LIST = 301,
     EXT_VAR_DEF = 302,
     FUNC_DEF = 303,
     FUNC_DEC = 304,
     EXT_DEC_LIST = 305,
     PARAM_LIST = 306,
     PARAM_DEC = 307,
     VAR_DEF = 308,
     DEC_LIST = 309,
     DEF_LIST = 310,
     COMP_STM = 311,
     STM_LIST = 312,
     EXP_STMT = 313,
     IF_THEN = 314,
     IF_THEN_ELSE = 315,
     FUNC_CALL = 316,
     ARGS = 317,
     FUNCTION = 318,
     PARAM = 319,
     ARG = 320,
     CALL = 321,
     CALL0 = 322,
     LABEL = 323,
     GOTO = 324,
     JLT = 325,
     JLE = 326,
     JGT = 327,
     JGE = 328,
     JEQ = 329,
     JNE = 330,
     END = 331,
     ARRASSIGN = 332,
     ARRLOAD = 333,
     ARRDPLUS = 334,
     ARRDMINUS = 335,
     ARRPLUSD = 336,
     ARRMINUSD = 337,
     UPLUS = 338,
     UMINUS = 339,
     LOWER_THEN_ELSE = 340
   };
#endif
/* Tokens.  */
#define INT 258
#define ID 259
#define TYPE 260
#define FLOAT 261
#define DPLUS 262
#define DMINUS 263
#define PLUSD 264
#define MINUSD 265
#define LP 266
#define RP 267
#define LB 268
#define RB 269
#define LC 270
#define RC 271
#define SEMI 272
#define COMMA 273
#define PLUS 274
#define MINUS 275
#define STAR 276
#define DIV 277
#define MOD 278
#define GE 279
#define GT 280
#define LE 281
#define LT 282
#define NE 283
#define EQ 284
#define ASSIGN 285
#define AND 286
#define OR 287
#define NOT 288
#define IF 289
#define ELSE 290
#define WHILE 291
#define RETURN 292
#define FOR 293
#define BREAK 294
#define CONTINUE 295
#define SWITCH 296
#define CASE 297
#define DEFAULT 298
#define COLON 299
#define ARRPRO 300
#define EXT_DEF_LIST 301
#define EXT_VAR_DEF 302
#define FUNC_DEF 303
#define FUNC_DEC 304
#define EXT_DEC_LIST 305
#define PARAM_LIST 306
#define PARAM_DEC 307
#define VAR_DEF 308
#define DEC_LIST 309
#define DEF_LIST 310
#define COMP_STM 311
#define STM_LIST 312
#define EXP_STMT 313
#define IF_THEN 314
#define IF_THEN_ELSE 315
#define FUNC_CALL 316
#define ARGS 317
#define FUNCTION 318
#define PARAM 319
#define ARG 320
#define CALL 321
#define CALL0 322
#define LABEL 323
#define GOTO 324
#define JLT 325
#define JLE 326
#define JGT 327
#define JGE 328
#define JEQ 329
#define JNE 330
#define END 331
#define ARRASSIGN 332
#define ARRLOAD 333
#define ARRDPLUS 334
#define ARRDMINUS 335
#define ARRPLUSD 336
#define ARRMINUSD 337
#define UPLUS 338
#define UMINUS 339
#define LOWER_THEN_ELSE 340




/* Copy the first part of user declarations.  */
#line 4 "parser.ypp"

#include "def.h"
extern int ErrorCharNum;
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
extern "C" int yylex();
#define SavePosition t->Line=yylloc.first_line;t->Column=yylloc.first_column
typedef struct YYLVAL {
       int                  type_int;
	float                type_float;
	char                 type_id[32];

	ProgAST                     *program;
	vector <ExtDefAST *>        ExtDefList;  	    //外部定义（外部变量、函数）列表
       ExtDefAST                   *ExtDef;
       vector <VarDecAST*>         ExtDecList;        //外部、局部变量列表
       TypeAST                     *Specifier;
       VarDecAST                   *VarDec;
       CompStmAST                  *CompSt;
	vector <ParamAST *>         ParamList;         //形参列表
	ParamAST                    *ParamDec;

	vector <StmAST *>           StmList;
	StmAST                      *Stmt;
	vector <DefAST *>           DefList;
	DefAST                      *Def;
       vector <VarDecAST *>        DecList;
       VarDecAST                   *Dec;
       ExpAST                      *Exp;
	vector <ExpAST *>           Args;       	       //实参列表
       CaseStmAST                  *Case;
       vector <CaseStmAST *>       CaseList;
}YYLVAL;
#define YYSTYPE YYLVAL



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 327 "parser.tab.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   587

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    13,    20,    27,    29,
      31,    35,    37,    42,    44,    45,    47,    51,    54,    59,
      60,    63,    64,    67,    71,    73,    77,    79,    83,    88,
      90,    93,    96,    98,   102,   105,   111,   119,   125,   135,
     143,   154,   157,   160,   163,   167,   171,   175,   179,   183,
     187,   191,   194,   197,   201,   205,   208,   212,   216,   220,
     224,   228,   232,   235,   238,   241,   244,   249,   251,   254,
     256,   258,   259,   261,   265,   269,   271
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      87,     0,    -1,    88,    -1,    -1,    89,    88,    -1,    90,
      91,    17,    -1,    90,     4,    11,    94,    12,    96,    -1,
      90,     4,    11,    94,    12,    17,    -1,     5,    -1,    92,
      -1,    92,    18,    91,    -1,     4,    -1,    92,    13,     3,
      14,    -1,     4,    -1,    -1,    95,    -1,    94,    18,    95,
      -1,    90,    93,    -1,    15,    98,    97,    16,    -1,    -1,
     104,    97,    -1,    -1,    99,    98,    -1,    90,   100,    17,
      -1,   101,    -1,   101,    18,   100,    -1,    92,    -1,    92,
      30,   105,    -1,    42,   105,    44,    97,    -1,   102,    -1,
     102,   103,    -1,   105,    17,    -1,    96,    -1,    37,   105,
      17,    -1,    37,    17,    -1,    34,    11,   105,    12,   104,
      -1,    34,    11,   105,    12,   104,    35,   104,    -1,    36,
      11,   105,    12,   104,    -1,    38,    11,   105,    17,   105,
      17,   105,    12,   104,    -1,    41,    11,   105,    12,    15,
     103,    16,    -1,    41,    11,   105,    12,    15,   103,    43,
      44,    97,    16,    -1,    39,    17,    -1,    40,    17,    -1,
       1,    17,    -1,   105,    30,   105,    -1,   105,    19,   105,
      -1,   105,    20,   105,    -1,   105,    21,   105,    -1,   105,
      22,   105,    -1,   105,    23,   105,    -1,    11,   105,    12,
      -1,    20,   105,    -1,    19,   105,    -1,   105,    31,   105,
      -1,   105,    32,   105,    -1,    33,   105,    -1,   105,    25,
     105,    -1,   105,    24,   105,    -1,   105,    27,   105,    -1,
     105,    26,   105,    -1,   105,    28,   105,    -1,   105,    29,
     105,    -1,     7,   105,    -1,     8,   105,    -1,   105,     7,
      -1,   105,     8,    -1,     4,    11,   106,    12,    -1,     4,
      -1,     4,   108,    -1,     3,    -1,     6,    -1,    -1,   105,
      -1,   106,    18,   105,    -1,    13,   105,    14,    -1,   107,
      -1,   108,   107,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   102,   102,   112,   113,   116,   118,   119,   121,   127,
     128,   130,   131,   133,   136,   137,   138,   140,   143,   145,
     146,   148,   149,   151,   153,   154,   156,   157,   160,   162,
     163,   165,   166,   167,   168,   169,   170,   171,   172,   174,
     175,   177,   178,   179,   182,   185,   186,   187,   188,   189,
     190,   191,   192,   194,   195,   196,   198,   199,   200,   201,
     202,   203,   206,   207,   208,   209,   212,   213,   214,   215,
     216,   218,   219,   220,   223,   225,   226
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "ID", "TYPE", "FLOAT", "DPLUS",
  "DMINUS", "PLUSD", "MINUSD", "LP", "RP", "LB", "RB", "LC", "RC", "SEMI",
  "COMMA", "PLUS", "MINUS", "STAR", "DIV", "MOD", "GE", "GT", "LE", "LT",
  "NE", "EQ", "ASSIGN", "AND", "OR", "NOT", "IF", "ELSE", "WHILE",
  "RETURN", "FOR", "BREAK", "CONTINUE", "SWITCH", "CASE", "DEFAULT",
  "COLON", "ARRPRO", "EXT_DEF_LIST", "EXT_VAR_DEF", "FUNC_DEF", "FUNC_DEC",
  "EXT_DEC_LIST", "PARAM_LIST", "PARAM_DEC", "VAR_DEF", "DEC_LIST",
  "DEF_LIST", "COMP_STM", "STM_LIST", "EXP_STMT", "IF_THEN",
  "IF_THEN_ELSE", "FUNC_CALL", "ARGS", "FUNCTION", "PARAM", "ARG", "CALL",
  "CALL0", "LABEL", "GOTO", "JLT", "JLE", "JGT", "JGE", "JEQ", "JNE",
  "END", "ARRASSIGN", "ARRLOAD", "ARRDPLUS", "ARRDMINUS", "ARRPLUSD",
  "ARRMINUSD", "UPLUS", "UMINUS", "LOWER_THEN_ELSE", "$accept", "program",
  "ExtDefList", "ExtDef", "Specifier", "ExtDecList", "VarDec",
  "ParamVarDec", "ParamList", "ParamDec", "CompSt", "StmList", "DefList",
  "Def", "DecList", "Dec", "Case", "CaseList", "Stmt", "Exp", "Args",
  "Sub", "SubList", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    89,    90,    91,
      91,    92,    92,    93,    94,    94,    94,    95,    96,    97,
      97,    98,    98,    99,   100,   100,   101,   101,   102,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   107,   108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     6,     6,     1,     1,
       3,     1,     4,     1,     0,     1,     3,     2,     4,     0,
       2,     0,     2,     3,     1,     3,     1,     3,     4,     1,
       2,     2,     1,     3,     2,     5,     7,     5,     9,     7,
      10,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     4,     1,     2,     1,
       1,     0,     1,     3,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     8,     0,     2,     3,     0,     1,     4,    11,     0,
       9,    14,     5,     0,     0,     0,     0,    15,     0,    11,
      10,    13,    17,     0,     0,    12,    21,     7,     6,    16,
       0,     0,    21,    26,     0,    24,     0,    69,    67,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,    22,     0,    23,
       0,    43,    71,     0,    75,    68,    62,    63,     0,    52,
      51,    55,     0,     0,    34,     0,     0,    41,    42,     0,
      18,    20,    64,    65,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      25,    72,     0,     0,    76,    50,     0,     0,    33,     0,
       0,    45,    46,    47,    48,    49,    57,    56,    59,    58,
      60,    61,    44,    53,    54,    66,     0,    74,     0,     0,
       0,     0,    73,    35,    37,     0,     0,     0,     0,     0,
      29,     0,    36,     0,     0,    30,    39,     0,     0,     0,
       0,    38,    28,     0,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     9,    10,    22,    16,    17,
      53,    54,    31,    32,    34,    35,   140,   141,    55,    56,
     102,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
       5,   -67,    17,   -67,     5,    56,   -67,   -67,    50,    51,
      46,     5,   -67,    66,    70,    74,    12,   -67,    77,   -67,
     -67,   -67,   -67,    14,     5,   -67,     5,   -67,   -67,   -67,
      70,   112,     5,    -4,    75,    65,    76,   -67,    54,   -67,
     206,   206,   206,   206,   206,   206,    83,    84,     8,    85,
      80,    87,   103,   -67,   101,    69,   221,   -67,   206,   -67,
      70,   -67,   206,   206,   -67,   111,    35,    35,   247,    35,
      35,    35,   206,   206,   -67,   273,   206,   -67,   -67,   206,
     -67,   -67,   -67,   -67,   -67,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   481,
     -67,   481,    26,   299,   -67,   -67,   325,   351,   -67,   377,
     403,    13,    13,    35,    35,   211,   558,   558,   558,   558,
     155,   155,   507,   114,   533,   -67,   206,   -67,   153,   153,
     206,   110,   481,    91,   -67,   429,    88,   153,   206,   206,
      88,    -3,   -67,   455,   176,   -67,   -67,   100,   153,    69,
     112,   -67,   -67,   113,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   143,   -67,    55,   141,   -23,   -67,   -67,   134,
     142,   -49,   135,   -67,   106,   -67,   -67,    29,   -66,   -40,
     -67,   105,   -67
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -20
static const yytype_int16 yytable[] =
{
      66,    67,    68,    69,    70,    71,    81,    33,    75,    13,
       1,    37,    38,   146,    39,    40,    41,     6,    99,    42,
      82,    83,   101,   103,    23,    74,    58,    43,    44,    26,
      24,    27,   106,   107,    87,    88,   109,    33,   125,   110,
     147,    45,    82,    83,   126,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    13,
       8,    11,   133,   134,    14,    62,    15,    63,    12,    18,
      36,   142,    37,    38,    19,    39,    40,    41,    21,    15,
      42,    30,   151,    60,    26,   -19,   132,    30,    43,    44,
     135,    25,    59,    61,    72,    73,    76,    77,   143,   144,
     152,   153,    45,    46,    78,    47,    48,    49,    50,    51,
      52,   -19,   -19,    36,    79,    37,    38,    80,    39,    40,
      41,    82,    83,    42,    63,   136,   137,    26,   -19,   154,
     139,    43,    44,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   150,    45,    46,     7,    47,    48,
      49,    50,    51,    52,    36,    20,    37,    38,    29,    39,
      40,    41,    82,    83,    42,    28,   100,    57,    26,   145,
     104,     0,    43,    44,    85,    86,    87,    88,    89,     0,
       0,     0,     0,    82,    83,     0,    45,    46,     0,    47,
      48,    49,    50,    51,    52,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    37,
      38,     0,    39,    40,    41,     0,     0,    42,    82,    83,
     149,     0,     0,     0,     0,    43,    44,     0,    82,    83,
      85,    86,    87,    88,     0,     0,     0,     0,    84,    45,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    82,    83,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    82,    83,     0,     0,
       0,     0,     0,   127,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    82,    83,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    82,    83,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      82,    83,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,   138,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    82,    83,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,    97,    98,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,    97,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,     0,     0,     0,     0,    94,    95
};

static const yytype_int16 yycheck[] =
{
      40,    41,    42,    43,    44,    45,    55,    30,    48,    13,
       5,     3,     4,    16,     6,     7,     8,     0,    58,    11,
       7,     8,    62,    63,    12,    17,    30,    19,    20,    15,
      18,    17,    72,    73,    21,    22,    76,    60,    12,    79,
      43,    33,     7,     8,    18,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    13,
       4,    11,   128,   129,    18,    11,    11,    13,    17,     3,
       1,   137,     3,     4,     4,     6,     7,     8,     4,    24,
      11,    26,   148,    18,    15,    16,   126,    32,    19,    20,
     130,    14,    17,    17,    11,    11,    11,    17,   138,   139,
     149,   150,    33,    34,    17,    36,    37,    38,    39,    40,
      41,    42,    43,     1,    11,     3,     4,    16,     6,     7,
       8,     7,     8,    11,    13,    15,    35,    15,    16,    16,
      42,    19,    20,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    44,    33,    34,     4,    36,    37,
      38,    39,    40,    41,     1,    14,     3,     4,    24,     6,
       7,     8,     7,     8,    11,    23,    60,    32,    15,   140,
      65,    -1,    19,    20,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,     7,     8,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     3,
       4,    -1,     6,     7,     8,    -1,    -1,    11,     7,     8,
      44,    -1,    -1,    -1,    -1,    19,    20,    -1,     7,     8,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    17,    33,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     7,     8,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       7,     8,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     7,     8,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    87,    88,    89,    90,     0,    88,     4,    91,
      92,    11,    17,    13,    18,    90,    94,    95,     3,     4,
      91,     4,    93,    12,    18,    14,    15,    17,    96,    95,
      90,    98,    99,    92,   100,   101,     1,     3,     4,     6,
       7,     8,    11,    19,    20,    33,    34,    36,    37,    38,
      39,    40,    41,    96,    97,   104,   105,    98,    30,    17,
      18,    17,    11,    13,   107,   108,   105,   105,   105,   105,
     105,   105,    11,    11,    17,   105,    11,    17,    17,    11,
      16,    97,     7,     8,    17,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   105,
     100,   105,   106,   105,   107,    12,   105,   105,    17,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,    12,    18,    14,    12,    12,
      17,    12,   105,   104,   104,   105,    15,    35,    17,    42,
     102,   103,   104,   105,   105,   103,    16,    43,    12,    44,
      44,   104,    97,    97,    16
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 102 "parser.ypp"
    {(yyval.program)=new ProgAST(); (yyval.program)->ExtDefs=(yyvsp[(1) - (1)].ExtDefList);
                      if (Errors::IsEmpty() && ErrorCharNum==0)
                           { (yyval.program)->DisplayAST(0); }         //无词法、语法错误显示语法树
                      else {Errors::ErrorsDisplay();return 0;}
                      (yyval.program)->Semantics0();                   //静态语义检查
                      if (Errors::IsEmpty())
                          (yyval.program)->GenIR();                    //中间代码生成
                      exit(0);
                      ;}
    break;

  case 3:
#line 112 "parser.ypp"
    {(yyval.ExtDefList)=vector <ExtDefAST*>();;}
    break;

  case 4:
#line 113 "parser.ypp"
    {(yyvsp[(2) - (2)].ExtDefList).insert((yyvsp[(2) - (2)].ExtDefList).begin(),(yyvsp[(1) - (2)].ExtDef));(yyval.ExtDefList)=(yyvsp[(2) - (2)].ExtDefList);;}
    break;

  case 5:
#line 116 "parser.ypp"
    { ExtVarDefAST *t=new ExtVarDefAST();     //创建一个外部变量声明的对象
                                        t->Type=(yyvsp[(1) - (3)].Specifier); t->ExtVars=(yyvsp[(2) - (3)].ExtDecList); (yyval.ExtDef)=t; SavePosition;;}
    break;

  case 6:
#line 118 "parser.ypp"
    {FuncDefAST *t=new FuncDefAST();t->Type=(yyvsp[(1) - (6)].Specifier);t->Name=(yyvsp[(2) - (6)].type_id);t->Params=(yyvsp[(4) - (6)].ParamList); t->Body=(yyvsp[(6) - (6)].CompSt);(yyval.ExtDef)=t;SavePosition;;}
    break;

  case 7:
#line 119 "parser.ypp"
    {FuncDefAST *t=new FuncDefAST();t->Type=(yyvsp[(1) - (6)].Specifier);t->Name=(yyvsp[(2) - (6)].type_id);t->Params=(yyvsp[(4) - (6)].ParamList);(yyval.ExtDef)=t;SavePosition;;}
    break;

  case 8:
#line 121 "parser.ypp"
    {  BasicTypeAST *t=new BasicTypeAST(); ;
                    if (string((yyvsp[(1) - (1)].type_id))==string("int"))    t->Type=T_INT;
                    if (string((yyvsp[(1) - (1)].type_id))==string("float"))  t->Type=T_FLOAT;
                    if (string((yyvsp[(1) - (1)].type_id))==string("void"))   t->Type=T_VOID;  (yyval.Specifier)=t;SavePosition;;}
    break;

  case 9:
#line 127 "parser.ypp"
    {(yyval.ExtDecList)=vector < VarDecAST*>();(yyval.ExtDecList).push_back((yyvsp[(1) - (1)].VarDec));;}
    break;

  case 10:
#line 128 "parser.ypp"
    {(yyvsp[(3) - (3)].ExtDecList).insert((yyvsp[(3) - (3)].ExtDecList).begin(),(yyvsp[(1) - (3)].VarDec));(yyval.ExtDecList)=(yyvsp[(3) - (3)].ExtDecList);;}
    break;

  case 11:
#line 130 "parser.ypp"
    {VarDecAST *t=new VarDecAST(); t->Name=string((yyvsp[(1) - (1)].type_id)); (yyval.VarDec)=t; SavePosition;;}
    break;

  case 12:
#line 131 "parser.ypp"
    {(yyvsp[(1) - (4)].VarDec)->Dims.push_back((yyvsp[(3) - (4)].type_int));(yyval.VarDec)=(yyvsp[(1) - (4)].VarDec);;}
    break;

  case 13:
#line 133 "parser.ypp"
    {VarDecAST *t=new VarDecAST(); t->Name=string((yyvsp[(1) - (1)].type_id)); (yyval.VarDec)=t; SavePosition;;}
    break;

  case 14:
#line 136 "parser.ypp"
    {(yyval.ParamList)=vector < ParamAST *>();;}
    break;

  case 15:
#line 137 "parser.ypp"
    {(yyval.ParamList)=vector < ParamAST *>(); (yyval.ParamList).push_back((yyvsp[(1) - (1)].ParamDec)); ;}
    break;

  case 16:
#line 138 "parser.ypp"
    {(yyvsp[(1) - (3)].ParamList).push_back((yyvsp[(3) - (3)].ParamDec)); (yyval.ParamList)=(yyvsp[(1) - (3)].ParamList);;}
    break;

  case 17:
#line 140 "parser.ypp"
    {ParamAST* t=new ParamAST();t->Type=(yyvsp[(1) - (2)].Specifier);t->ParamName=(yyvsp[(2) - (2)].VarDec); (yyval.ParamDec)=t; SavePosition;;}
    break;

  case 18:
#line 143 "parser.ypp"
    {CompStmAST *t=new CompStmAST();t->Decls=(yyvsp[(2) - (4)].DefList);t->Stms=(yyvsp[(3) - (4)].StmList);(yyval.CompSt)=t;SavePosition;;}
    break;

  case 19:
#line 145 "parser.ypp"
    {(yyval.StmList)=vector <StmAST *>(); ;}
    break;

  case 20:
#line 146 "parser.ypp"
    {(yyval.StmList)=(yyvsp[(2) - (2)].StmList);(yyval.StmList).insert((yyval.StmList).begin(),(yyvsp[(1) - (2)].Stmt));;}
    break;

  case 21:
#line 148 "parser.ypp"
    {(yyval.DefList)=vector <DefAST *>();  ;}
    break;

  case 22:
#line 149 "parser.ypp"
    {(yyval.DefList)=(yyvsp[(2) - (2)].DefList);(yyval.DefList).insert((yyval.DefList).begin(),(yyvsp[(1) - (2)].Def));;}
    break;

  case 23:
#line 151 "parser.ypp"
    {DefAST *t=new DefAST();t->Type=(yyvsp[(1) - (3)].Specifier);t->LocVars=(yyvsp[(2) - (3)].DecList);(yyval.Def)=t;SavePosition;;}
    break;

  case 24:
#line 153 "parser.ypp"
    {(yyval.DecList)=vector <VarDecAST *>(); (yyval.DecList).push_back((yyvsp[(1) - (1)].Dec));;}
    break;

  case 25:
#line 154 "parser.ypp"
    {(yyval.DecList)=(yyvsp[(3) - (3)].DecList);(yyval.DecList).insert((yyval.DecList).begin(),(yyvsp[(1) - (3)].Dec));;}
    break;

  case 26:
#line 156 "parser.ypp"
    {(yyval.Dec)=(yyvsp[(1) - (1)].VarDec);;}
    break;

  case 27:
#line 157 "parser.ypp"
    {(yyval.Dec)=(yyvsp[(1) - (3)].VarDec);(yyval.Dec)->Exp=(yyvsp[(3) - (3)].Exp); ;}
    break;

  case 28:
#line 160 "parser.ypp"
    {CaseStmAST *t=new CaseStmAST(); t->Cond=(yyvsp[(2) - (4)].Exp); t->Body=(yyvsp[(4) - (4)].StmList); (yyval.Case)=t; SavePosition;;}
    break;

  case 29:
#line 162 "parser.ypp"
    {(yyval.CaseList)=vector <CaseStmAST *>(); (yyval.CaseList).push_back((yyvsp[(1) - (1)].Case)); ;}
    break;

  case 30:
#line 163 "parser.ypp"
    {(yyval.CaseList)=(yyvsp[(2) - (2)].CaseList); (yyval.CaseList).insert((yyval.CaseList).begin(),(yyvsp[(1) - (2)].Case)); ;}
    break;

  case 31:
#line 165 "parser.ypp"
    {ExprStmAST *t=new ExprStmAST();t->Exp=(yyvsp[(1) - (2)].Exp);(yyval.Stmt)=t;SavePosition;;}
    break;

  case 32:
#line 166 "parser.ypp"
    {(yyval.Stmt)=(yyvsp[(1) - (1)].CompSt);;}
    break;

  case 33:
#line 167 "parser.ypp"
    {ReturnStmAST *t=new ReturnStmAST();t->Exp=(yyvsp[(2) - (3)].Exp);(yyval.Stmt)=t;SavePosition;;}
    break;

  case 34:
#line 168 "parser.ypp"
    {ReturnStmAST *t=new ReturnStmAST();t->Exp=NULL;(yyval.Stmt)=t;SavePosition;;}
    break;

  case 35:
#line 169 "parser.ypp"
    {IfStmAST *t=new IfStmAST();t->Cond=(yyvsp[(3) - (5)].Exp);t->ThenStm=(yyvsp[(5) - (5)].Stmt);(yyval.Stmt)=t; SavePosition;;}
    break;

  case 36:
#line 170 "parser.ypp"
    {IfElseStmAST *t=new IfElseStmAST();t->Cond=(yyvsp[(3) - (7)].Exp);t->ThenStm=(yyvsp[(5) - (7)].Stmt);t->ElseStm=(yyvsp[(7) - (7)].Stmt);(yyval.Stmt)=t;SavePosition;;}
    break;

  case 37:
#line 171 "parser.ypp"
    {WhileStmAST *t=new WhileStmAST();t->Cond=(yyvsp[(3) - (5)].Exp);t->Body=(yyvsp[(5) - (5)].Stmt); (yyval.Stmt)=t; SavePosition; ;}
    break;

  case 38:
#line 173 "parser.ypp"
    {ForStmAST *t=new ForStmAST(); t->SinExp=(yyvsp[(3) - (9)].Exp); t->Cond=(yyvsp[(5) - (9)].Exp); t->EndExp=(yyvsp[(7) - (9)].Exp); t->Body=(yyvsp[(9) - (9)].Stmt); (yyval.Stmt)=t; SavePosition;;}
    break;

  case 39:
#line 174 "parser.ypp"
    {SwitchStmAST *t=new SwitchStmAST(); t->Exp=(yyvsp[(3) - (7)].Exp); t->Cases=(yyvsp[(6) - (7)].CaseList); t->containDefault=0; (yyval.Stmt)=t; SavePosition;;}
    break;

  case 40:
#line 176 "parser.ypp"
    {SwitchStmAST *t=new SwitchStmAST(); t->Exp=(yyvsp[(3) - (10)].Exp); t->Cases=(yyvsp[(6) - (10)].CaseList); t->containDefault=1; t->Default=(yyvsp[(9) - (10)].StmList); (yyval.Stmt)=t; SavePosition;;}
    break;

  case 41:
#line 177 "parser.ypp"
    {BreakStmAST *t=new BreakStmAST(); (yyval.Stmt)=t; SavePosition; ;}
    break;

  case 42:
#line 178 "parser.ypp"
    {ContinueStmAST *t=new ContinueStmAST(); (yyval.Stmt)=t; SavePosition; ;}
    break;

  case 43:
#line 179 "parser.ypp"
    {(yyval.Stmt)=NULL;;}
    break;

  case 44:
#line 182 "parser.ypp"
    {AssignAST *t=new AssignAST();t->Op=ASSIGN;
                t->LeftValExp=(yyvsp[(1) - (3)].Exp);t->RightValExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 45:
#line 185 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=PLUS;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 46:
#line 186 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=MINUS;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 47:
#line 187 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=STAR;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 48:
#line 188 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=DIV;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 49:
#line 189 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=MOD;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 50:
#line 190 "parser.ypp"
    {(yyval.Exp)=(yyvsp[(2) - (3)].Exp);;}
    break;

  case 51:
#line 191 "parser.ypp"
    {UnaryExprAST *t=new UnaryExprAST();t->Op=UMINUS;t->Exp=(yyvsp[(2) - (2)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 52:
#line 192 "parser.ypp"
    {UnaryExprAST *t=new UnaryExprAST();t->Op=UPLUS;t->Exp=(yyvsp[(2) - (2)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 53:
#line 194 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=AND;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 54:
#line 195 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=OR;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 55:
#line 196 "parser.ypp"
    {UnaryExprAST *t=new UnaryExprAST();t->Op=NOT;t->Exp=(yyvsp[(2) - (2)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 56:
#line 198 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=GT;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 57:
#line 199 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=GE;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 58:
#line 200 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=LT;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 59:
#line 201 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=LE;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 60:
#line 202 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=NE;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 61:
#line 203 "parser.ypp"
    {BinaryExprAST *t=new BinaryExprAST();t->Op=EQ;t->LeftExp=(yyvsp[(1) - (3)].Exp);t->RightExp=(yyvsp[(3) - (3)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 62:
#line 206 "parser.ypp"
    {UnaryExprAST *t=new UnaryExprAST();t->Op=DPLUS;t->Exp=(yyvsp[(2) - (2)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 63:
#line 207 "parser.ypp"
    {UnaryExprAST *t=new UnaryExprAST();t->Op=DMINUS;t->Exp=(yyvsp[(2) - (2)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 64:
#line 208 "parser.ypp"
    {UnaryExprAST *t=new UnaryExprAST();t->Op=PLUSD;t->Exp=(yyvsp[(1) - (2)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 65:
#line 209 "parser.ypp"
    {UnaryExprAST *t=new UnaryExprAST();t->Op=MINUSD;t->Exp=(yyvsp[(1) - (2)].Exp);(yyval.Exp)=t;SavePosition;;}
    break;

  case 66:
#line 212 "parser.ypp"
    {FuncCallAST *t=new FuncCallAST();t->Name=(yyvsp[(1) - (4)].type_id);t->Params=(yyvsp[(3) - (4)].Args);(yyval.Exp)=t;SavePosition;;}
    break;

  case 67:
#line 213 "parser.ypp"
    {VarAST *t=new VarAST();t->Name=(yyvsp[(1) - (1)].type_id);(yyval.Exp)=t;SavePosition;;}
    break;

  case 68:
#line 214 "parser.ypp"
    {VarAST *t=new VarAST();t->Name=(yyvsp[(1) - (2)].type_id);t->index=(yyvsp[(2) - (2)].Args);(yyval.Exp)=t;SavePosition;;}
    break;

  case 69:
#line 215 "parser.ypp"
    {ConstAST *t=new ConstAST();t->Type=T_INT;t->ConstVal.constINT=(yyvsp[(1) - (1)].type_int);(yyval.Exp)=t;SavePosition;;}
    break;

  case 70:
#line 216 "parser.ypp"
    {ConstAST *t=new ConstAST();t->Type=T_FLOAT;t->ConstVal.constFLOAT=(yyvsp[(1) - (1)].type_float);(yyval.Exp)=t;SavePosition;;}
    break;

  case 71:
#line 218 "parser.ypp"
    {;}
    break;

  case 72:
#line 219 "parser.ypp"
    {(yyval.Args)=vector <ExpAST *>(); (yyval.Args).push_back((yyvsp[(1) - (1)].Exp)); ;}
    break;

  case 73:
#line 220 "parser.ypp"
    {(yyval.Args)=(yyvsp[(1) - (3)].Args);(yyval.Args).push_back((yyvsp[(3) - (3)].Exp));;}
    break;

  case 74:
#line 223 "parser.ypp"
    {(yyval.Exp)=(yyvsp[(2) - (3)].Exp); ;}
    break;

  case 75:
#line 225 "parser.ypp"
    {(yyval.Args)=vector <ExpAST *>(); (yyval.Args).push_back((yyvsp[(1) - (1)].Exp)); ;}
    break;

  case 76:
#line 226 "parser.ypp"
    {(yyval.Args)=(yyvsp[(1) - (2)].Args); (yyval.Args).push_back((yyvsp[(2) - (2)].Exp));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2169 "parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 228 "parser.ypp"


int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	if (!yyin) return 0;
	yylineno=1;
	yyparse();
	return 0;
	}

#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
    Errors::ErrorAdd(yylloc.first_line,yylloc.first_column,fmt);
}

