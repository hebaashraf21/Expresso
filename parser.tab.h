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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    STRING = 276,
    PRINT = 277,
    ASSERT = 278,
    EQUALS = 279,
    NOT_EQUALS = 280,
    LESS_THAN = 281,
    LESS_THAN_OR_EQUALS = 282,
    GREATER_THAN = 283,
    GREATER_THAN_OR_EQUALS = 284,
    LOGICAL_AND = 285,
    LOGICAL_OR = 286,
    LOGICAL_NOT = 287,
    ASSIGN = 288,
    PLUS = 289,
    MINUS = 290,
    MUL = 291,
    DIV = 292,
    POWER = 293,
    MOD = 294,
    LEFT_BRACE = 295,
    RIGHT_BRACE = 296,
    LEFT_PAREN = 297,
    RIGHT_PAREN = 298,
    LEFT_SQUARE_BRACKET = 299,
    RIGHT_SQUARE_BRACKET = 300,
    SEMICOLON = 301,
    COMMA = 302,
    QUESTION_MARK = 303,
    FLOAT_CONSTANT = 304,
    INTEGER_CONSTANT = 305,
    CHAR_CONSTANT = 306,
    STRING_CONSTANT = 307,
    BOOL_CONSTANT = 308,
    IDENTIFIER = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
