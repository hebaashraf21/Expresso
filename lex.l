%{
#include "parser.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%

[0-9]+      {
                yylval = atoi(yytext);
                return INTEGER;
            }

[+*/-]      { return *yytext; }

"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"do"        { return DO; }
"switch"    { return SWITCH; }
"case"      { return CASE; }
"default"   { return DEFAULT; }
"int"       { return INTEGER; }
"float"     { return FLOAT; }
"char"      { return CHAR; }
"bool"      { return BOOL; }
"void"      { return VOID; }
"return"    { return RETURN; }

"{"         { return LEFT_BRACE; }
"}"         { return RIGHT_BRACE; }
"("         { return LEFT_PAREN; }
")"         { return RIGHT_PAREN; }
";"         { return SEMICOLON; }
","         { return COMMA; }

[ \t]       ;  // Skip whitespace

.           yyerror("Unknown character");

%%

int yywrap(void) {
    return 1;
}
