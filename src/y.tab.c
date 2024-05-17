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
	int sym[26];

    #define Symbol_TABLE_SIZE 1000

    typedef struct Value{
        int int_value;         
        char* str_value; 
        char char_value;
        float float_value;
        bool bool_value;
        char* id_value;
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

#line 165 "y.tab.c"

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
    SWITCH = 266,
    CASE = 267,
    DEFAULT = 268,
    REPEAT = 269,
    UNTIL = 270,
    VOID = 271,
    ENUM = 272,
    INTEGER = 273,
    FLOAT = 274,
    CHAR = 275,
    BOOL = 276,
    STRING = 277,
    CONST = 278,
    FLOAT_VAL = 279,
    INTEGER_VAL = 280,
    CHAR_VAL = 281,
    STRING_VAL = 282,
    TRUE_VAL = 283,
    FALSE_VAL = 284,
    IDENTIFIER = 285,
    INCR = 286,
    DECR = 287,
    LOGICAL_OR = 288,
    LOGICAL_AND = 289,
    EQUALS = 290,
    NOT_EQUALS = 291,
    LESS_THAN = 292,
    LESS_THAN_OR_EQUALS = 293,
    GREATER_THAN = 294,
    GREATER_THAN_OR_EQUALS = 295,
    LOGICAL_NOT = 296,
    UMINUS = 297
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
#define SWITCH 266
#define CASE 267
#define DEFAULT 268
#define REPEAT 269
#define UNTIL 270
#define VOID 271
#define ENUM 272
#define INTEGER 273
#define FLOAT 274
#define CHAR 275
#define BOOL 276
#define STRING 277
#define CONST 278
#define FLOAT_VAL 279
#define INTEGER_VAL 280
#define CHAR_VAL 281
#define STRING_VAL 282
#define TRUE_VAL 283
#define FALSE_VAL 284
#define IDENTIFIER 285
#define INCR 286
#define DECR 287
#define LOGICAL_OR 288
#define LOGICAL_AND 289
#define EQUALS 290
#define NOT_EQUALS 291
#define LESS_THAN 292
#define LESS_THAN_OR_EQUALS 293
#define GREATER_THAN 294
#define GREATER_THAN_OR_EQUALS 295
#define LOGICAL_NOT 296
#define UMINUS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 96 "parser.y"
 
    int int_value;        
    char* str_value;        
    char char_value;      
    float float_value;  
    bool bool_value;    
    char* identifier;
    struct Node *node_value;
;

#line 312 "y.tab.c"

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   815

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


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
       2,     2,     2,     2,     2,     2,     2,    56,     2,     2,
      24,    25,    54,    52,    31,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    30,
       2,    43,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    44,    45,
      46,    47,    48,    49,    50,    51,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   161,   161,   162,   167,   168,   174,   176,   184,   209,
     234,   258,   262,   262,   262,   265,   265,   266,   266,   267,
     267,   267,   270,   270,   273,   273,   277,   277,   288,   288,
     298,   299,   300,   304,   314,   317,   317,   319,   323,   327,
     331,   335,   343,   368,   389,   392,   396,   404,   407,   411,
     418,   419,   420,   424,   428,   432,   446,   452,   458,   460,
     474,   480,   486,   492,   500,   503,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   519,   520,   521,
     524,   525,   526,   527,   528,   529
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "WHILE", "FOR",
  "DO", "CONTINUE", "BREAK", "SWITCH", "CASE", "DEFAULT", "REPEAT",
  "UNTIL", "VOID", "ENUM", "INTEGER", "FLOAT", "CHAR", "BOOL", "STRING",
  "CONST", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", "'?'",
  "':'", "FLOAT_VAL", "INTEGER_VAL", "CHAR_VAL", "STRING_VAL", "TRUE_VAL",
  "FALSE_VAL", "IDENTIFIER", "INCR", "DECR", "'='", "LOGICAL_OR",
  "LOGICAL_AND", "EQUALS", "NOT_EQUALS", "LESS_THAN",
  "LESS_THAN_OR_EQUALS", "GREATER_THAN", "GREATER_THAN_OR_EQUALS", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "LOGICAL_NOT", "UMINUS", "$accept",
  "program", "statements", "stmt", "$@1", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "function_call", "else_stmt", "$@11",
  "datatype", "assignment", "var_declaration", "parameters_list",
  "parameters_list_call", "case_list", "case_stmt", "default_case",
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
     275,   276,   277,   278,    40,    41,   123,   125,    91,    93,
      59,    44,    63,    58,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    61,   288,   289,   290,   291,   292,   293,
     294,   295,    43,    45,    42,    47,    37,    94,   296,   297
};
# endif

