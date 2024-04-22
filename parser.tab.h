
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
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     FOR = 261,
     DO = 262,
     SWITCH = 263,
     CASE = 264,
     DEFAULT = 265,
     RETURN = 266,
     CONTINUE = 267,
     BREAK = 268,
     CONST = 269,
     INTEGER = 270,
     FLOAT = 271,
     CHAR = 272,
     BOOL = 273,
     VOID = 274,
     ENUM = 275,
     LEFT_BRACE = 276,
     RIGHT_BRACE = 277,
     LEFT_PAREN = 278,
     RIGHT_PAREN = 279,
     SEMICOLON = 280,
     COLON = 281,
     COMMA = 282,
     LEFT_SQUARE_BRACKET = 283,
     RIGHT_SQUARE_BRACKET = 284,
     IDENTIFIER = 285,
     INTEGER_CONSTANT = 286,
     STRING_CONSTANT = 287,
     FLOAT_CONSTANT = 288,
     BOOL_CONSTANT = 289,
     CHAR_CONSTANT = 290,
     QUESTION_MARK = 291,
     PLUS = 292,
     MINUS = 293,
     MUL = 294,
     DIV = 295,
     POWER = 296,
     MOD = 297,
     EQUALS = 298,
     NOT_EQUALS = 299,
     LESS_THAN = 300,
     LESS_THAN_OR_EQUALS = 301,
     GREATER_THAN = 302,
     GREATER_THAN_OR_EQUALS = 303,
     LOGICAL_AND = 304,
     LOGICAL_OR = 305,
     LOGICAL_NOT = 306,
     ASSIGN = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


