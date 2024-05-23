
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "src/parser.y"

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
    FILE *errors_file;
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
    int label_count = 0;
    // used for printing boolean values
    const char* boolToString(bool b);

    // to store the variable we check in the witch statement
    char* switch_expression;
    char* end_switch_label = "E0000";
    int case_count = 0;
    int default_count = 0;

    void generate_quadruple_push_operation_2_ops(char* operation, Node* operand1, Node* operand2);
    void generate_quadruple_push_operation_1_op(char* operation, Node* operand, bool numeric);
    void generate_quadruple_push_terminal(Node* operand);
    void generate_quadruple_pop(char* operand);
    void quad_print(Node* operand);
    void quad_function_call_label(char* operand);
    void quad_function_call_parameters(char* operand);
    void quad_function_declare(char* operand);
    void quad_function_end(char* operand);
    void quad_return();
    void quad_get_label();
    void generate_label(char* label, int label_number);
    void quad_jmp_loop();
    void quad_repeat_jnz();
    void quad_repeat_jmp();
    void quad_if_jnz();
    void push_switch_expression();
    void switch_jmp_to_end();
    void case_jnz();
    void case_jz();
    void quad_EQ();
    void generate_end_label();


/* Line 189 of yacc.c  */
#line 216 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINT = 258,
     IF = 259,
     ELSE = 260,
     WHILE = 261,
     FOR = 262,
     DO = 263,
     CONTINUE = 264,
     BREAK = 265,
     RETURN = 266,
     SWITCH = 267,
     CASE = 268,
     DEFAULT = 269,
     REPEAT = 270,
     UNTIL = 271,
     VOID = 272,
     ENUM = 273,
     INTEGER = 274,
     FLOAT = 275,
     CHAR = 276,
     BOOL = 277,
     STRING = 278,
     CONST = 279,
     FLOAT_VAL = 280,
     INTEGER_VAL = 281,
     CHAR_VAL = 282,
     STRING_VAL = 283,
     TRUE_VAL = 284,
     FALSE_VAL = 285,
     IDENTIFIER = 286,
     INCR = 287,
     DECR = 288,
     LOGICAL_OR = 289,
     LOGICAL_AND = 290,
     NOT_EQUALS = 291,
     EQUALS = 292,
     GREATER_THAN_OR_EQUALS = 293,
     GREATER_THAN = 294,
     LESS_THAN_OR_EQUALS = 295,
     LESS_THAN = 296,
     LOGICAL_NOT = 297,
     UMINUS = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 143 "src/parser.y"
 
    int int_value;        
    char* str_value;        
    char* char_value;      
    float float_value;  
    bool bool_value;    
    char* identifier;
    struct Node *node_value;
;


