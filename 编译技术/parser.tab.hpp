/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
