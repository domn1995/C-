/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "c-.y" /* yacc.c:339  */

#include <cstdio>
#include <getopt.h>
#include "Token.h"
#include "TreeNode.h"
#include "SymbolTable.h"
#include "PrintTree.h"
#include "Semantic.h"

extern int yylex();
//extern void yyerror(const char* msg);
extern char* yytext;
extern int yylineno;
extern FILE* yyin;

Scope globalScope("global");

static TreeNode* savedTree;
static char* savedName;
static int savedLineNum;

#define YYERROR_VERBOSE
void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", yylineno, msg);
}

#line 94 "c-.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c-.tab.h".  */
#ifndef YY_YY_C_TAB_H_INCLUDED
# define YY_YY_C_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMCONST = 258,
    BOOLCONST = 259,
    ID = 260,
    CHARCONST = 261,
    RECTYPE = 262,
    RECORD = 263,
    STATIC = 264,
    INT = 265,
    CHAR = 266,
    BOOL = 267,
    IF = 268,
    ELSE = 269,
    AND = 270,
    OR = 271,
    NOT = 272,
    WHILE = 273,
    BREAK = 274,
    RETURN = 275,
    DIV = 276,
    STAR = 277,
    ADD = 278,
    MINUS = 279,
    PERCENT = 280,
    COMMA = 281,
    ASSIGN = 282,
    MULASS = 283,
    INC = 284,
    ADDASS = 285,
    DEC = 286,
    SUBASS = 287,
    DIVASS = 288,
    LTHAN = 289,
    LESSEQ = 290,
    EQ = 291,
    NOTEQ = 292,
    GTHAN = 293,
    GRTEQ = 294,
    QMARK = 295,
    LPAREN = 296,
    RPAREN = 297,
    LCURLY = 298,
    RCURLY = 299,
    LBRACKET = 300,
    RBRACKET = 301,
    COLON = 302,
    SEMICOLON = 303,
    DOT = 304,
    ERROR = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "c-.y" /* yacc.c:355  */

    Token t;
    TreeNode* treeNode;
    ExpType expType;

