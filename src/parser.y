%{
	#include <stdio.h>
	#include <math.h>
    #include <stdbool.h> 
	#include "symbol_table.c" 
	void yyerror();
	extern int yylex(void);
	extern FILE *yyin;
    extern int lineno;
	int sym[26];
%}

%union { 
    int int_val;          /* integer value */ 
    char* str_val;        /* string value */
    char char_val;      /* char value */
    float float_val;  /* float value */
    bool bool_val;    /* boolean value */
    char* identifier; /* IDENTIFIER */
}
%token PRINT ASSERT


%token IF ELSE 
%token WHILE FOR DO CONTINUE BREAK
%token SWITCH CASE DEFAULT 
%token REPEAT UNTIL

%token VOID ENUM RETURN

%token INTEGER FLOAT CHAR BOOL STRING
%token CONST 
%token '(' ')' '{' '}' '[' ']' 
%token ';' ',' '?' ':'
%token FLOAT_VAL INTEGER_VAL CHAR_VAL STRING_VAL TRUE_VAL FALSE_VAL 
%token IDENTIFIER
%token INCR DECR

%right '='
%left LOGICAL_OR
%left LOGICAL_AND

%left EQUALS NOT_EQUALS
%left LESS_THAN LESS_THAN_OR_EQUALS GREATER_THAN GREATER_THAN_OR_EQUALS

%left '+' '-'


%left '*' '/' '%'
%left '^'
%right LOGICAL_NOT
%nonassoc UMINUS
%left INCR DECR

%start program
%%

program:
        statements '\n'
        | /* NULL */
        ;


statements:
        stmt
        | statements stmt
        ;

        
stmt:
	 ';'  
	 /*Variables declaration*/
        | type IDENTIFIER ';'
        
        /*Constant declaration*/
        | CONST type IDENTIFIER '=' expr ';'
	
	/*expressions*/                          
        | expr ';' 				
        
        /*Assignment statements*/
        | IDENTIFIER '=' expr ';'		
        
        /*Print Statement*/
        | PRINT '(' expr ')' ';'                 
            
        
        /*Conditional Statements*/
        | IF '(' expr ')' '{' statements '}' ELSE '{' statements '}'
        | IF '(' expr ')' '{' statements '}'
        
        /*Loops*/
        | WHILE '(' expr ')' '{' statements '}'
        | FOR '(' assignment ';' expr ';' IDENTIFIER '=' expr ')' '{' statements '}'
        | REPEAT '{' statements '}' UNTIL '(' expr ')' ';'
        
        /*Switch Statements*/
        | SWITCH '(' IDENTIFIER ')' '{' case_list default_case '}'
        
        /*Block Strusture*/
        | '{' statements '}'
        
        
        /*Functions Definition*/   
        | VOID IDENTIFIER '(' parameters_list ')' '{' statements '}'
        | type IDENTIFIER '(' parameters_list ')' '{' statements '}'
        
        /*Functions Call*/   
        | IDENTIFIER '(' parameters_list ')' ';'
        | BREAK
        | RETURN
        | CONTINUE
        ;	
	
	
type:   INTEGER
      | FLOAT
      | CHAR
      | STRING
      | BOOL
      ;


assignment:
	type IDENTIFIER '=' expr 


var_declaration: 
		type IDENTIFIER
		;


parameters_list:
		/* Empty production */
		| var_declaration
		| parameters_list ',' var_declaration
		;
              

case_list:
    /* Empty production */
    | case_list case_stmt
    ;


default_case:
    DEFAULT ':' stmt ';'
    
    
case_stmt:
    CASE expr ':' stmt ';'
    ;  


expr :
       TRUE_VAL				
     | FALSE_VAL				

     | IDENTIFIER

     | INTEGER_VAL				
     | FLOAT_VAL				
     | CHAR_VAL				
     | STRING_VAL				
	
     /* (expressions) */
     | '(' expr ')'				
     
     /* Mthematical expressions */
     | '-' expr	
     | INCR expr                 		
     | expr INCR                 		
     | DECR expr                 		
     | expr DECR                 		
     | expr '+' expr				
     | expr '-' expr				
     | expr '*' expr				
     | expr '/' expr				
     | expr '^' expr				
     | expr '%' expr				
     
     /* logical expressions */
     | expr LOGICAL_AND expr			
     | expr LOGICAL_OR expr			
     | LOGICAL_NOT expr			
     
     /* comparison expressions */
     | expr EQUALS expr			
     | expr NOT_EQUALS expr			
     | expr LESS_THAN expr			
     | expr LESS_THAN_OR_EQUALS expr		
     | expr GREATER_THAN expr			
     | expr GREATER_THAN_OR_EQUALS expr 	
     
     
     ;
%%

int main (int argc, char *argv[]){

    // parsing
    int flag;
    yyin = fopen(argv[1], "r");
    flag = yyparse();
    fclose(yyin);
    
    return flag;
}

void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d\n", lineno);
}
