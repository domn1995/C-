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
#include "YyError.h"

extern int yylex();
extern char* yytext;
extern int yylineno;
extern FILE* yyin;
int numErrors = 0, numWarnings = 0;

Scope globalScope("global");

static TreeNode* savedTree;
static char* savedName;
static int savedLineNum;

extern int globalOffset;

#define YYERROR_VERBOSE
extern void yyerror(const char* msg);

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   776

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253

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
       0,   110,   110,   116,   133,   139,   143,   147,   151,   159,
     172,   191,   195,   200,   207,   228,   233,   239,   257,   261,
     265,   271,   275,   280,   285,   291,   297,   305,   309,   316,
     326,   333,   337,   343,   347,   351,   359,   369,   379,   383,
     387,   391,   395,   401,   405,   410,   428,   432,   437,   443,
     461,   467,   486,   490,   494,   500,   505,   511,   520,   524,
     530,   534,   538,   542,   546,   550,   556,   560,   566,   574,
     579,   586,   603,   608,   625,   630,   635,   642,   651,   655,
     660,   666,   676,   684,   688,   693,   700,   708,   713,   718,
     722,   728,   736,   741,   748,   755,   765,   775,   783,   791,
     799,   807,   815,   823,   831,   835,   839,   843,   847,   851,
     855,   860,   867,   876,   880,   885,   889,   895,   904,   908,
     913,   917,   923,   930,   936,   945,   949,   953,   958,   964,
     968,   972,   976,   980,   984,   990,   999,  1003,  1008,  1013,
    1019,  1023,  1029,  1038,  1044,  1048,  1052,  1058,  1066,  1072,
    1077,  1081,  1087,  1091,  1097,  1102,  1110,  1122,  1127,  1131,
    1135,  1139,  1146,  1154,  1160,  1164,  1168,  1186,  1190,  1196,
    1203,  1210
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
  "simpleExpression", "andExpression", "unaryRelExpression",
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

#define YYPACT_NINF -207

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-207)))