#define YYPACT_NINF (-35)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     411,   -23,   -14,   -11,     3,   -35,   -35,    19,    22,    11,
     -35,   -35,   -35,   -35,   -35,   101,   -35,   -35,    20,    52,
     411,   -35,   -35,    18,   171,   171,   171,   101,    21,   -35,
      36,    25,   411,    28,   171,   -35,   -35,   -15,   171,   -35,
     -35,   -35,   -35,   -35,   -35,    51,   171,   171,   171,   171,
     -35,   -35,   463,   481,   499,    38,    46,   -35,    62,   411,
     101,    45,    15,   -35,   -20,   581,   101,   -35,   171,   517,
     -35,   -35,    50,   -25,    64,   -35,   -35,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,    71,    72,    59,   171,    90,    63,    77,   -35,   -19,
     171,   -35,    94,    87,   -35,    70,   609,   -35,   -35,   724,
     741,   758,   758,    58,    58,    58,    58,    50,    50,   -34,
     -34,   -34,   -25,   -35,   -35,   171,   637,   -35,   -35,   -35,
     102,   101,   665,   -35,   -35,   103,   -35,   411,   411,   707,
      93,   118,   119,   -35,   -35,   -35,   -35,   247,   272,    92,
     171,    27,   -35,   112,   411,   411,   -35,   -35,   171,   690,
     106,   -35,   -35,   -35,   171,   311,   336,   137,   535,   411,
     411,   553,   -35,   -35,   117,   -35,   120,   436,   461,   114,
     -35,   -35,    37,    44,   -35,   411,   411,   361,   386,   -35,
     -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,    32,    31,     0,     0,     0,
      37,    38,    39,    41,    40,     0,    24,     6,     0,     0,
       2,     4,    30,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,    47,     0,     1,     5,     0,     0,    61,
      60,    62,    63,    56,    57,    59,     0,     0,     0,     0,
      58,    64,     0,     0,     0,     0,     0,    55,     0,     0,
      44,     0,     0,    48,     0,     0,    44,     7,     0,     0,
      67,    69,    66,    79,     0,    68,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,    25,     0,     0,    10,     0,     0,    65,    11,    78,
      77,    80,    81,    82,    83,    84,    85,    71,    72,    73,
      74,    76,    75,    12,    15,     0,     0,    22,    20,    43,
       0,     0,     0,    33,    49,     0,     8,     0,     0,    42,
       0,     0,     0,    26,    46,     9,    28,     0,     0,     0,
       0,     0,    50,     0,     0,     0,    13,    16,     0,     0,
       0,    23,    51,    52,     0,     0,     0,    34,     0,     0,
       0,     0,    27,    29,     0,    14,     0,     0,     0,     0,
      35,    17,     6,     6,    21,     0,     0,     0,     0,    36,
      18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,   -29,   -16,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,     0,   -35,   -35,   -13,   -35,    14,
      85,   -35,   -35,     1,   -35,   -35,   -35,   155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,   137,   167,   138,   186,    59,   142,
     141,    32,   154,   155,    50,   175,   185,    23,    56,    98,
      99,    64,   151,   152,   163,    58,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    24,    31,    62,    36,   102,   130,    75,    76,    66,
      25,   103,   131,    26,    55,    67,    75,    76,     1,     2,
      22,     3,     4,    90,     5,     6,     7,    27,    68,     8,
      96,     9,    22,    10,    11,    12,    13,    14,    15,   150,
     160,    16,   101,    28,    33,    17,    36,    97,    29,   -53,
     -53,    30,    35,    97,   161,    18,   -54,   -54,    37,    22,
      60,    57,    22,    34,   -53,    61,     1,     2,    63,     3,
       4,   -54,     5,     6,     7,    33,    94,     8,    93,     9,
      36,    10,    11,    12,    13,    14,    15,    95,   100,    16,
     128,    75,    76,    17,   108,   135,    22,   123,   124,    75,
      76,   131,   125,    18,    87,    88,    89,    90,   147,   148,
      85,    86,    87,    88,    89,    90,   127,   129,    97,    10,
      11,    12,    13,    14,   133,   165,   166,   134,   143,   146,
     150,    36,    36,   149,   153,   158,   164,    22,    22,   170,
     177,   178,   174,   180,   184,   144,   181,    22,    22,    36,
      36,   105,   162,     0,    22,    22,   187,   188,     0,     0,
       0,    36,    36,     0,     0,    22,    22,     0,     0,    22,
      22,    36,    36,     0,     0,     0,     0,    22,    22,     0,
      53,    54,     0,     0,     0,    22,    22,    22,    22,    65,
       0,     0,     0,    69,     0,    38,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,    48,     0,     0,     0,     0,    49,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,   126,
       1,     2,     0,     3,     4,   132,     5,     6,     7,     0,
       0,     8,     0,     9,     0,    10,    11,    12,    13,    14,
      15,     0,     0,    16,   156,     1,     2,    17,     3,     4,
     139,     5,     6,     7,     0,     0,     8,    18,     9,     0,
      10,    11,    12,    13,    14,    15,     0,     0,    16,   157,
       0,     0,    17,     0,     0,   159,     0,     0,     0,     0,
       0,     0,    18,   168,     1,     2,     0,     3,     4,   171,
       5,     6,     7,     0,     0,     8,     0,     9,     0,    10,
      11,    12,    13,    14,    15,     0,     0,    16,   172,     1,
       2,    17,     3,     4,     0,     5,     6,     7,     0,     0,
       8,    18,     9,     0,    10,    11,    12,    13,    14,    15,
       0,     0,    16,   173,     1,     2,    17,     3,     4,     0,
       5,     6,     7,     0,     0,     8,    18,     9,     0,    10,
      11,    12,    13,    14,    15,     0,     0,    16,   189,     1,
       2,    17,     3,     4,     0,     5,     6,     7,     0,     0,
       8,    18,     9,     0,    10,    11,    12,    13,    14,    15,
       0,     0,    16,   190,     1,     2,    17,     3,     4,     0,
       5,     6,     7,     0,     0,     8,    18,     9,     0,    10,
      11,    12,    13,    14,    15,     0,     0,    16,     0,     1,
       2,    17,     3,     4,     0,     5,     6,     7,     0,     0,
       8,    18,     9,     0,    10,    11,    12,    13,    14,    15,
       0,     0,    16,     0,     1,     2,   182,     3,     4,     0,
       5,     6,     7,     0,     0,     8,    18,     9,     0,    10,
      11,    12,    13,    14,    15,     0,     0,    16,    74,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,    75,    76,    91,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    75,    76,    92,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      75,    76,   107,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    75,    76,
     176,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    75,    76,   179,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    75,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    76,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   169,     0,     0,     0,     0,     0,     0,
       0,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    75,    76,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    75,    76,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    75,    76,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    75,
      76,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
       0,    24,    15,    32,    20,    25,    25,    41,    42,    24,
      24,    31,    31,    24,    27,    30,    41,    42,     3,     4,
      20,     6,     7,    57,     9,    10,    11,    24,    43,    14,
      59,    16,    32,    18,    19,    20,    21,    22,    23,    12,
      13,    26,    27,    24,    24,    30,    62,    60,    26,    12,
      13,    40,     0,    66,    27,    40,    12,    13,    40,    59,
      24,    40,    62,    43,    27,    40,     3,     4,    40,     6,
       7,    27,     9,    10,    11,    24,    30,    14,    40,    16,
      96,    18,    19,    20,    21,    22,    23,    25,    43,    26,
      27,    41,    42,    30,    30,    25,    96,    26,    26,    41,
      42,    31,    43,    40,    54,    55,    56,    57,   137,   138,
      52,    53,    54,    55,    56,    57,    26,    40,   131,    18,
      19,    20,    21,    22,    30,   154,   155,    40,    26,    26,
      12,   147,   148,    40,    15,    43,    24,   137,   138,    33,
     169,   170,     5,    26,    30,   131,    26,   147,   148,   165,
     166,    66,   151,    -1,   154,   155,   185,   186,    -1,    -1,
      -1,   177,   178,    -1,    -1,   165,   166,    -1,    -1,   169,
     170,   187,   188,    -1,    -1,    -1,    -1,   177,   178,    -1,
      25,    26,    -1,    -1,    -1,   185,   186,   187,   188,    34,
      -1,    -1,    -1,    38,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    53,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    94,
       3,     4,    -1,     6,     7,   100,     9,    10,    11,    -1,
      -1,    14,    -1,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,     3,     4,    30,     6,     7,
     125,     9,    10,    11,    -1,    -1,    14,    40,    16,    -1,
      18,    19,    20,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    40,   158,     3,     4,    -1,     6,     7,   164,
       9,    10,    11,    -1,    -1,    14,    -1,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    27,     3,
       4,    30,     6,     7,    -1,     9,    10,    11,    -1,    -1,
      14,    40,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,    27,     3,     4,    30,     6,     7,    -1,
       9,    10,    11,    -1,    -1,    14,    40,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    27,     3,
       4,    30,     6,     7,    -1,     9,    10,    11,    -1,    -1,
      14,    40,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,    27,     3,     4,    30,     6,     7,    -1,
       9,    10,    11,    -1,    -1,    14,    40,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    -1,     3,
       4,    30,     6,     7,    -1,     9,    10,    11,    -1,    -1,
      14,    40,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,    -1,     3,     4,    30,     6,     7,    -1,
       9,    10,    11,    -1,    -1,    14,    40,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    25,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    41,    42,    25,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    41,    42,    25,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      41,    42,    25,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    41,    42,
      25,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    41,    42,    25,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    41,    42,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,     7,     9,    10,    11,    14,    16,
      18,    19,    20,    21,    22,    23,    26,    30,    40,    61,
      62,    63,    74,    77,    24,    24,    24,    24,    24,    26,
      40,    77,    71,    24,    43,     0,    63,    40,    24,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    53,    58,
      74,    86,    87,    87,    87,    77,    78,    40,    85,    68,
      24,    40,    62,    40,    81,    87,    24,    30,    43,    87,
      87,    87,    87,    87,    25,    41,    42,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    25,    25,    40,    30,    25,    62,    77,    79,    80,
      43,    27,    25,    31,    30,    80,    87,    25,    30,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    26,    26,    43,    87,    26,    27,    40,
      25,    31,    87,    30,    40,    25,    30,    64,    66,    87,
      30,    70,    69,    26,    79,    30,    26,    62,    62,    40,
      12,    82,    83,    15,    72,    73,    27,    27,    43,    87,
      13,    27,    83,    84,    24,    62,    62,    65,    87,    33,
      33,    87,    27,    27,     5,    75,    25,    62,    62,    25,
      26,    26,    30,    30,    30,    76,    67,    62,    62,    27,
      27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    65,    63,    66,    63,    67,    63,    68,
      69,    63,    70,    63,    71,    63,    72,    63,    73,    63,
      63,    63,    63,    74,    75,    76,    75,    77,    77,    77,
      77,    77,    78,    79,    80,    80,    80,    81,    81,    81,
      82,    82,    82,    83,    84,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     3,     5,     6,
       4,     5,     0,     0,    10,     0,     8,     0,    14,     0,
       0,    11,     0,     8,     0,     4,     0,     9,     0,     9,
       1,     1,     1,     5,     0,     0,     5,     1,     1,     1,
       1,     1,     4,     2,     0,     1,     3,     0,     1,     3,
       1,     2,     2,     5,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3
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
#line 176 "parser.y"
                                                {
                                                // check multiple declaration
                                                if(!is_redeclared((yyvsp[-1].identifier), current_scope)){
                                                    // insert the symbol
                                                    insert_symbol((yyvsp[-1].identifier), (yyvsp[-2].node_value)->type, false, current_scope, NULL);
                                                }
                                                }
