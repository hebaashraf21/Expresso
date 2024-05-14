#include <stdbool.h> 
/*size of the symbol table */
#define HASH_TABLE_SIZE 503
/* maximum size of tokens-identifiers */
#define MAXTOKENLEN 40
typedef struct SymbolType {
    int int_type;
    int float_type;
    int string_tupe;
    int bool_type;
    int function_type;
} SymbolType;

int scope_index = 0;

typedef struct Value{
    int int_value;         
    char* str_value; 
    char char_value;
    float float_value;
    bool bool_value;
}Value;

// function parameters
typedef struct Param{
	char *parameter_name;
    int parmeter_type;
	Value parmeter_value;
}Param;

typedef struct Function_parameters{
    // function parameters
    Param *parameters;
    int num_of_parameters;
    int return_type;
}Function_parameters;

typedef struct Vriable_Lines{ 
    int line_number;
    int type;
    struct Vriable_Lines *next;
}Vriable_Lines;

typedef struct Symbol{
    char *symbol_name;
    int symbol_length;
    int symbol_type;
    int symbol_scope;
    Value value;

    Vriable_Lines *lines;
    
    Function_parameters function_parameters;

    // pointer to next item in the list
    struct Symbol *next;
}Symbol;

Symbol **symbol_table[HASH_TABLE_SIZE];

void init_symbol_table();
unsigned int hash_function(char *key);
void insert(char *symbol_name, int symbol_length, int symbol_type, int lineno);
Symbol *lookup(char *name);
Symbol *lookup_inside_scope(char *name, int scope);

void exit_scope();
void enter_scope();

void symbol_table_output_fle(FILE *of);