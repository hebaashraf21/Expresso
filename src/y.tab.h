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
    RETURN = 266,
    SWITCH = 267,
    CASE = 268,
    DEFAULT = 269,
    REPEAT = 270,
    UNTIL = 271,
    VOID = 272,
    ENUM = 273,
    INTEGER = 274,
    FLOAT = 275,
    CHAR = 276,
    BOOL = 277,
    STRING = 278,
    CONST = 279,
    FLOAT_VAL = 280,
    INTEGER_VAL = 281,
    CHAR_VAL = 282,
    STRING_VAL = 283,
    TRUE_VAL = 284,
    FALSE_VAL = 285,
    IDENTIFIER = 286,
    INCR = 287,
    DECR = 288,
    LOGICAL_OR = 289,
    LOGICAL_AND = 290,
    EQUALS = 291,
    NOT_EQUALS = 292,
    LESS_THAN = 293,
    LESS_THAN_OR_EQUALS = 294,
    GREATER_THAN = 295,
    GREATER_THAN_OR_EQUALS = 296,
    LOGICAL_NOT = 297,
    UMINUS = 298
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
#define RETURN 266
#define SWITCH 267
#define CASE 268
#define DEFAULT 269
#define REPEAT 270
#define UNTIL 271
#define VOID 272
#define ENUM 273
#define INTEGER 274
#define FLOAT 275
#define CHAR 276
#define BOOL 277
#define STRING 278
#define CONST 279
#define FLOAT_VAL 280
#define INTEGER_VAL 281
#define CHAR_VAL 282
#define STRING_VAL 283
#define TRUE_VAL 284
#define FALSE_VAL 285
#define IDENTIFIER 286
#define INCR 287
#define DECR 288
#define LOGICAL_OR 289
#define LOGICAL_AND 290
#define EQUALS 291
#define NOT_EQUALS 292
#define LESS_THAN 293
#define LESS_THAN_OR_EQUALS 294
#define GREATER_THAN 295
#define GREATER_THAN_OR_EQUALS 296
#define LOGICAL_NOT 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 124 "parser.y"
 
    int int_value;        
    char* str_value;        
    char* char_value;      
    float float_value;  
    bool bool_value;    
    char* identifier;
    struct Node *node_value;
;

#line 154 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
