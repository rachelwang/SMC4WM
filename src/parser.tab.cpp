/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 18 "parser.ypp" /* yacc.c:339  */

  #include "parser.hpp"
  #include "lex.yy.cpp" /* can't think of a better way to avoid clashes between C
                         and C++ */

  extern FILE *yyin;
  extern char *yytext;
  Node *parse_tree;

  #ifdef VERBOSE
    class Q_el {
    public:
      Node *n;
      Q_el *next;
    };
  #endif

  Node *nodep_copy(Node *, double);
  LogicalRelationalNode *push_neg(LogicalRelationalNode *);
  #ifdef VERBOSE
    void traverse(Node *);
  #endif
  int yyerror(const char *);

#line 91 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
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
    ID = 258,
    T_DOUBLE = 259,
    T_INT = 260,
    TRUE = 261,
    FALSE = 262,
    L_PAREN = 263,
    R_PAREN = 264,
    L_SQUARE = 265,
    R_SQUARE = 266,
    COMMA = 267,
    EQ = 268,
    NEQ = 269,
    LTE = 270,
    LT = 271,
    GTE = 272,
    GT = 273,
    MUL = 274,
    ADD = 275,
    SUB = 276,
    DIV = 277,
    NEG = 278,
    AND = 279,
    OR = 280,
    NEXT = 281,
    FUTURE = 282,
    GLOBAL = 283,
    UNTIL = 284,
    UNKN = 285,
    ENDOFFILE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "parser.ypp" /* yacc.c:355  */

  double constant;
  Node *tree_node;

#line 168 "parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "parser.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   84

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  72

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    98,   105,   115,   122,   132,   139,   149,
     156,   164,   172,   180,   189,   196,   205,   213,   221,   228,
     236,   244,   252,   260,   268,   278,   285,   292,   299,   308,
     315,   322,   331,   338,   345,   352
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "T_DOUBLE", "T_INT", "TRUE",
  "FALSE", "L_PAREN", "R_PAREN", "L_SQUARE", "R_SQUARE", "COMMA", "EQ",
  "NEQ", "LTE", "LT", "GTE", "GT", "MUL", "ADD", "SUB", "DIV", "NEG",
  "AND", "OR", "NEXT", "FUTURE", "GLOBAL", "UNTIL", "UNKN", "ENDOFFILE",
  "$accept", "formula", "disj", "conj", "until", "neg", "bound",
  "relation", "sum", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF -19

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-19)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,   -19,   -19,   -19,   -19,   -19,    -1,    46,    -1,     9,
      18,    20,    17,   -16,    -3,     8,   -19,   -19,    59,   -11,
     -19,     7,    50,    10,   -11,   -19,    44,    19,    19,   -19,
      -1,    -1,    51,    10,    10,    10,    10,    10,    10,    46,
      46,    46,    46,   -19,   -19,    27,    -1,   -19,   -19,    45,
      49,    -3,     8,    19,    25,    25,    25,    25,    25,    25,
     -11,   -11,   -19,   -19,   -19,    -1,    -1,    58,   -19,   -19,
      -1,   -19
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,    33,    32,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     5,     7,    13,     0,    25,
      29,     0,     0,     0,    26,     9,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    35,     0,     0,    15,    14,     0,
       0,     4,     6,     0,    21,    22,    19,    20,    23,    24,
      27,    28,    30,    31,    10,     0,     0,     0,    11,    12,
       0,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -19,   -19,    72,    52,    53,    -8,   -18,   -19,     6,    -6,
      11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    49,    17,    18,    19,
      20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    24,     1,     2,     3,     4,     5,     6,    41,    30,
      50,    42,    22,     1,     2,     3,    43,    29,    23,    26,
       7,    31,     8,    47,    48,     9,    10,    11,    27,    45,
      28,     7,    30,    60,    61,    67,    44,    32,    64,    54,
      55,    56,    57,    58,    59,    39,    40,    39,    40,     1,
       2,     3,    62,    63,    23,    46,    65,    68,    69,    44,
      66,    53,    71,    33,    34,    35,    36,    37,    38,    70,
      39,    40,    33,    34,    35,    36,    37,    38,    21,    39,
      40,     0,    51,     0,    52
};

