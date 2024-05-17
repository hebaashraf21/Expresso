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
        char* char_value;
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
    char* get_symbol_type(char* name, Scope *scope);
    int parameter_count = 0;
    function_parameter * parameters[100];

    // check all variables are used
    bool is_all_used();

    // to deal with nested blocks
    void enter_block();
    void exit_block();

    // quadruples
    // Define the quadruple struct
    typedef struct Quadruple {
        char* operation;
        char* operand1;
        char* operand2;
        char* result;
    } Quadruple;

    Quadruple quadruples[1000];
    int quad_idx = -1;

    // used for printing boolean values
    const char* boolToString(bool b);

    void generate_quadruple_push_operation_2_ops(char* operation, Node* operand1, Node* operand2);
    void generate_quadruple_push_operation_1_op(char* operation, Node* operand, bool numeric);
    void generate_quadruple_push_terminal(Node* operand);
    void generate_quadruple_pop(char* operand);
    void quad_print(Node* operand);
%}

%union { 
    int int_value;        
    char* str_value;        
    char* char_value;      
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
                                                                generate_quadruple_pop($2);
                                                            }
                                                        }
                                                    }
                                                    else if(strcmp($4 -> type, "FUNC") == 0){
                                                        if(is_correct_scope($4 -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($2, current_scope, $4)){
                                                                // set initialized
                                                                set_initialized($2, current_scope);
                                                                generate_quadruple_pop($2);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type($2, current_scope, $4)){
                                                            // set initialized
                                                            set_initialized($2, current_scope);
                                                            generate_quadruple_pop($2);
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
                                                                generate_quadruple_pop($3);
                                                            }
                                                        }
                                                    }
                                                    else if(strcmp($5 -> type, "FUNC") == 0){
                                                        if(is_correct_scope($5 -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($3, current_scope, $5)){
                                                                // set initialized
                                                                set_initialized($3, current_scope);
                                                                generate_quadruple_pop($3);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        // check type matching
                                                        if(is_same_type($3, current_scope, $5)){
                                                            // set initialized
                                                            set_initialized($3, current_scope);
                                                            generate_quadruple_pop($3);
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
                                                                generate_quadruple_pop($1);
                                                            } 
                                                        }
                                                    }
                                                    else if(strcmp($3 -> type, "FUNC") == 0){
                                                        if(is_correct_scope($3 -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($1, current_scope, $3)){
                                                                // set initialized
                                                                set_initialized($1, current_scope);
                                                                generate_quadruple_pop($1);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type($1, current_scope, $3)){
                                                            // set initialized
                                                            set_initialized($1, current_scope);
                                                            generate_quadruple_pop($1);
                                                        } 
                                                    }
                                                }
                                            }
                                            }
        
        /*Print Statement*/
        | PRINT '(' expr ')' ';'                {quad_print($3);}           
            
        
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
                                                        Value value;
                                                        value.func_value = $1;
                                                        $$ = insert_node("FUNC", value);
                                                        if(is_correct_scope($1, current_scope, true) == 1 && is_function($1, current_scope,true)){
                                                            check_correct_parameters($1, current_scope, parameters, parameter_count);
                                                        }
                                                        parameter_count = 0;
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
                                                                generate_quadruple_pop($2);
                                                            } 
                                                        }
                                                    }
                                                    else if(strcmp($4 -> type, "FUNC") == 0){
                                                        if(is_correct_scope($4 -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type($2, current_scope, $4)){
                                                                // set initialized
                                                                set_initialized($2, current_scope);
                                                                generate_quadruple_pop($2);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type($2, current_scope, $4)){
                                                            // set initialized
                                                            set_initialized($2, current_scope);
                                                            generate_quadruple_pop($2);
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
        // check scope
        // check initialized
        // set parameters
        if(is_correct_scope($1, current_scope, true) == 1 && !is_function($1, current_scope,false)){
            // check initialized
            if(is_initialized($1, current_scope)){
                // set used
                set_used($1, current_scope);
                parameters[parameter_count] = malloc(sizeof(function_parameter));
                if (parameters[parameter_count] != NULL) {
                    parameters[parameter_count]->name = $1;
                    parameters[parameter_count]->type = get_symbol_type($1, current_scope);
                    parameter_count++; // Increment after assignment
                } else {
                    // Handle memory allocation failure if needed
                    yyerror("Memory allocation failed for function parameter");
                }
            }
        }
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
                            generate_quadruple_push_terminal($$);
                            }	

    | FALSE_VAL	            {
                            Value value;
                            value.bool_value = false;
                            $$ = insert_node("BOOL", value);
                            generate_quadruple_push_terminal($$);
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
                                    generate_quadruple_push_terminal($$);
                                }
                            }
                            } 

    | INTEGER_VAL	        {
                            Value value;
                            value.int_value = $1;
                            $$ = insert_node("INT", value);
                            generate_quadruple_push_terminal($$);
                            }	

    | FLOAT_VAL		        {
                            Value value;
                            value.float_value = $1;
                            $$ = insert_node("FLOAT", value);
                            generate_quadruple_push_terminal($$);
                            }	

    | CHAR_VAL				{
                            Value value;
                            value.char_value = $1;
                            $$ = insert_node("CHAR", value);
                            generate_quadruple_push_terminal($$);
                            }

    | STRING_VAL            {
                            Value value;
                            value.str_value = $1;
                            $$ = insert_node("STRING", value);
                            generate_quadruple_push_terminal($$);
                            }
    ;
    
