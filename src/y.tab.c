/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 212 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    EQUALS = 291,
    NOT_EQUALS = 292,
    LESS_THAN = 293,
    LESS_THAN_OR_EQUALS = 294,
    GREATER_THAN = 295,
    GREATER_THAN_OR_EQUALS = 296,
    LOGICAL_NOT = 297,
    UMINUS = 298
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define WHILE 261
#define FOR 262
#define DO 263
#define CONTINUE 264
#define BREAK 265
#define RETURN 266
#define SWITCH 267
#define CASE 268
#define DEFAULT 269
#define REPEAT 270
#define UNTIL 271
#define VOID 272
#define ENUM 273
#define INTEGER 274
#define FLOAT 275
#define CHAR 276
#define BOOL 277
#define STRING 278
#define CONST 279
#define FLOAT_VAL 280
#define INTEGER_VAL 281
#define CHAR_VAL 282
#define STRING_VAL 283
#define TRUE_VAL 284
#define FALSE_VAL 285
#define IDENTIFIER 286
#define INCR 287
#define DECR 288
#define LOGICAL_OR 289
#define LOGICAL_AND 290
#define EQUALS 291
#define NOT_EQUALS 292
#define LESS_THAN 293
#define LESS_THAN_OR_EQUALS 294
#define GREATER_THAN 295
#define GREATER_THAN_OR_EQUALS 296
#define LOGICAL_NOT 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 143 "parser.y"
 
    int int_value;        
    char* str_value;        
    char* char_value;      
    float float_value;  
    bool bool_value;    
    char* identifier;
    struct Node *node_value;
;

#line 361 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "'='", "LOGICAL_OR", "LOGICAL_AND", "EQUALS", "NOT_EQUALS", "LESS_THAN",
  "LESS_THAN_OR_EQUALS", "GREATER_THAN", "GREATER_THAN_OR_EQUALS", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "LOGICAL_NOT", "UMINUS", "$accept",
  "program", "statements", "stmt", "$@1", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "return_stmt", "function_call",
  "else_stmt", "$@20", "datatype", "assignment", "var_declaration",
  "parameters_list", "parameters_list_call", "case_list", "case_stmt",
  "$@21", "$@22", "$@23", "default_case", "$@24", "$@25",
  "switch_identifier", "terminals", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
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

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
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
      93,    96,    97,    98,    99,   100,   101,    87,    88,    89,
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,    47,   -19,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   -38,   -38,   -13,   -38,   -28,
      -4,   -38,   -38,   -32,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,     3
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
static const yytype_int8 yystos[] =
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 224 "parser.y"
                                                {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[-1].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[-1].identifier), (yyvsp[-2].node_value)->type, false, current_scope, NULL);
                                                }
                                                }
#line 1831 "y.tab.c"
    break;

  case 8:
#line 232 "parser.y"
                                                {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[-3].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[-3].identifier), (yyvsp[-4].node_value)->type, false, current_scope,"");
                                                    if(strcmp((yyvsp[-1].node_value) -> type, "ID") == 0){
                                                        if(is_correct_scope((yyvsp[-1].node_value) -> value.id_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[-3].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[-3].identifier));
                                                            }
                                                        }
                                                    }
                                                    else if(strcmp((yyvsp[-1].node_value) -> type, "FUNC") == 0){
                                                        if(is_correct_scope((yyvsp[-1].node_value) -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[-3].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[-3].identifier));
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[-3].identifier), current_scope);
                                                            generate_quadruple_pop((yyvsp[-3].identifier));
                                                        }
                                                    }
                                                    
                                                }
                                                }
#line 1871 "y.tab.c"
    break;

  case 9:
#line 269 "parser.y"
                                                 {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[-3].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[-3].identifier), (yyvsp[-4].node_value)->type, true, current_scope,NULL);
                                                    if(strcmp((yyvsp[-1].node_value) -> type, "ID") == 0){
                                                        if(is_correct_scope((yyvsp[-1].node_value) -> value.id_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[-3].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[-3].identifier));
                                                            }
                                                        }
                                                    }
                                                    else if(strcmp((yyvsp[-1].node_value) -> type, "FUNC") == 0){
                                                        if(is_correct_scope((yyvsp[-1].node_value) -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[-3].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[-3].identifier));
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        // check type matching
                                                        if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[-3].identifier), current_scope);
                                                            generate_quadruple_pop((yyvsp[-3].identifier));
                                                        }
                                                    }
                                                }
                                                }
#line 1911 "y.tab.c"
    break;

  case 10:
#line 306 "parser.y"
                                                    {
                                            // check declared or not ($1)
                                            if(is_correct_scope((yyvsp[-3].identifier), current_scope, true) == 1 && !is_function((yyvsp[-3].identifier), current_scope,false)){
                                                // check if constant
                                                if(!is_const((yyvsp[-3].identifier), current_scope)){
                                                    if(strcmp((yyvsp[-1].node_value) -> type, "ID") == 0){
                                                        if(is_correct_scope((yyvsp[-1].node_value) -> value.id_value, current_scope, false) == 1){
                                                            if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[-3].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[-3].identifier));
                                                            } 
                                                        }
                                                    }
                                                    else if(strcmp((yyvsp[-1].node_value) -> type, "FUNC") == 0){
                                                        if(is_correct_scope((yyvsp[-1].node_value) -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[-3].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[-3].identifier));
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[-3].identifier), current_scope);
                                                            generate_quadruple_pop((yyvsp[-3].identifier));
                                                        } 
                                                    }
                                                }
                                            }
                                            }
#line 1950 "y.tab.c"
    break;

  case 11:
#line 342 "parser.y"
                                                {quad_print((yyvsp[-2].node_value));}
#line 1956 "y.tab.c"
    break;

  case 12:
#line 346 "parser.y"
                      {quad_if_jnz();}
#line 1962 "y.tab.c"
    break;

  case 13:
#line 346 "parser.y"
                                              {enter_block();}
#line 1968 "y.tab.c"
    break;

  case 14:
#line 346 "parser.y"
                                                                               {exit_block();}
#line 1974 "y.tab.c"
    break;

  case 15:
#line 346 "parser.y"
                                                                                               {quad_get_label();}
#line 1980 "y.tab.c"
    break;

  case 17:
#line 349 "parser.y"
                    {quad_get_label();}
#line 1986 "y.tab.c"
    break;

  case 18:
#line 349 "parser.y"
                                             {quad_jmp_loop();}
#line 1992 "y.tab.c"
    break;

  case 19:
#line 349 "parser.y"
                                                                       {enter_block();}
#line 1998 "y.tab.c"
    break;

  case 20:
#line 349 "parser.y"
                                                                                                       {exit_block(); quad_get_label();}
#line 2004 "y.tab.c"
    break;

  case 21:
#line 350 "parser.y"
                  {quad_get_label();}
#line 2010 "y.tab.c"
    break;

  case 22:
#line 350 "parser.y"
                                                              {quad_jmp_loop();}
#line 2016 "y.tab.c"
    break;

  case 23:
#line 350 "parser.y"
                                                                                                             {enter_block();}
#line 2022 "y.tab.c"
    break;

  case 24:
#line 350 "parser.y"
                                                                                                                                              {exit_block(); quad_get_label();}
#line 2028 "y.tab.c"
    break;

  case 25:
#line 351 "parser.y"
                     {quad_get_label();}
#line 2034 "y.tab.c"
    break;

  case 26:
#line 351 "parser.y"
                                         {enter_block();}
#line 2040 "y.tab.c"
    break;

  case 27:
#line 351 "parser.y"
                                                                         {exit_block(); }
#line 2046 "y.tab.c"
    break;

  case 28:
#line 351 "parser.y"
                                                                                                                 {quad_repeat_jnz();  quad_repeat_jmp();  quad_get_label();}
#line 2052 "y.tab.c"
    break;

  case 29:
#line 354 "parser.y"
                                               {enter_block();}