static const yytype_int8 yycheck[] =
{
       8,     7,     3,     4,     5,     6,     7,     8,    19,    25,
      28,    22,     6,     3,     4,     5,     9,     0,     8,    10,
      21,    24,    23,     4,     5,    26,    27,    28,    10,    23,
      10,    21,    25,    39,    40,    53,     9,    29,    46,    33,
      34,    35,    36,    37,    38,    20,    21,    20,    21,     3,
       4,     5,    41,    42,     8,    11,    11,    65,    66,     9,
      11,    10,    70,    13,    14,    15,    16,    17,    18,    11,
      20,    21,    13,    14,    15,    16,    17,    18,     6,    20,
      21,    -1,    30,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    21,    23,    26,
      27,    28,    33,    34,    35,    36,    37,    39,    40,    41,
      42,    34,    40,     8,    41,    37,    10,    10,    10,     0,
      25,    24,    29,    13,    14,    15,    16,    17,    18,    20,
      21,    19,    22,     9,     9,    40,    11,     4,     5,    38,
      38,    35,    36,    10,    40,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    37,    11,    11,    38,    37,    37,
      11,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    37,    37,    37,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    40,    40,    40,    40,    41,
      41,    41,    42,    42,    42,    42
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     1,     6,     2,
       4,     5,     5,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     3,     3,     1,
       3,     3,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 85 "parser.ypp" /* yacc.c:1646  */
    {
             #ifdef VERBOSE
               printf("\tformula: disj\n");
             #endif
             (yyval.tree_node) = (yyvsp[0].tree_node);
             #ifdef VERBOSE
               traverse((yyval.tree_node));
             #endif
             /* copy $$ to global memory */
             parse_tree = (yyval.tree_node);
           }
#line 1318 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 99 "parser.ypp" /* yacc.c:1646  */
    {
          #ifdef VERBOSE
            printf("\tdisj: conj\n");
          #endif
          (yyval.tree_node) = (yyvsp[0].tree_node);
        }
#line 1329 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 106 "parser.ypp" /* yacc.c:1646  */
    {
          #ifdef VERBOSE
            printf("\tdisj: disj OR conj\n");
          #endif
          (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), OR_L, -0.1,
                                         DONT_KNOW, 0);
        }
#line 1341 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "parser.ypp" /* yacc.c:1646  */
    {
          #ifdef VERBOSE
            printf("\tconj: until\n");
          #endif
          (yyval.tree_node) = (yyvsp[0].tree_node);
        }
#line 1352 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 123 "parser.ypp" /* yacc.c:1646  */
    {
          #ifdef VERBOSE
            printf("\tconj: conj AND until\n");
          #endif
          (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), AND_L, -0.1,
                                         DONT_KNOW, 0);
        }
#line 1364 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 133 "parser.ypp" /* yacc.c:1646  */
    {
           #ifdef VERBOSE
             printf("\tuntil: neg\n");
           #endif
           (yyval.tree_node) = (yyvsp[0].tree_node);
         }
#line 1375 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 140 "parser.ypp" /* yacc.c:1646  */
    {
           #ifdef VERBOSE
             printf("\tuntil: until UNTIL L_SQUARE bound R_SQUARE neg\n");
           #endif
           (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-5].tree_node), (yyvsp[0].tree_node), UNTIL_L, (yyvsp[-2].constant),
                                          DONT_KNOW, 0);
         }
#line 1387 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 150 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tneg: NEG neg\n");
         #endif
         (yyval.tree_node) = push_neg((LogicalRelationalNode *)(yyvsp[0].tree_node));
       }
#line 1398 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 157 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tneg: NEXT L_SQUARE R_SQUARE neg\n");
         #endif
         (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, NULL, (yyvsp[0].tree_node), NEXT_L, 1,
                                        DONT_KNOW, 0);
       }
#line 1410 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tneg: FUTURE L_SQUARE bound R_SQUARE neg\n");
         #endif
         (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, NULL, (yyvsp[0].tree_node), FUTURE_L, (yyvsp[-2].constant),
                                        DONT_KNOW, 0);
       }
