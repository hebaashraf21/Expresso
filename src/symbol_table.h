#ifndef SYMBO_TABLE_H
#define SYMBO_TABLE_H
#include <stdbool.h> 
/*size of the symbol table */
#define HASH_TABLE_SIZE 503
/* maximum size of tokens-identifiers */
#define MAXTOKENLEN 40

enum SymbolType {
    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE,
    BOOL_TYPE,
    FUNCTION_TYPE,
    UNDEFINED
};

enum SymbolType symbolType;
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
    enum SymbolType parmeter_type;
	Value parmeter_value;
}Param;

typedef struct Function_parameters{
    // function parameters
    Param *parameters;
    int num_of_parameters;
    enum SymbolType return_type;
}Function_parameters;

typedef struct Vriable_Lines{ 
    int line_number;
    int type;
    struct Vriable_Lines *next;
}Vriable_Lines;

typedef struct Symbol{
    char *symbol_name;
    int symbol_length;
    enum SymbolType symbol_type;
    int symbol_scope;
    Value value;

    Vriable_Lines *lines;
    
    Function_parameters *function_parameters;

    // pointer to next item in the list
    struct Symbol *next;
}Symbol;

Symbol *symbol_table[HASH_TABLE_SIZE] = {NULL};

unsigned int hash_function(char *key);
void insert(char *symbol_name, enum SymbolType symbol_type, int lineno);
Symbol *lookup(char *symbol_name);
Symbol *lookup_inside_scope(char *symbol_name, int scope);

void exit_scope();
void enter_scope();

void symbol_table_output_fle(FILE *of);

#endif