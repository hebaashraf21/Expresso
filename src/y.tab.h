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
    IF = 259,
    ELSE = 260,
    WHILE = 261,
    FOR = 262,
    DO = 263,
    CONTINUE = 264,
    BREAK = 265,
    SWITCH = 266,
    CASE = 267,
    DEFAULT = 268,
    REPEAT = 269,
    UNTIL = 270,
    VOID = 271,
    ENUM = 272,
    INTEGER = 273,
    FLOAT = 274,
    CHAR = 275,
    BOOL = 276,
    STRING = 277,
    CONST = 278,
    FLOAT_VAL = 279,
    INTEGER_VAL = 280,
    CHAR_VAL = 281,
    STRING_VAL = 282,
    TRUE_VAL = 283,
    FALSE_VAL = 284,
    IDENTIFIER = 285,
    INCR = 286,
    DECR = 287,
    LOGICAL_OR = 288,
    LOGICAL_AND = 289,
    EQUALS = 290,
    NOT_EQUALS = 291,
    LESS_THAN = 292,
    LESS_THAN_OR_EQUALS = 293,
    GREATER_THAN = 294,
    GREATER_THAN_OR_EQUALS = 295,
    LOGICAL_NOT = 296,
    UMINUS = 297
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define WHILE 261
#define FOR 262
#define DO 263
#define CONTINUE 264
#define BREAK 265
#define SWITCH 266
#define CASE 267
#define DEFAULT 268
#define REPEAT 269
#define UNTIL 270
#define VOID 271
#define ENUM 272
#define INTEGER 273
#define FLOAT 274
#define CHAR 275
#define BOOL 276
#define STRING 277
#define CONST 278
#define FLOAT_VAL 279
#define INTEGER_VAL 280
#define CHAR_VAL 281
#define STRING_VAL 282
#define TRUE_VAL 283
#define FALSE_VAL 284
#define IDENTIFIER 285
#define INCR 286
#define DECR 287
#define LOGICAL_OR 288
#define LOGICAL_AND 289
#define EQUALS 290
#define NOT_EQUALS 291
#define LESS_THAN 292
#define LESS_THAN_OR_EQUALS 293
#define GREATER_THAN 294
#define GREATER_THAN_OR_EQUALS 295
#define LOGICAL_NOT 296
#define UMINUS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "parser.y"
 
    int int_value;        
    char* str_value;        
    char char_value;      
    float float_value;  
    bool bool_value;    
    char* identifier;
    struct Node *node_value;
;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