#line 1422 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 173 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tneg: GLOBAL L_SQUARE bound R_SQUARE neg\n");
         #endif
         (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, NULL, (yyvsp[0].tree_node), GLOBAL_L, (yyvsp[-2].constant),
                                        DONT_KNOW, 0);
       }
#line 1434 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 181 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tneg: relation\n");
         #endif
         (yyval.tree_node) = (yyvsp[0].tree_node);
       }
#line 1445 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 190 "parser.ypp" /* yacc.c:1646  */
    {
           #ifdef VERBOSE
             printf("\tbound: T_INT\n");
           #endif
           (yyval.constant) = atof(yytext);
         }
#line 1456 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "parser.ypp" /* yacc.c:1646  */
    {
           #ifdef VERBOSE
             printf("\tbound: T_DOUBLE\n");
           #endif
           (yyval.constant) = atof(yytext);
         }
#line 1467 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 206 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: TRUE\n");
              #endif
              (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, NULL, NULL, NOOP_L, -0.1,
                                             SAT, 0);
            }
#line 1479 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 214 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: FALSE\n");
              #endif
              (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, NULL, NULL, NOOP_L, -0.1,
                                             UNSAT, 0);
            }
#line 1491 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 222 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: L_PAREN disj R_PAREN\n");
              #endif
              (yyval.tree_node) = (yyvsp[-1].tree_node);
            }
#line 1502 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 229 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: sum LTE sum\n");
              #endif
              (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), LTE_R, -0.1,
                                             DONT_KNOW, 0);
            }
#line 1514 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 237 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: sum LT sum\n");
              #endif
              (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), LT_R, -0.1,
                                             DONT_KNOW, 0);
            }
#line 1526 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: sum EQ sum\n");
              #endif
              (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), EQ_R, -0.1,
                                             DONT_KNOW, 0);
            }
#line 1538 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 253 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: sum NEQ sum\n");
              #endif
              (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), NEQ_R, -0.1,
                                             DONT_KNOW, 0);
            }
#line 1550 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 261 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: sum GTE sum\n");
              #endif
              (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), GTE_R, -0.1,
                                             DONT_KNOW, 0);
            }
#line 1562 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 269 "parser.ypp" /* yacc.c:1646  */
    {
              #ifdef VERBOSE
                printf("\trelation: sum GT sum\n");
              #endif
              (yyval.tree_node) = new LogicalRelationalNode(LOGICAL_RELATIONAL, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), GT_R, -0.1,
                                             DONT_KNOW, 0);
            }
#line 1574 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 279 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tsum: term\n");
         #endif
         (yyval.tree_node) = (yyvsp[0].tree_node);
       }
#line 1585 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 286 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tsum: SUB term\n");
         #endif
         (yyval.tree_node) = new ArithmeticNode(ARITHMETIC, NULL, (yyvsp[0].tree_node), SUB_A, "", 0.0);
       }
#line 1596 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 293 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tsum: sum ADD term\n");
         #endif
         (yyval.tree_node) = new ArithmeticNode(ARITHMETIC, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), ADD_A, "", 0.0);
       }
#line 1607 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 300 "parser.ypp" /* yacc.c:1646  */
    {
         #ifdef VERBOSE
           printf("\tsum: sum SUB term\n");
         #endif
         (yyval.tree_node) = new ArithmeticNode(ARITHMETIC, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), SUB_A, "", 0.0);
       }
#line 1618 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 309 "parser.ypp" /* yacc.c:1646  */
    {
          #ifdef VERBOSE
            printf("\tterm: factor\n");
          #endif
          (yyval.tree_node) = (yyvsp[0].tree_node);
        }
#line 1629 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 316 "parser.ypp" /* yacc.c:1646  */
    {
          #ifdef VERBOSE
            printf("\tterm: term MUL factor\n");
          #endif
          (yyval.tree_node) = new ArithmeticNode(ARITHMETIC, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), MUL_A, "", 0.0);
        }
#line 1640 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 323 "parser.ypp" /* yacc.c:1646  */
    {
          #ifdef VERBOSE
            printf("\tterm: term DIV factor\n");
          #endif
          (yyval.tree_node) = new ArithmeticNode(ARITHMETIC, (yyvsp[-2].tree_node), (yyvsp[0].tree_node), DIV_A, "", 0.0);
        }
