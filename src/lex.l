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

"if"                { printf("IF: %s\n", yytext);       return IF; }
"else"              { printf("ELSE: %s\n", yytext);     return ELSE; }

"while"             { printf("WHILE: %s\n", yytext);    return WHILE; }
"do"                { printf("DO: %s\n", yytext);       return DO; }

"repeat"            { printf("REPEAT: %s\n", yytext);   return REPEAT; }
"until"             { printf("UNTIL: %s\n", yytext);    return UNTIL; }

"for"               { printf("FOR: %s\n", yytext);      return FOR; }

"switch"            { printf("SWITCH: %s\n", yytext);   return SWITCH; }
"case"              { printf("CASE: %s\n", yytext);     return CASE; }
"default"           { printf("DEFAULT: %s\n", yytext);  return DEFAULT; }

"int"               { printf("INTEGER: %s\n", yytext);  return INTEGER; }
"float"             { printf("FLOAT: %s\n", yytext);    return FLOAT; }
"char"              { printf("CHAR: %s\n", yytext);     return CHAR; }
"string"            { printf("STRING: %s\n", yytext);     return STRING; }
"bool"              { printf("BOOL: %s\n", yytext);     return BOOL; }

"void"              { printf("VOID: %s\n", yytext);     return VOID; }
"continue"          { printf("CONTINUE: %s\n", yytext); return CONTINUE; }
"break"             { printf("BREAK: %s\n", yytext);    return BREAK; }

"const"             { printf("CONST: %s\n", yytext);    return CONST;}

"print"             { printf("PRINT: %s\n", yytext);    return PRINT;}

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

"="                 { printf("ASSIGN: %s\n", yytext);		 return *yytext; }

"{"                 { printf("LEFT_BRACE: %s\n", yytext);             return *yytext; }
"}"                 { printf("RIGHT_BRACE: %s\n", yytext);            return *yytext; }
"("                 { printf("LEFT_PAREN: %s\n", yytext);             return *yytext; }
")"                 { printf("RIGHT_PAREN: %s\n", yytext);            return *yytext; }
"["                 { printf("LEFT_SQUARE_BRACKET: %s\n", yytext);    return *yytext; }
"]"                 { printf("RIGHT_SQUARE_BRACKET: %s\n", yytext);   return *yytext; }

"++"		     	{ printf("MOD: %s\n", yytext);    return INCR; }
"--"		     	{ printf("MOD: %s\n", yytext);    return DECR; }
"+"                 { printf("PLUS: %s\n", yytext);   return *yytext; }
"-"                 { printf("MINUS: %s\n", yytext);  return *yytext; }
"*"                 { printf("MUL: %s\n", yytext);    return *yytext; }
"/"                 { printf("DIV: %s\n", yytext);    return *yytext; }
"^"                 { printf("POWER: %s\n", yytext);  return *yytext; }
"%"                 { printf("MOD: %s\n", yytext);    return *yytext; }

[0-9]*"."[0-9]+     { 
						printf("FLOAT_CONSTANT: %s\n", yytext);
						yylval.float_value = atof(yytext);	
						return FLOAT_VAL; 
		    		}
		     
0  	             	{
						printf("INTEGER_VAL: %s\n", yytext);
						yylval.int_value = atoi(yytext);	
						return INTEGER_VAL; 
		     		}
		     
[1-9][0-9]*         { 
						printf("INTEGER_VAL: %s\n", yytext); 
						yylval.int_value = atoi(yytext);  
						return INTEGER_VAL; 
		    		}
		    
'[^\\']'            { 
						printf("CHAR_CONSTANT: %s\n", yytext);
						yylval.char_value = yytext[0];
		       			return CHAR_VAL; 
		   			}
		      
\"([^\"\\;]|\\.)*\" { 
						printf("STRING_CONSTANT: %s\n", yytext);
						yylval.str_value = strdup(yytext);
		       			return STRING_VAL; 
		      		}
		      
"true"		     	{ 
						printf("BOOL_CONSTANT: %s\n", yytext);
						yylval.bool_value = 1;      
						return TRUE_VAL; 
					}

"false"             { 
						printf("BOOL_CONSTANT: %s\n", yytext);
						yylval.bool_value = 0;
						return FALSE_VAL; 
					}

[a-zA-Z_][a-zA-Z0-9_]* {
						printf("IDENTIFIER: %s\n", yytext);
						yylval.identifier = strdup(yytext);
						return IDENTIFIER; 
					}

";"                 { printf("SEMICOLON: %s\n", yytext);              return *yytext; }
","                 { printf("COMMA: %s\n", yytext);                  return *yytext; }
"?"                 { printf("QUESTION_MARK: %s\n", yytext);          return *yytext; }
":"		    		{ printf("COLON: %s\n", yytext);          return *yytext; }

\/\/.*		    	{ printf("inline comment");} // Skip inline comments
\/\*([^*]|\*+[^/])*\*+\/ { printf("multi lines comment\n"); } // Skip multi lines comments 


"\n"            	{ lineno += 1; }
[ \t]             ; // Skip whitespace and newlines
. 			yyerror("invalid token");
%%

int mywrap()
{
    return 1;
}