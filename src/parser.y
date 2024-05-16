%{
	#include <stdio.h>
	#include <math.h>
    #include <stdbool.h> 
    #include <string.h>

	void yyerror(const char *);
	extern int yylex(void);
	extern FILE *yyin;
    extern FILE *yyout;
    extern int lineno;
	int sym[26];

    #define Symbol_TABLE_SIZE 1000

    typedef struct Value{
        int int_value;         
        char* str_value; 
        char char_value;
        float float_value;
        bool bool_value;
    }Value;

    typedef struct Node{
        char *type;
    }Node;

    typedef struct Symbol{
        char *name;
        char *type;
        Value value;
        bool is_const;
        int scope;
    }Symbol;

    Symbol *symbol_table [Symbol_TABLE_SIZE];
    int symbol_table_idx = -1;
    int current_scope = 0;
    int get_symbol_index(char *name);
    void insert_symbol(char *name, char *type, bool is_const, int scope);
    Node* insert_node(char *type);
    // to check peoper use
    int is_correct_scope(char *name, int scope);
    // to prevent redeclaration
    bool is_redeclared(char *name, int scope);
    
%}

%union { 
    int int_value;        
    char* str_value;        
    char char_value;      
    float float_value;  
    bool bool_value;    
    char* identifier;
    struct Node *node_value;
;}

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

// association rules and operators precedence
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

// types of non terminals
%type <node_value> datatype
%type <node_value> values

// starting point of parsing
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
        | datatype IDENTIFIER ';'               {
                                                // check multiple declaration
                                                is_redeclared($2,current_scope);
                                                // insert the symbol
                                                insert_symbol($2, $1->type, false, current_scope);
                                                }

        | datatype IDENTIFIER '=' expr ';'      {
                                                // check multiple declaration
                                                is_redeclared($2,current_scope);
                                                // insert the symbol
                                                insert_symbol($2, $1->type, false, current_scope);
                                                // check type matching
                                                }
        
        /*Constant declaration*/
        | CONST datatype IDENTIFIER '=' expr ';' {
                                                // check multiple declaration
                                                is_redeclared($3,current_scope);
                                                // check type matching
                                                // set initialized ($1)
                                                // insert the symbol
                                                insert_symbol($3, $2->type, false, current_scope);
                                                }				
        
        /*Assignment statements*/
        | IDENTIFIER '=' expr ';'		    {
                                            // check declared or not ($1)
                                            is_correct_scope($1, current_scope);
                                            // check if constant
                                            // check type matching ($1)
                                            // set initialized ($1)
                                            }
        
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
        | datatype IDENTIFIER '(' parameters_list ')' '{' statements '}'
        
        /*Functions Call*/   
        | IDENTIFIER '(' parameters_list ')' ';'
        | BREAK
        | CONTINUE
        ;	
	
	
datatype:   
        INTEGER             {$$ = insert_node("INT");}
      | FLOAT               {$$ = insert_node("FLOAT");}
      | CHAR                {$$ = insert_node("CHAR");}
      | STRING              {$$ = insert_node("STRING");}
      | BOOL                {$$ = insert_node("BOOL");}
      ;


assignment:
	datatype IDENTIFIER '=' expr                {
                                                // check multiple declaration
                                                is_redeclared($2,current_scope);
                                                // check type matching
                                                // insert the symbol
                                                insert_symbol($2, $1->type, false, current_scope);
                                                }

var_declaration: 
		datatype IDENTIFIER                     {
                                                // check multiple declaration
                                                is_redeclared($2,current_scope);
                                                // insert the symbol
                                                insert_symbol($2, $1->type, false, current_scope);
                                                }
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

values: 
      TRUE_VAL	            {$$ = insert_node("BOOL");}			
    | FALSE_VAL	            {$$ = insert_node("BOOL");}			

    | IDENTIFIER            {
                            // check declared
                            is_correct_scope($1, current_scope);
                            // check initialized
                            // set used
                            }          

    | INTEGER_VAL	        {$$ = insert_node("INT");}			
    | FLOAT_VAL		        {$$ = insert_node("FLOAT");}		
    | CHAR_VAL				{$$ = insert_node("CHAR");}
    | STRING_VAL            {$$ = insert_node("STRING");}
    ;
    
expr :
    values				
	
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

void insert_symbol(char *name, char *type, bool is_const, int scope){
    symbol_table_idx ++;
    Symbol *new_symbol =  malloc(sizeof(Symbol));
    new_symbol -> name = name;
    new_symbol -> type = type;
    new_symbol -> is_const = is_const;
    new_symbol -> scope = scope;
    symbol_table[symbol_table_idx] = new_symbol;
}

Node* insert_node(char *type){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node -> type = type;
    return new_node;
}

int get_symbol_index(char *name){
    int index = -1;
    for (int i =0; i<=symbol_table_idx; i++){
        if(strcmp(symbol_table[i]-> name, name)==0){
            index = i;
            break;
        }
    }
    return index;
}

int is_correct_scope(char* name, int scope){
    bool found = false;
    for (int i =0; i<=symbol_table_idx; i++){
        if(strcmp(symbol_table[i]-> name, name)==0){
            found = true;
            if(symbol_table[i] -> scope == scope){
                // return 1 if all right!
                return 1;
            }
        }
    }
    if(!found){
        // return -1 if not declared (ERROR)
        printf("Not Declared: %s\n", name);
        return -1;
    }
    else{
        // found = true ==> declared but wrong scope (ERROR)
        return 0; 
    }
}

bool is_redeclared(char* name, int scope){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0 && symbol_table[i] -> scope == scope){
            // redeclaration (ERROR)
            printf("Redeclared: %s\n", name);
            return 0;
        }
    }
    // not redeclaration
    return 1;
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