#line 1651 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 332 "parser.ypp" /* yacc.c:1646  */
    {
            #ifdef VERBOSE
              printf("\tfactor: T_INT\n");
            #endif
            (yyval.tree_node) = new ArithmeticNode(ARITHMETIC, NULL, NULL, NOOP_A, "", atof(yytext));
          }
#line 1662 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 339 "parser.ypp" /* yacc.c:1646  */
    {
            #ifdef VERBOSE
              printf("\tfactor: T_DOUBLE\n");
            #endif
            (yyval.tree_node) = new ArithmeticNode(ARITHMETIC, NULL, NULL, NOOP_A, "", atof(yytext));
          }
#line 1673 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 346 "parser.ypp" /* yacc.c:1646  */
    {
            #ifdef VERBOSE
              printf("\tfactor: ID\n");
            #endif
            (yyval.tree_node) = new ArithmeticNode(ARITHMETIC, NULL, NULL, NOOP_A, yytext, 0.0);
          }
#line 1684 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 353 "parser.ypp" /* yacc.c:1646  */
    {
            #ifdef VERBOSE
              printf("\tfactor: L_PAREN sum R_PAREN\n");
            #endif
            (yyval.tree_node) = (yyvsp[-1].tree_node);
          }
#line 1695 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1699 "parser.tab.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
  return yyresult;
}
#line 361 "parser.ypp" /* yacc.c:1906  */


/**
 * copies the entire subtree rooted at src, recursively, and returns the result
 */
Node *nodep_copy(Node *src, double ts) {
  if (src == NULL) {
    return NULL;
  }
  if (src->op_type == ARITHMETIC) {
    return new ArithmeticNode(ARITHMETIC,
                              nodep_copy(src->left, ts),
                              nodep_copy(src->right, ts),
                              src->golden,
                              ts,
                              (((ArithmeticNode *)src)->a).op,
                              (((ArithmeticNode *)src)->a).var,
                              (((ArithmeticNode *)src)->a).val);
  } else { // src->op_type == LOGICAL_RELATIONAL
    return new LogicalRelationalNode(LOGICAL_RELATIONAL,
                                     nodep_copy(src->left, ts),
                                     nodep_copy(src->right, ts),
                                     src->golden,
                                     ts,
                                     (((LogicalRelationalNode *)src)->lr).op,
                                     (((LogicalRelationalNode *)src)->lr).vect,
                                     (((LogicalRelationalNode *)src)->lr).path);
  }
}

/**
 * this is a utility function for converting the input property to Negation Normal
 * Form. It pushes the negation sign inwards recursively
 */
