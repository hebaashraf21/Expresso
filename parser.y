%{
#include <stdio.h>
int yylex();
void yyerror(char *);

int result = 0;
%}

%token IF ELSE WHILE FOR DO SWITCH CASE DEFAULT INTEGER FLOAT CHAR BOOL VOID RETURN LEFT_BRACE RIGHT_BRACE LEFT_PAREN RIGHT_PAREN SEMICOLON COMMA
%left '+' '-'
%left '*' '/'

%%

stmt_list : /* empty */
          | stmt_list stmt { printf("Result: %d\n", result); }
          ;

stmt      : expr { result = $1; }
          ;

expr      : INTEGER
          | expr '+' expr { $$ = $1 + $3; }
          | expr '-' expr { $$ = $1 - $3; }
          | expr '*' expr { $$ = $1 * $3; }
          | expr '/' expr { $$ = $1 / $3; }
          | '(' expr ')'   { $$ = $2; }
          ;

%%

void yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