expr:
    terminals				
	
     /* (expressions) */
    | '(' expr ')'				
     
     /* Mthematical expressions */
    | '-' expr	        {generate_quadruple_push_operation_1_op("NEG", $2, true);}
    | INCR expr         {generate_quadruple_push_operation_1_op("PRE_INCR", $2, true);}     		
    | expr INCR         {generate_quadruple_push_operation_1_op("POST_INCR", $1, true);}         		
    | DECR expr         {generate_quadruple_push_operation_1_op("PRE_DEC", $2, true);}        		
    | expr DECR         {generate_quadruple_push_operation_1_op("POST_DECR", $1, true);}

    | expr '+' expr		{generate_quadruple_push_operation_2_ops("ADD", $1, $3);}		
    | expr '-' expr		{generate_quadruple_push_operation_2_ops("SUB", $1, $3);}		
    | expr '*' expr		{generate_quadruple_push_operation_2_ops("MUL", $1, $3);}		
    | expr '/' expr		{generate_quadruple_push_operation_2_ops("DIV", $1, $3);}		
    | expr '^' expr		{generate_quadruple_push_operation_2_ops("POW", $1, $3);}		
    | expr '%' expr		{generate_quadruple_push_operation_2_ops("MOD", $1, $3);}		
     
     /* logical expressions */
    | expr LOGICAL_AND expr		{generate_quadruple_push_operation_2_ops("LOGICAL_AND", $1, $3);}	
    | expr LOGICAL_OR expr		{generate_quadruple_push_operation_2_ops("LOGICAL_OR", $1, $3);}		
    | LOGICAL_NOT expr	        {generate_quadruple_push_operation_1_op("LOGICAL_NOT", $2, false);}
     
     /* comparison expressions */
    | expr EQUALS expr			        {generate_quadruple_push_operation_2_ops("IS_EQUAL", $1, $3);}	
    | expr NOT_EQUALS expr		        {generate_quadruple_push_operation_2_ops("IS_NOT_EQUAL", $1, $3);}		
    | expr LESS_THAN expr		        {generate_quadruple_push_operation_2_ops("LESS_THAN", $1, $3);}		
    | expr LESS_THAN_OR_EQUALS expr	    {generate_quadruple_push_operation_2_ops("LESS_THAN_OR_EQUALS", $1, $3);}		
    | expr GREATER_THAN expr		    {generate_quadruple_push_operation_2_ops("GREATER_THAN", $1, $3);}		
    | expr GREATER_THAN_OR_EQUALS expr 	{generate_quadruple_push_operation_2_ops("GREATER_THAN_OR_EQUALS", $1, $3);}	 
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
                    else{
                        return false;
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
/*======================================================================================================*/
/*Function Hnadling functions*/
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

char* get_symbol_type(char* name, Scope *scope){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    return symbol_table[i] -> type;
                }
                else{
                    temp_scope = temp_scope -> parent;
                }
            }
            
        }
    }
}