#define YYTABLE_NINF -166

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     249,    16,   -16,  -207,    53,  -207,  -207,  -207,    67,   692,
    -207,  -207,  -207,    86,  -207,  -207,   165,    52,  -207,   -12,
    -207,    65,   109,    72,  -207,  -207,    23,    73,    -7,  -207,
     379,   102,   135,  -207,   405,    40,   138,    75,    76,  -207,
    -207,  -207,   137,  -207,   672,  -207,  -207,    85,  -207,   411,
    -207,  -207,  -207,   420,   118,   130,  -207,  -207,   252,    64,
    -207,   564,  -207,   101,  -207,  -207,  -207,  -207,   107,   165,
    -207,   672,   118,    -4,   120,   152,  -207,   293,   217,    36,
      40,   153,   452,   461,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,   571,   593,   315,   734,  -207,   644,
     155,   118,   698,   467,   493,   615,   621,  -207,  -207,  -207,
     564,   142,  -207,   508,   200,  -207,  -207,   167,   302,   644,
      11,    14,   172,   347,    89,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,   183,  -207,  -207,
    -207,   170,  -207,  -207,   322,  -207,   325,   734,  -207,   725,
     130,   202,   199,   142,    64,   644,  -207,   194,   213,   251,
     254,  -207,   257,  -207,   262,   267,  -207,   508,   508,  -207,
     508,  -207,   508,   508,   725,   130,   734,  -207,   202,   199,
     142,    64,  -207,   225,  -207,  -207,   236,  -207,   242,   518,
     250,   540,  -207,  -207,   245,  -207,   197,  -207,  -207,    -8,
       8,   644,  -207,  -207,   549,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,   357,   672,    15,   357,
     700,    17,  -207,   229,   256,   261,  -207,   644,  -207,   644,
    -207,   281,   357,  -207,  -207,   151,   357,  -207,  -207,  -207,
    -207,   357,  -207,   294,  -207,  -207,  -207,  -207,  -207,  -207,
     357,  -207,  -207
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    32,     0,    33,    35,    34,     0,     0,
       4,     7,     5,     0,    31,     6,    20,    25,    13,     0,
      18,    21,     0,     0,     1,     3,    38,    25,     0,    28,
       0,     0,     0,    11,     0,    41,     0,     0,    43,    46,
      72,    12,     0,    10,     0,   169,   171,   154,   170,     0,
     150,   149,   151,     0,    23,   113,   118,   123,   125,   136,
     143,     0,   148,   153,   152,   158,   159,    27,     0,    19,
      17,    24,    22,    50,    55,    49,    52,     0,     0,     0,
      39,     0,     0,     0,   140,   141,   130,   129,   133,   134,
     131,   132,   163,   161,     0,     0,     0,     0,   122,   160,
       0,   104,   153,     0,     0,     0,     0,   145,   144,   146,
       0,     0,   147,     0,     0,    26,    57,     0,     0,    42,
       0,     0,     0,     0,     0,    76,    37,    58,    59,    63,
      62,    60,    66,    61,    67,    64,    65,     0,    47,    45,
      15,     0,     9,    71,     0,    30,     0,   121,   119,   116,
     114,   128,   127,   139,   138,     0,   167,     0,   164,     0,
       0,   110,     0,   111,     0,     0,   157,     0,     0,   102,
       0,   103,     0,     0,   115,   112,   120,   117,   126,   124,
     137,   135,   142,     0,   156,    56,    53,    51,    83,     0,
      89,     0,    96,    94,     0,    74,     0,    75,    29,    16,
       0,    40,    36,   162,     0,   105,   108,   106,   107,   109,
      97,   100,    98,    99,   101,   155,     0,    78,     0,     0,
       0,     0,    95,     0,    15,     0,    14,   168,   166,    80,
      84,    58,     0,    87,    92,     0,     0,    69,    73,    70,
      68,     0,    82,    58,    88,    93,    86,    91,    79,    85,
       0,    77,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,   305,  -207,  -207,  -207,    -9,   290,  -207,
    -207,     0,  -207,  -207,   282,  -207,   247,  -207,   222,   -74,
     416,  -206,  -207,   211,   150,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,   -45,   -28,   -20,   -42,  -207,   296,   -44,   -48,
     -22,  -207,   -50,  -207,  -207,   -29,  -207,  -207,  -207,  -207,
    -207
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,   143,    19,    20,    21,
     144,    36,    14,    15,    37,    38,    39,    75,    76,   238,
     127,   128,   129,    79,   223,   130,   131,   132,   133,   134,
     135,   136,   137,   101,    55,    56,    57,    94,    58,    95,
      59,   110,    60,    61,    62,   102,    64,    65,   157,   158,
      66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    63,    54,   126,    28,    63,    72,    98,   100,    13,
     106,   112,   188,   234,    32,   190,    -8,    16,   -20,    32,
      63,    17,   -54,    -8,    -8,    22,    -8,    -8,    -8,   245,
     247,   103,    63,   103,    32,   249,    33,   140,    29,    30,
     148,    43,   116,     3,   252,   141,     5,     6,     7,   -20,
     152,   156,   189,    63,    63,   191,   226,   232,    23,   236,
     182,   179,   177,   150,    18,    63,    63,    24,   183,    29,
      30,    41,   202,   154,    63,    63,    63,    63,   194,   145,
     142,    63,   -48,   175,   181,   107,   108,    26,   -48,   109,
     195,    27,   -72,   -72,   -72,   -72,   -72,    31,   -72,   -72,
     -72,   -72,   -72,    67,   106,    68,   -72,   -72,   -72,   -72,
      35,   -72,    34,   -72,    42,    40,     3,    77,    31,     5,
       6,     7,   210,   211,    78,   212,    96,   213,   214,   -72,
     -72,   106,   -72,   -72,   103,   200,    69,   -72,    80,    73,
      17,   198,   230,    74,     3,   104,   113,     5,     6,     7,
     114,   -44,   229,   115,    45,    46,    47,    48,   242,   228,
      63,   218,    63,   221,   120,   117,  -161,  -161,    49,   121,
     122,   123,  -161,    50,  -161,    51,  -161,     3,   118,   -44,
       5,     6,     7,    92,    93,  -161,  -161,  -161,  -161,  -161,
    -161,    52,    53,  -161,   124,   146,   145,   166,   224,   125,
     -74,   -74,   -74,   -74,     3,   184,   141,     5,     6,     7,
     -74,    29,    30,   185,   -74,   -74,   -74,   -74,   138,   -74,
     192,   -74,    84,    85,     3,    84,    85,     5,     6,     7,
     229,   197,    45,    46,    47,    48,   203,   -74,   -74,   204,
     -74,   -74,   120,    92,    93,   -74,    49,   121,   122,   123,
       1,    50,   205,    51,     2,   206,     3,     4,   207,     5,
       6,     7,   229,   208,    45,    46,    47,    48,   209,    52,
      53,   215,   124,   237,   120,    84,    85,   125,    49,   121,
     122,   123,   116,    50,   216,    51,    86,    87,    88,    89,
      90,    91,   219,   222,   119,   241,    45,    46,    47,    48,
     239,    52,    53,   186,   124,   240,   120,    74,   250,   125,
      49,   121,   122,   123,    25,    50,   155,    51,    45,    46,
      47,    48,    70,   199,    81,   139,   201,    17,    45,    46,
      47,    48,    49,    52,    53,   196,   124,    50,   120,    51,
     187,   125,    49,   121,   122,   123,   225,    50,   155,    51,
      45,    46,    47,    48,   105,    52,    53,  -165,   229,     0,
      45,    46,    47,    48,    49,    52,    53,     0,   124,    50,
     120,    51,     0,   125,    49,   121,   122,   123,     0,    50,
      44,    51,    45,    46,    47,    48,     0,    52,    53,     0,
       0,     0,     0,     0,     0,   193,    49,    52,    53,     0,
     124,    50,     0,    51,     0,   125,    71,     0,    45,    46,
      47,    48,    97,     0,    45,    46,    47,    48,     0,    52,
      53,    99,    49,    45,    46,    47,    48,    50,    49,    51,
       0,     0,     0,    50,     0,    51,     0,    49,     0,     0,
       0,     0,    50,     0,    51,    52,    53,     0,     0,     0,
       0,    52,    53,   147,     0,    45,    46,    47,    48,     0,
      52,    53,   149,     0,    45,    46,    47,    48,   174,    49,
      45,    46,    47,    48,    50,     0,    51,     0,    49,     0,
       0,     0,     0,    50,    49,    51,     0,     0,     0,    50,
       0,    51,    52,    53,   176,     0,    45,    46,    47,    48,
       0,    52,    53,     0,     0,     0,     0,    52,    53,   155,
      49,    45,    46,    47,    48,    50,     0,    51,     0,   217,
       0,    45,    46,    47,    48,    49,     0,     0,     0,     0,
      50,     0,    51,    52,    53,    49,     0,     0,     0,     0,
      50,   220,    51,    45,    46,    47,    48,     0,    52,    53,
     227,     0,    45,    46,    47,    48,     0,    49,    52,    53,
       0,     0,    50,     0,    51,   111,    49,    45,    46,    47,
      48,    50,   151,    51,    45,    46,    47,    48,     0,     0,
      52,    53,     0,     0,     0,     0,    50,     0,    51,    52,
      53,     0,     0,    50,   153,    51,    45,    46,    47,    48,
       0,     0,     0,     0,    52,    53,     0,     0,     0,     0,
       0,    52,    53,     0,     0,    50,   178,    51,    45,    46,
      47,    48,   180,     0,    45,    46,    47,    48,     0,     0,
       0,     0,   231,    52,    53,   233,     0,    50,     0,    51,
       0,     0,     0,    50,     0,    51,     0,     0,   243,     0,
       0,   244,   246,     0,     0,    52,    53,   248,     0,    82,
      83,    52,    53,     0,     0,     0,   251,    84,    85,     0,
       0,   159,   160,   161,   162,   163,   164,   165,    86,    87,
      88,    89,    90,    91,     0,    92,    93,    82,    83,     0,
       0,     0,    -2,     1,     0,    84,    85,     2,     0,     3,
       4,     0,     5,     6,     7,     0,    86,    87,    88,    89,
      90,    91,     0,    92,    93,    82,    83,     0,     0,     0,
       0,     0,     0,    84,    85,   167,   168,   169,   170,   171,
     172,   173,     0,     0,    86,    87,    88,    89,    90,    91,
      82,    92,   235,   113,     0,     0,     0,   114,    84,    85,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,    93,    86,    87,
      88,    89,    90,    91,     0,    92,    93
};