#line 2058 "y.tab.c"
    break;

  case 30:
#line 354 "parser.y"
                                                                              {exit_block(); case_count = 0; default_count = 0; generate_end_label();}
#line 2064 "y.tab.c"
    break;

  case 31:
#line 357 "parser.y"
              {enter_block();}
#line 2070 "y.tab.c"
    break;

  case 32:
#line 357 "parser.y"
                                             {exit_block();}
#line 2076 "y.tab.c"
    break;

  case 33:
#line 361 "parser.y"
                           {quad_function_declare((yyvsp[0].identifier));}
#line 2082 "y.tab.c"
    break;

  case 34:
#line 361 "parser.y"
                                                                                   {enter_block();}
#line 2088 "y.tab.c"
    break;

  case 35:
#line 361 "parser.y"
                                                                                                                     { 
                                                                                        exit_block();
                                                                                        if(!is_redeclared((yyvsp[-8].identifier), current_scope)){
                                                                                            insert_symbol((yyvsp[-8].identifier), "FUNC", true, current_scope, "VOID");
                                                                                            insert_function_parameters((yyvsp[-8].identifier), current_scope, parameters, parameter_count);
                                                                                        } 
                                                                                        parameter_count = 0; 
                                                                                        quad_function_end((yyvsp[-8].identifier));
                                                                                        }
#line 2102 "y.tab.c"
    break;

  case 36:
#line 372 "parser.y"
                              {quad_function_declare((yyvsp[0].identifier));}
#line 2108 "y.tab.c"
    break;

  case 37:
#line 372 "parser.y"
                                                                                      {enter_block();}
#line 2114 "y.tab.c"
    break;

  case 38:
#line 372 "parser.y"
                                                                                                                        {
                                                                                            exit_block();
                                                                                            if(!is_redeclared((yyvsp[-8].identifier), current_scope)){
                                                                                                insert_symbol((yyvsp[-8].identifier), "FUNC", true, current_scope, (yyvsp[-9].node_value) -> type);
                                                                                                insert_function_parameters((yyvsp[-8].identifier), current_scope, parameters, parameter_count);
                                                                                            }
                                                                                            parameter_count = 0;
                                                                                            quad_function_end((yyvsp[-8].identifier));
                                                                                            }
#line 2128 "y.tab.c"
    break;

  case 41:
#line 385 "parser.y"
                                    {quad_return();}
#line 2134 "y.tab.c"
    break;

  case 44:
#line 394 "parser.y"
                                                 {
                                                        Value value;
                                                        value.func_value = (yyvsp[-3].identifier);
                                                        (yyval.node_value) = insert_node("FUNC", value);
                                                        if(is_correct_scope((yyvsp[-3].identifier), current_scope, true) == 1 && is_function((yyvsp[-3].identifier), current_scope,true)){
                                                            check_correct_parameters((yyvsp[-3].identifier), current_scope, parameters, parameter_count);
                                                        }
                                                        parameter_count = 0;
                                                        quad_function_call_label((yyvsp[-3].identifier));
                                                    }
#line 2149 "y.tab.c"
    break;

  case 46:
#line 408 "parser.y"
                 {enter_block();}
#line 2155 "y.tab.c"
    break;

  case 47:
#line 408 "parser.y"
                                                  {exit_block();}
#line 2161 "y.tab.c"
    break;

  case 48:
#line 410 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("INT", value);
                            }
#line 2170 "y.tab.c"
    break;

  case 49:
#line 414 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("FLOAT", value);
                            }
#line 2179 "y.tab.c"
    break;

  case 50:
#line 418 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("CHAR", value);
                            }
#line 2188 "y.tab.c"
    break;

  case 51:
#line 422 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("STRING", value);
                            }
#line 2197 "y.tab.c"
    break;

  case 52:
#line 426 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("BOOL", value);
                            }
#line 2206 "y.tab.c"
    break;

  case 53:
#line 434 "parser.y"
                                                    {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[-2].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[-2].identifier), (yyvsp[-3].node_value)->type, false, current_scope,NULL);
                                                    // check type matching
                                                    if(strcmp((yyvsp[0].node_value) -> type, "ID") == 0){
                                                        if(is_correct_scope((yyvsp[0].node_value) -> value.id_value, current_scope, false) == 1){
                                                            if(is_same_type((yyvsp[-2].identifier), current_scope, (yyvsp[0].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[-2].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[-2].identifier));
                                                            } 
                                                        }
                                                    }
                                                    else if(strcmp((yyvsp[0].node_value) -> type, "FUNC") == 0){
                                                        if(is_correct_scope((yyvsp[0].node_value) -> value.func_value, current_scope, false) == 1){
                                                            // check type matching
                                                            if(is_same_type((yyvsp[-2].identifier), current_scope, (yyvsp[0].node_value))){
                                                                // set initialized
                                                                set_initialized((yyvsp[-2].identifier), current_scope);
                                                                generate_quadruple_pop((yyvsp[-2].identifier));
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[-2].identifier), current_scope, (yyvsp[0].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[-2].identifier), current_scope);
                                                            generate_quadruple_pop((yyvsp[-2].identifier));
                                                        }
                                                    }
                                                     
                                                }
                                                }
#line 2246 "y.tab.c"
    break;

  case 54:
#line 471 "parser.y"
                                                        {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[0].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[0].identifier), (yyvsp[-1].node_value)->type, false, current_scope, NULL);
                                                    parameters[parameter_count] = malloc(sizeof(function_parameter));
                                                    if (parameters[parameter_count] != NULL) {
                                                        parameters[parameter_count]->name = (yyvsp[0].identifier);
                                                        parameters[parameter_count]->type = (yyvsp[-1].node_value)->type;
                                                        parameter_count++; // Increment after assignment
                                                        // create node for the identifier
                                                        Value value;
                                                        value.id_value = (yyvsp[0].identifier);
                                                        (yyval.node_value) = insert_node("ID", value);
                                                        generate_quadruple_push_terminal((yyval.node_value));
                                                    } else {
                                                        // Handle memory allocation failure if needed
                                                        yyerror("Memory allocation failed for function parameter");
                                                    }
                                                }
                                                }
#line 2272 "y.tab.c"
    break;

  case 55:
#line 497 "parser.y"
    {
        (yyval.int_value) = 0; // Initialize count to 0
    }
#line 2280 "y.tab.c"
    break;

  case 56:
#line 500 "parser.y"
                      { 
        // Increment count for each var_declaration
        (yyval.int_value) = 1;
      }
#line 2289 "y.tab.c"
    break;

  case 57:
#line 504 "parser.y"
                                          {
        // Increment count for each var_declaration
        (yyval.int_value) = (yyvsp[-2].int_value) + 1;
    }
#line 2298 "y.tab.c"
    break;

  case 58:
#line 512 "parser.y"
    {
        (yyval.int_value) = 0; // Initialize count to 0
    }
#line 2306 "y.tab.c"
    break;

  case 59:
#line 516 "parser.y"
                 {
        // check scope
        // check initialized
        // set parameters
        if(is_correct_scope((yyvsp[0].identifier), current_scope, true) == 1 && !is_function((yyvsp[0].identifier), current_scope,false)){
            // check initialized
            if(is_initialized((yyvsp[0].identifier), current_scope)){
                // set used
                set_used((yyvsp[0].identifier), current_scope);
                parameters[parameter_count] = malloc(sizeof(function_parameter));
                if (parameters[parameter_count] != NULL) {
                    parameters[parameter_count]->name = (yyvsp[0].identifier);
                    parameters[parameter_count]->type = get_symbol_type((yyvsp[0].identifier), current_scope);
                    parameter_count++; // Increment after assignment
                    quad_function_call_parameters((yyvsp[0].identifier));
                } else {
                    // Handle memory allocation failure if needed
                    yyerror("Memory allocation failed for function parameter");
                }
            }
        }
        // Increment count for each var_declaration
        (yyval.int_value) = 1;
      }
