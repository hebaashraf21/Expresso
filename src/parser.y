%{
	#include <stdio.h>
	#include <math.h>
    #include <stdbool.h> 
    #include <string.h>
    #include <stdlib.h>
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
        char* id_value;
    }Value;

    typedef struct Node{
        char *type;
        Value value;
    }Node;

    typedef struct Scope{
        struct Scope* parent;
    }Scope;

    typedef struct Symbol{
        char *name;
        char *type;
        Value value;
        bool is_const;
        Scope *scope;
        bool is_initialized;
        bool is_used;
    }Symbol;


    Scope *current_scope;

    Symbol *symbol_table [Symbol_TABLE_SIZE];
    int symbol_table_idx = -1;
    void insert_symbol(char *name, char *type, bool is_const, Scope * scope);
    Node* insert_node(char *type, Value value);

    // to check peoper use
    int is_correct_scope(char *name, Scope *scope, bool in_place);
    // to prevent redeclaration
    bool is_redeclared(char *name, Scope *scope);
    // to prevent type mismatch
    bool is_same_type(char *name, Scope *scope, Node* id_node);
    // check if we are assigning a value to const
    bool is_const(char *name, Scope *scope);
    // when initialize variable ==> set it initialized
    void set_initialized(char* name, Scope *scope);
    // check if a variable is initialized before using
    bool is_initialized(char* name, Scope *scope);
    // shen use varuiable ==> set that
    void set_used(char* name, Scope *scope);

    // check all variables are used
    bool is_all_used();

    // to deal with nested blocks
    void enter_scope();
    void exit_scope();
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
%type <node_value> terminals
%type <node_value> expr

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
    /*Empty production*/
	 ';'  
	 /*Variables declaration*/
        | datatype IDENTIFIER ';'               {
                                                // check multiple declaration
                                                if(!is_redeclared($2, current_scope)){
                                                    // insert the symbol
                                                    insert_symbol($2, $1->type, false, current_scope);
                                                }
                                                }

        | datatype IDENTIFIER '=' expr ';'      {
                                                // check multiple declaration
                                                if(!is_redeclared($2, current_scope)){
                                                    // insert the symbol
                                                    insert_symbol($2, $1->type, false, current_scope);
                                                    if(strcmp($4 -> type, "ID") == 0){
                                                        if(is_correct_scope($4 -> value.id_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($2, current_scope, $4)){
                                                                // set initialized
                                                                set_initialized($2, current_scope);
                                                            }
                                                        }
                                                    }
                                                    
                                                }
                                                }
        
        /*Constant declaration*/
        | CONST datatype IDENTIFIER '=' expr ';' {
                                                // check multiple declaration
                                                if(!is_redeclared($3, current_scope)){
                                                    // insert the symbol
                                                    insert_symbol($3, $2->type, true, current_scope);
                                                    if(strcmp($5 -> type, "ID") == 0){
                                                        if(is_correct_scope($5 -> value.id_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($3, current_scope, $5)){
                                                                // set initialized
                                                                set_initialized($3, current_scope);
                                                            }
                                                        }
                                                    }
                                                }
                                                }				
        
        /*Assignment statements*/
        | IDENTIFIER '=' expr ';'		    {
                                            // check declared or not ($1)
                                            if(is_correct_scope($1, current_scope, true) == 1){
                                                // check if constant
                                                if(!is_const($1, current_scope)){
                                                    if(strcmp($3 -> type, "ID") == 0){
                                                        if(is_correct_scope($3 -> value.id_value, current_scope, false) == 1){
                                                            if(is_same_type($1, current_scope, $3)){
                                                                // set initialized
                                                                set_initialized($1, current_scope);
                                                            } 
                                                        }
                                                    }
                                                }
                                            }
                                            }
        
        /*Print Statement*/
        | PRINT '(' expr ')' ';'                 
            
        
        /*Conditional Statements*/
        | IF '(' expr ')' '{' {enter_scope();} statements '}'  {exit_scope();} else_stmt
        
        /*Loops*/
        | WHILE '(' expr ')' '{' {enter_scope();} statements '}' {exit_scope();}
        | FOR '(' assignment ';' expr ';' IDENTIFIER '=' expr ')' '{' {enter_scope();} statements '}'  {exit_scope();}
        | REPEAT '{' {enter_scope();} statements '}' {exit_scope();} UNTIL '(' expr ')' ';'
        
        /*Switch Statements*/
        | SWITCH '(' IDENTIFIER ')' '{' {enter_scope();} case_list default_case '}'  {exit_scope();}
        
        /*Block Strusture*/
        | '{' {enter_scope();} statements'}' {exit_scope();}
        
        
        /*Functions Definition*/   
        | VOID IDENTIFIER '(' parameters_list ')' '{' {enter_scope();} statements '}' {exit_scope();}
        | datatype IDENTIFIER '(' parameters_list ')' '{' {enter_scope();} statements '}' {exit_scope();}
        
        /*Functions Call*/   
        | IDENTIFIER '(' parameters_list ')' ';'
        | BREAK
        | CONTINUE
        ;	
	