LogicalRelationalNode *push_neg(LogicalRelationalNode *n) {
  if (n == NULL) {
    printf("error! pushing neg inside NULL\n");
    return NULL;
  }
  if (n->op_type == LOGICAL_RELATIONAL) {
    LogicalRelationalNode *new_node;
    switch((n->lr).op) {
      case OR_L :
        (n->lr).op = AND_L;
        n->left = push_neg((LogicalRelationalNode *)(n->left));
        n->right = push_neg((LogicalRelationalNode *)(n->right));
        return n;

      case AND_L :
        (n->lr).op = OR_L;
        n->left = push_neg((LogicalRelationalNode *)(n->left));
        n->right = push_neg((LogicalRelationalNode *)(n->right));
        return n;

      case NEXT_L :
        n->right = push_neg((LogicalRelationalNode *)(n->right));
        return n;

      case FUTURE_L :
        (n->lr).op = GLOBAL_L;
        n->right = push_neg((LogicalRelationalNode *)(n->right));
        return n;

      case GLOBAL_L :
        (n->lr).op = FUTURE_L;
        n->right = push_neg((LogicalRelationalNode *)(n->right));
        return n;

      case UNTIL_L :
        /* ~(pUq) = [~q U (~p & ~q)] | G(~q)
         *
         * keeps multiple copies of ~q instead of creating one and everyone
         * pointing to that. that is, we ultimately have a tree and not a dag
         */
        new_node
          = new LogicalRelationalNode
                  (LOGICAL_RELATIONAL,
                   new LogicalRelationalNode(LOGICAL_RELATIONAL,
                                             nodep_copy(push_neg((LogicalRelationalNode *)(n->right)), 0),
                                             new LogicalRelationalNode(LOGICAL_RELATIONAL,
                                                                       push_neg((LogicalRelationalNode *)(n->left)),
                                                                       nodep_copy(push_neg((LogicalRelationalNode *)(n->right)), 0),
                                                                       AND_L,
                                                                       -0.1,
                                                                       DONT_KNOW,
                                                                       0),
                                             UNTIL_L,
                                             (n->lr).vect.at(0).bound,
                                             DONT_KNOW,
                                             0),
                   new LogicalRelationalNode(LOGICAL_RELATIONAL,
                                             NULL,
                                             nodep_copy(push_neg((LogicalRelationalNode *)(n->right)), 0),
                                             GLOBAL_L,
                                             (n->lr).vect.at(0).bound,
                                             DONT_KNOW,
                                             0),
                   OR_L,
                   -0.1,
                   DONT_KNOW,
                   0);
         delete n->right;
         delete n;
         return new_node;

      case NOOP_L :
        if ((n->lr).vect.at(0).val == SAT) {
          (n->lr).vect.at(0).val = UNSAT;
        } else if ((n->lr).vect.at(0).val == UNSAT) {
          (n->lr).vect.at(0).val = SAT;
        } else {
          printf("push_neg : NOOP_L : has a value of DONT_KNOW\n");
        }
        return n;

      case EQ_R :
        (n->lr).op = NEQ_R;
        return n;

      case NEQ_R :
        (n->lr).op = EQ_R;
        return n;

      case LTE_R :
        (n->lr).op = GT_R;
        return n;

      case LT_R :
        (n->lr).op = GTE_R;
        return n;

      case GTE_R :
        (n->lr).op = LT_R;
        return n;

      case GT_R :
        (n->lr).op = LTE_R;
        return n;
      default:return NULL;
    }
  } else {
    printf("push_neg : arithmetic?\n");
    return NULL;
  }
}

#ifdef VERBOSE
  /**
   * traverse the entire subtree rooted at "root" in a breadth-first manner and
   * print out some information
   */
  void traverse(Node *root) {
    /* do a bfs */
    Q_el *head, *end;
    Node *current;
  
    head = new Q_el();
    head -> n = root;
    head -> next = NULL;
    end = head;
  
    while (head != NULL) {
      current = head -> n;
      if (current->left == NULL && current->right == NULL) {
        /* leaf node */
        if (current->op_type == ARITHMETIC) {
          if ((((ArithmeticNode *)current)->a).var.empty() == false) {
            cout << (((ArithmeticNode *)current)->a).var << "  ";
          } else {
            printf("%f  ", (((ArithmeticNode *)current)->a).val);
          }
        } else if (current->op_type == LOGICAL_RELATIONAL && (((LogicalRelationalNode *)current)->lr).op == NOOP_L) {
          if ((((LogicalRelationalNode *)current)->lr).vect.at(0).val == SAT) {
            printf("SAT  ");
          } else if ((((LogicalRelationalNode *)current)->lr).vect.at(0).val == UNSAT) {
            printf("UNSAT  ");
          } else {
            printf("error!  ");
          }
        } else {
          printf("error!  ");
        }
      } else {
        /* non-leaf node */
        if (current->op_type == ARITHMETIC) {
          printf("%d  ", (((ArithmeticNode *)current)->a).op);
        } else if (current->op_type == LOGICAL_RELATIONAL) {
          printf("%d:%f  ", (((LogicalRelationalNode *)current)->lr).op, (((LogicalRelationalNode *)current)->lr).vect.at(0).bound);
        }
        if (current->left != NULL) {
          end->next = new Q_el();
          end->next->n = current->left;
          end = end->next;
          end->next = NULL;
        }
        if (current->right != NULL) {
          end->next = new Q_el();
          end->next->n = current->right;
          end = end->next;
          end->next = NULL;
        }
      }
      head = head -> next;
    }
    printf("\n");
  }
#endif

/**
 * this is called when a parse error is encountered by Bison
 */
int yyerror(const char *s) {
  printf("%s\n", s);
  return 0;
}
