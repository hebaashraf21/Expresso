/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINT = 258,
    ASSERT = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    FOR = 263,
    DO = 264,
    CONTINUE = 265,
    BREAK = 266,
    SWITCH = 267,
    CASE = 268,
    DEFAULT = 269,
    REPEAT = 270,
    UNTIL = 271,
    VOID = 272,
    ENUM = 273,
    RETURN = 274,
    INTEGER = 275,
    FLOAT = 276,
    CHAR = 277,
    BOOL = 278,
    STRING = 279,
    CONST = 280,
    FLOAT_VAL = 281,
    INTEGER_VAL = 282,
    CHAR_VAL = 283,
    STRING_VAL = 284,
    TRUE_VAL = 285,
    FALSE_VAL = 286,
    IDENTIFIER = 287,
    INCR = 288,
    DECR = 289,
    LOGICAL_OR = 290,
    LOGICAL_AND = 291,
    EQUALS = 292,
    NOT_EQUALS = 293,
    LESS_THAN = 294,
    LESS_THAN_OR_EQUALS = 295,
    GREATER_THAN = 296,
    GREATER_THAN_OR_EQUALS = 297,
    LOGICAL_NOT = 298,
    UMINUS = 299
  };
#endif
/* Tokens.  */
#define PRINT 258
#define ASSERT 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define FOR 263
#define DO 264
#define CONTINUE 265
#define BREAK 266
#define SWITCH 267
#define CASE 268
#define DEFAULT 269
#define REPEAT 270
#define UNTIL 271
#define VOID 272
#define ENUM 273
#define RETURN 274
#define INTEGER 275
#define FLOAT 276
#define CHAR 277
#define BOOL 278
#define STRING 279
#define CONST 280
#define FLOAT_VAL 281
#define INTEGER_VAL 282
#define CHAR_VAL 283
#define STRING_VAL 284
#define TRUE_VAL 285
#define FALSE_VAL 286
#define IDENTIFIER 287
#define INCR 288
#define DECR 289
#define LOGICAL_OR 290
#define LOGICAL_AND 291
#define EQUALS 292
#define NOT_EQUALS 293
#define LESS_THAN 294
#define LESS_THAN_OR_EQUALS 295
#define GREATER_THAN 296
#define GREATER_THAN_OR_EQUALS 297
#define LOGICAL_NOT 298
#define UMINUS 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "parser.y"
 
    int int_val;          /* integer value */ 
    char* str_val;        /* string value */
    char char_val;      /* char value */
    float float_val;  /* float value */
    bool bool_val;    /* boolean value */
    char* identifier; /* IDENTIFIER */

#line 154 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
