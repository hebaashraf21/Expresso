#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

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
	return hash_index % HASH_TABLE_SIZE;
}