bool check_correct_parameters(char* name, Scope *scope, function_parameter ** parameters, int no_of_parameters){
    for (int i =0; i<=symbol_table_idx; i++){
        // same name and same scope
        if(strcmp(symbol_table[i]-> name, name)==0){
            Scope *temp_scope = scope;
            while(temp_scope){
                if(symbol_table[i] -> scope == temp_scope){
                    if(symbol_table[i] -> no_of_parameters == no_of_parameters){
                        for(int j = 0; j < no_of_parameters ;j++){
                            if(strcmp(symbol_table[i] -> parameters[j] -> type, parameters[j] -> type)){
                                printf("Unexpected parameter at position %d for function %s at line %d\n", j + 1, name, lineno);
                                return false;
                            }
                        }
                        return true;
                    }
                    else{
                        printf("Wrong Number of parameters for function: %s at line: %d    expected: %d, but found: %d\n", name, lineno, symbol_table[i] -> no_of_parameters, no_of_parameters);
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
/*=======================================================================================================*/
/*General Methods*/
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

/*==========================================================================================*/
/*Quadruples*/
void generate_quadruple_push_operation_2_ops(char* operation, Node* operand1, Node* operand2) {
    // check if the 2 operands are IDs
    if(strcmp(operand1->type, "ID") == 0 && strcmp(operand1->type, "ID") == 0){
        // check the 2 IDs are the same type
        // if not the same type ==> return
        if(strcmp(get_symbol_type(operand1 -> value.id_value, current_scope), get_symbol_type(operand2 -> value.id_value, current_scope)) != 0){
            printf("Error at line: %d    the 2 operands must be the same type\n", lineno);
            return;
        }
    }
    // check if the first operand is ID
    else if(strcmp(operand1->type, "ID") == 0 ){
        // if not the same type ==> return
        if(strcmp(get_symbol_type(operand1 -> value.id_value, current_scope), operand2->type) != 0){
            printf("Error at line: %d    the 2 operands must be the same type\n", lineno);
            return;
        }
    }
    // check if the second operand is ID
    else if(strcmp(operand2->type, "ID") == 0 ){
        // if not the same type ==> return
        if(strcmp(operand1->type, get_symbol_type(operand2 -> value.id_value, current_scope)) != 0){
            printf("Error at line: %d    the 2 operands must be the same type\n", lineno);
            return;
        }
    }
    // the 2 operands are not IDs ==> check the type
    else if(strcmp(operand1->type, operand2->type) != 0){
        printf("Error at line: %d    the 2 operands must be the same type\n", lineno);
        return;
    }
    // Generate quadruple based on the type
    quad_idx++;
    quadruples[quad_idx].operation = operation;
    quadruples[quad_idx].operand1 = malloc(sizeof(char) * 10); // Assuming operand1 is a string
    quadruples[quad_idx].operand2 = malloc(sizeof(char) * 10); // Assuming operand2 is a string

    if (strcmp(operand1->type, "INT") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%d", operand1->value.int_value);
        sprintf(quadruples[quad_idx].operand2, "%d", operand2->value.int_value);
    } 
    else if (strcmp(operand1->type, "FLOAT") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%f", operand1->value.float_value);
        sprintf(quadruples[quad_idx].operand2, "%f", operand2->value.float_value);
    } 
    else if (strcmp(operand1->type, "BOOL") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", boolToString(operand1->value.bool_value));
        sprintf(quadruples[quad_idx].operand2, "%s", boolToString(operand2->value.bool_value));
    }
    else if (strcmp(operand1->type, "ID") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand1->value.id_value);
        sprintf(quadruples[quad_idx].operand2, "%s", operand2->value.id_value);
    }
    else if (strcmp(operand1->type, "CHAR") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand1->value.char_value);
        sprintf(quadruples[quad_idx].operand2, "%s", operand2->value.char_value);
    }
    else if (strcmp(operand1->type, "STRING") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand1->value.str_value);
        sprintf(quadruples[quad_idx].operand2, "%s", operand2->value.str_value);
    }

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "push %s\n", quadruples[quad_idx].operand1);
    fprintf(quad_file, "push %s\n", quadruples[quad_idx].operand2);
    fprintf(quad_file, "%s\n", operation);
    fclose(quad_file);
}

void generate_quadruple_push_operation_1_op(char* operation, Node* operand, bool numeric){
    // this function is for unary operators
    //  if the operator is arithmetic ==> numeric is true ==> check the rype of the operand
    if(numeric){
        if(strcmp(operand->type, "INT") != 0 && strcmp(operand->type, "FLOAT") != 0){
            if(strcmp(operand->type, "ID") != 0){
                printf("Improper type for arithmetic operation at line: %d      expected float or int\n", lineno);
                return;
            }
            if(strcmp(operand->type, "ID") == 0){
                // if ID ==> check its type
                //if not INT or FLOAT ==> return
                if(strcmp(get_symbol_type(operand -> value.id_value, current_scope), "INT") != 0 && strcmp(get_symbol_type(operand -> value.id_value, current_scope), "FLOAT") != 0){
                    printf("Improper type for arithmetic operation at line: %d      expected float or int\n", lineno);
                    return;
                }
            }
        }
    }
    quad_idx++;
    quadruples[quad_idx].operation = operation;
    quadruples[quad_idx].operand1 = malloc(sizeof(char) * 10); // Assuming operand1 is a string
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    if (strcmp(operand->type, "INT") == 0) {
            sprintf(quadruples[quad_idx].operand1, "%d", operand->value.int_value);
    } 
    else if (strcmp(operand->type, "FLOAT") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%f", operand->value.float_value);
    } 
    else if (strcmp(operand->type, "BOOL") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", boolToString(operand->value.bool_value));
    }
    else if (strcmp(operand->type, "ID") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.id_value);
    }
    else if (strcmp(operand->type, "CHAR") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.char_value);
    }
    else if (strcmp(operand->type, "STRING") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.str_value);
    }

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "push %s\n", quadruples[quad_idx].operand1);
    fprintf(quad_file, "%s\n", operation);
    fclose(quad_file);
}

