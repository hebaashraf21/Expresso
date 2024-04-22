%{
#include <stdio.h>
#include "parser.tab.h"
void yyerror(const char*);
%}

%token IF ELSE WHILE FOR DO SWITCH CASE DEFAULT INTEGER FLOAT CHAR BOOL VOID RETURN CONTINUE BREAK
%token LEFT_BRACE RIGHT_BRACE LEFT_PAREN RIGHT_PAREN SEMICOLON COLON COMMA DIGIT IDENTIFIER STRING_IDENTIFIER BOOL_IDENTIFIER QUESTION_MARK LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET PLUS MINUS MUL DIV POWER

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

cases : /* empty */ | cases CASE DIGIT COLON statement ;

expression : IDENTIFIER
           | DIGIT
           | expression PLUS expression
           | expression MINUS expression
           | expression MUL expression
           | expression DIV expression
           | expression POWER expression
           | LEFT_PAREN expression RIGHT_PAREN
           | STRING_IDENTIFIER
           | BOOL_IDENTIFIER
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