#line 1748 "y.tab.c"
    break;

  case 8:
#line 184 "parser.y"
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
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[-3].identifier), current_scope);
                                                        }
                                                    }
                                                    
                                                }
                                                }
#line 1776 "y.tab.c"
    break;

  case 9:
#line 209 "parser.y"
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
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        // check type matching
                                                        if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[-3].identifier), current_scope);
                                                        }
                                                    }
                                                }
                                                }
#line 1804 "y.tab.c"
    break;

  case 10:
#line 234 "parser.y"
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
                                                            } 
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[-3].identifier), current_scope, (yyvsp[-1].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[-3].identifier), current_scope);
                                                        } 
                                                    }
                                                }
                                            }
                                            }
#line 1831 "y.tab.c"
    break;

  case 12:
#line 262 "parser.y"
                              {enter_block();}
#line 1837 "y.tab.c"
    break;

  case 13:
#line 262 "parser.y"
                                                               {exit_block();}
#line 1843 "y.tab.c"
    break;

  case 15:
#line 265 "parser.y"
                                 {enter_block();}
#line 1849 "y.tab.c"
    break;

  case 16:
#line 265 "parser.y"
                                                                 {exit_block();}
#line 1855 "y.tab.c"
    break;

  case 17:
#line 266 "parser.y"
                                                                      {enter_block();}