else_stmt:
        /*Empty production*/
        |
        ELSE '{' {enter_scope();} statements '}'  {exit_scope();}
datatype:   
        INTEGER             {
                            struct Value value;
                            $$ = insert_node("INT", value);
                            }
      | FLOAT               {
                            struct Value value;
                            $$ = insert_node("FLOAT", value);
                            }
      | CHAR                {
                            struct Value value;
                            $$ = insert_node("CHAR", value);
                            }
      | STRING              {
                            struct Value value;
                            $$ = insert_node("STRING", value);
                            }
      | BOOL                {
                            struct Value value;
                            $$ = insert_node("BOOL", value);
                            }
      ;


assignment:
	datatype IDENTIFIER '=' expr                {
                                                // check multiple declaration
                                                if(!is_redeclared($2, current_scope)){
                                                    // insert the symbol
                                                    insert_symbol($2, $1->type, false, current_scope);
                                                    // check type matching
                                                    if(strcmp($4 -> type, "ID") == 0){
                                                        if(is_correct_scope($4 -> value.id_value, current_scope, false) == 1){
                                                            if(is_same_type($2, current_scope, $4)){
                                                                // set initialized
                                                                set_initialized($2, current_scope);
                                                            } 
                                                        }
                                                    }
                                                     
                                                }
                                                }

var_declaration: 
		datatype IDENTIFIER                     {
                                                // check multiple declaration
                                                if(!is_redeclared($2, current_scope)){
                                                    // insert the symbol
                                                    insert_symbol($2, $1->type, false, current_scope);
                                                }
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

terminals: 
      TRUE_VAL	            {
                            Value value;
                            value.bool_value = true;
                            $$ = insert_node("BOOL", value);
                            }	

    | FALSE_VAL	            {
                            Value value;
                            value.bool_value = false;
                            $$ = insert_node("BOOL", value);
                            }			

    | IDENTIFIER            {
                            Value value;
                            value.id_value = $1;
                            $$ = insert_node("ID", value);
                            // check declared
                            if(is_correct_scope($1, current_scope, true) == 1){
                                // check initialized
                                if(is_initialized($1, current_scope)){
                                    // set used
                                    set_used($1, current_scope);
                                }
                            }
                            }          

    | INTEGER_VAL	        {
                            Value value;
                            value.int_value = $1;
                            $$ = insert_node("INT", value);
                            }	

    | FLOAT_VAL		        {
                            Value value;
                            value.float_value = $1;
                            $$ = insert_node("FLOAT", value);
                            }	

    | CHAR_VAL				{
                            Value value;
                            value.char_value = $1;
                            $$ = insert_node("CHAR", value);
                            }

    | STRING_VAL            {
                            Value value;
                            value.str_value = $1;
                            $$ = insert_node("STRING", value);
                            }
    ;
    
expr:
    terminals				
	
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

void insert_symbol(char *name, char *type, bool is_const, Scope *scope){
    symbol_table_idx++;
    Symbol *new_symbol = malloc(sizeof(Symbol));
    // Allocate memory for name and type
    new_symbol->name = strdup(name);
    new_symbol->type = strdup(type);
    
    // Initialize other fields
    new_symbol->is_const = is_const;
    new_symbol->scope = scope;
    new_symbol->is_initialized = false;
    new_symbol->is_used = false;

    // Initialize Value field based on type
    if (strcmp(type, "INT") == 0) {
        new_symbol->value.int_value = 0; // Initialize to default value for int
    } else if (strcmp(type, "FLOAT") == 0) {
        new_symbol->value.float_value = 0.0; // Initialize to default value for float
    } else if (strcmp(type, "CHAR") == 0) {
        new_symbol->value.char_value = '\0'; // Initialize to default value for char
    } else if (strcmp(type, "BOOL") == 0) {
        new_symbol->value.bool_value = false; // Initialize to default value for bool
    } else {
        // Handle invalid type
        fprintf(stderr, "Invalid type: %s\n", type);
        //exit(EXIT_FAILURE);
    }

    // Insert symbol into symbol table
    symbol_table[symbol_table_idx] = new_symbol;
}


Node* insert_node(char *type, Value value){
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->type = strdup(type);
    new_node -> value = value;
    return new_node;
}

int is_correct_scope(char* name, Scope *scope, bool in_place){
    bool found = false;
    for (int i =0; i<=symbol_table_idx; i++){
        if(strcmp(symbol_table[i]-> name, name)==0){
            found = true;
            Scope *temp_scope = scope;
            while(temp_scope != NULL){
                if(symbol_table[i] -> scope == temp_scope){
                    // return 1 if all right!
                    return 1;
                }
                else{
                    temp_scope = temp_scope -> parent;
                }
            }
        }
    }
    if(!found){
        // return -1 if not declared (ERROR)
        if(in_place){
            printf("Not Declared: %s at line %d\n", name, lineno);
        }
        return -1;
    }
    else{
        // found = true ==> declared but wrong scope (ERROR)
        if(in_place){
            printf("Not Declared In this scope: %s at line %d\n", name, lineno);
        }
        return 0; 
    }
}

bool is_redeclared(char* name, Scope *scope){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    // redeclaration (ERROR)
                    printf("Redeclared: %s at line %d\n", name, lineno);
                    return true;
                }
                else{
                    temp_scope = temp_scope -> parent;
                }
            }
        }
    }
    // not redeclaration
    return false;
}

