
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
     INTEGER = 266,
     FLOAT = 267,
     CHAR = 268,
     BOOL = 269,
     VOID = 270,
     ENUM = 271,
     RETURN = 272,
     CONTINUE = 273,
     BREAK = 274,
     CONST = 275,
     EQUALS = 276,
     NOT_EQUALS = 277,
     LESS_THAN = 278,
     LESS_THAN_OR_EQUALS = 279,
     GREATER_THAN = 280,
     GREATER_THAN_OR_EQUALS = 281,
     LOGICAL_AND = 282,
     LOGICAL_OR = 283,
     LOGICAL_NOT = 284,
     ASSIGN = 285,
     PLUS = 286,
     MINUS = 287,
     MUL = 288,
     DIV = 289,
     POWER = 290,
     MOD = 291,
     LEFT_BRACE = 292,
     RIGHT_BRACE = 293,
     LEFT_PAREN = 294,
     RIGHT_PAREN = 295,
     LEFT_SQUARE_BRACKET = 296,
     RIGHT_SQUARE_BRACKET = 297,
     SEMICOLON = 298,
     COMMA = 299,
     QUESTION_MARK = 300,
     FLOAT_CONSTANT = 301,
     INTEGER_CONSTANT = 302,
     CHAR_CONSTANT = 303,
     STRING_CONSTANT = 304,
     BOOL_CONSTANT = 305,
     IDENTIFIER = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


