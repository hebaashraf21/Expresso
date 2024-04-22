
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
     INTEGER = 269,
     FLOAT = 270,
     CHAR = 271,
     BOOL = 272,
     VOID = 273,
     LEFT_BRACE = 274,
     RIGHT_BRACE = 275,
     LEFT_PAREN = 276,
     RIGHT_PAREN = 277,
     SEMICOLON = 278,
     COLON = 279,
     COMMA = 280,
     LEFT_SQUARE_BRACKET = 281,
     RIGHT_SQUARE_BRACKET = 282,
     DIGIT = 283,
     IDENTIFIER = 284,
     STRING_IDENTIFIER = 285,
     BOOL_IDENTIFIER = 286,
     QUESTION_MARK = 287,
     PLUS = 288,
     MINUS = 289,
     MUL = 290,
     DIV = 291,
     POWER = 292,
     MOD = 293,
     EQUALS = 294,
     NOT_EQUALS = 295,
     LESS_THAN = 296,
     LESS_THAN_OR_EQUALS = 297,
     GREATER_THAN = 298,
     GREATER_THAN_OR_EQUALS = 299,
     LOGICAL_AND = 300,
     LOGICAL_OR = 301,
     LOGICAL_NOT = 302,
     ASSIGN = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