#line 1861 "y.tab.c"
    break;

  case 18:
#line 266 "parser.y"
                                                                                                       {exit_block();}
#line 1867 "y.tab.c"
    break;

  case 19:
#line 267 "parser.y"
                     {enter_block();}
#line 1873 "y.tab.c"
    break;

  case 20:
#line 267 "parser.y"
                                                     {exit_block();}
#line 1879 "y.tab.c"
    break;

  case 22:
#line 270 "parser.y"
                                               {enter_block();}
#line 1885 "y.tab.c"
    break;

  case 23:
#line 270 "parser.y"
                                                                              {exit_block();}
#line 1891 "y.tab.c"
    break;

  case 24:
#line 273 "parser.y"
              {enter_block();}
#line 1897 "y.tab.c"
    break;

  case 25:
#line 273 "parser.y"
                                             {exit_block();}
#line 1903 "y.tab.c"
    break;

  case 26:
#line 277 "parser.y"
                                                      {enter_block();}
#line 1909 "y.tab.c"
    break;

  case 27:
#line 277 "parser.y"
                                                                                        { 
                                                                                        printf("parameter_count %d\n", parameter_count);
                                                                                        exit_block();
                                                                                        if(!is_redeclared((yyvsp[-7].identifier), current_scope)){
                                                                                            insert_symbol((yyvsp[-7].identifier), "FUNC", true, current_scope, "VOID");
                                                                                            insert_function_parameters((yyvsp[-7].identifier), current_scope, parameters, parameter_count);
                                                                                        } 
                                                                                        parameter_count = 0; 
                                                                                        }
