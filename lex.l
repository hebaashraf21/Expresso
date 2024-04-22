%{
#include <stdio.h>
#include "parser.tab.h"
void yyerror(const char*);
%}

%%

"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"for"               { return FOR; }
"do"                { return DO; }
"switch"            { return SWITCH; }
"case"              { return CASE; }
"default"           { return DEFAULT; }
"int"               { return INTEGER; }
"float"             { return FLOAT; }
"char"              { return CHAR; }
"bool"              { return BOOL; }
"void"              { return VOID; }
"enum"              { return ENUM; }
"return"            { return RETURN; }
"continue"          { return CONTINUE; }
"break"             { return BREAK; }
"const"             { return CONST;}

"=="                { return EQUALS; }
"!="                { return NOT_EQUALS; }
"<"                 { return LESS_THAN; }
"<="                { return LESS_THAN_OR_EQUALS; }
">"                 { return GREATER_THAN; }
">="                { return GREATER_THAN_OR_EQUALS; }
"&&"                { return LOGICAL_AND; }
"||"                { return LOGICAL_OR; }
"!"                 { return LOGICAL_NOT; }

"="                 { return ASSIGN; }

"{"                 { return LEFT_BRACE; }
"}"                 { return RIGHT_BRACE; }
"("                 { return LEFT_PAREN; }
")"                 { return RIGHT_PAREN; }
"["                 { return LEFT_SQUARE_BRACKET; }
"]"                 { return RIGHT_SQUARE_BRACKET; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }
"?"                 { return QUESTION_MARK; }

"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL; }
"/"                 { return DIV; }
"^"                 { return POWER; }
"%"                 { return MOD; }

[0-9]+"."[0-9]*      { return FLOAT_CONSTANT; }
[0-9]+               { return INTEGER_CONSTANT; }
'[^\\']'             { return CHAR_CONSTANT; }
"\"([^\"\\]|\\.)*\"" { return STRING_CONSTANT; }
"true"|"false"       { return BOOL_CONSTANT; }

[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }

[ \t\n]             ; // Skip whitespace and newlines

%%

int yywrap()
{
    return 1;
}