bool is_same_type(char *name, Scope* scope, Node* id_node){
    for (int i =0; i<=symbol_table_idx; i++){
        // get the variable in this scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    if(strcmp(symbol_table[i]-> type, id_node -> type)==0){
                        return true;
                    }
                    else{
                        // IDs type is ID
                        // we want to check the ID type
                        if(strcmp(id_node-> type, "ID")==0){
                            // get the type of the ID from the symbol table
                            for (int j =0; j<=symbol_table_idx; j++){
                                // get the variable in this scope
                                if(strcmp(symbol_table[j]-> name, id_node -> value.id_value)==0){
                                    if(strcmp(symbol_table[i]-> type, symbol_table[j]-> type)==0){
                                        return true;
                                    }
                                }
                            }
                        }
                        else{
                            printf("type mismatch: %s at line %d\n", name, lineno);
                            return false;
                        }
                        
                    }
                }
                else{
                    temp_scope = temp_scope -> parent;
                }
            }
        }
    }
}

bool is_const(char *name, Scope *scope){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    if(symbol_table[i]-> is_const){
                        // const (ERROR)
                        printf("trying to modify const variable %s at line %d\n\n",name, lineno);
                        return true;
                    }
                }
                else{
                    temp_scope = temp_scope -> parent;
                }
            }
            
        }
    }
    return false;
}

void set_initialized(char* name, Scope *scope){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    symbol_table[i]-> is_initialized = true;
                    return;
                }
                else{
                    temp_scope = temp_scope -> parent;
                }
            }
            
        }
    }
}

bool is_initialized(char* name, Scope *scope){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    if(symbol_table[i]-> is_initialized){
                        return true;
                    }
                    else{
                        // used before initializing (ERROR)
                        printf("trying to use variable before initializing %s at line %d\n",name, lineno);
                        return false;
                    }
                }
                else{
                    temp_scope = temp_scope -> parent;
                }
            }
        }
    }
}

void set_used(char* name, Scope *scope){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    symbol_table[i]-> is_used = true;
                    return;
                }
                else{
                    temp_scope = temp_scope -> parent;
                }
            }
            
        }
    }
}

bool is_all_used(){
    for (int i =0; i<=symbol_table_idx; i++){
        if(symbol_table[i] && symbol_table[i]-> is_used == false){
            return false;
        }
    }
    return true;
}

void enter_scope(){
    Scope* new_scope = (Scope*) malloc(sizeof(Scope));
    new_scope -> parent = current_scope;
    current_scope = new_scope;
}

void exit_scope(){
    current_scope = current_scope -> parent;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    current_scope = (Scope*) malloc(sizeof(Scope));
    if (current_scope == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    current_scope->parent = NULL;
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        free(current_scope); // Clean up allocated memory
        return EXIT_FAILURE;
    }
    yyparse();

    fclose(yyin);

    if (!is_all_used()) {
        printf("Not all variables used\n");
    }

    free(current_scope); // Clean up allocated memory before exiting
    return EXIT_SUCCESS;
}


void yyerror(char const *s)
{
    fprintf(stderr, "%s at line %d\n", s, lineno);
}