#line 1923 "y.tab.c"
    break;

  case 28:
#line 288 "parser.y"
                                                          {enter_block();}
#line 1929 "y.tab.c"
    break;

  case 29:
#line 288 "parser.y"
                                                                                            {
                                                                                            printf("parameter_count %d\n", parameter_count);
                                                                                            exit_block();
                                                                                            if(!is_redeclared((yyvsp[-7].identifier), current_scope)){
                                                                                                insert_symbol((yyvsp[-7].identifier), "FUNC", true, current_scope, (yyvsp[-8].node_value) -> type);
                                                                                            }
                                                                                            parameter_count = 0;
                                                                                            }
#line 1942 "y.tab.c"
    break;

  case 33:
#line 304 "parser.y"
                                                     {
                                                        parameter_count = 0;
                                                        Value value;
                                                        value.id_value = (yyvsp[-4].identifier);
                                                        (yyval.node_value) = insert_node("FUNC", value);
                                                        if(is_correct_scope((yyvsp[-4].identifier), current_scope, true) == 1 && is_function((yyvsp[-4].identifier), current_scope,true)){
                                                            
                                                        }
                                                    }
#line 1956 "y.tab.c"
    break;

  case 35:
#line 317 "parser.y"
                 {enter_block();}
#line 1962 "y.tab.c"
    break;

  case 36:
#line 317 "parser.y"
                                                  {exit_block();}
#line 1968 "y.tab.c"
    break;

  case 37:
#line 319 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("INT", value);
                            }