static const yytype_int16 yycheck[] =
{
       0,    30,    30,    77,    13,    34,    34,    49,    53,     9,
      58,    61,     1,   219,    26,     1,     0,     1,    26,    26,
      49,     5,    26,     7,     8,    41,    10,    11,    12,   235,
     236,    16,    61,    16,    26,   241,    48,     1,    46,    47,
      82,    48,    46,     7,   250,     9,    10,    11,    12,    26,
      94,    96,    41,    82,    83,    41,    48,    42,     5,    42,
     110,   105,   104,    83,    48,    94,    95,     0,   113,    46,
      47,    48,   146,    95,   103,   104,   105,   106,   123,    79,
      44,   110,    42,   103,   106,    21,    22,     1,    48,    25,
       1,     5,     3,     4,     5,     6,     7,    45,     9,    10,
      11,    12,    13,     1,   152,     3,    17,    18,    19,    20,
       1,    22,    47,    24,    41,    43,     7,    42,    45,    10,
      11,    12,   167,   168,    48,   170,    41,   172,   173,    40,
      41,   179,    43,    44,    16,   144,     1,    48,     1,     1,
       5,   141,   216,     5,     7,    15,    45,    10,    11,    12,
      49,    42,     1,    46,     3,     4,     5,     6,   232,   204,
     189,   189,   191,   191,    13,    45,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     7,    26,    42,
      10,    11,    12,    41,    42,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    42,   196,    42,     1,    48,
       3,     4,     5,     6,     7,     5,     9,    10,    11,    12,
      13,    46,    47,    46,    17,    18,    19,    20,     1,    22,
      48,    24,    23,    24,     7,    23,    24,    10,    11,    12,
       1,    48,     3,     4,     5,     6,    42,    40,    41,    26,
      43,    44,    13,    41,    42,    48,    17,    18,    19,    20,
       1,    22,     1,    24,     5,     1,     7,     8,     1,    10,
      11,    12,     1,     1,     3,     4,     5,     6,     1,    40,
      41,    46,    43,    44,    13,    23,    24,    48,    17,    18,
      19,    20,    46,    22,    42,    24,    34,    35,    36,    37,
      38,    39,    42,    48,     1,    14,     3,     4,     5,     6,
      44,    40,    41,     1,    43,    44,    13,     5,    14,    48,
      17,    18,    19,    20,     9,    22,     1,    24,     3,     4,
       5,     6,    32,     1,    42,    78,     1,     5,     3,     4,
       5,     6,    17,    40,    41,   124,    43,    22,    13,    24,
     118,    48,    17,    18,    19,    20,   196,    22,     1,    24,
       3,     4,     5,     6,    58,    40,    41,    42,     1,    -1,
       3,     4,     5,     6,    17,    40,    41,    -1,    43,    22,
      13,    24,    -1,    48,    17,    18,    19,    20,    -1,    22,
       1,    24,     3,     4,     5,     6,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    17,    40,    41,    -1,
      43,    22,    -1,    24,    -1,    48,     1,    -1,     3,     4,
       5,     6,     1,    -1,     3,     4,     5,     6,    -1,    40,
      41,     1,    17,     3,     4,     5,     6,    22,    17,    24,
      -1,    -1,    -1,    22,    -1,    24,    -1,    17,    -1,    -1,
      -1,    -1,    22,    -1,    24,    40,    41,    -1,    -1,    -1,
      -1,    40,    41,     1,    -1,     3,     4,     5,     6,    -1,
      40,    41,     1,    -1,     3,     4,     5,     6,     1,    17,
       3,     4,     5,     6,    22,    -1,    24,    -1,    17,    -1,
      -1,    -1,    -1,    22,    17,    24,    -1,    -1,    -1,    22,
      -1,    24,    40,    41,     1,    -1,     3,     4,     5,     6,
      -1,    40,    41,    -1,    -1,    -1,    -1,    40,    41,     1,
      17,     3,     4,     5,     6,    22,    -1,    24,    -1,     1,
      -1,     3,     4,     5,     6,    17,    -1,    -1,    -1,    -1,
      22,    -1,    24,    40,    41,    17,    -1,    -1,    -1,    -1,
      22,     1,    24,     3,     4,     5,     6,    -1,    40,    41,
       1,    -1,     3,     4,     5,     6,    -1,    17,    40,    41,
      -1,    -1,    22,    -1,    24,     1,    17,     3,     4,     5,
       6,    22,     1,    24,     3,     4,     5,     6,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    22,    -1,    24,    40,
      41,    -1,    -1,    22,     1,    24,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    22,     1,    24,     3,     4,
       5,     6,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,   216,    40,    41,   219,    -1,    22,    -1,    24,
      -1,    -1,    -1,    22,    -1,    24,    -1,    -1,   232,    -1,
      -1,   235,   236,    -1,    -1,    40,    41,   241,    -1,    15,
      16,    40,    41,    -1,    -1,    -1,   250,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    15,    16,    -1,
      -1,    -1,     0,     1,    -1,    23,    24,     5,    -1,     7,
       8,    -1,    10,    11,    12,    -1,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    34,    35,    36,    37,    38,    39,
      15,    41,    42,    45,    -1,    -1,    -1,    49,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    34,    35,
      36,    37,    38,    39,    -1,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,     7,     8,    10,    11,    12,    52,    53,
      54,    55,    56,    62,    63,    64,     1,     5,    48,    58,
      59,    60,    41,     5,     0,    54,     1,     5,    58,    46,
      47,    45,    26,    48,    47,     1,    62,    65,    66,    67,
      43,    48,    41,    48,     1,     3,     4,     5,     6,    17,
      22,    24,    40,    41,    84,    85,    86,    87,    89,    91,
      93,    94,    95,    96,    97,    98,   101,     1,     3,     1,
      59,     1,    84,     1,     5,    68,    69,    42,    48,    74,
       1,    65,    15,    16,    23,    24,    34,    35,    36,    37,
      38,    39,    41,    42,    88,    90,    41,     1,    86,     1,
      83,    84,    96,    16,    15,    88,    90,    21,    22,    25,
      92,     1,    93,    45,    49,    46,    46,    45,    26,     1,
      13,    18,    19,    20,    43,    48,    70,    71,    72,    73,
      76,    77,    78,    79,    80,    81,    82,    83,     1,    67,
       1,     9,    44,    57,    61,    62,    42,     1,    86,     1,
      85,     1,    89,     1,    91,     1,    83,    99,   100,    27,
      28,    29,    30,    31,    32,    33,    42,    27,    28,    29,
      30,    31,    32,    33,     1,    85,     1,    86,     1,    89,
       1,    91,    93,    83,     5,    46,     1,    69,     1,    41,
       1,    41,    48,    48,    83,     1,    74,    48,    62,     1,
      58,     1,    70,    42,    26,     1,     1,     1,     1,     1,
      83,    83,    83,    83,    83,    46,    42,     1,    84,    42,
       1,    84,    48,    75,     1,    75,    48,     1,    83,     1,
      70,    71,    42,    71,    72,    42,    42,    44,    70,    44,
      44,    14,    70,    71,    71,    72,    71,    72,    71,    72,
      14,    71,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    55,
      56,    56,    56,    56,    57,    57,    57,    58,    58,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    68,    68,    68,    68,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    80,    80,    80,    81,    81,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    87,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    93,    93,    94,
      94,    94,    95,    95,    96,    96,    96,    97,    97,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   100,   101,
     101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     2,     3,     1,     2,     3,     1,     3,
       1,     1,     3,     3,     3,     1,     4,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     6,     5,     2,     4,
       6,     3,     5,     1,     0,     3,     1,     3,     1,     2,
       2,     3,     1,     3,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     2,     0,     2,     0,     2,     1,     7,     3,     6,
       1,     7,     5,     2,     4,     6,     5,     4,     5,     2,
       1,     5,     4,     5,     2,     3,     2,     3,     3,     3,
       3,     3,     2,     2,     1,     3,     3,     3,     3,     3,
       2,     2,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     2,     1,     3,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     3,     3,
       1,     1,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     1,     1,
       2,     2,     4,     2,     1,     0,     3,     1,     3,     1,
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
#line 1590 "c-.tab.c" /* yacc.c:1646  */
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
#line 1611 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 134 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1619 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 140 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1627 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 144 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1635 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1643 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 152 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1651 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "c-.y" /* yacc.c:1646  */
    {
							// We need to add the user-defined type to the global symbol table.
							globalScope.insert((yyvsp[-3].t).tokenStr, static_cast<char*>("recordType"));
						
							(yyval.treeNode) = NewDeclNode(VarK);
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
							(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
							(yyval.treeNode)->isRecord = true;
							(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);						
						}
#line 1666 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 173 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
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
#line 1689 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 192 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1697 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 196 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1706 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 201 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1715 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 208 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
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
#line 1740 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 229 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1749 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 234 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1757 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 240 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
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
#line 1779 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 258 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1787 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 262 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1795 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 266 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1803 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 272 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1811 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 276 "c-.y" /* yacc.c:1646  */
    {
							(yyvsp[-2].treeNode)->children[0] = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-2].treeNode);
						}