#line 191 "c-.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "c-.tab.c" /* yacc.c:358  */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   110,   110,   116,   133,   139,   143,   147,   155,   168,
     188,   210,   227,   233,   237,   244,   250,   260,   270,   277,
     281,   287,   291,   295,   303,   313,   325,   329,   334,   351,
     357,   377,   395,   401,   406,   416,   420,   426,   430,   434,
     438,   442,   446,   452,   456,   462,   471,   488,   493,   510,
     515,   519,   525,   536,   546,   556,   566,   576,   582,   591,
     600,   607,   614,   621,   628,   635,   641,   647,   653,   661,
     667,   675,   681,   688,   694,   702,   708,   712,   716,   720,
     724,   728,   734,   742,   748,   752,   758,   766,   772,   776,
     780,   786,   793,   799,   804,   808,   814,   818,   824,   829,
     837,   849,   853,   857,   863,   871,   875,   879,   896,   902,
     909,   916
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMCONST", "BOOLCONST", "ID",
  "CHARCONST", "RECTYPE", "RECORD", "STATIC", "INT", "CHAR", "BOOL", "IF",
  "ELSE", "AND", "OR", "NOT", "WHILE", "BREAK", "RETURN", "DIV", "STAR",
  "ADD", "MINUS", "PERCENT", "COMMA", "ASSIGN", "MULASS", "INC", "ADDASS",
  "DEC", "SUBASS", "DIVASS", "LTHAN", "LESSEQ", "EQ", "NOTEQ", "GTHAN",
  "GRTEQ", "QMARK", "LPAREN", "RPAREN", "LCURLY", "RCURLY", "LBRACKET",
  "RBRACKET", "COLON", "SEMICOLON", "DOT", "ERROR", "$accept", "program",
  "declarationList", "declaration", "recDeclaration", "varDeclaration",
  "scopedVarDeclaration", "varDeclList", "varDeclInitialize", "varDeclId",
  "scopedTypeSpecifier", "typeSpecifier", "returnTypeSpecifier",
  "funDeclaration", "params", "paramList", "paramTypeList", "paramIdList",
  "paramId", "statement", "matched", "unmatched", "compoundStmt",
  "localDeclarations", "statementList", "expressionStmt",
  "selectionStmtMatched", "selectionStmtUnmatched", "iterationStmtMatched",
  "iterationStmtUnmatched", "returnStmt", "breakStmt", "expression",
  "simpleExpression", "andExpresssion", "unaryRelExpression",
  "relExpression", "relop", "sumExpression", "sumop", "term", "mulop",
  "unaryExpression", "unaryop", "factor", "mutable", "immutable", "call",
  "args", "argList", "constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -156

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-156)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     177,   -26,  -156,    11,  -156,  -156,  -156,    22,   177,  -156,
    -156,  -156,    24,  -156,  -156,   100,     8,  -156,  -156,   -14,
      -8,  -156,    21,    64,    32,    25,  -156,  -156,   100,    75,
      80,  -156,    31,    35,    60,  -156,    96,   100,    52,    45,
      51,    58,  -156,  -156,  -156,    65,  -156,    31,  -156,  -156,
    -156,    31,   101,   104,  -156,  -156,   142,    70,  -156,   127,
    -156,     7,  -156,  -156,  -156,    76,    64,    82,    84,    73,
     123,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,    86,   101,   125,  -156,   100,  -156,
    -156,    80,  -156,    96,  -156,    31,  -156,    93,    31,    31,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,   127,   127,
    -156,  -156,  -156,   127,  -156,    31,   133,  -156,  -156,    31,
      31,  -156,  -156,    94,   183,  -156,    31,    31,  -156,    31,
    -156,    31,    31,  -156,    -5,  -156,  -156,    99,   117,  -156,
     104,  -156,    18,    70,  -156,   102,  -156,    -9,    -3,  -156,
       6,  -156,  -156,  -156,  -156,  -156,  -156,  -156,    31,  -156,
      96,    96,  -156,  -156,  -156,  -156,   132,  -156,  -156,    96,
    -156,  -156
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    20,     0,    21,    23,    22,     0,     2,     4,
       7,     5,     0,    19,     6,    27,     0,     1,     3,    15,
       0,    12,    13,     0,     0,    26,    29,    47,    27,     0,
       0,     9,     0,    33,    30,    32,     0,     0,     0,     0,
       0,    15,    11,   109,   111,    98,   110,     0,    94,    93,
      95,     0,    14,    69,    71,    73,    75,    83,    87,     0,
      92,    97,    96,   102,   103,     0,     0,     0,     0,     0,
       0,    47,    51,    25,    35,    36,    40,    39,    37,    43,
      38,    44,    41,    42,     0,    67,    97,    28,     0,     8,
      46,     0,    18,     0,    16,   106,    72,     0,     0,     0,
      84,    85,    77,    76,    80,    81,    78,    79,     0,     0,
      89,    88,    90,     0,    91,     0,     0,    34,    31,     0,
       0,    59,    57,     0,    49,    50,     0,     0,    65,     0,
      66,     0,     0,    17,     0,    24,   108,     0,   105,   101,
      68,    70,    74,    82,    86,     0,   100,     0,     0,    58,
       0,    60,    63,    61,    62,    64,    10,   104,     0,    99,
       0,     0,    45,    48,   107,    54,    35,    55,    56,     0,
      52,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,   151,  -156,  -156,  -156,    59,   130,  -156,
    -156,     0,  -156,  -156,   134,  -156,   124,  -156,   103,   -90,
     -94,  -155,  -156,   112,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,   -50,   -30,    74,   -42,  -156,  -156,    67,  -156,
      77,  -156,   -55,  -156,  -156,   -15,  -156,  -156,  -156,  -156,
    -156
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    90,    20,    21,    22,
      91,    23,    13,    14,    24,    25,    26,    34,    35,    73,
      74,    75,    76,    38,   150,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    53,    54,    55,   108,    56,   109,
      57,   113,    58,    59,    60,    86,    62,    63,   137,   138,
      64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    97,    52,   135,   114,    96,   168,    98,    12,    43,
      44,    45,    46,    98,   171,    15,    16,    61,    30,    67,
     123,    30,    17,    47,    68,    69,    70,    28,    48,    19,
      49,    29,    61,   160,    43,    44,    45,    46,    92,   161,
      31,   100,   101,   156,    61,   136,    50,    51,    47,    71,
     162,    27,   115,    48,    72,    49,   116,   141,   144,     2,
     163,    88,     4,     5,     6,   145,   166,   167,    32,    33,
     165,    50,    51,    37,    36,   170,   151,   152,    40,   153,
      65,   154,   155,    61,    61,    41,    66,    93,   133,   147,
     148,   110,   111,    61,    61,   112,    89,    94,    61,    43,
      44,    45,    46,    29,    61,    61,    95,     2,   164,    67,
       4,     5,     6,    47,    68,    69,    70,    98,    48,    99,
      49,   121,   117,   119,    92,   120,    43,    44,    45,    46,
      43,    44,    45,    46,   125,   139,    50,    51,   146,    71,
      47,   157,   149,   158,    72,    48,   169,    49,   159,    48,
     134,    49,   126,   127,   128,   129,   130,   131,   132,    18,
      42,    87,    39,    50,    51,   100,   101,    50,    51,   118,
     115,   122,   140,     0,   116,   142,   102,   103,   104,   105,
     106,   107,     1,   124,     2,     3,   143,     4,     5,     6,
       2,     0,    88,     4,     5,     6
};

