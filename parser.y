%{
	#include <stdio.h>
	void yyerror(const char *);
	int yylex(void);
	int sym[26];
%}

%token IF ELSE WHILE FOR DO SWITCH CASE DEFAULT REPEAT UNTIL
%token INTEGER FLOAT CHAR BOOL STRING
%token VOID ENUM RETURN CONTINUE BREAK CONST PRINT ASSERT
%token '(' ')' '{' '}' '[' ']' 
%token SEMICOLON COMMA QUESTION_MARK
%token FLOAT_VAL INTEGER_VAL CHAR_VAL STRING_VAL TRUE_VAL FALSE_VAL 
%token IDENTIFIER

%left EQUALS NOT_EQUALS LESS_THAN LESS_THAN_OR_EQUALS GREATER_THAN GREATER_THAN_OR_EQUALS
%left PLUS MINUS MUL DIV POWER MOD
%left LOGICAL_AND LOGICAL_OR

%right '='
%right LOGICAL_NOT

%nonassoc UMINUS

%%

program:
        program statement '\n'
        | /* NULL */
        ;

        
stmt:
	 ';'  
	 /*Variables declaration*/
        | assignmen ';'
        
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
        | FOR '(' assignmen ';' expr ';' expr ')' '{' stmt '}'
        
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


assignmen:
	type IDENTIFIER '=' expr 


var_declaration: 
		type IDENTIFIER
		;


parameters_list:
		''
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

     /* comparison expressions */
     | expr EQUALS expr
     | expr NOT_EQUALS expr
     | expr LESS_THAN expr
     | expr LESS_THAN_OR_EQUALS expr
     | expr GREATER_THAN expr
     | expr GREATER_THAN_OR_EQUALS expr 

     /* logical expressions */
     | expr LOGICAL_AND expr
     | expr LOGICAL_OR expr
     | LOGICAL_NOT expr
     
     /* Mthematical expressions */
     | expr PLUS expr				{ $$ = $1 + $3; }
     | expr MINUS expr				{ $$ = $1 - $3; }
     | expr MUL expr				{ $$ = $1 * $3; }
     | expr DIV expr				{ $$ = $1 / $3; }
     | expr POWER expr				{ $$ = pow($1, $3); }
     | expr MOD expr				{ $$ = $1 % $3; }
     | MINUS expr				{ $$ = - $3; }
     
     /* logical expressions */
     | expr LOGICAL_AND expr
     | expr LOGICAL_OR expr
     | LOGICAL_NOT expr
     
     /* (expressions) */
     | '(' expr ')'				{ $$ = $2; }
     ;
%%

int main()
{
    yyparse();
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