#line 1820 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 281 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1829 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 286 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1837 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 292 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(VarK);
							(yyval.treeNode)->lineNumber = (yyvsp[0].t).lineNum;
							(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
						}
#line 1847 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 298 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(VarK);
							(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-3].t).lineNum;
							(yyval.treeNode)->isArray = true;
							(yyval.treeNode)->arrayLength = (yyvsp[-1].t).intVal;
						}
#line 1859 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 306 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1867 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 310 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1876 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 317 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(VarK);
							(yyval.treeNode)->isStatic = true;
							(yyval.treeNode)->expType = (yyvsp[0].expType);
							if ((yyvsp[0].expType) == Record)
							{
								(yyval.treeNode)->isRecord = true;
							}
						}
#line 1890 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 327 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(VarK);						
							(yyval.treeNode)->expType = (yyvsp[0].expType);
						}
#line 1899 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 334 "c-.y" /* yacc.c:1646  */
    {
							(yyval.expType) = (yyvsp[0].expType);
						}
#line 1907 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 338 "c-.y" /* yacc.c:1646  */
    {	
							(yyval.expType) = Record;
						}
#line 1915 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 344 "c-.y" /* yacc.c:1646  */
    {
							(yyval.expType) = Int;
						}
#line 1923 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 348 "c-.y" /* yacc.c:1646  */
    {
							(yyval.expType) = Bool;
						}