static const yytype_int16 yycheck[] =
{
       0,    51,    32,    93,    59,    47,   161,    16,     8,     3,
       4,     5,     6,    16,   169,    41,     5,    32,    26,    13,
      70,    26,     0,    17,    18,    19,    20,    41,    22,     5,
      24,    45,    47,    42,     3,     4,     5,     6,    38,    42,
      48,    23,    24,    48,    59,    95,    40,    41,    17,    43,
      44,    43,    45,    22,    48,    24,    49,    99,   113,     7,
     150,     9,    10,    11,    12,   115,   160,   161,    47,     5,
     160,    40,    41,    48,    42,   169,   126,   127,     3,   129,
      45,   131,   132,    98,    99,     5,    26,    42,    88,   119,
     120,    21,    22,   108,   109,    25,    44,    46,   113,     3,
       4,     5,     6,    45,   119,   120,    41,     7,   158,    13,
      10,    11,    12,    17,    18,    19,    20,    16,    22,    15,
      24,    48,    46,    41,   124,    41,     3,     4,     5,     6,
       3,     4,     5,     6,    48,    42,    40,    41,     5,    43,
      17,    42,    48,    26,    48,    22,    14,    24,    46,    22,
      91,    24,    27,    28,    29,    30,    31,    32,    33,     8,
      30,    37,    28,    40,    41,    23,    24,    40,    41,    66,
      45,    48,    98,    -1,    49,   108,    34,    35,    36,    37,
      38,    39,     5,    71,     7,     8,   109,    10,    11,    12,
       7,    -1,     9,    10,    11,    12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,     8,    10,    11,    12,    52,    53,    54,
      55,    56,    62,    63,    64,    41,     5,     0,    54,     5,
      58,    59,    60,    62,    65,    66,    67,    43,    41,    45,
      26,    48,    47,     5,    68,    69,    42,    48,    74,    65,
       3,     5,    59,     3,     4,     5,     6,    17,    22,    24,
      40,    41,    84,    85,    86,    87,    89,    91,    93,    94,
      95,    96,    97,    98,   101,    45,    26,    13,    18,    19,
      20,    43,    48,    70,    71,    72,    73,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    96,    67,     9,    44,
      57,    61,    62,    42,    46,    41,    86,    83,    16,    15,
      23,    24,    34,    35,    36,    37,    38,    39,    88,    90,
      21,    22,    25,    92,    93,    45,    49,    46,    69,    41,
      41,    48,    48,    83,    74,    48,    27,    28,    29,    30,
      31,    32,    33,    62,    58,    70,    83,    99,   100,    42,
      85,    86,    89,    91,    93,    83,     5,    84,    84,    48,
      75,    83,    83,    83,    83,    83,    48,    42,    26,    46,
      42,    42,    44,    70,    83,    70,    71,    71,    72,    14,
      71,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    55,    56,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    74,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    80,    81,    81,    82,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    93,    93,    94,    94,    94,    95,    95,    96,    96,
      96,    97,    97,    97,    98,    99,    99,   100,   100,   101,
     101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     5,     3,
       3,     3,     1,     1,     3,     1,     4,     2,     1,     1,
       1,     1,     1,     1,     6,     5,     1,     0,     3,     1,
       2,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     2,     0,     2,     0,
       2,     1,     7,     7,     5,     5,     5,     2,     3,     2,
       3,     3,     3,     3,     3,     2,     2,     1,     3,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     3,     1,     1,     4,     1,     0,     3,     1,     1,
       1,     1
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
#line 111 "c-.y" /* yacc.c:1646  */
    {
						savedTree = (yyvsp[0].treeNode);
					}
#line 1432 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 117 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-1].treeNode);
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
						else
						{
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
					}
#line 1453 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 134 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1461 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 140 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1469 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 144 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1477 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1485 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "c-.y" /* yacc.c:1646  */
    {
						// We need to add the user-defined type to the global symbol table.
						globalScope.insert((yyvsp[-3].t).tokenStr, static_cast<char*>("recordType"));
						
						(yyval.treeNode) = NewDeclNode(VarK);
						(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
						(yyval.treeNode)->isRecord = true;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);						
					}
#line 1500 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 169 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-1].treeNode);
						if (t != NULL)
						{
							do
							{
								t->expType = (yyvsp[-2].expType);
								t = t->sibling;
							}
							while (t != NULL);
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
						else
						{
							(yyval.treeNode) = NULL;
						}
					}
#line 1522 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 189 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-1].treeNode);
						if (t != NULL)
						{
							do
							{
								t->expType = (yyvsp[-2].treeNode)->expType;
								t->isRecord = (yyvsp[-2].treeNode)->isRecord;
								t->isStatic = (yyvsp[-2].treeNode)->isStatic;
								t = t->sibling;
							}
							while (t != NULL);
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
						else
						{
							(yyval.treeNode) = NULL;
						}
					}
#line 1546 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 211 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-2].treeNode);
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-2].treeNode);
						}
						else
						{
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
					}
