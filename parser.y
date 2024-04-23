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
%token SEMICOLON COMMA QUESTION_MARK
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
        program stmt '\n'
        | /* NULL */
        ;

        
stmt:
	 ';'  
	 /*Variables declaration*/
        | assignment ';'
        
        /*Constant declaration*/
        | CONST type IDENTIFIER '=' expr ';'
	
	/*expressions*/                          
        | expr ';' 				{ printf("%d\n", $1); }
        
        /*Assignment statements*/
        | IDENTIFIER '=' expr ';'		{ sym[$1] = $3; }
        
        /*Print Statement*/
        | PRINT expr ';'                 
            
        
        /*Conditional Statements*/
        | IF '(' expr ')' '{' stmt '}' ELSE '{' stmt '}'
        | IF '(' expr ')' '{' stmt '}'
        
        /*Loops*/
        | WHILE '(' expr ')' '{' stmt '}'
        | FOR '(' assignment ';' expr ';' expr ')' '{' stmt '}'
        
        /*Switch Statements*/
        | SWITCH '(' IDENTIFIER ')' '{' case_list default_case '}'
        
        /*Block Strusture*/
        | '{' stmt_list '}'
        
        
        /*Functions*/   
        | VOID IDENTIFIER '(' parameters_list ')' '{' stmt '}'
        | type IDENTIFIER '(' parameters_list ')' '{' stmt '}'
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


stmt_list:
          stmt
         | stmt_list stmt
	 ;
              

case_list:
    /* Empty production */
    | case_list case_stmt
    ;


default_case:
    DEFAULT ':' stmt
    
    
case_stmt:
    CASE expr ':' stmt
    ;  


expr :
       TRUE_VAL
     | FALSE_VAL

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

int main()
{
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}