#line 1931 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 352 "c-.y" /* yacc.c:1646  */
    {
							(yyval.expType) = Char;
						}
#line 1939 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 360 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(FuncK);
							(yyval.treeNode)->expType = (yyvsp[-5].expType);
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							// Sets the line number where the function declaration starts.
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum; 
						}
#line 1953 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 370 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(FuncK);
							(yyval.treeNode)->expType = Void;
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							// Sets the line number where the function call starts.
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						}
#line 1967 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 380 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1975 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 384 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1983 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 388 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1991 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 392 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1999 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2007 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 402 "c-.y" /* yacc.c:1646  */
    { 
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2015 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 405 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2023 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 411 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
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
#line 2045 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 429 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2053 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 433 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2062 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 438 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2070 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 444 "c-.y" /* yacc.c:1646  */
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
#line 2092 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 462 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2100 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 468 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
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
#line 2123 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 487 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2131 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 491 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2139 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 495 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2147 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 501 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(ParamK);
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
					}
#line 2156 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 506 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(ParamK);
						(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
						(yyval.treeNode)->isArray = true;
					}
#line 2166 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 512 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NULL;
					}
#line 2175 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 521 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2183 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 525 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2191 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 531 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2199 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 535 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2207 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 539 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2215 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 543 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2223 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 547 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2231 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 551 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2239 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 557 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2247 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 561 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2255 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 567 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewStmtNode(CompK);
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[-1].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-3].t).lineNum;
						}