/* Line 214 of yacc.c  */
#line 307 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 319 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    57,     2,     2,
      25,    26,    55,    53,    32,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    31,
       2,    44,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    45,
      46,    47,    48,    49,    50,    51,    52,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    17,    23,
      30,    35,    41,    42,    43,    44,    45,    58,    59,    60,
      61,    72,    73,    74,    75,    92,    93,    94,    95,   108,
     109,   118,   119,   124,   125,   126,   137,   138,   139,   150,
     152,   154,   156,   159,   163,   168,   169,   170,   176,   178,
     180,   182,   184,   186,   191,   194,   195,   197,   201,   202,
     204,   208,   210,   213,   216,   217,   218,   219,   229,   230,
     231,   239,   241,   243,   245,   247,   249,   251,   253,   255,
     257,   259,   263,   266,   269,   272,   275,   278,   282,   286,
     290,   294,   298,   302,   306,   310,   313,   317,   321,   325,
     329,   333
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    63,    -1,    -1,    64,    -1,    63,    64,
      -1,    31,    -1,    88,    41,    31,    -1,    88,    41,    44,
     103,    31,    -1,    24,    88,    41,    44,   103,    31,    -1,
      41,    44,   103,    31,    -1,     3,    25,   103,    26,    31,
      -1,    -1,    -1,    -1,    -1,     4,    25,   103,    65,    26,
      27,    66,    63,    28,    67,    68,    86,    -1,    -1,    -1,
      -1,     6,    25,    69,   103,    70,    26,    27,    71,    63,
      28,    -1,    -1,    -1,    -1,     7,    25,    72,    89,    31,
     103,    31,    73,    41,    44,   103,    26,    27,    74,    63,
      28,    -1,    -1,    -1,    -1,    15,    27,    75,    76,    63,
      28,    77,    16,    25,   103,    26,    31,    -1,    -1,    12,
      25,   101,    26,    27,    78,    93,    28,    -1,    -1,    27,
      79,    63,    28,    -1,    -1,    -1,    17,    41,    80,    25,
      91,    26,    27,    81,    63,    28,    -1,    -1,    -1,    88,
      41,    82,    25,    91,    26,    27,    83,    63,    28,    -1,
      85,    -1,     9,    -1,    84,    -1,    11,    31,    -1,    11,
     103,    31,    -1,    41,    25,    92,    26,    -1,    -1,    -1,
       5,    27,    87,    63,    28,    -1,    19,    -1,    20,    -1,
      21,    -1,    23,    -1,    22,    -1,    88,    41,    44,   103,
      -1,    88,    41,    -1,    -1,    90,    -1,    91,    32,    90,
      -1,    -1,    41,    -1,    92,    32,    41,    -1,    94,    -1,
      93,    94,    -1,    93,    98,    -1,    -1,    -1,    -1,    13,
      95,   103,    96,    34,    63,    10,    97,    31,    -1,    -1,
      -1,    14,    34,    99,    63,    10,   100,    31,    -1,    41,
      -1,    39,    -1,    40,    -1,    85,    -1,    41,    -1,    36,
      -1,    35,    -1,    37,    -1,    38,    -1,   102,    -1,    25,
     103,    26,    -1,    54,   103,    -1,    42,   103,    -1,   103,
      42,    -1,    43,   103,    -1,   103,    43,    -1,   103,    53,
     103,    -1,   103,    54,   103,    -1,   103,    55,   103,    -1,
     103,    56,   103,    -1,   103,    58,   103,    -1,   103,    57,
     103,    -1,   103,    46,   103,    -1,   103,    45,   103,    -1,
      59,   103,    -1,   103,    48,   103,    -1,   103,    47,   103,
      -1,   103,    52,   103,    -1,   103,    51,   103,    -1,   103,
      50,   103,    -1,   103,    49,   103,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   209,   209,   210,   215,   216,   222,   224,   232,   269,
     306,   342,   346,   346,   346,   346,   346,   349,   349,   349,
     349,   350,   350,   350,   350,   351,   351,   351,   351,   354,
     354,   357,   357,   361,   361,   361,   372,   372,   372,   383,
     384,   385,   389,   390,   394,   405,   408,   408,   410,   414,
     418,   422,   426,   434,   471,   497,   500,   504,   512,   516,
     541,   548,   549,   550,   554,   554,   554,   554,   558,   558,
     558,   562,   577,   584,   591,   593,   608,   615,   622,   629,
     638,   641,   644,   645,   646,   647,   648,   650,   651,   652,
     653,   654,   655,   658,   659,   660,   663,   664,   665,   666,
     667,   668
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "WHILE", "FOR",
  "DO", "CONTINUE", "BREAK", "RETURN", "SWITCH", "CASE", "DEFAULT",
  "REPEAT", "UNTIL", "VOID", "ENUM", "INTEGER", "FLOAT", "CHAR", "BOOL",
  "STRING", "CONST", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'",
  "','", "'?'", "':'", "FLOAT_VAL", "INTEGER_VAL", "CHAR_VAL",
  "STRING_VAL", "TRUE_VAL", "FALSE_VAL", "IDENTIFIER", "INCR", "DECR",
  "'='", "LOGICAL_OR", "LOGICAL_AND", "NOT_EQUALS", "EQUALS",
  "GREATER_THAN_OR_EQUALS", "GREATER_THAN", "LESS_THAN_OR_EQUALS",
  "LESS_THAN", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "LOGICAL_NOT",
  "UMINUS", "$accept", "program", "statements", "stmt", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "return_stmt",
  "function_call", "else_stmt", "$@20", "datatype", "assignment",
  "var_declaration", "parameters_list", "parameters_list_call",
  "case_list", "case_stmt", "$@21", "$@22", "$@23", "default_case", "$@24",
  "$@25", "switch_identifier", "terminals", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    40,    41,   123,   125,    91,
      93,    59,    44,    63,    58,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    61,   289,   290,   291,   292,   293,
     294,   295,   296,    43,    45,    42,    47,    37,    94,   297,
     298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    65,    66,    67,    68,    64,    69,    70,    71,
      64,    72,    73,    74,    64,    75,    76,    77,    64,    78,
      64,    79,    64,    80,    81,    64,    82,    83,    64,    64,
      64,    64,    84,    84,    85,    86,    87,    86,    88,    88,
      88,    88,    88,    89,    90,    91,    91,    91,    92,    92,
      92,    93,    93,    93,    95,    96,    97,    94,    99,   100,
      98,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     3,     5,     6,
       4,     5,     0,     0,     0,     0,    12,     0,     0,     0,
      10,     0,     0,     0,    16,     0,     0,     0,    12,     0,
       8,     0,     4,     0,     0,    10,     0,     0,    10,     1,
       1,     1,     2,     3,     4,     0,     0,     5,     1,     1,
       1,     1,     1,     4,     2,     0,     1,     3,     0,     1,
       3,     1,     2,     2,     0,     0,     0,     9,     0,     0,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,    40,     0,     0,     0,     0,
      48,    49,    50,    52,    51,     0,    31,     6,     0,     0,
       2,     4,    41,    39,     0,     0,     0,    17,    21,     0,
      42,    77,    76,    78,    79,    72,    73,    75,     0,     0,
       0,     0,    74,    80,     0,     0,    25,    33,     0,     0,
      58,     0,     1,     5,    36,     0,    12,     0,     0,     0,
      83,    85,    82,    95,    43,    84,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,     0,    26,     0,     0,     0,    59,     0,     0,
       7,     0,     0,     0,     0,    18,     0,     0,    81,    94,
      93,    97,    96,   101,   100,    99,    98,    87,    88,    89,
      90,    92,    91,     0,     0,    55,     0,    32,    44,     0,
      10,     0,    55,    11,     0,     0,     0,     0,    29,     0,
       0,    56,     0,     0,    60,     8,     0,    13,     0,     0,
       0,     0,    27,    54,     0,     0,     9,     0,     0,    19,
      53,    22,    64,     0,    61,     0,    34,    57,    37,     0,
       0,     0,     0,     0,    30,    62,    63,     0,     0,     0,
      14,     0,     0,    65,    68,     0,     0,     0,    15,    20,
       0,     0,     0,     0,    35,    38,    45,     0,     0,     0,
       0,     0,    16,     0,     0,    69,    28,    46,    23,    66,
       0,     0,     0,     0,    70,     0,     0,    67,    47,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    94,   148,   178,   186,    57,   125,
     160,    58,   161,   202,    83,   114,   155,   141,    49,    84,
     168,    92,   169,    22,    42,   192,   201,    24,    97,   131,
     132,    88,   153,   154,   162,   181,   203,   166,   182,   200,
      82,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -38
