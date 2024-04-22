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
"return"            { return RETURN; }
"continue"          { return CONTINUE; }
"break"             { return BREAK; }



"{"                 { return LEFT_BRACE; }
"}"                 { return RIGHT_BRACE; }
"("                 { return LEFT_PAREN; }
")"                 { return RIGHT_PAREN; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }
[0-9]+              {  return DIGIT; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }
\"([^"\\]|\\.)*\"   {  return STRING_IDENTIFIER; }
"true|false"        {  return BOOL_IDENTIFIER; }
"?"                 { return QUESTION_MARK; }
"["                 { return LEFT_SQUARE_BRACKET; }
"]"                 { return RIGHT_SQUARE_BRACKET; }
[ \t\n]             ; // Skip whitespace and newlines

"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL; }
"/"                 { return DIV; }
"^"                 { return POWER; }



%%





int yywrap()
{
    return 1;
}


