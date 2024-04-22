%{
#include <stdio.h>
#include "parser.tab.h"
void yyerror(const char*);
%}

%token IF ELSE WHILE FOR DO SWITCH CASE DEFAULT RETURN CONTINUE BREAK CONST
%token INTEGER FLOAT CHAR BOOL VOID ENUM
%token LEFT_BRACE RIGHT_BRACE LEFT_PAREN RIGHT_PAREN SEMICOLON COLON COMMA LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET
%token IDENTIFIER INTEGER_CONSTANT STRING_CONSTANT FLOAT_CONSTANT BOOL_CONSTANT CHAR_CONSTANT QUESTION_MARK  
%token PLUS MINUS MUL DIV POWER MOD
%token  EQUALS NOT_EQUALS LESS_THAN LESS_THAN_OR_EQUALS GREATER_THAN GREATER_THAN_OR_EQUALS
%token LOGICAL_AND LOGICAL_OR LOGICAL_NOT ASSIGN

%%

program : /* empty */ | program statement ;

statement : expression SEMICOLON
          | IF LEFT_PAREN expression RIGHT_PAREN statement
          | IF LEFT_PAREN expression RIGHT_PAREN statement ELSE statement
          | WHILE LEFT_PAREN expression RIGHT_PAREN statement
          | FOR LEFT_PAREN expression SEMICOLON expression SEMICOLON expression RIGHT_PAREN statement
          | DO statement WHILE LEFT_PAREN expression RIGHT_PAREN SEMICOLON
          | SWITCH LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE cases RIGHT_BRACE
          | RETURN expression SEMICOLON
          | CONTINUE SEMICOLON
          | BREAK SEMICOLON
          ;

cases : /* empty */ | cases CASE INTEGER_CONSTANT COLON statement ;

expression : IDENTIFIER
           | INTEGER_CONSTANT
           | expression PLUS expression
           | expression MINUS expression
           | expression MUL expression
           | expression DIV expression
           | expression POWER expression
           | LEFT_PAREN expression RIGHT_PAREN
           | STRING_CONSTANT
           | BOOL_CONSTANT
           | expression QUESTION_MARK expression COLON expression
           | LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET
           ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
    yyparse();
    return 0;
}