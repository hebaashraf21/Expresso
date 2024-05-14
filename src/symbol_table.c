#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

// initialize the symbol table
void init_symbol_table(){
	// allocate the initial size of the symbol table
	// dynamic array ==> malloc
	symbol_table = malloc(SYMBOL_TABLE_SIZE * sizeof(Node*));
	for(int i = 0; i < SYMBOL_TABLE_SIZE; i++) {
		symbol_table[i] = NULL;
	}
}

/* Process the input string/identifier using the hash function 
and then return a integer value (the hash-value of this string)*/
unsigned int hash(char *key){
	// Initialize a hashval variable with value 0
	int hash_index = 0;
	// Loop through all the characters of the string and add their ASCII value to this variable
	while(*key!='\0'){
		// Update the hash value using a simple multiplicative hash function
		// It has good distribution properties and is easy to implement.
        hash_index = (hash_index * 31) + *key;
        key++;
	} 
	return hash_index % SYMBOL_TABLE_SIZE;
}

// inserting a new identifier to the Symbol Table.

void insert(char *id_name, int id_len, int id_type, int lineno){
	// get the hash index of the id_name
	unsigned int hash_index = hash(id_name);
	// get the entry at this index
	Node *entry_list = symbol_table[hash_index];

	while ((entry_list != NULL) && (strcmp(id_name,entry_list->node_name) != 0)) {
		// If the identifier has not been inserted before
		// move the pointer till the end or reaching the id_name
		entry_list = entry_list->next;
	}

	// If we reached the end of the list ==> the identifier isn't in the tanle before
	if(entry_list == NULL){
		// create a new entry
		entry_list = (Node*) malloc(sizeof(Node));
		// copy the name of the node to the new entry
		strncpy(entry_list->node_name, id_name, id_len);
		// Add the new entry to the symbol table
		entry_list -> node_type = id_type;
		entry_list -> scope = current_scope;
	}
}