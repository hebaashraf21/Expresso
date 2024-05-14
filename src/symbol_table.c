#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

/* Process the input string/identifier using the hash function 
and then return a integer value (the hash-value of this string)*/
unsigned int hash_function(char *key){
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

void insert(char *symbol_name, enum SymbolType symbol_type, int lineno){
	unsigned int hash_index = hash_function(symbol_name);
	// get the entry  in the table at this index (if exist):
	Symbol *table_entry = symbol_table[hash_index];
	while(table_entry && strcmp(table_entry->symbol_name, symbol_name)){
		table_entry = table_entry ->next;
	}

	if (table_entry == NULL){
		// entry not in the table
		table_entry = (Symbol*) malloc(sizeof(Symbol));
		strcpy(table_entry->symbol_name, symbol_name);  
		/* add to hashtable */
		table_entry->symbol_type = symbol_type;
		table_entry -> symbol_scope = scope_index;
		table_entry ->lines = (Vriable_Lines*) malloc(sizeof(Vriable_Lines));
		table_entry ->lines ->line_number = lineno;
		table_entry ->lines ->next = NULL;
		table_entry ->next = symbol_table[hash_index];
		symbol_table[hash_index] = table_entry; 
	}
	else{
		// entry in the table
		// add line number
		table_entry -> symbol_scope = scope_index;
		// get the variable lines
		Vriable_Lines * lines = table_entry->lines;
		while(lines-> next){
			lines = lines->next;
			lines->next = (Vriable_Lines*) malloc(sizeof(Vriable_Lines));
			lines->next ->line_number = lineno;
			lines ->next ->next = NULL;
		}
	}
}

Symbol *lookup(char *symbol_name){
	// get the hash index of this key
	unsigned int hash_index = hash_function(symbol_name);
	// get the entry at this index
    Symbol *entry = symbol_table[hash_index];
    while ((entry != NULL) && (strcmp(symbol_name,entry->symbol_name) != 0)) {
		entry = entry->next;
	}
    return entry; // NULL if not found
}

// Lookup for a symbol in a giben scope
Symbol *lookup_inside_scope(char *symbol_name, int scope){
	// get the hash index of this key
	unsigned int hash_index = hash_function(symbol_name);
	// get the entry at this index
    Symbol *entry = symbol_table[hash_index];
    while ((entry != NULL) && (strcmp(symbol_name,entry->symbol_name) != 0) && entry->symbol_scope == scope) {
		entry = entry->next;
	}
    return entry; // NULL if not found
}

void enter_scope(){
	scope_index++;
}

void exit_scope(){
	if (scope_index > 0){
		scope_index--;
	}
}

void symbol_table_output_fle(FILE *of){
	fprintf(of,"------------ ------ ------------\n");
	fprintf(of,"Name         Type   Line Numbers\n");
	fprintf(of,"------------ ------ -------------\n");
	for (int i=0; i < HASH_TABLE_SIZE; ++i){
		if (symbol_table[i]){
			Symbol *entry= symbol_table[i];
			while (entry){
				fprintf(of,"%-12s ",entry->symbol_name);
				if(entry->symbol_type != FUNCTION_TYPE){
					fprintf(of,"%-7s",entry->symbol_type);
				}
				else{
					fprintf(of,"%-7s %s","function returns ");
					fprintf(of,"%-7s",entry-> function_parameters-> return_type);
				}
				Vriable_Lines *entry_lines = entry ->lines;
				while(entry_lines){
					fprintf(of,"%4d ",entry_lines->line_number);
					entry_lines = entry_lines ->next;
				}
				fprintf(of,"\n");
				entry = entry->next;
			}
		} 
	}
}