static const yytype_int16 yypact[] =
{
     533,   -10,    -6,     5,     6,   -38,   540,     9,   -20,   -30,
     -38,   -38,   -38,   -38,   -38,    36,   -38,   -38,   -22,    26,
     533,   -38,   -38,   -38,     7,   565,   565,   -38,   -38,   565,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,    21,   565,   565,
     565,   565,   -38,   -38,   665,    11,   -38,   -38,    12,   533,
      20,   565,   -38,   -38,   -27,   583,   794,   565,    36,   601,
     -38,   -38,     8,   -29,   -38,   -38,   -38,   565,   565,   565,
     565,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   -38,    42,   -38,    22,    18,   219,   -38,   -16,   693,
     -38,   565,    44,    53,    59,   794,    46,    57,   -38,   811,
     828,   845,   845,   -18,   -18,   -18,   -18,     8,     8,   -37,
     -37,   -37,   -29,    62,   533,    36,   565,   -38,   -38,    49,
     -38,   721,    36,   -38,    64,    66,    51,   565,   -38,   250,
      52,   -38,   -14,   749,   -38,   -38,     1,   -38,    70,   565,
     777,    85,   -38,   -38,    72,    36,   -38,    73,   533,   -38,
     794,   -38,   -38,    -5,   -38,    87,   -38,   -38,   -38,   281,
     533,    60,   565,    71,   -38,   -38,   -38,    79,   533,   533,
     -38,   312,    63,   794,   -38,   565,   343,   374,   -38,   -38,
     565,    74,   533,   619,   -38,   -38,   101,   637,   533,   407,
      80,    86,   -38,    88,   440,   -38,   -38,   -38,   -38,   -38,
      81,   533,   533,    89,   -38,   471,   502,   -38,   -38,   -38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,    47,   -19,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   -38,   -38,   -13,   -38,   -28,
      -4,   -38,   -38,   -32,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,     3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      23,    53,    48,    50,    90,    65,    66,    46,   152,   163,
     118,    47,   144,    65,    66,    25,   119,    91,   145,    26,
      23,    80,    51,   164,    65,    66,    52,   147,    55,    56,
      27,    28,    59,   145,    45,    75,    76,    77,    78,    79,
      80,    60,    61,    62,    63,    96,    50,   115,    54,    23,
      65,    66,    81,    85,    89,    10,    11,    12,    13,    14,
      95,    87,   116,    77,    78,    79,    80,    53,   113,   122,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   123,   124,    23,   126,   127,   128,
     134,   137,   138,   143,   121,   139,    86,   149,   152,   156,
     158,   172,   130,   167,   175,   174,   191,   180,   188,   130,
      53,   196,   204,   197,    23,   198,     0,   157,   136,   133,
     207,   165,     0,     0,     0,     0,     0,     0,     0,    23,
     140,     0,   130,     0,     0,     0,     0,     0,     0,     0,
      53,     0,   150,     0,     0,     0,     0,     0,    23,     0,
       0,     0,    53,     0,     0,     0,     0,    53,    53,    23,
      23,   129,     0,     0,     0,   173,     0,     0,    23,    23,
      53,    23,     0,     0,     0,    53,    23,    23,   183,     0,
       0,     0,    23,   187,     0,     0,    53,    53,    23,    23,
       0,     0,     0,     0,    23,   159,     0,     0,     0,     0,
       0,    23,    23,     0,     0,    23,    23,   171,     0,     0,
       0,     0,     0,     0,     0,   176,   177,     0,     0,     0,
       0,     0,     1,     2,     0,     3,     4,     0,     5,   189,
       6,     7,     0,     0,     8,   194,     9,     0,    10,    11,
      12,    13,    14,    15,     0,     0,    16,   117,   205,   206,
      17,     0,     0,     1,     2,     0,     3,     4,     0,     5,
      18,     6,     7,     0,     0,     8,     0,     9,     0,    10,
      11,    12,    13,    14,    15,     0,     0,    16,   142,     0,
       0,    17,     0,     0,     1,     2,     0,     3,     4,     0,
       5,    18,     6,     7,     0,     0,     8,     0,     9,     0,
      10,    11,    12,    13,    14,    15,     0,     0,    16,   170,
       0,     0,    17,     0,     0,     1,     2,     0,     3,     4,
       0,     5,    18,     6,     7,     0,     0,     8,     0,     9,
       0,    10,    11,    12,    13,    14,    15,     0,     0,    16,
     179,     0,     0,    17,     0,     0,     1,     2,     0,     3,
       4,     0,     5,    18,     6,     7,     0,     0,     8,     0,
       9,     0,    10,    11,    12,    13,    14,    15,     0,     0,
      16,   184,     0,     0,    17,     0,     0,     1,     2,     0,
       3,     4,     0,     5,    18,     6,     7,     0,     0,     8,
       0,     9,     0,    10,    11,    12,    13,    14,    15,     0,
       0,    16,   185,     0,     0,    17,     0,     0,     0,     0,
       1,     2,     0,     3,     4,    18,     5,   195,     6,     7,
       0,     0,     8,     0,     9,     0,    10,    11,    12,    13,
      14,    15,     0,     0,    16,     0,     0,     0,    17,     0,
       0,     0,     0,     1,     2,     0,     3,     4,    18,     5,
     199,     6,     7,     0,     0,     8,     0,     9,     0,    10,
      11,    12,    13,    14,    15,     0,     0,    16,     0,     0,
       0,    17,     0,     0,     1,     2,     0,     3,     4,     0,
       5,    18,     6,     7,     0,     0,     8,     0,     9,     0,
      10,    11,    12,    13,    14,    15,     0,     0,    16,   208,
       0,     0,    17,     0,     0,     1,     2,     0,     3,     4,
       0,     5,    18,     6,     7,     0,     0,     8,     0,     9,
       0,    10,    11,    12,    13,    14,    15,     0,     0,    16,
     209,     0,     0,    17,     0,     0,     1,     2,     0,     3,
       4,     0,     5,    18,     6,     7,     0,     0,     8,     0,
       9,     0,    10,    11,    12,    13,    14,    15,     0,     0,
      16,     0,     0,     0,    17,    29,     0,     0,     0,     0,
       0,    30,     0,     0,    18,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,    40,     0,     0,     0,     0,    41,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,    41,    65,    66,    98,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,    65,    66,   190,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    65,    66,   193,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,     0,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    65,    66,     0,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      65,    66,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    65,    66,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
       0,    20,    15,    25,    31,    42,    43,    27,    13,    14,
      26,    41,    26,    42,    43,    25,    32,    44,    32,    25,
      20,    58,    44,    28,    42,    43,     0,    26,    25,    26,
      25,    25,    29,    32,    25,    53,    54,    55,    56,    57,
      58,    38,    39,    40,    41,    58,    25,    25,    41,    49,
      42,    43,    41,    41,    51,    19,    20,    21,    22,    23,
      57,    41,    44,    55,    56,    57,    58,    86,    26,    25,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    31,    26,    86,    41,    31,    27,
      41,    27,    26,    41,    91,    44,    49,    27,    13,    27,
      27,    41,   115,    16,    25,    34,     5,    44,    34,   122,
     129,    31,    31,    27,   114,    27,    -1,   145,   122,   116,
      31,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     127,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,   139,    -1,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,   176,   177,   159,
     160,   114,    -1,    -1,    -1,   162,    -1,    -1,   168,   169,
     189,   171,    -1,    -1,    -1,   194,   176,   177,   175,    -1,
      -1,    -1,   182,   180,    -1,    -1,   205,   206,   188,   189,
      -1,    -1,    -1,    -1,   194,   148,    -1,    -1,    -1,    -1,
      -1,   201,   202,    -1,    -1,   205,   206,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,     6,     7,    -1,     9,   182,
      11,    12,    -1,    -1,    15,   188,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    28,   201,   202,
      31,    -1,    -1,     3,     4,    -1,     6,     7,    -1,     9,
      41,    11,    12,    -1,    -1,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,     3,     4,    -1,     6,     7,    -1,
       9,    41,    11,    12,    -1,    -1,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,     3,     4,    -1,     6,     7,
      -1,     9,    41,    11,    12,    -1,    -1,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,     3,     4,    -1,     6,
       7,    -1,     9,    41,    11,    12,    -1,    -1,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,     3,     4,    -1,
       6,     7,    -1,     9,    41,    11,    12,    -1,    -1,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
       3,     4,    -1,     6,     7,    41,     9,    10,    11,    12,
      -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,     3,     4,    -1,     6,     7,    41,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    -1,    -1,     3,     4,    -1,     6,     7,    -1,
       9,    41,    11,    12,    -1,    -1,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,     3,     4,    -1,     6,     7,
      -1,     9,    41,    11,    12,    -1,    -1,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,     3,     4,    -1,     6,
       7,    -1,     9,    41,    11,    12,    -1,    -1,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    41,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    59,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    59,    42,    43,    26,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    42,    43,    26,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    42,    43,    26,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    42,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      42,    43,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    42,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     9,    11,    12,    15,    17,
      19,    20,    21,    22,    23,    24,    27,    31,    41,    62,
      63,    64,    84,    85,    88,    25,    25,    25,    25,    25,
      31,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      54,    59,    85,   102,   103,    25,    27,    41,    88,    79,
      25,    44,     0,    64,    41,   103,   103,    69,    72,   103,
     103,   103,   103,   103,    31,    42,    43,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    41,   101,    75,    80,    41,    63,    41,    92,   103,
      31,    44,    82,    26,    65,   103,    88,    89,    26,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,    26,    76,    25,    44,    28,    26,    32,
      31,   103,    25,    31,    26,    70,    41,    31,    27,    63,
      88,    90,    91,   103,    41,    31,    91,    27,    26,    44,
     103,    78,    28,    41,    26,    32,    31,    26,    66,    27,
     103,    31,    13,    93,    94,    77,    27,    90,    27,    63,
      71,    73,    95,    14,    28,    94,    98,    16,    81,    83,
      28,    63,    41,   103,    34,    25,    63,    63,    67,    28,
      44,    96,    99,   103,    28,    28,    68,   103,    34,    63,
      26,     5,    86,    26,    63,    10,    31,    27,    27,    10,
     100,    87,    74,    97,    31,    63,    63,    31,    28,    28
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:

/* Line 1455 of yacc.c  */
#line 224 "src/parser.y"
    {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[(2) - (3)].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[(2) - (3)].identifier), (yyvsp[(1) - (3)].node_value)->type, false, current_scope, NULL);
                                                }
                                                ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 232 "src/parser.y"
    {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[(2) - (5)].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[(2) - (5)].identifier), (yyvsp[(1) - (5)].node_value)->type, false, current_scope,"");
                                                    if(strcmp((yyvsp[(4) - (5)].node_value) -> type, "ID") == 0){
                                                        if(is_correct_scope((yyvsp[(4) - (5)].node_value) -> value.id_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[(2) - (5)].identifier), current_scope, (yyvsp[(4) - (5)].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[(2) - (5)].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[(2) - (5)].identifier));
                                                            }
                                                        }
                                                    }
                                                    else if(strcmp((yyvsp[(4) - (5)].node_value) -> type, "FUNC") == 0){
                                                        if(is_correct_scope((yyvsp[(4) - (5)].node_value) -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[(2) - (5)].identifier), current_scope, (yyvsp[(4) - (5)].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[(2) - (5)].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[(2) - (5)].identifier));
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[(2) - (5)].identifier), current_scope, (yyvsp[(4) - (5)].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[(2) - (5)].identifier), current_scope);
                                                            generate_quadruple_pop((yyvsp[(2) - (5)].identifier));
                                                        }
                                                    }
                                                    
                                                }
                                                ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 269 "src/parser.y"
    {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[(3) - (6)].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[(3) - (6)].identifier), (yyvsp[(2) - (6)].node_value)->type, true, current_scope,NULL);
                                                    if(strcmp((yyvsp[(5) - (6)].node_value) -> type, "ID") == 0){
                                                        if(is_correct_scope((yyvsp[(5) - (6)].node_value) -> value.id_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[(3) - (6)].identifier), current_scope, (yyvsp[(5) - (6)].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[(3) - (6)].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[(3) - (6)].identifier));
                                                            }
                                                        }
                                                    }
                                                    else if(strcmp((yyvsp[(5) - (6)].node_value) -> type, "FUNC") == 0){
                                                        if(is_correct_scope((yyvsp[(5) - (6)].node_value) -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[(3) - (6)].identifier), current_scope, (yyvsp[(5) - (6)].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[(3) - (6)].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[(3) - (6)].identifier));
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        // check type matching
                                                        if(is_same_type((yyvsp[(3) - (6)].identifier), current_scope, (yyvsp[(5) - (6)].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[(3) - (6)].identifier), current_scope);
                                                            generate_quadruple_pop((yyvsp[(3) - (6)].identifier));
                                                        }
                                                    }
                                                }
                                                ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 306 "src/parser.y"
    {
                                            // check declared or not ($1)
                                            if(is_correct_scope((yyvsp[(1) - (4)].identifier), current_scope, true) == 1 && !is_function((yyvsp[(1) - (4)].identifier), current_scope,false)){
                                                // check if constant
                                                if(!is_const((yyvsp[(1) - (4)].identifier), current_scope)){
                                                    if(strcmp((yyvsp[(3) - (4)].node_value) -> type, "ID") == 0){
                                                        if(is_correct_scope((yyvsp[(3) - (4)].node_value) -> value.id_value, current_scope, false) == 1){
                                                            if(is_same_type((yyvsp[(1) - (4)].identifier), current_scope, (yyvsp[(3) - (4)].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[(1) - (4)].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[(1) - (4)].identifier));
                                                            } 
                                                        }
                                                    }
                                                    else if(strcmp((yyvsp[(3) - (4)].node_value) -> type, "FUNC") == 0){
                                                        if(is_correct_scope((yyvsp[(3) - (4)].node_value) -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[(1) - (4)].identifier), current_scope, (yyvsp[(3) - (4)].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[(1) - (4)].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[(1) - (4)].identifier));
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[(1) - (4)].identifier), current_scope, (yyvsp[(3) - (4)].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[(1) - (4)].identifier), current_scope);
                                                            generate_quadruple_pop((yyvsp[(1) - (4)].identifier));
                                                        } 
                                                    }
                                                }
                                            }
                                            ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 342 "src/parser.y"
    {quad_print((yyvsp[(3) - (5)].node_value));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 346 "src/parser.y"
    {quad_if_jnz();;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 346 "src/parser.y"
    {enter_block();;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 346 "src/parser.y"
    {exit_block();;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 346 "src/parser.y"
    {quad_get_label();;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 349 "src/parser.y"
    {quad_get_label();;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 349 "src/parser.y"
    {quad_jmp_loop();;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 349 "src/parser.y"
    {enter_block();;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 349 "src/parser.y"
    {exit_block(); quad_get_label();;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 350 "src/parser.y"
    {quad_get_label();;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 350 "src/parser.y"
    {quad_jmp_loop();;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 350 "src/parser.y"
    {enter_block();;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 350 "src/parser.y"
    {exit_block(); quad_get_label();;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 351 "src/parser.y"
    {quad_get_label();;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 351 "src/parser.y"
    {enter_block();;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 351 "src/parser.y"
    {exit_block(); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 351 "src/parser.y"
    {quad_repeat_jnz();  quad_repeat_jmp();  quad_get_label();;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 354 "src/parser.y"
    {enter_block();;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 354 "src/parser.y"
    {exit_block(); case_count = 0; default_count = 0; generate_end_label();;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 357 "src/parser.y"
    {enter_block();;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 357 "src/parser.y"
    {exit_block();;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 361 "src/parser.y"
    {quad_function_declare((yyvsp[(2) - (2)].identifier));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 361 "src/parser.y"
    {enter_block();;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 361 "src/parser.y"
    { 
                                                                                        exit_block();
                                                                                        if(!is_redeclared((yyvsp[(2) - (10)].identifier), current_scope)){
                                                                                            insert_symbol((yyvsp[(2) - (10)].identifier), "FUNC", true, current_scope, "VOID");
                                                                                            insert_function_parameters((yyvsp[(2) - (10)].identifier), current_scope, parameters, parameter_count);
                                                                                        } 
                                                                                        parameter_count = 0; 
                                                                                        quad_function_end((yyvsp[(2) - (10)].identifier));
                                                                                        ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 372 "src/parser.y"
    {quad_function_declare((yyvsp[(2) - (2)].identifier));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 372 "src/parser.y"
    {enter_block();;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 372 "src/parser.y"
    {
                                                                                            exit_block();
                                                                                            if(!is_redeclared((yyvsp[(2) - (10)].identifier), current_scope)){
                                                                                                insert_symbol((yyvsp[(2) - (10)].identifier), "FUNC", true, current_scope, (yyvsp[(1) - (10)].node_value) -> type);
                                                                                                insert_function_parameters((yyvsp[(2) - (10)].identifier), current_scope, parameters, parameter_count);
                                                                                            }
                                                                                            parameter_count = 0;
                                                                                            quad_function_end((yyvsp[(2) - (10)].identifier));
                                                                                            ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 385 "src/parser.y"
    {quad_return();;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 394 "src/parser.y"
    {
                                                        Value value;
                                                        value.func_value = (yyvsp[(1) - (4)].identifier);
                                                        (yyval.node_value) = insert_node("FUNC", value);
                                                        if(is_correct_scope((yyvsp[(1) - (4)].identifier), current_scope, true) == 1 && is_function((yyvsp[(1) - (4)].identifier), current_scope,true)){
                                                            check_correct_parameters((yyvsp[(1) - (4)].identifier), current_scope, parameters, parameter_count);
                                                        }
                                                        parameter_count = 0;
                                                        quad_function_call_label((yyvsp[(1) - (4)].identifier));
                                                    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 408 "src/parser.y"
    {enter_block();;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 408 "src/parser.y"
    {exit_block();;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 410 "src/parser.y"
    {
                            struct Value value;
                            (yyval.node_value) = insert_node("INT", value);
                            ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 414 "src/parser.y"
    {
                            struct Value value;
                            (yyval.node_value) = insert_node("FLOAT", value);
                            ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 418 "src/parser.y"
    {
                            struct Value value;
                            (yyval.node_value) = insert_node("CHAR", value);
                            ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 422 "src/parser.y"
    {
                            struct Value value;
                            (yyval.node_value) = insert_node("STRING", value);
                            ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 426 "src/parser.y"
    {
                            struct Value value;
                            (yyval.node_value) = insert_node("BOOL", value);
                            ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 434 "src/parser.y"
    {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[(2) - (4)].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[(2) - (4)].identifier), (yyvsp[(1) - (4)].node_value)->type, false, current_scope,NULL);
                                                    // check type matching
                                                    if(strcmp((yyvsp[(4) - (4)].node_value) -> type, "ID") == 0){
                                                        if(is_correct_scope((yyvsp[(4) - (4)].node_value) -> value.id_value, current_scope, false) == 1){
                                                            if(is_same_type((yyvsp[(2) - (4)].identifier), current_scope, (yyvsp[(4) - (4)].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[(2) - (4)].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[(2) - (4)].identifier));
                                                            } 
                                                        }
                                                    }
                                                    else if(strcmp((yyvsp[(4) - (4)].node_value) -> type, "FUNC") == 0){
                                                        if(is_correct_scope((yyvsp[(4) - (4)].node_value) -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[(2) - (4)].identifier), current_scope, (yyvsp[(4) - (4)].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[(2) - (4)].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[(2) - (4)].identifier));
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[(2) - (4)].identifier), current_scope, (yyvsp[(4) - (4)].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[(2) - (4)].identifier), current_scope);
                                                            generate_quadruple_pop((yyvsp[(2) - (4)].identifier));
                                                        }
                                                    }
                                                     
                                                }
                                                ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 471 "src/parser.y"
    {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[(2) - (2)].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[(2) - (2)].identifier), (yyvsp[(1) - (2)].node_value)->type, false, current_scope, NULL);
                                                    parameters[parameter_count] = malloc(sizeof(function_parameter));
                                                    if (parameters[parameter_count] != NULL) {
                                                        parameters[parameter_count]->name = (yyvsp[(2) - (2)].identifier);
                                                        parameters[parameter_count]->type = (yyvsp[(1) - (2)].node_value)->type;
                                                        parameter_count++; // Increment after assignment
                                                        // create node for the identifier
                                                        Value value;
                                                        value.id_value = (yyvsp[(2) - (2)].identifier);
                                                        (yyval.node_value) = insert_node("ID", value);
                                                        generate_quadruple_push_terminal((yyval.node_value));
                                                    } else {
                                                        // Handle memory allocation failure if needed
                                                        yyerror("Memory allocation failed for function parameter");
                                                    }
                                                }
                                                ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 497 "src/parser.y"
    {
        (yyval.int_value) = 0; // Initialize count to 0
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 500 "src/parser.y"
    { 
        // Increment count for each var_declaration
        (yyval.int_value) = 1;
      ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 504 "src/parser.y"
    {
        // Increment count for each var_declaration
        (yyval.int_value) = (yyvsp[(1) - (3)].int_value) + 1;
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 512 "src/parser.y"
    {
        (yyval.int_value) = 0; // Initialize count to 0
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 516 "src/parser.y"
    {
        // check scope
        // check initialized
        // set parameters
        if(is_correct_scope((yyvsp[(1) - (1)].identifier), current_scope, true) == 1 && !is_function((yyvsp[(1) - (1)].identifier), current_scope,false)){
            // check initialized
            if(is_initialized((yyvsp[(1) - (1)].identifier), current_scope)){
                // set used
                set_used((yyvsp[(1) - (1)].identifier), current_scope);
                parameters[parameter_count] = malloc(sizeof(function_parameter));
                if (parameters[parameter_count] != NULL) {
                    parameters[parameter_count]->name = (yyvsp[(1) - (1)].identifier);
                    parameters[parameter_count]->type = get_symbol_type((yyvsp[(1) - (1)].identifier), current_scope);
                    parameter_count++; // Increment after assignment
                    quad_function_call_parameters((yyvsp[(1) - (1)].identifier));
                } else {
                    // Handle memory allocation failure if needed
                    yyerror("Memory allocation failed for function parameter");
                }
            }
        }
        // Increment count for each var_declaration
        (yyval.int_value) = 1;
      ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 541 "src/parser.y"
    {
        // Increment count for each var_declaration
        (yyval.int_value) = (yyvsp[(1) - (3)].int_value) + 1;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 554 "src/parser.y"
    {quad_get_label(); push_switch_expression();;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 554 "src/parser.y"
    { quad_EQ();   case_jz();    case_jnz();  quad_get_label(); case_count ++;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 554 "src/parser.y"
    {switch_jmp_to_end();;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 558 "src/parser.y"
    {quad_get_label(); default_count++;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 558 "src/parser.y"
    {switch_jmp_to_end();;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 562 "src/parser.y"
    {
                            Value value;
                            value.id_value = (yyvsp[(1) - (1)].identifier);
                            (yyval.node_value) = insert_node("ID", value);
                            // check declared
                            if(is_correct_scope((yyvsp[(1) - (1)].identifier), current_scope, true) == 1 && !is_function((yyvsp[(1) - (1)].identifier), current_scope,false)){
                                // check initialized
                                if(is_initialized((yyvsp[(1) - (1)].identifier), current_scope)){
                                    // set used
                                    set_used((yyvsp[(1) - (1)].identifier), current_scope);
                                    switch_expression = (yyvsp[(1) - (1)].identifier);
                                }
                            }
                            ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 577 "src/parser.y"
    {
                            Value value;
                            value.bool_value = true;
                            (yyval.node_value) = insert_node("BOOL", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 584 "src/parser.y"
    {
                            Value value;
                            value.bool_value = false;
                            (yyval.node_value) = insert_node("BOOL", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 593 "src/parser.y"
    {
                            Value value;
                            value.id_value = (yyvsp[(1) - (1)].identifier);
                            (yyval.node_value) = insert_node("ID", value);
                            // check declared
                            if(is_correct_scope((yyvsp[(1) - (1)].identifier), current_scope, true) == 1 && !is_function((yyvsp[(1) - (1)].identifier), current_scope,false)){
                                // check initialized
                                if(is_initialized((yyvsp[(1) - (1)].identifier), current_scope)){
                                    // set used
                                    set_used((yyvsp[(1) - (1)].identifier), current_scope);
                                    generate_quadruple_push_terminal((yyval.node_value));
                                }
                            }
                            ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 608 "src/parser.y"
    {
                            Value value;
                            value.int_value = (yyvsp[(1) - (1)].int_value);
                            (yyval.node_value) = insert_node("INT", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 615 "src/parser.y"
    {
                            Value value;
                            value.float_value = (yyvsp[(1) - (1)].float_value);
                            (yyval.node_value) = insert_node("FLOAT", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 622 "src/parser.y"
    {
                            Value value;
                            value.char_value = (yyvsp[(1) - (1)].char_value);
                            (yyval.node_value) = insert_node("CHAR", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 629 "src/parser.y"
    {
                            Value value;
                            value.str_value = (yyvsp[(1) - (1)].str_value);
                            (yyval.node_value) = insert_node("STRING", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 644 "src/parser.y"
    {generate_quadruple_push_operation_1_op("NEG", (yyvsp[(2) - (2)].node_value), true);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 645 "src/parser.y"
    {generate_quadruple_push_operation_1_op("PRE_INCR", (yyvsp[(2) - (2)].node_value), true);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 646 "src/parser.y"
    {generate_quadruple_push_operation_1_op("POST_INCR", (yyvsp[(1) - (2)].node_value), true);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 647 "src/parser.y"
    {generate_quadruple_push_operation_1_op("PRE_DECR", (yyvsp[(2) - (2)].node_value), true);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 648 "src/parser.y"
    {generate_quadruple_push_operation_1_op("POST_DECR", (yyvsp[(1) - (2)].node_value), true);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 650 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("ADD", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 651 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("SUB", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 652 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("MUL", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 653 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("DIV", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 654 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("POW", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 655 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("MOD", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 658 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("LOGICAL_AND", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 659 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("LOGICAL_OR", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 660 "src/parser.y"
    {generate_quadruple_push_operation_1_op("LOGICAL_NOT", (yyvsp[(2) - (2)].node_value), false);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 663 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("EQ", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 664 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("NEQ", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 665 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("LT", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 666 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("LTQ", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 667 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("GT", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 668 "src/parser.y"
    {generate_quadruple_push_operation_2_ops("GTQ", (yyvsp[(1) - (3)].node_value), (yyvsp[(3) - (3)].node_value));;}
    break;



/* Line 1455 of yacc.c  */
#line 2701 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 670 "src/parser.y"


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
            if (errors_file == NULL) {
                fprintf(stderr, "Error: Could not open file errors_file for writing\n");
            }
                fprintf(errors_file, "Not Declared: %s at line %d\n", name, lineno);
                fclose(errors_file);
            printf("Not Declared: %s at line %d\n", name, lineno);
        }
        return -1;
    }
    else{
        // found = true ==> declared but wrong scope (ERROR)
        if(in_place){
            if (errors_file == NULL) {
                fprintf(stderr, "Error: Could not open file errors_file for writing\n");
            }
                fprintf(errors_file, "Not Declared In this scope: %s at line %d\n", name, lineno );
                fclose(errors_file);
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
                    if (errors_file == NULL) {
                        fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                    }
                        fprintf(errors_file, "Redeclared: %s at line %d\n", name, lineno);
                        fclose(errors_file);
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
                                    else{
                                        if (errors_file == NULL) {
                                            fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                                        }
                                            fprintf(errors_file, "type mismatch: %s at line %d\n", name, lineno);
                                            fclose(errors_file);
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
                                        if (errors_file == NULL) {
                                            fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                                        }
                                            fprintf(errors_file, "type mismatch: %s at line %d\n", name, lineno);
                                            fclose(errors_file);
                                        printf("type mismatch: %s at line %d\n", name, lineno);
                                        return false;
                                    }
                                }
                            }
                        }
                        else{
                            if (errors_file == NULL) {
                                fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                            }
                                fprintf(errors_file, "type mismatch: %s at line %d\n", name, lineno);
                                fclose(errors_file);
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
                        if (errors_file == NULL) {
                            fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                        }
                            fprintf(errors_file, "trying to modify const variable %s at line %d\n\n",name, lineno);
                            fclose(errors_file);
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
                        if (errors_file == NULL) {
                            fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                        }
                            fprintf(errors_file, "trying to use variable before initializing %s at line %d\n",name, lineno);
                            fclose(errors_file);
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
                            if (errors_file == NULL) {
                                fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                            }
                                fprintf(errors_file, "improper function useage: name %s at line number %d", name, lineno);
                                fclose(errors_file);
                            printf("improper function useage: name %s at line number %d", name, lineno);
                        }
                        return true;
                    }
                    else{
                        if(need_to_be_function){
                            if (errors_file == NULL) {
                                fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                            }
                                fprintf(errors_file, "Error at line: %d     this ID: %s isn't a function name\n", lineno, name);
                                fclose(errors_file);
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
                                if (errors_file == NULL) {
                                    fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                                }
                                    fprintf(errors_file, "Unexpected parameter at position %d for function %s at line %d\n", j + 1, name, lineno);
                                    fclose(errors_file);
                                printf("Unexpected parameter at position %d for function %s at line %d\n", j + 1, name, lineno);
                                return false;
                            }
                        }
                        return true;
                    }
                    else{
                        if (errors_file == NULL) {
                            fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                        }
                            fprintf(errors_file, "Wrong Number of parameters for function: %s at line: %d    expected: %d, but found: %d\n", name, lineno, symbol_table[i] -> no_of_parameters, no_of_parameters);
                            fclose(errors_file);
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
            if (errors_file == NULL) {
                fprintf(stderr, "Error: Could not open file errors_file for writing\n");
            }
                fprintf(errors_file, "Error at line: %d    the 2 operands must be the same type\n", lineno);
                fclose(errors_file);
            printf("Error at line: %d    the 2 operands must be the same type\n", lineno);
            return;
        }
    }
    // check if the first operand is ID
    else if(strcmp(operand1->type, "ID") == 0 ){
        // if not the same type ==> return
        if(strcmp(get_symbol_type(operand1 -> value.id_value, current_scope), operand2->type) != 0){
            if (errors_file == NULL) {
                fprintf(stderr, "Error: Could not open file errors_file for writing\n");
            }
                fprintf(errors_file, "Error at line: %d    the 2 operands must be the same type\n", lineno);
                fclose(errors_file);
            printf("Error at line: %d    the 2 operands must be the same type\n", lineno);
            return;
        }
    }
    // check if the second operand is ID
    else if(strcmp(operand2->type, "ID") == 0 ){
        // if not the same type ==> return
        if(strcmp(operand1->type, get_symbol_type(operand2 -> value.id_value, current_scope)) != 0){
            if (errors_file == NULL) {
                fprintf(stderr, "Error: Could not open file errors_file for writing\n");
            }
                fprintf(errors_file, "Error at line: %d    the 2 operands must be the same type\n", lineno);
                fclose(errors_file);
            printf("Error at line: %d    the 2 operands must be the same type\n", lineno);
            return;
        }
    }
    // the 2 operands are not IDs ==> check the type
    else if(strcmp(operand1->type, operand2->type) != 0){
        if (errors_file == NULL) {
            fprintf(stderr, "Error: Could not open file errors_file for writing\n");
        }
            fprintf(errors_file, "Error at line: %d    the 2 operands must be the same type\n", lineno);
            fclose(errors_file);
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
    //fprintf(quad_file, "push %s\n", quadruples[quad_idx].operand1);
    //fprintf(quad_file, "push %s\n", quadruples[quad_idx].operand2);
    fprintf(quad_file, "%s\n", operation);
    fclose(quad_file);
}

void generate_quadruple_push_operation_1_op(char* operation, Node* operand, bool numeric){
    // this function is for unary operators
    //  if the operator is arithmetic ==> numeric is true ==> check the rype of the operand
    if(numeric){
        if(strcmp(operand->type, "INT") != 0 && strcmp(operand->type, "FLOAT") != 0){
            if(strcmp(operand->type, "ID") != 0){
                if (errors_file == NULL) {
                    fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                }
                    fprintf(errors_file, "Improper type for arithmetic operation at line: %d      expected float or int\n", lineno);
                    fclose(errors_file);
                printf("Improper type for arithmetic operation at line: %d      expected float or int\n", lineno);
                return;
            }
            if(strcmp(operand->type, "ID") == 0){
                // if ID ==> check its type
                //if not INT or FLOAT ==> return
                if(strcmp(get_symbol_type(operand -> value.id_value, current_scope), "INT") != 0 && strcmp(get_symbol_type(operand -> value.id_value, current_scope), "FLOAT") != 0){
                    if (errors_file == NULL) {
                        fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                    }
                        fprintf(errors_file, "Improper type for arithmetic operation at line: %d      expected float or int\n", lineno);
                        fclose(errors_file);
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
    //fprintf(quad_file, "push %s\n", quadruples[quad_idx].operand1);
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

void quad_function_call_label(char* operand){
    quad_idx++;
    quadruples[quad_idx].operation = "CALL";
    quadruples[quad_idx].operand1 = operand;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "CALL %s\n", operand);
    fclose(quad_file);
}

void quad_function_call_parameters(char* operand){
    quad_idx++;
    quadruples[quad_idx].operation = "PUSH";
    quadruples[quad_idx].operand1 = operand;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "push %s\n", operand);
    fclose(quad_file);
}

void quad_function_declare(char* operand){
    quad_idx++;
    quadruples[quad_idx].operation = "START PROC";
    quadruples[quad_idx].operand1 = operand;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "START PROC %s\n", operand);
    fclose(quad_file);
}

void quad_function_end(char* operand){
    quad_idx++;
    quadruples[quad_idx].operation = "ENDPROC";
    quadruples[quad_idx].operand1 = operand;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "ENDPROC %s\n", operand);
    fclose(quad_file);
}

void quad_return(){
    quad_idx++;
    quadruples[quad_idx].operation = "RET";
    quadruples[quad_idx].operand1 = NULL;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "RET\n");
    fclose(quad_file);
}

void quad_get_label(){
    char Label[10];
    generate_label(Label, label_count);
    quad_idx++;
    quadruples[quad_idx].operation = Label;
    quadruples[quad_idx].operand1 = NULL;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;
    label_count++;
    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "%s:\n", quadruples[quad_idx].operation);
    fclose(quad_file);
}

void quad_jmp_loop(){
    char Label[10];
    generate_label(Label, label_count);

    quad_idx++;
    quadruples[quad_idx].operation = "JZ";
    quadruples[quad_idx].operand1 = Label;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;
    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "%s %s\n", quadruples[quad_idx].operation, quadruples[quad_idx].operand1);
    fclose(quad_file);

}
void quad_if_jnz(){
    char Label[10];
    generate_label(Label, label_count);

    quad_idx++;
    quadruples[quad_idx].operation = "JNZ";
    quadruples[quad_idx].operand1 = Label;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;
    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "%s %s\n", quadruples[quad_idx].operation, quadruples[quad_idx].operand1);
    fclose(quad_file);
}

void quad_repeat_jnz(){
    char Label[10];
    generate_label(Label, label_count - 1);

    quad_idx++;
    quadruples[quad_idx].operation = "JNZ";
    quadruples[quad_idx].operand1 = Label;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;
    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "%s %s\n", quadruples[quad_idx].operation, quadruples[quad_idx].operand1);
    fclose(quad_file);
}

void quad_repeat_jmp(){
    char Label[10];
    generate_label(Label, label_count);

    quad_idx++;
    quadruples[quad_idx].operation = "JMP";
    quadruples[quad_idx].operand1 = Label;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;
    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "%s %s\n", quadruples[quad_idx].operation, quadruples[quad_idx].operand1);
    fclose(quad_file);
}

void push_switch_expression(){
    // Generate quadruple for push
    quad_idx++;
    quadruples[quad_idx].operation = "push";
    quadruples[quad_idx].operand1 = switch_expression;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;

    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "push %s\n", switch_expression);
    fclose(quad_file);
}

void switch_jmp_to_end(){
    quad_idx++;
    quadruples[quad_idx].operation = "JMP";
    quadruples[quad_idx].operand1 = end_switch_label;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;
    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "JMP %s\n", end_switch_label);
    fclose(quad_file);
}

void case_jz(){
    char Label[10];
    generate_label(Label, label_count);

    quad_idx++;
    quadruples[quad_idx].operation = "JZ";
    quadruples[quad_idx].operand1 = Label;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;
    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "%s %s\n", quadruples[quad_idx].operation, quadruples[quad_idx].operand1);
    fclose(quad_file);
}

void case_jnz(){
    char Label[10];
    generate_label(Label, label_count + 1);

    quad_idx++;
    quadruples[quad_idx].operation = "JNZ";
    quadruples[quad_idx].operand1 = Label;
    quadruples[quad_idx].operand2 = NULL;
    quadruples[quad_idx].result = NULL;
    // Output the quadruple to a file
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "%s %s\n", quadruples[quad_idx].operation, quadruples[quad_idx].operand1);
    fclose(quad_file);
}

void quad_EQ(){
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "EQ\n");
    fclose(quad_file);
}

void generate_end_label(){
    FILE *quad_file = fopen("quads.txt", "a");
    fprintf(quad_file, "E0000:\n");
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

void generate_label(char* label, int label_number) {
    sprintf(label, "L%03d", label_number);
}
/*==============================================================================*/

void print_symbol_table(const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename);
        return;
    }

    for (int i = 0; i <= symbol_table_idx; i++) {
        Symbol *symbol = symbol_table[i];
        fprintf(file, "Name: %s, Type: %s, Const: %s, Initialized: %s, Used: %s, Return Type: %s\n",
                symbol->name,
                symbol->type,
                symbol->is_const ? "true" : "false",
                symbol->is_initialized ? "true" : "false",
                symbol->is_used ? "true" : "false",
                symbol->return_type ? symbol->return_type : "N/A");

        if (strcmp(symbol->type, "FUNC") == 0) {
            fprintf(file, "Parameters: \n");
            for (int j = 0; j < symbol->no_of_parameters; j++) {
                function_parameter *param = symbol->parameters[j];
                fprintf(file, "  Param Name: %s, Param Type: %s\n", param->name, param->type);
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void write_to_errors_file(char * error_txt){
    if (errors_file == NULL) {
        fprintf(stderr, "Error: Could not open file errors_file for writing\n");
    }
        fprintf(errors_file, "%s\n", error_txt);
        fclose(errors_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Delete the file at the start
    if (remove("quads.txt") != 0) {
        fprintf(stderr, "Error deleting file: quads.txt\n");
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
    errors_file = fopen("errors.txt", "w");
    yyparse();

    fclose(yyin);

    if (!is_all_used()) {
        if (errors_file == NULL) {
        fprintf(stderr, "Error: Could not open file errors_file for writing\n");
    }
        fprintf(errors_file, "Not all variables used\n");
        fclose(errors_file);
        printf("Not all variables used\n");
    }
    print_symbol_table("symbol_table.txt");
    free(current_scope); // Clean up allocated memory before exiting
    return EXIT_SUCCESS;
}

void yyerror(char const *s)
{
    fprintf(stderr, "%s at line %d\n", s, lineno);
}