#line 1977 "y.tab.c"
    break;

  case 38:
#line 323 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("FLOAT", value);
                            }
#line 1986 "y.tab.c"
    break;

  case 39:
#line 327 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("CHAR", value);
                            }
#line 1995 "y.tab.c"
    break;

  case 40:
#line 331 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("STRING", value);
                            }
#line 2004 "y.tab.c"
    break;

  case 41:
#line 335 "parser.y"
                            {
                            struct Value value;
                            (yyval.node_value) = insert_node("BOOL", value);
                            }
#line 2013 "y.tab.c"
    break;

  case 42:
#line 343 "parser.y"
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
                                                            } 
                                                        }
                                                    }
                                                    else{
                                                        if(is_same_type((yyvsp[-2].identifier), current_scope, (yyvsp[0].node_value))){
                                                            // set initialized
                                                            set_initialized((yyvsp[-2].identifier), current_scope);
                                                        }
                                                    }
                                                     
                                                }
                                                }
#line 2041 "y.tab.c"
    break;

  case 43:
#line 368 "parser.y"
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
                                                    } else {
                                                        // Handle memory allocation failure if needed
                                                        yyerror("Memory allocation failed for function parameter");
                                                    }
                                                }
                                                }
#line 2062 "y.tab.c"
    break;

  case 44:
#line 389 "parser.y"
    {
        (yyval.int_value) = 0; // Initialize count to 0
    }
#line 2070 "y.tab.c"
    break;

  case 45:
#line 392 "parser.y"
                      { 
        // Increment count for each var_declaration
        (yyval.int_value) = 1;
      }
#line 2079 "y.tab.c"
    break;

  case 46:
#line 396 "parser.y"
                                          {
        // Increment count for each var_declaration
        (yyval.int_value) = (yyvsp[-2].int_value) + 1;
      }
#line 2088 "y.tab.c"
    break;

  case 47:
#line 404 "parser.y"
    {
        (yyval.int_value) = 0; // Initialize count to 0
    }
#line 2096 "y.tab.c"
    break;

  case 48:
#line 407 "parser.y"
                 {
        // Increment count for each var_declaration
        (yyval.int_value) = 1;
      }
#line 2105 "y.tab.c"
    break;

  case 49:
#line 411 "parser.y"
                                          {
        // Increment count for each var_declaration
        (yyval.int_value) = (yyvsp[-2].int_value) + 1;
      }
#line 2114 "y.tab.c"
    break;

  case 55:
#line 432 "parser.y"
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
                                }
                            }
                            }
#line 2132 "y.tab.c"
    break;

  case 56:
#line 446 "parser.y"
                            {
                            Value value;
                            value.bool_value = true;
                            (yyval.node_value) = insert_node("BOOL", value);
                            }
#line 2142 "y.tab.c"
    break;

  case 57:
#line 452 "parser.y"
                            {
                            Value value;
                            value.bool_value = false;
                            (yyval.node_value) = insert_node("BOOL", value);
                            }
#line 2152 "y.tab.c"
    break;

  case 59:
#line 460 "parser.y"
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
                                }
                            }
                            }
#line 2170 "y.tab.c"
    break;

  case 60:
#line 474 "parser.y"
                                {
                            Value value;
                            value.int_value = (yyvsp[0].int_value);
                            (yyval.node_value) = insert_node("INT", value);
                            }
#line 2180 "y.tab.c"
    break;

  case 61:
#line 480 "parser.y"
                                {
                            Value value;
                            value.float_value = (yyvsp[0].float_value);
                            (yyval.node_value) = insert_node("FLOAT", value);
                            }
#line 2190 "y.tab.c"
    break;

  case 62:
#line 486 "parser.y"
                                        {
                            Value value;
                            value.char_value = (yyvsp[0].char_value);
                            (yyval.node_value) = insert_node("CHAR", value);
                            }
#line 2200 "y.tab.c"
    break;

  case 63:
#line 492 "parser.y"
                            {
                            Value value;
                            value.str_value = (yyvsp[0].str_value);
                            (yyval.node_value) = insert_node("STRING", value);
                            }
#line 2210 "y.tab.c"
    break;


#line 2214 "y.tab.c"

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
#line 531 "parser.y"


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