void generate_quadruple_push_terminal(Node* operand){
    quad_idx++;
    quadruples[quad_idx].operation = NULL;
    quadruples[quad_idx].operand1 = malloc(sizeof(char) * 10); // Assuming operand1 is a string
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    if (strcmp(operand->type, "INT") == 0) {
            sprintf(quadruples[quad_idx].operand1, "%d", operand->value.int_value);
    } 
    else if (strcmp(operand->type, "FLOAT") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%f", operand->value.float_value);
    } 
    else if (strcmp(operand->type, "BOOL") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", boolToString(operand->value.bool_value));
    }
    else if (strcmp(operand->type, "ID") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.id_value);
    }
    else if (strcmp(operand->type, "CHAR") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.char_value);
    }
    else if (strcmp(operand->type, "STRING") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.str_value);
    }

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "push %s\n", quadruples[quad_idx].operand1);
    fclose(quad_file);
}
void quad_print(Node* operand){
    quad_idx++;
    quadruples[quad_idx].operation = "CALL PRINT";
    quadruples[quad_idx].operand1 = malloc(sizeof(char) * 10); // Assuming operand1 is a string
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    if (strcmp(operand->type, "INT") == 0) {
            sprintf(quadruples[quad_idx].operand1, "%d", operand->value.int_value);
    } 
    else if (strcmp(operand->type, "FLOAT") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%f", operand->value.float_value);
    } 
    else if (strcmp(operand->type, "BOOL") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", boolToString(operand->value.bool_value));
    }
    else if (strcmp(operand->type, "ID") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.id_value);
    }
    else if (strcmp(operand->type, "CHAR") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.char_value);
    }
    else if (strcmp(operand->type, "STRING") == 0) {
        sprintf(quadruples[quad_idx].operand1, "%s", operand->value.str_value);
    }

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "CALL PRINT \n");
    fprintf(quad_file, "pop %s\n", quadruples[quad_idx].operand1);
    fclose(quad_file);
}

void generate_quadruple_pop(char* operand) {
    // Generate quadruple for pop
    quad_idx++;
    quadruples[quad_idx].operation = "pop";
    quadruples[quad_idx].operand1 = operand;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "pop %s\n", operand);
    fclose(quad_file);
}

const char* boolToString(bool b) {
    return b ? "true" : "false";
}
/*==============================================================================*/
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
