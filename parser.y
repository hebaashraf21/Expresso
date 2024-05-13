%{
	#include <stdio.h>
	#include <math.h>
	void yyerror(const char *);
	int yylex(void);
	int sym[26];
%}

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

%right '='
%left LOGICAL_AND LOGICAL_OR

%left EQUALS NOT_EQUALS
%left LESS_THAN LESS_THAN_OR_EQUALS GREATER_THAN GREATER_THAN_OR_EQUALS

%left PLUS MINUS

%right LOGICAL_NOT

%left MUL DIV MOD
%left POWER
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
        | assignment ';'
        | type IDENTIFIER ';'
        
        /*Constant declaration*/
        | CONST type IDENTIFIER '=' expr ';'	{ sym[$3] = $5; }
	
	/*expressions*/                          
        | expr ';' 				
        
        /*Assignment statements*/
        | IDENTIFIER '=' expr ';'		{ sym[$1] = $3; }
        
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
        ;	
	
	
type:   INTEGER
      | FLOAT
      | CHAR
      | STRING
      | BOOL
      ;


assignment:
	type IDENTIFIER '=' expr 	{ sym[$2] = $4; }


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
       TRUE_VAL				{ $$ = sym[$1]; }
     | FALSE_VAL				{ $$ = sym[$1]; }

     | IDENTIFIER				{ $$ = sym[$1]; }

     | INTEGER_VAL				{ $$ = sym[$1]; }
     | FLOAT_VAL				{ $$ = sym[$1]; }
     | CHAR_VAL				{ $$ = sym[$1]; }
     | STRING_VAL				{ $$ = sym[$1]; }
	
     /* (expressions) */
     | '(' expr ')'				{ $$ = $2; }
     
     /* Mthematical expressions */
     | MINUS expr				{ $$ = - $2; }
     | expr PLUS expr				{ $$ = $1 + $3; }
     | expr MINUS expr				{ $$ = $1 - $3; }
     | expr MUL expr				{ $$ = $1 * $3; }
     | expr DIV expr				{ $$ = $1 / $3; }
     | expr POWER expr				{ $$ = pow($1, $3); }
     | expr MOD expr				{ $$ = $1 % $3; }
     
     /* logical expressions */
     | expr LOGICAL_AND expr			{ $$ = $1 && $3; }
     | expr LOGICAL_OR expr			{ $$ = $1 || $3; }
     | LOGICAL_NOT expr			{ $$ = !$2; }
     
     /* comparison expressions */
     | expr EQUALS expr			{ $$ = ($1 == $3); }
     | expr NOT_EQUALS expr			{ $$ = ($1 != $3); }
     | expr LESS_THAN expr			{ $$ = ($1 < $3); }
     | expr LESS_THAN_OR_EQUALS expr		{ $$ = ($1 <= $3); }
     | expr GREATER_THAN expr			{ $$ = ($1 > $3); }
     | expr GREATER_THAN_OR_EQUALS expr 	{ $$ = ($1 >= $3); }
     
     
     ;
%%

int main()
{
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}