#line 2267 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 575 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2276 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 580 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2285 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 587 "c-.y" /* yacc.c:1646  */
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
#line 2306 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 603 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2314 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 609 "c-.y" /* yacc.c:1646  */
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
#line 2335 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 625 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2343 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 631 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
#line 2352 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 636 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2361 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 643 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(IfK);
							(yyval.treeNode)->attr.name = (yyvsp[-6].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-4].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[2] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-6].t).lineNum;
						}
#line 2374 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 652 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2382 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 656 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2391 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 661 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2399 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 667 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(IfK);
							(yyval.treeNode)->attr.name = (yyvsp[-6].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-4].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[2] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-6].t).lineNum;
						}
#line 2412 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 677 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(IfK);
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						}
#line 2424 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 685 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2432 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 689 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2441 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 694 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2450 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 701 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(WhileK);
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						}
#line 2462 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 709 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2471 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 714 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2480 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 719 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2488 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 723 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2496 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 729 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(WhileK);
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						}
#line 2508 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 737 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2517 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 742 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2526 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 749 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewStmtNode(ReturnK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						}
#line 2537 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 756 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewStmtNode(ReturnK);
							(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-2].t).lineNum;
							(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
						}
#line 2549 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 766 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewStmtNode(BreakK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						}
#line 2559 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 776 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2571 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 784 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2583 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 792 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2595 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 800 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2607 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 808 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2619 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 816 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[0].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
					}
