
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
     NOT_EQUALS = 291,
     EQUALS = 292,
     GREATER_THAN_OR_EQUALS = 293,
     GREATER_THAN = 294,
     LESS_THAN_OR_EQUALS = 295,
     LESS_THAN = 296,
     LOGICAL_NOT = 297,
     UMINUS = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 143 "parser.y"
 
    int int_value;        
    char* str_value;        
    char* char_value;      
    float float_value;  
    bool bool_value;    
    char* identifier;
    struct Node *node_value;
;


/* Line 1676 of yacc.c  */
#line 107 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