#line 1567 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 228 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1575 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 234 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1583 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 238 "c-.y" /* yacc.c:1646  */
    {
						(yyvsp[-2].treeNode)->children[0] = (yyvsp[0].treeNode);
						(yyval.treeNode) = (yyvsp[-2].treeNode);
					}
#line 1592 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 245 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(VarK);
						(yyval.treeNode)->lineNumber = (yyvsp[0].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
					}
#line 1602 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 251 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(VarK);
						(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
						(yyval.treeNode)->lineNumber = (yyvsp[-3].t).lineNum;
						(yyval.treeNode)->isArray = true;
						(yyval.treeNode)->arraySize = (yyvsp[-1].t).intVal;
					}
#line 1614 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 261 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(VarK);
						(yyval.treeNode)->isStatic = true;
						(yyval.treeNode)->expType = (yyvsp[0].expType);
						if ((yyvsp[0].expType) == Record)
						{
							(yyval.treeNode)->isRecord = true;
						}
					}
#line 1628 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 271 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(VarK);						
						(yyval.treeNode)->expType = (yyvsp[0].expType);
					}
#line 1637 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 278 "c-.y" /* yacc.c:1646  */
    {
						(yyval.expType) = (yyvsp[0].expType);
					}
#line 1645 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 282 "c-.y" /* yacc.c:1646  */
    {	
						(yyval.expType) = Record;
					}