#line 2335 "y.tab.c"
    break;

  case 60:
#line 541 "parser.y"
                                          {
        // Increment count for each var_declaration
        (yyval.int_value) = (yyvsp[-2].int_value) + 1;
    }
#line 2344 "y.tab.c"
    break;

  case 64:
#line 554 "parser.y"
            {quad_get_label(); push_switch_expression();}
#line 2350 "y.tab.c"
    break;

  case 65:
#line 554 "parser.y"
                                                               { quad_EQ();   case_jz();    case_jnz();  quad_get_label(); case_count ++;}
#line 2356 "y.tab.c"
    break;

  case 66:
#line 554 "parser.y"
                                                                                                                                                               {switch_jmp_to_end();}
#line 2362 "y.tab.c"
    break;

  case 68:
#line 558 "parser.y"
                {quad_get_label(); default_count++;}
#line 2368 "y.tab.c"
    break;

  case 69:
#line 558 "parser.y"
                                                                      {switch_jmp_to_end();}
#line 2374 "y.tab.c"
    break;

  case 71:
#line 562 "parser.y"
                            {
                            Value value;
                            value.id_value = (yyvsp[0].identifier);
                            (yyval.node_value) = insert_node("ID", value);
                            // check declared
                            if(is_correct_scope((yyvsp[0].identifier), current_scope, true) == 1 && !is_function((yyvsp[0].identifier), current_scope,false)){
                                // check initialized
                                if(is_initialized((yyvsp[0].identifier), current_scope)){
                                    // set used
                                    set_used((yyvsp[0].identifier), current_scope);
                                    switch_expression = (yyvsp[0].identifier);
                                }
                            }
                            }
#line 2393 "y.tab.c"
    break;

  case 72:
#line 577 "parser.y"
                            {
                            Value value;
                            value.bool_value = true;
                            (yyval.node_value) = insert_node("BOOL", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            }
#line 2404 "y.tab.c"
    break;

  case 73:
#line 584 "parser.y"
                            {
                            Value value;
                            value.bool_value = false;
                            (yyval.node_value) = insert_node("BOOL", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            }
#line 2415 "y.tab.c"
    break;

  case 75:
#line 593 "parser.y"
                            {
                            Value value;
                            value.id_value = (yyvsp[0].identifier);
                            (yyval.node_value) = insert_node("ID", value);
                            // check declared
                            if(is_correct_scope((yyvsp[0].identifier), current_scope, true) == 1 && !is_function((yyvsp[0].identifier), current_scope,false)){
                                // check initialized
                                if(is_initialized((yyvsp[0].identifier), current_scope)){
                                    // set used
                                    set_used((yyvsp[0].identifier), current_scope);
                                    generate_quadruple_push_terminal((yyval.node_value));
                                }
                            }
                            }
#line 2434 "y.tab.c"
    break;

  case 76:
#line 608 "parser.y"
                                {
                            Value value;
                            value.int_value = (yyvsp[0].int_value);
                            (yyval.node_value) = insert_node("INT", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            }
#line 2445 "y.tab.c"
    break;

  case 77:
#line 615 "parser.y"
                                {
                            Value value;
                            value.float_value = (yyvsp[0].float_value);
                            (yyval.node_value) = insert_node("FLOAT", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            }
#line 2456 "y.tab.c"
    break;

  case 78:
#line 622 "parser.y"
                                        {
                            Value value;
                            value.char_value = (yyvsp[0].char_value);
                            (yyval.node_value) = insert_node("CHAR", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            }
#line 2467 "y.tab.c"
    break;

  case 79:
#line 629 "parser.y"
                            {
                            Value value;
                            value.str_value = (yyvsp[0].str_value);
                            (yyval.node_value) = insert_node("STRING", value);
                            generate_quadruple_push_terminal((yyval.node_value));
                            }
#line 2478 "y.tab.c"
    break;

  case 82:
#line 644 "parser.y"
                        {generate_quadruple_push_operation_1_op("NEG", (yyvsp[0].node_value), true);}
#line 2484 "y.tab.c"
    break;

  case 83:
#line 645 "parser.y"
                        {generate_quadruple_push_operation_1_op("PRE_INCR", (yyvsp[0].node_value), true);}
#line 2490 "y.tab.c"
    break;

  case 84:
#line 646 "parser.y"
                        {generate_quadruple_push_operation_1_op("POST_INCR", (yyvsp[-1].node_value), true);}
#line 2496 "y.tab.c"
    break;

  case 85:
#line 647 "parser.y"
                        {generate_quadruple_push_operation_1_op("PRE_DEC", (yyvsp[0].node_value), true);}
#line 2502 "y.tab.c"
    break;

  case 86:
#line 648 "parser.y"
                        {generate_quadruple_push_operation_1_op("POST_DECR", (yyvsp[-1].node_value), true);}
#line 2508 "y.tab.c"
    break;

  case 87:
#line 650 "parser.y"
                                {generate_quadruple_push_operation_2_ops("ADD", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2514 "y.tab.c"
    break;

  case 88:
#line 651 "parser.y"
                                {generate_quadruple_push_operation_2_ops("SUB", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2520 "y.tab.c"
    break;

  case 89:
#line 652 "parser.y"
                                {generate_quadruple_push_operation_2_ops("MUL", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2526 "y.tab.c"
    break;

  case 90:
#line 653 "parser.y"
                                {generate_quadruple_push_operation_2_ops("DIV", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2532 "y.tab.c"
    break;

  case 91:
#line 654 "parser.y"
                                {generate_quadruple_push_operation_2_ops("POW", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2538 "y.tab.c"
    break;

  case 92:
#line 655 "parser.y"
                                {generate_quadruple_push_operation_2_ops("MOD", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2544 "y.tab.c"
    break;

  case 93:
#line 658 "parser.y"
                                        {generate_quadruple_push_operation_2_ops("LOGICAL_AND", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2550 "y.tab.c"
    break;

  case 94:
#line 659 "parser.y"
                                        {generate_quadruple_push_operation_2_ops("LOGICAL_OR", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2556 "y.tab.c"
    break;

  case 95:
#line 660 "parser.y"
                                {generate_quadruple_push_operation_1_op("LOGICAL_NOT", (yyvsp[0].node_value), false);}
#line 2562 "y.tab.c"
    break;

  case 96:
#line 663 "parser.y"
                                                {generate_quadruple_push_operation_2_ops("EQ", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2568 "y.tab.c"
    break;

  case 97:
#line 664 "parser.y"
                                                {generate_quadruple_push_operation_2_ops("NEQ", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2574 "y.tab.c"
    break;

  case 98:
#line 665 "parser.y"
                                                {generate_quadruple_push_operation_2_ops("LT", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2580 "y.tab.c"
    break;

  case 99:
#line 666 "parser.y"
                                            {generate_quadruple_push_operation_2_ops("LTQ", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2586 "y.tab.c"
    break;

  case 100:
#line 667 "parser.y"
                                            {generate_quadruple_push_operation_2_ops("GT", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2592 "y.tab.c"
    break;

  case 101:
#line 668 "parser.y"
                                        {generate_quadruple_push_operation_2_ops("GTQ", (yyvsp[-2].node_value), (yyvsp[0].node_value));}
#line 2598 "y.tab.c"
    break;


#line 2602 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 670 "parser.y"


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
                    if (errors_file == NULL) {
                        fprintf(stderr, "Error: Could not open file errors_file for writing\n");
                    }
                        fprintf(errors_file, "Well Done: %s at line %d\n", name, lineno);
                        fclose(errors_file);
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

// Delete the file at the start
    if (remove("quads.txt") != 0) {
        fprintf(stderr, "Error deleting file: quads.txt\n");
        return EXIT_FAILURE;
    }

void yyerror(char const *s)
{
    fprintf(stderr, "%s at line %d\n", s, lineno);
}
