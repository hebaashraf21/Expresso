%{
#include <stdio.h>
#include <stdbool.h> 
#include "y.tab.h" 
// In the event of syntax errors yacc calls the user-supplied function yyerror.
void yyerror(char *);
extern FILE *yyin;
extern FILE *yyout;
int lineno = 1; // initialize to 1
%}
%option noyywrap

%%

"if"                { return IF; }
"else"              { return ELSE; }

"while"             { return WHILE; }
"do"                { return DO; }

"repeat"            { return REPEAT; }
"until"             { return UNTIL; }

"for"               { return FOR; }

"switch"            { return SWITCH; }
"case"              { return CASE; }
"default"           { return DEFAULT; }

"int"               { return INTEGER; }
"float"             { return FLOAT; }
"char"              { return CHAR; }
"string"            { return STRING; }
"bool"              { return BOOL; }

"void"              { return VOID; }
"continue"          { return CONTINUE; }
"break"             { return BREAK; }

"const"             { return CONST;}

"print"             { return PRINT;}

"enum"              { return ENUM; }

"=="                { return EQUALS; }
"!="                { return NOT_EQUALS; }
"<"                 { return LESS_THAN; }
"<="                { return LESS_THAN_OR_EQUALS; }
">"                 { return GREATER_THAN; }
">="                { return GREATER_THAN_OR_EQUALS; }

"&&"                { return LOGICAL_AND; }
"||"                { return LOGICAL_OR; }
"!"                 { return LOGICAL_NOT; }

"="                 { return *yytext; }

"{"                 { return *yytext; }
"}"                 { return *yytext; }
"("                 { return *yytext; }
")"                 { return *yytext; }
"["                 { return *yytext; }
"]"                 { return *yytext; }

"++"		     	{ return INCR; }
"--"		     	{ return DECR; }
"+"                 { return *yytext; }
"-"                 { return *yytext; }
"*"                 { return *yytext; }
"/"                 { return *yytext; }
"^"                 { return *yytext; }
"%"                 { return *yytext; }

[0-9]*"."[0-9]+     { 
						yylval.float_value = atof(yytext);	
						return FLOAT_VAL; 
		    		}
		     
0  	             	{
						yylval.int_value = atoi(yytext);	
						return INTEGER_VAL; 
		     		}
		     
[1-9][0-9]*         { 
						yylval.int_value = atoi(yytext);  
						return INTEGER_VAL; 
		    		}
		    
'[^\\']'            { 
						yylval.char_value = yytext[0];
		       			return CHAR_VAL; 
		   			}
		      
\"([^\"\\;]|\\.)*\" { 
						yylval.str_value = strdup(yytext);
		       			return STRING_VAL; 
		      		}
		      
"true"		     	{ 
						yylval.bool_value = 1;      
						return TRUE_VAL; 
					}

"false"             { 
						yylval.bool_value = 0;
						return FALSE_VAL; 
					}

[a-zA-Z_][a-zA-Z0-9_]* {
						yylval.identifier = strdup(yytext);
						return IDENTIFIER; 
					}

";"                 { return *yytext; }
","                 { return *yytext; }
"?"                 { return *yytext; }
":"		    		{ return *yytext; }

\/\/.*		    	{;} // Skip inline comments
\/\*([^*]|\*+[^/])*\*+\/ {;} // Skip multi lines comments 


"\n"            	{ lineno += 1; }
[ \t]             ; // Skip whitespace and newlines
. 			yyerror("invalid token");
%%

int mywrap()
{
    return 1;
}