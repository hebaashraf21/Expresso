%{
	#include <stdio.h>
	#include <math.h>
    #include <stdbool.h> 
	void yyerror(const char *);
	extern int yylex(void);
	extern FILE *yyin;
    extern FILE *yyout;
    extern int lineno;
	int sym[26];

    #define HASH_TABLE_SIZE 503
    typedef struct Value{
        int int_value;         
        char* str_value; 
        char char_value;
        float float_value;
        bool bool_value;
    }Value;

    typedef struct Symbol{
        char *name;
        char *type;
        Value value;
        bool isConst;
        struct Symbol* next;
    }Symbol;

    Symbol *symbol_table [HASH_TABLE_SIZE];

    int hash_function(char *key);
    void insert_symbol(char *name, char *type, bool is_const);

%}

%union { 
    int int_value;        
    char* str_value;        
    char char_value;      
    float float_value;  
    bool bool_value;    
    char* identifier;
}

%token PRINT

%token IF ELSE 
%token WHILE FOR DO CONTINUE BREAK
%token SWITCH CASE DEFAULT 
%token REPEAT UNTIL

%token VOID ENUM

%token INTEGER FLOAT CHAR BOOL STRING
%token CONST 
%token '(' ')' '{' '}' '[' ']' 
%token ';' ',' '?' ':'

%token <float_value> FLOAT_VAL 
%token <int_value> INTEGER_VAL 
%token <char_value> CHAR_VAL 
%token <str_value> STRING_VAL 
%token <bool_value> TRUE_VAL 
%token <bool_value> FALSE_VAL 
%token <identifier>  IDENTIFIER

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
        statements
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
        | type IDENTIFIER '=' expr ';'
        
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

int hash_function(char *key){
	int hash_index = 0;
	// Loop through all the characters of the string
	while(*key!='\0'){
		// Update the hash value using a simple multiplicative hash function
		// It has good distribution properties and is easy to implement.
        hash_index = (hash_index * 31) + *key;
        key++;
	} 
	return hash_index % HASH_TABLE_SIZE;
}

void insert_symbol(char *name, char *type, bool is_const){
    int hash_index = hash_function(name);
    Symbol *table_entry = symbol_table[hash_index];
    // insert at the end of the bucket
    while(table_entry ->next){
		table_entry = table_entry ->next;
	}
    Symbol* new_entry = (Symbol*) malloc(sizeof(Symbol));
    new_entry -> name = name;
    new_entry -> type = type;
    new_entry -> isConst = is_const;
    new_entry -> next = NULL;
    table_entry -> next = new_entry;
}

int main (int argc, char *argv[]){

    // parsing
    yyin = fopen(argv[1], "r");
    yyparse();
    fclose(yyin);

    return 0;
}

void yyerror(char const *s)
{
    fprintf(stderr, "%s at line %d\n", s, lineno);
}