#line 1653 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 288 "c-.y" /* yacc.c:1646  */
    {
						(yyval.expType) = Int;
					}
#line 1661 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 292 "c-.y" /* yacc.c:1646  */
    {
						(yyval.expType) = Bool;
					}
#line 1669 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 296 "c-.y" /* yacc.c:1646  */
    {
						(yyval.expType) = Char;
					}
#line 1677 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 304 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(FuncK);
						(yyval.treeNode)->expType = (yyvsp[-5].expType);
						(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						// Sets the line number where the function declaration starts.
						(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum; 
					}
#line 1691 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 314 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(FuncK);
						(yyval.treeNode)->expType = Void;
						(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						// Sets the line number where the function call starts.
						(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
					}
#line 1705 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 326 "c-.y" /* yacc.c:1646  */
    { 
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1713 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 329 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 1721 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 335 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-2].treeNode);
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-2].treeNode);
						}
						else
						{
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
					}
#line 1742 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 352 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1750 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 358 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[0].treeNode);
						if (t != NULL)
						{
							do
							{
								t->expType = (yyvsp[-1].expType);
								t = t->sibling;
							}
							while (t != NULL);
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
						else
						{
							(yyval.treeNode) = NULL;
						}
					}
#line 1772 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 378 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-2].treeNode);
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							
							t->sibling = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-2].treeNode);
						}
						else
						{
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
					}
#line 1794 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 396 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1802 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 402 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(ParamK);
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
					}
#line 1811 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 407 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(ParamK);
						(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
						(yyval.treeNode)->isArray = true;
					}
#line 1821 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 417 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1829 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 421 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1837 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 427 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1845 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 431 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1853 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 435 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1861 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 439 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1869 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 443 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1877 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 447 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1885 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 453 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1893 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 457 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 1901 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 463 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(CompK);
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[-1].treeNode);
						(yyval.treeNode)->lineNumber = (yyvsp[-3].t).lineNum;
					}
#line 1912 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 472 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-1].treeNode);
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
						else
						{
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
					}
#line 1933 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 488 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 1941 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 494 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-1].treeNode);
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
						else
						{
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
					}
#line 1962 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 510 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 1970 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 516 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[-1].treeNode);
					}
#line 1978 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 520 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 1986 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 526 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(IfK);
						(yyval.treeNode)->attr.name = (yyvsp[-6].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-4].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[2] = (yyvsp[0].treeNode);
						(yyval.treeNode)->lineNumber = (yyvsp[-6].t).lineNum;
					}
#line 1999 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 537 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(IfK);
						(yyval.treeNode)->attr.name = (yyvsp[-6].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-4].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[2] = (yyvsp[0].treeNode);
						(yyval.treeNode)->lineNumber = (yyvsp[-6].t).lineNum;
					}
#line 2012 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 547 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(IfK);
						(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
					}
#line 2024 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 557 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(WhileK);
						(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
					}
#line 2036 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 567 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(WhileK);
						(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
					}
#line 2048 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 577 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(ReturnK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
					}
#line 2058 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 583 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(ReturnK);
						(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
						(yyval.treeNode)->lineNumber = (yyvsp[-2].t).lineNum;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
					}
#line 2069 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 592 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewStmtNode(BreakK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
					}
#line 2078 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 601 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2089 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 608 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2100 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 615 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2111 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 622 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2122 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 629 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2133 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 636 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
					}
#line 2143 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 642 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
					}
#line 2153 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 648 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2161 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 654 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2173 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 662 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2181 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 668 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2193 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 676 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2201 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 682 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->isConst = (yyvsp[0].treeNode)->isConst;
						(yyval.treeNode)->children[0] = (yyvsp[0].treeNode);
					}