#line 2631 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 824 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[0].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
					}
#line 2643 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 832 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2651 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 836 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2659 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 840 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2667 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 844 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2675 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 848 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2683 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 852 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2691 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 856 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NULL;
					}
#line 2700 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 861 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NULL;
					}
#line 2709 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 868 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
							(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						}
#line 2722 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 877 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2730 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 881 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2739 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 886 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2747 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 890 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2755 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 896 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						}
#line 2768 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 905 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2776 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 909 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2785 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 914 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2793 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 918 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2801 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 924 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->isConst = (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[0].treeNode);
						}
#line 2812 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 931 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2820 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 937 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
							(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						}
#line 2833 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 946 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2841 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 950 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2849 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 954 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2858 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 959 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2866 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 965 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2874 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 969 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2882 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 973 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2890 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 977 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2898 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 981 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2906 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 985 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2914 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 991 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
							(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						}
#line 2927 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1000 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2935 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1004 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2944 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1009 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2953 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1014 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2961 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1020 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2969 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1024 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2977 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1030 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
					}
#line 2990 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1039 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2998 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1045 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 3006 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1049 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 3014 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1053 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 3022 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1059 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->children[0] = (yyvsp[0].treeNode);
						(yyval.treeNode)->isConst = (yyvsp[-1].t).isConst && (yyvsp[0].treeNode)->isConst;
					}
#line 3034 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1067 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 3042 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1073 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
						(yyval.t).isConst = true;
					}
#line 3051 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1078 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 3059 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1082 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 3067 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1088 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 3075 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1092 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 3083 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1098 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(IdK);
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
					}
#line 3092 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1103 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
						
						(yyval.treeNode)->children[0] = (yyvsp[-3].treeNode);						
						(yyval.treeNode)->children[1] = (yyvsp[-1].treeNode);
					}
#line 3104 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1111 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						
						TreeNode* t = NewExprNode(IdK);
						t->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[1] = t;
					}
#line 3118 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1123 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
#line 3127 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1128 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 3135 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1132 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 3143 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1136 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 3151 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1140 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 3160 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1147 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewExprNode(CallK);
							(yyval.treeNode)->lineNumber = (yyvsp[-3].t).lineNum;
							(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
						}
#line 3172 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1155 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 3180 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1161 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 3188 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1164 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 3196 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1169 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
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
#line 3218 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1187 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 3226 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1191 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 3234 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1197 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(ConstK);
							(yyval.treeNode)->isConst = true;
							(yyval.treeNode)->attr.value = (yyvsp[0].t).intVal;
							(yyval.treeNode)->expType = Int;
						}
#line 3245 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1204 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(ConstK);
							(yyval.treeNode)->isConst = true;
							(yyval.treeNode)->attr.cValue = (yyvsp[0].t).charVal;
							(yyval.treeNode)->expType = Char;
						}
#line 3256 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1211 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(ConstK);
							(yyval.treeNode)->isConst = true;
							(yyval.treeNode)->attr.value = (yyvsp[0].t).intVal;
							(yyval.treeNode)->expType = Bool;
						}
#line 3267 "c-.tab.c" /* yacc.c:1646  */
    break;


#line 3271 "c-.tab.c" /* yacc.c:1646  */
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
#line 1219 "c-.y" /* yacc.c:1906  */


int main(int argc, char** argv)
{
	int arg;
	bool argFound;
	
	bool printAbstractSyntaxTree = false;
	bool printAnnotatedSyntaxTree = false;	

	InitErrorProcessing();
	
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
		
	if (printAbstractSyntaxTree && numErrors == 0)
	{		
		PrintSyntaxTree(savedTree, -1, false);
	}
	

	if (numErrors == 0)
	{
		AttachIOLib(savedTree);
		SemanticAnalysis(savedTree, numErrors, numWarnings);
	
		if (printAnnotatedSyntaxTree)
		{
			PrintSyntaxTree(savedTree, -1, true);
		}
	}
	
	printf("Offset for end of global space: %d\n", globalOffset);
	printf("Number of warnings: %d\n", numWarnings);
	printf("Number of errors: %d\n", numErrors);
	
	return 0;
}
