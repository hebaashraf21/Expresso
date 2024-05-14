/*size of the symbol table */
#define SYMBOL_TABLE_SIZE 500

/* maximum size of tokens-identifiers */
#define MAXTOKENLEN 40

/* token types */
#define UNDEF 0
#define INT_TYPE 1
#define REAL_TYPE 2
#define STR_TYPE 3
#define LOGIC_TYPE 4
#define FUNCTION_TYPE 6

/* how parameter is passed */
#define BY_VALUE 1
#define BY_REFER 2

/* current scope */
int current_scope = 0;

/* parameter struct */
typedef struct Param{
	int type;
	char name[MAXTOKENLEN];
	// to store value
	int ival; 
	double fval; 
	char cval;
	char *st_sval;
	int passing; // value or reference
}Param;

/* a linked list of references (lineno's) for each variable */
typedef struct RefList{ 
    int lineno;
    struct RefList *next;
    int type;
}RefList;

// struct that represents a list node
typedef struct Node{
    char node_name[MAXTOKENLEN];
    int node_type; // type
    int node_size;
    int scope;
    RefList *lines;
    // to store value
    int node_ival; 
    double node_fval; 
    char *node_sval;
    char cval;
    // for functions return type
    int ret_type; 
    // function parameters
    Param *parameters;
    int num_of_pars;
    // pointer to next item in the list
    struct Node *next;
}Node;


/* the symbol table */
static Node **symbol_table;

// symbol_table functios
void init_symbol_table(); // initialize the symbol table
unsigned int hash(char *key); // hash function 
void insert(char *id_name, int id_len, int id_type, int lineno); // insert 
Node *lookup(char *name); // search for entry
Node *lookup_scope(char *name, int scope); // search for entry
void hide_scope(); // hide the current scope
void incr_scope(); // go to next scope
void symtab_dump(FILE *of); // dump file