#line 2212 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 689 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2220 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 695 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2232 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 703 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2240 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 709 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2248 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 713 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2256 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 717 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2264 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 721 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2272 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 725 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2280 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 729 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2288 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 735 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2300 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 743 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2308 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 749 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2316 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 753 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2324 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 759 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
					}
#line 2336 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 767 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2344 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 773 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2352 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 777 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2360 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 781 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2368 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 787 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[0].treeNode);
						(yyval.treeNode)->isConst = (yyvsp[-1].t).isConst && (yyvsp[0].treeNode)->isConst;
					}
#line 2379 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 794 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2387 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 800 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
						(yyval.t).isConst = true;
					}
#line 2396 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 805 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2404 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 809 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2412 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 815 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2420 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 819 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2428 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 825 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(IdK);
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
					}
#line 2437 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 830 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
						
						(yyval.treeNode)->children[0] = (yyvsp[-3].treeNode);						
						(yyval.treeNode)->children[1] = (yyvsp[-1].treeNode);
					}
#line 2449 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 838 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						
						TreeNode* t = NewExprNode(IdK);
						t->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[1] = t;
					}
#line 2463 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 850 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[-1].treeNode);
					}
#line 2471 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 854 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2479 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 858 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2487 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 864 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(CallK);
						(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
					}
#line 2497 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 872 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2505 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 875 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2513 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 880 "c-.y" /* yacc.c:1646  */
    {
						TreeNode* t = (yyvsp[-2].treeNode);
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-2].treeNode);
						}
						else
						{
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
					}
#line 2534 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 897 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2542 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 903 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(ConstK);
						(yyval.treeNode)->isConst = true;
						(yyval.treeNode)->attr.value = (yyvsp[0].t).intVal;
						(yyval.treeNode)->expType = Int;
					}
#line 2553 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 910 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(ConstK);
						(yyval.treeNode)->isConst = true;
						(yyval.treeNode)->attr.cValue = (yyvsp[0].t).charVal;
						(yyval.treeNode)->expType = Char;
					}
#line 2564 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 917 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(ConstK);
						(yyval.treeNode)->isConst = true;
						(yyval.treeNode)->attr.value = (yyvsp[0].t).intVal;
						(yyval.treeNode)->expType = Bool;
					}
#line 2575 "c-.tab.c" /* yacc.c:1646  */
    break;


#line 2579 "c-.tab.c" /* yacc.c:1646  */
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
#line 925 "c-.y" /* yacc.c:1906  */


int main(int argc, char** argv)
{
	int arg;
	bool argFound;
	
	bool printAbstractSyntaxTree = false;
	bool printAnnotatedSyntaxTree = false;	
	
	while ((arg = getopt(argc, argv, "dpP0")) != EOF)
	{
		switch (arg)
		{			
			case 'd':
				argFound = true;
				yydebug = 1;
				break;
			case 'p':
				argFound = true;
				printAbstractSyntaxTree = true;
				break;
			case 'P':
				argFound = true;
				printAnnotatedSyntaxTree = true;
				break;				
			case '0': // Case '0' does nothing.
				break;
			default:
				printf("Invalid argument: %c", arg);
				return -1;
		}
	}	
	
	if (argc >= 2)
	{
		FILE* inputFile = fopen(argv[argc - 1], "r");
		
		if (inputFile)
		{
			yyin = inputFile;
		}
	}	
	
	do 
	{
		yyparse();
	} 
	while (!feof(yyin));	
		
	if (printAbstractSyntaxTree)
	{		
		PrintSyntaxTree(savedTree, -1, false);
	}	
	
	int numOfErrors = 0;
	int numOfWarnings = 0;	
	
	AttachIOLib(savedTree);
	SemanticAnalysis(savedTree, numOfErrors, numOfWarnings);
	
	if (printAnnotatedSyntaxTree)
	{
		PrintSyntaxTree(savedTree, -1, true);
	}
		
	printf("Number of warnings: %d\n", numOfWarnings);
	printf("Number of errors: %d\n", numOfErrors);
	
	return 0;
}
