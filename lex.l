%{
#include <stdio.h>
#include "parser.tab.h"
void yyerror(const char*);
%}

%option noyywrap

%%

"if"                { printf("IF: %s\n", yytext);       return IF; }
"else"              { printf("ELSE: %s\n", yytext);     return ELSE; }

"while"             { printf("WHILE: %s\n", yytext);    return WHILE; }
"for"               { printf("FOR: %s\n", yytext);      return FOR; }
"do"                { printf("DO: %s\n", yytext);       return DO; }

"switch"            { printf("SWITCH: %s\n", yytext);   return SWITCH; }
"case"              { printf("CASE: %s\n", yytext);     return CASE; }
"default"           { printf("DEFAULT: %s\n", yytext);  return DEFAULT; }

"int"               { printf("INTEGER: %s\n", yytext);  return INTEGER; }
"float"             { printf("FLOAT: %s\n", yytext);    return FLOAT; }
"char"              { printf("CHAR: %s\n", yytext);     return CHAR; }
"string"            { printf("STRING: %s\n", yytext);     return STRING; }
"bool"              { printf("BOOL: %s\n", yytext);     return BOOL; }

"void"              { printf("VOID: %s\n", yytext);     return VOID; }
"return"            { printf("RETURN: %s\n", yytext);   return RETURN; }
"continue"          { printf("CONTINUE: %s\n", yytext); return CONTINUE; }
"break"             { printf("BREAK: %s\n", yytext);    return BREAK; }

"const"             { printf("CONST: %s\n", yytext);    return CONST;}

"print"             { printf("PRINT: %s\n", yytext);    return PRINT;}

"assert"            { printf("ASSERT: %s\n", yytext);    return ASSERT;}

"enum"              { printf("ENUM: %s\n", yytext);     return ENUM; }

"=="                { printf("EQUALS: %s\n", yytext);                  return EQUALS; }
"!="                { printf("NOT_EQUALS: %s\n", yytext);              return NOT_EQUALS; }
"<"                 { printf("LESS_THAN: %s\n", yytext);               return LESS_THAN; }
"<="                { printf("LESS_THAN_OR_EQUALS: %s\n", yytext);     return LESS_THAN_OR_EQUALS; }
">"                 { printf("GREATER_THAN: %s\n", yytext);            return GREATER_THAN; }
">="                { printf("GREATER_THAN_OR_EQUALS: %s\n", yytext);  return GREATER_THAN_OR_EQUALS; }

"&&"                { printf("LOGICAL_AND: %s\n", yytext);             return LOGICAL_AND; }
"||"                { printf("LOGICAL_OR: %s\n", yytext);              return LOGICAL_OR; }
"!"                 { printf("LOGICAL_NOT: %s\n", yytext);             return LOGICAL_NOT; }

"="                 { printf("ASSIGN: %s\n", yytext);return ASSIGN; }

"{"                 { printf("LEFT_BRACE: %s\n", yytext);             return LEFT_BRACE; }
"}"                 { printf("RIGHT_BRACE: %s\n", yytext);            return RIGHT_BRACE; }
"("                 { printf("LEFT_PAREN: %s\n", yytext);             return LEFT_PAREN; }
")"                 { printf("RIGHT_PAREN: %s\n", yytext);            return RIGHT_PAREN; }
"["                 { printf("LEFT_SQUARE_BRACKET: %s\n", yytext);    return LEFT_SQUARE_BRACKET; }
"]"                 { printf("RIGHT_SQUARE_BRACKET: %s\n", yytext);   return RIGHT_SQUARE_BRACKET; }

";"                 { printf("SEMICOLON: %s\n", yytext);              return SEMICOLON; }
","                 { printf("COMMA: %s\n", yytext);                  return COMMA; }
"?"                 { printf("QUESTION_MARK: %s\n", yytext);          return QUESTION_MARK; }

"+"                 { printf("PLUS: %s\n", yytext);   return PLUS; }
"-"                 { printf("MINUS: %s\n", yytext);  return MINUS; }
"*"                 { printf("MUL: %s\n", yytext);    return MUL; }
"/"                 { printf("DIV: %s\n", yytext);    return DIV; }
"^"                 { printf("POWER: %s\n", yytext);  return POWER; }
"%"                 { printf("MOD: %s\n", yytext);    return MOD; }

[0-9]*"."[0-9]*      { printf("FLOAT_CONSTANT: %s\n", yytext);     return FLOAT_CONSTANT; }
[0-9]+               { printf("INTEGER_CONSTANT: %s\n", yytext);   return INTEGER_CONSTANT; }
'[^\\']'             { printf("CHAR_CONSTANT: %s\n", yytext);      return CHAR_CONSTANT; }
\"([^\"\\]|\\.)*\"   { printf("STRING_CONSTANT: %s\n", yytext);    return STRING_CONSTANT; }
"true"|"false"       { printf("BOOL_CONSTANT: %s\n", yytext);      return BOOL_CONSTANT; }

[a-zA-Z_][a-zA-Z0-9_]* {printf("IDENTIFIER: %s\n", yytext); return IDENTIFIER; }

\/\/.*		    { printf("inline comment");} // Skip inline comments
\/\*([^*]|\*+[^/])*\*+\/ { printf("multi lines comment\n"); } // Skip multi lines comments 

[ \t\n]             ; // Skip whitespace and newlines

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int my_wrap()
{
    return 1;
}
