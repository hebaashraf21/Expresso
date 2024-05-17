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
        char* func_value;
    }Value;

    typedef struct Node{
        char *type;
        Value value;
    }Node;

    typedef struct Scope{
        struct Scope* parent;
    }Scope;

    typedef struct function_parameter{
        char *name;
        char *type;
        Value value;
    }function_parameter;

    typedef struct Symbol{
        char *name;
        char *type;
        Value value;
        bool is_const;
        Scope *scope;
        bool is_initialized;
        bool is_used;
        // for function name symbols
        function_parameter * parameters[100];
        char* return_type;
        int no_of_parameters;
    }Symbol;


    Scope *current_scope;

    Symbol *symbol_table [Symbol_TABLE_SIZE];
    int symbol_table_idx = -1;
    void insert_symbol(char *name, char *type, bool is_const, Scope * scope, char* return_type);
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

    // for dealing with Functions
    // check if a symbol is function or variable
    // second parameter to handle errors
    bool is_function(char* name, Scope *scope, bool need_to_be_function);
    // insert the function parameters in the symol table
    void insert_function_parameters(char* name, Scope *scope, function_parameter ** parameters, int no_of_parameters);
    bool check_correct_parameters(char* name, Scope *scope, function_parameter ** parameters, int no_of_parameters);

    int parameter_count = 0;
    function_parameter * parameters[100];

    // check all variables are used
    bool is_all_used();

    // to deal with nested blocks
    void enter_block();
    void exit_block();
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
%type <node_value> switch_identifier
%type <node_value> function_call
%type<int_value> parameters_list
%type<int_value> parameters_list_call
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
                                                    insert_symbol($2, $1->type, false, current_scope, NULL);
                                                }
                                                }

        | datatype IDENTIFIER '=' expr ';'      {
                                                // check multiple declaration
                                                if(!is_redeclared($2, current_scope)){
                                                    // insert the symbol
                                                    insert_symbol($2, $1->type, false, current_scope,"");
                                                    if(strcmp($4 -> type, "ID") == 0){
                                                        if(is_correct_scope($4 -> value.id_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($2, current_scope, $4)){
                                                                // set initialized
                                                                set_initialized($2, current_scope);
                                                            }
                                                        }
                                                    }
                                                    else if(strcmp($4 -> type, "FUNC") == 0){
                                                        if(is_correct_scope($4 -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($2, current_scope, $4)){
                                                                // set initialized
                                                                set_initialized($2, current_scope);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type($2, current_scope, $4)){
                                                            // set initialized
                                                            set_initialized($2, current_scope);
                                                        }
                                                    }
                                                    
                                                }
                                                }
        
        /*Constant declaration*/
        | CONST datatype IDENTIFIER '=' expr ';' {
                                                // check multiple declaration
                                                if(!is_redeclared($3, current_scope)){
                                                    // insert the symbol
                                                    insert_symbol($3, $2->type, true, current_scope,NULL);
                                                    if(strcmp($5 -> type, "ID") == 0){
                                                        if(is_correct_scope($5 -> value.id_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($3, current_scope, $5)){
                                                                // set initialized
                                                                set_initialized($3, current_scope);
                                                            }
                                                        }
                                                    }
                                                    else if(strcmp($5 -> type, "FUNC") == 0){
                                                        if(is_correct_scope($5 -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($3, current_scope, $5)){
                                                                // set initialized
                                                                set_initialized($3, current_scope);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        // check type matching
                                                        if(is_same_type($3, current_scope, $5)){
                                                            // set initialized
                                                            set_initialized($3, current_scope);
                                                        }
                                                    }
                                                }
                                                }				
        
        /*Assignment statements*/
        | IDENTIFIER '=' expr ';'		    {
                                            // check declared or not ($1)
                                            if(is_correct_scope($1, current_scope, true) == 1 && !is_function($1, current_scope,false)){
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
                                                    else if(strcmp($3 -> type, "FUNC") == 0){
                                                        if(is_correct_scope($3 -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($1, current_scope, $3)){
                                                                // set initialized
                                                                set_initialized($1, current_scope);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type($1, current_scope, $3)){
                                                            // set initialized
                                                            set_initialized($1, current_scope);
                                                        } 
                                                    }
                                                }
                                            }
                                            }
        
        /*Print Statement*/
        | PRINT '(' expr ')' ';'                 
            
        
        /*Conditional Statements*/
        | IF '(' expr ')' '{' {enter_block();} statements '}'  {exit_block();} else_stmt
        
        /*Loops*/
        | WHILE '(' expr ')' '{' {enter_block();} statements '}' {exit_block();}
        | FOR '(' assignment ';' expr ';' IDENTIFIER '=' expr ')' '{' {enter_block();} statements '}'  {exit_block();}
        | REPEAT '{' {enter_block();} statements '}' {exit_block();} UNTIL '(' expr ')' ';'
        
        /*Switch Statements*/
        | SWITCH '(' switch_identifier ')' '{' {enter_block();} case_list '}' {exit_block();}
        
        /*Block Strusture*/
        | '{' {enter_block();} statements'}' {exit_block();}
        
        
        /*Functions Definition*/   
        | VOID IDENTIFIER '(' parameters_list ')' '{' {enter_block();} statements '}'   { 
                                                                                        exit_block();
                                                                                        if(!is_redeclared($2, current_scope)){
                                                                                            insert_symbol($2, "FUNC", true, current_scope, "VOID");
                                                                                            insert_function_parameters($2, current_scope, parameters, parameter_count);
                                                                                        } 
                                                                                        parameter_count = 0; 
                                                                                        }
                            
            
        | datatype IDENTIFIER '(' parameters_list ')' '{' {enter_block();} statements '}'   {
                                                                                            exit_block();
                                                                                            if(!is_redeclared($2, current_scope)){
                                                                                                insert_symbol($2, "FUNC", true, current_scope, $1 -> type);
                                                                                                insert_function_parameters($2, current_scope, parameters, parameter_count);
                                                                                            }
                                                                                            parameter_count = 0;
                                                                                            }
        
        /*Functions Call*/   
        | function_call
        | BREAK
        | CONTINUE
        ;	

function_call: 
        IDENTIFIER '(' parameters_list_call ')'  {
                                                        parameter_count = 0;
                                                        Value value;
                                                        value.func_value = $1;
                                                        $$ = insert_node("FUNC", value);
                                                        if(is_correct_scope($1, current_scope, true) == 1 && is_function($1, current_scope,true)){
                                                            
                                                        }
                                                    }

else_stmt:
        /*Empty production*/
        |
        ELSE '{' {enter_block();} statements '}'  {exit_block();}
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
                                                    insert_symbol($2, $1->type, false, current_scope,NULL);
                                                    // check type matching
                                                    if(strcmp($4 -> type, "ID") == 0){
                                                        if(is_correct_scope($4 -> value.id_value, current_scope, false) == 1){
                                                            if(is_same_type($2, current_scope, $4)){
                                                                // set initialized
                                                                set_initialized($2, current_scope);
                                                            } 
                                                        }
                                                    }
                                                    else if(strcmp($4 -> type, "FUNC") == 0){
                                                        if(is_correct_scope($4 -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($2, current_scope, $4)){
                                                                // set initialized
                                                                set_initialized($2, current_scope);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type($2, current_scope, $4)){
                                                            // set initialized
                                                            set_initialized($2, current_scope);
                                                        }
                                                    }
                                                     
                                                }
                                                }

var_declaration: 
		datatype IDENTIFIER                     {
                                                // check multiple declaration
                                                if(!is_redeclared($2, current_scope)){
                                                    // insert the symbol
                                                    insert_symbol($2, $1->type, false, current_scope, NULL);
                                                    parameters[parameter_count] = malloc(sizeof(function_parameter));
                                                    if (parameters[parameter_count] != NULL) {
                                                        parameters[parameter_count]->name = $2;
                                                        parameters[parameter_count]->type = $1->type;
                                                        parameter_count++; // Increment after assignment
                                                    } else {
                                                        // Handle memory allocation failure if needed
                                                        yyerror("Memory allocation failed for function parameter");
                                                    }
                                                }
                                                }
		;


parameters_list:
    /* Empty production */
    {
        $$ = 0; // Initialize count to 0
    }
    | var_declaration { 
        // Increment count for each var_declaration
        $$ = 1;
      }
    | parameters_list ',' var_declaration {
        // Increment count for each var_declaration
        $$ = $1 + 1;
      }
    ;

parameters_list_call:
    /* Empty production */
    {
        $$ = 0; // Initialize count to 0
    }
    | IDENTIFIER {
        // Increment count for each var_declaration
        $$ = 1;
      }
    | parameters_list_call ',' IDENTIFIER {
        // Increment count for each var_declaration
        $$ = $1 + 1;
      }
    ;

case_list:
      case_stmt
    | case_list case_stmt
    | case_list default_case
    ;
    
case_stmt:
      CASE expr ':' statements ';'
    ;  

default_case:
    DEFAULT ':' statements ';'


switch_identifier: 
    IDENTIFIER              {
                            Value value;
                            value.id_value = $1;
                            $$ = insert_node("ID", value);
                            // check declared
                            if(is_correct_scope($1, current_scope, true) == 1 && !is_function($1, current_scope,false)){
                                // check initialized
                                if(is_initialized($1, current_scope)){
                                    // set used
                                    set_used($1, current_scope);
                                }
                            }
                            }
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

    | function_call

    | IDENTIFIER            {
                            Value value;
                            value.id_value = $1;
                            $$ = insert_node("ID", value);
                            // check declared
                            if(is_correct_scope($1, current_scope, true) == 1 && !is_function($1, current_scope,false)){
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

void insert_symbol(char *name, char *type, bool is_const, Scope *scope, char* return_type){
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

    new_symbol-> return_type = return_type;

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
                    printf("Well Done: %s at line %d\n", name, lineno);
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
                                    else{
                                        printf("type mismatch: %s at line %d\n", name, lineno);
                                        return false;
                                    }
                                }
                            }
                        }
                        // functions type is FUNC
                        // we want to check the ID type
                        if(strcmp(id_node-> type, "FUNC")==0){
                            // get the type of the ID from the symbol table
                            for (int j =0; j<=symbol_table_idx; j++){
                                // get the variable in this scope
                                if(strcmp(symbol_table[j]-> name, id_node -> value.func_value)==0){
                                    if(strcmp(symbol_table[i]-> type, symbol_table[j]-> return_type)==0){
                                        return true;
                                    }
                                    else{
                                        printf("type mismatch: %s at line %d\n", name, lineno);
                                        return false;
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

bool is_function(char* name, Scope *scope, bool need_to_be_function){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    if(strcmp(symbol_table[i] -> type, "FUNC")==0){
                        if(!need_to_be_function){
                            printf("improper function useage: name %s at line number %d", name, lineno);
                        }
                        return true;
                    }
                    else{
                        if(need_to_be_function){
                            printf("Error at line: %d     this ID: %s isn't a function name\n", lineno, name);
                        }
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

void insert_function_parameters(char* name, Scope *scope, function_parameter **parameters, int no_of_parameters){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    symbol_table[i] -> no_of_parameters = no_of_parameters;
                    for (int k = 0; k< no_of_parameters; k++){
                        symbol_table[i] -> parameters[k] = parameters[k];
                    }
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

void enter_block(){
    Scope* new_scope = (Scope*) malloc(sizeof(Scope));
    new_scope -> parent = current_scope;
    current_scope = new_scope;
}

void exit_block(){
    current_scope = current_scope -> parent;
}

void print_symbol_table() {
    FILE *file = fopen("symbol_table.txt", "w");
    if (!file) {
        printf("Error: unable to open symbol table file.\n");
        return;
    }

    fprintf(file, "Name\tType\tConst\tScope\tReturn Type\tInitialized\tUsed\n");
    for (int i = 0; i <= symbol_table_idx; i++) {
        fprintf(file, "%s\t%s\t%s\t%p\t%s\t%s\t%s\n", 
                symbol_table[i]->name,
                symbol_table[i]->type,
                symbol_table[i]->is_const ? "true" : "false",
                (void*)symbol_table[i]->scope,
                symbol_table[i]->return_type ? symbol_table[i]->return_type : "N/A",
                symbol_table[i]->is_initialized ? "true" : "false",
                symbol_table[i]->is_used ? "true" : "false");
    }

    fclose(file);
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
    print_symbol_table();
    free(current_scope); // Clean up allocated memory before exiting
    return EXIT_SUCCESS;
}


void yyerror(char const *s)
{
    fprintf(stderr, "%s at line %d\n", s, lineno);
}
