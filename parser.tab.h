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
    SEMICOLON = 281,
    COMMA = 282,
    QUESTION_MARK = 283,
    FLOAT_VAL = 284,
    INTEGER_VAL = 285,
    CHAR_VAL = 286,
    STRING_VAL = 287,
    TRUE_VAL = 288,
    FALSE_VAL = 289,
    IDENTIFIER = 290,
    LOGICAL_AND = 291,
    LOGICAL_OR = 292,
    EQUALS = 293,
    NOT_EQUALS = 294,
    LESS_THAN = 295,
    LESS_THAN_OR_EQUALS = 296,
    GREATER_THAN = 297,
    GREATER_THAN_OR_EQUALS = 298,
    PLUS = 299,
    MINUS = 300,
    LOGICAL_NOT = 301,
    MUL = 302,
    DIV = 303,
    MOD = 304,
    POWER = 305
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
