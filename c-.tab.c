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
extern int numErrors, numWarnings;

Scope globalScope("global");

static TreeNode* savedTree;
static char* savedName;
static int savedLineNum;

#define YYERROR_VERBOSE
extern void yyerror(const char* msg);

#line 92 "c-.tab.c" /* yacc.c:339  */

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
#line 28 "c-.y" /* yacc.c:355  */

    Token t;
    TreeNode* treeNode;
    ExpType expType;

#line 189 "c-.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "c-.tab.c" /* yacc.c:358  */

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   587

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

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
       0,   108,   108,   114,   131,   137,   141,   145,   149,   157,
     170,   189,   193,   200,   223,   241,   245,   249,   255,   259,
     264,   269,   275,   281,   289,   293,   300,   310,   317,   321,
     327,   331,   335,   343,   353,   363,   367,   371,   375,   379,
     385,   389,   394,   412,   416,   421,   427,   445,   451,   470,
     474,   478,   484,   489,   495,   504,   508,   514,   518,   522,
     526,   530,   534,   540,   544,   550,   558,   563,   570,   587,
     592,   609,   614,   619,   626,   635,   639,   644,   650,   660,
     668,   672,   677,   684,   692,   697,   702,   706,   712,   720,
     725,   732,   739,   749,   759,   767,   775,   783,   791,   799,
     807,   815,   819,   823,   827,   831,   835,   839,   844,   851,
     859,   865,   873,   879,   886,   892,   900,   904,   908,   915,
     919,   923,   927,   931,   935,   941,   950,   954,   961,   965,
     971,   980,   986,   990,   994,  1000,  1008,  1014,  1019,  1023,
    1029,  1033,  1039,  1044,  1052,  1064,  1069,  1073,  1077,  1081,
    1088,  1096,  1102,  1106,  1110,  1128,  1132,  1138,  1145,  1152
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

#define YYPACT_NINF -155

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-155)))

#define YYTABLE_NINF -154

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     557,   492,   -16,  -155,    74,  -155,  -155,  -155,    39,   525,
    -155,  -155,  -155,    22,  -155,  -155,    17,    29,    -7,  -155,
      45,    33,    70,  -155,  -155,   208,   100,    10,  -155,   345,
      86,   169,  -155,   371,    34,   171,    84,    81,  -155,  -155,
    -155,   176,  -155,   536,  -155,  -155,    90,  -155,   345,  -155,
    -155,  -155,   377,   118,   127,  -155,  -155,   505,    69,  -155,
     442,  -155,   130,  -155,  -155,  -155,  -155,    98,    17,  -155,
     536,   118,    -8,   106,   131,  -155,   259,   395,   213,    34,
     123,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,   442,
     281,  -155,   518,   143,   118,   489,   345,   345,  -155,  -155,
     474,   483,  -155,  -155,  -155,   442,   122,  -155,   386,   189,
    -155,  -155,   145,   177,   518,     9,    12,   147,   313,   149,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,   155,  -155,  -155,   126,  -155,  -155,   179,  -155,
     291,   186,   518,  -155,   174,   185,   220,   225,  -155,   226,
    -155,   228,   236,  -155,   386,   386,  -155,   386,  -155,   386,
     386,   127,  -155,   122,   186,   122,    69,  -155,   196,  -155,
    -155,   202,  -155,   199,   418,   210,   427,  -155,  -155,   205,
    -155,   195,  -155,  -155,    62,   518,  -155,  -155,   433,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
     323,   536,     5,   323,   545,     6,  -155,    11,   206,   227,
    -155,   518,  -155,   518,  -155,   244,   323,  -155,  -155,    80,
     323,  -155,  -155,  -155,  -155,   323,  -155,   245,  -155,  -155,
    -155,  -155,  -155,  -155,   323,  -155,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    29,     0,    30,    32,    31,     0,     0,
       4,     7,     5,     0,    28,     6,    17,    22,     0,    15,
      18,     0,     0,     1,     3,    35,    22,     0,    25,     0,
       0,     0,    11,     0,    38,     0,     0,    40,    43,    69,
      12,     0,    10,     0,   157,   159,   142,   158,     0,   138,
     137,   139,     0,    20,   110,   112,   114,   116,   126,   131,
       0,   136,   141,   140,   146,   147,    24,     0,    16,    14,
      21,    19,    47,    52,    46,    49,     0,     0,     0,    36,
       0,   120,   119,   123,   124,   121,   122,   151,   149,     0,
       0,   113,   148,     0,   101,   141,     0,     0,   128,   129,
       0,     0,   133,   132,   134,     0,     0,   135,     0,     0,
      23,    54,     0,     0,    39,     0,     0,     0,     0,     0,
      73,    34,    55,    56,    60,    59,    57,    63,    58,    64,
      61,    62,     0,    44,    42,     0,     9,    68,     0,    27,
       0,   118,     0,   155,     0,   152,     0,     0,   107,     0,
     108,     0,     0,   145,     0,     0,    99,     0,   100,     0,
       0,   109,   111,   117,   115,   127,   125,   130,     0,   144,
      53,    50,    48,    80,     0,    86,     0,    93,    91,     0,
      71,     0,    72,    26,     0,    37,    33,   150,     0,   102,
     105,   103,   104,   106,    94,    97,    95,    96,    98,   143,
       0,    75,     0,     0,     0,     0,    92,     0,     0,     0,
      13,   156,   154,    77,    81,    55,     0,    84,    89,     0,
       0,    66,    70,    67,    65,     0,    79,    55,    85,    90,
      83,    88,    76,    82,     0,    74,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,  -155,   252,  -155,  -155,  -155,    -6,   235,  -155,
    -155,     0,  -155,  -155,   232,  -155,   192,  -155,   161,   -73,
    -154,   -95,  -155,   170,    99,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,   -48,   -27,   194,   -40,  -155,   231,   -63,  -155,
     190,  -155,   -49,  -155,  -155,   -28,  -155,  -155,  -155,  -155,
    -155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,   137,    18,    19,    20,
     138,    35,    14,    15,    36,    37,    38,    74,    75,   222,
     122,   123,   124,    78,   207,   125,   126,   127,   128,   129,
     130,   131,   132,    94,    54,    55,    56,    89,    57,   101,
      58,   105,    59,    60,    61,    95,    63,    64,   144,   145,
      65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    62,    53,   121,    93,    62,    71,    27,    91,    13,
     173,   107,   213,   175,    44,    45,    46,    47,   -51,    31,
      62,    96,    96,    25,   115,    21,   141,    26,    48,   116,
     117,   118,    62,    49,    34,    50,    31,   164,   111,    23,
       3,    32,   143,     5,     6,     7,   215,   216,   220,   217,
     174,    51,    52,   176,   119,   221,   167,   162,    42,   120,
     168,    62,   227,    28,    29,   228,   230,   186,    62,    62,
     179,   232,    62,    62,    30,   -41,   -45,    62,   139,    22,
     235,   213,   -45,    44,    45,    46,    47,    66,    31,    67,
     102,   103,    33,   115,   104,  -149,  -149,    48,   116,   117,
     118,  -149,    49,  -149,    50,  -149,   194,   195,   218,   196,
     210,   197,   198,    39,  -149,  -149,  -149,  -149,  -149,  -149,
      51,    52,  -149,   119,   229,   231,    76,   214,   120,    77,
     233,    90,   184,     3,    96,   183,     5,     6,     7,   236,
     212,    41,    97,   226,   110,    30,    62,   202,    62,   205,
     180,   112,   -69,   -69,   -69,   -69,   -69,   113,   -69,   -69,
     -69,   -69,   -69,    87,    88,   140,   -69,   -69,   -69,   -69,
      68,   -69,    72,   -69,    17,   108,    73,    79,   171,   109,
      16,   139,    73,     3,    17,   153,     5,     6,     7,   -69,
     -69,   170,   -69,   -69,   169,   177,   208,   -69,   -71,   -71,
     -71,   -71,     3,   182,   135,     5,     6,     7,   -71,    98,
      99,   188,   -71,   -71,   -71,   -71,   187,   -71,   -41,   -71,
       3,   189,   135,     5,     6,     7,   190,   191,   213,   192,
      44,    45,    46,    47,   -17,   -71,   -71,   193,   -71,   -71,
     115,   200,   199,   -71,    48,   116,   117,   118,   111,    49,
     223,    50,   203,   206,    28,    29,    40,   136,   225,   234,
     114,    24,    44,    45,    46,    47,    69,    51,    52,   134,
     119,   224,   115,    80,   172,   120,    48,   116,   117,   118,
     209,    49,   142,    50,    44,    45,    46,    47,   100,   181,
     161,   166,   185,     0,    44,    45,    46,    47,    48,    51,
      52,     0,   119,    49,   115,    50,     0,   120,    48,   116,
     117,   118,     0,    49,   142,    50,    44,    45,    46,    47,
       0,    51,    52,  -153,   213,     0,    44,    45,    46,    47,
      48,    51,    52,     0,   119,    49,   115,    50,     0,   120,
      48,   116,   117,   118,     0,    49,    43,    50,    44,    45,
      46,    47,     0,    51,    52,     0,     0,     0,     0,     0,
       0,   178,    48,    51,    52,     0,   119,    49,     0,    50,
       0,   120,    70,     0,    44,    45,    46,    47,    92,     0,
      44,    45,    46,    47,     0,    51,    52,   142,    48,    44,
      45,    46,    47,    49,    48,    50,   133,     0,     0,    49,
       0,    50,     3,    48,     0,     5,     6,     7,    49,     0,
      50,    51,    52,     0,     0,     0,     0,    51,    52,   201,
       0,    44,    45,    46,    47,     0,    51,    52,   204,     0,
      44,    45,    46,    47,   211,    48,    44,    45,    46,    47,
      49,     0,    50,   106,    48,    44,    45,    46,    47,    49,
      48,    50,     0,     0,     0,    49,     0,    50,    51,    52,
       0,     0,     0,     0,    49,     0,    50,    51,    52,     0,
       0,     0,     0,    51,    52,   163,     0,    44,    45,    46,
      47,     0,    51,    52,   165,     0,    44,    45,    46,    47,
       0,     0,    -8,    16,     0,     0,    49,    17,    50,    -8,
      -8,     0,    -8,    -8,    -8,    49,     0,    50,     0,     0,
       0,     0,     0,     0,    51,    52,   154,   155,   156,   157,
     158,   159,   160,    51,    52,    -2,     1,     0,    98,    99,
       2,     0,     3,     4,   108,     5,     6,     7,   109,    81,
      82,    83,    84,    85,    86,   146,   147,   148,   149,   150,
     151,   152,    81,    82,    83,    84,    85,    86,     1,    87,
      88,     0,     2,     0,     3,     4,     0,     5,     6,     7,
      81,    82,    83,    84,    85,    86,     0,    87,    88,    81,
      82,    83,    84,    85,    86,     0,    87,   219
};

static const yytype_int16 yycheck[] =
{
       0,    29,    29,    76,    52,    33,    33,    13,    48,     9,
       1,    60,     1,     1,     3,     4,     5,     6,    26,    26,
      48,    16,    16,     1,    13,    41,    89,     5,    17,    18,
      19,    20,    60,    22,     1,    24,    26,   100,    46,     0,
       7,    48,    90,    10,    11,    12,   200,    42,    42,   203,
      41,    40,    41,    41,    43,    44,   105,    97,    48,    48,
     108,    89,   216,    46,    47,   219,   220,   140,    96,    97,
     118,   225,   100,   101,    45,    42,    42,   105,    78,     5,
     234,     1,    48,     3,     4,     5,     6,     1,    26,     3,
      21,    22,    47,    13,    25,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   154,   155,   203,   157,
      48,   159,   160,    43,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   219,   220,    42,   200,    48,    48,
     225,    41,   138,     7,    16,   135,    10,    11,    12,   234,
     188,    41,    15,   216,    46,    45,   174,   174,   176,   176,
       1,    45,     3,     4,     5,     6,     7,    26,     9,    10,
      11,    12,    13,    41,    42,    42,    17,    18,    19,    20,
       1,    22,     1,    24,     5,    45,     5,     1,     1,    49,
       1,   181,     5,     7,     5,    42,    10,    11,    12,    40,
      41,    46,    43,    44,     5,    48,     1,    48,     3,     4,
       5,     6,     7,    48,     9,    10,    11,    12,    13,    23,
      24,    26,    17,    18,    19,    20,    42,    22,    42,    24,
       7,     1,     9,    10,    11,    12,     1,     1,     1,     1,
       3,     4,     5,     6,    26,    40,    41,     1,    43,    44,
      13,    42,    46,    48,    17,    18,    19,    20,    46,    22,
      44,    24,    42,    48,    46,    47,    48,    44,    14,    14,
       1,     9,     3,     4,     5,     6,    31,    40,    41,    77,
      43,    44,    13,    41,   113,    48,    17,    18,    19,    20,
     181,    22,     1,    24,     3,     4,     5,     6,    57,   119,
      96,   101,     1,    -1,     3,     4,     5,     6,    17,    40,
      41,    -1,    43,    22,    13,    24,    -1,    48,    17,    18,
      19,    20,    -1,    22,     1,    24,     3,     4,     5,     6,
      -1,    40,    41,    42,     1,    -1,     3,     4,     5,     6,
      17,    40,    41,    -1,    43,    22,    13,    24,    -1,    48,
      17,    18,    19,    20,    -1,    22,     1,    24,     3,     4,
       5,     6,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    17,    40,    41,    -1,    43,    22,    -1,    24,
      -1,    48,     1,    -1,     3,     4,     5,     6,     1,    -1,
       3,     4,     5,     6,    -1,    40,    41,     1,    17,     3,
       4,     5,     6,    22,    17,    24,     1,    -1,    -1,    22,
      -1,    24,     7,    17,    -1,    10,    11,    12,    22,    -1,
      24,    40,    41,    -1,    -1,    -1,    -1,    40,    41,     1,
      -1,     3,     4,     5,     6,    -1,    40,    41,     1,    -1,
       3,     4,     5,     6,     1,    17,     3,     4,     5,     6,
      22,    -1,    24,     1,    17,     3,     4,     5,     6,    22,
      17,    24,    -1,    -1,    -1,    22,    -1,    24,    40,    41,
      -1,    -1,    -1,    -1,    22,    -1,    24,    40,    41,    -1,
      -1,    -1,    -1,    40,    41,     1,    -1,     3,     4,     5,
       6,    -1,    40,    41,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     0,     1,    -1,    -1,    22,     5,    24,     7,
       8,    -1,    10,    11,    12,    22,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    27,    28,    29,    30,
      31,    32,    33,    40,    41,     0,     1,    -1,    23,    24,
       5,    -1,     7,     8,    45,    10,    11,    12,    49,    34,
      35,    36,    37,    38,    39,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     1,    41,
      42,    -1,     5,    -1,     7,     8,    -1,    10,    11,    12,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    34,
      35,    36,    37,    38,    39,    -1,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,     7,     8,    10,    11,    12,    52,    53,
      54,    55,    56,    62,    63,    64,     1,     5,    58,    59,
      60,    41,     5,     0,    54,     1,     5,    58,    46,    47,
      45,    26,    48,    47,     1,    62,    65,    66,    67,    43,
      48,    41,    48,     1,     3,     4,     5,     6,    17,    22,
      24,    40,    41,    84,    85,    86,    87,    89,    91,    93,
      94,    95,    96,    97,    98,   101,     1,     3,     1,    59,
       1,    84,     1,     5,    68,    69,    42,    48,    74,     1,
      65,    34,    35,    36,    37,    38,    39,    41,    42,    88,
      41,    86,     1,    83,    84,    96,    16,    15,    23,    24,
      88,    90,    21,    22,    25,    92,     1,    93,    45,    49,
      46,    46,    45,    26,     1,    13,    18,    19,    20,    43,
      48,    70,    71,    72,    73,    76,    77,    78,    79,    80,
      81,    82,    83,     1,    67,     9,    44,    57,    61,    62,
      42,    89,     1,    83,    99,   100,    27,    28,    29,    30,
      31,    32,    33,    42,    27,    28,    29,    30,    31,    32,
      33,    85,    86,     1,    89,     1,    91,    93,    83,     5,
      46,     1,    69,     1,    41,     1,    41,    48,    48,    83,
       1,    74,    48,    62,    58,     1,    70,    42,    26,     1,
       1,     1,     1,     1,    83,    83,    83,    83,    83,    46,
      42,     1,    84,    42,     1,    84,    48,    75,     1,    75,
      48,     1,    83,     1,    70,    71,    42,    71,    72,    42,
      42,    44,    70,    44,    44,    14,    70,    71,    71,    72,
      71,    72,    71,    72,    14,    71,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    55,
      56,    56,    56,    57,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    68,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    79,    80,    80,
      80,    81,    81,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    93,    93,    94,    94,    94,
      95,    95,    96,    96,    96,    97,    97,    97,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     1,     3,     1,     1,     3,
       3,     3,     1,     4,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     6,     5,     2,     4,     6,     3,     5,
       1,     0,     3,     1,     3,     1,     2,     2,     3,     1,
       3,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     2,     0,
       2,     0,     2,     1,     7,     3,     6,     1,     7,     5,
       2,     4,     6,     5,     4,     5,     2,     1,     5,     4,
       5,     2,     3,     2,     3,     3,     3,     3,     3,     2,
       2,     1,     3,     3,     3,     3,     3,     2,     2,     3,
       1,     3,     1,     2,     1,     3,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     1,     1,     2,     2,
       4,     2,     1,     0,     3,     1,     3,     1,     1,     1
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
#line 109 "c-.y" /* yacc.c:1646  */
    {
							savedTree = (yyvsp[0].treeNode);
						}
#line 1538 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 115 "c-.y" /* yacc.c:1646  */
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
#line 1559 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 132 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1567 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1575 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 142 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1583 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 146 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1591 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 150 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1599 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 158 "c-.y" /* yacc.c:1646  */
    {
							// We need to add the user-defined type to the global symbol table.
							globalScope.insert((yyvsp[-3].t).tokenStr, static_cast<char*>("recordType"));
						
							(yyval.treeNode) = NewDeclNode(VarK);
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
							(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
							(yyval.treeNode)->isRecord = true;
							(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);						
						}
#line 1614 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 171 "c-.y" /* yacc.c:1646  */
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
#line 1637 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 190 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1645 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 194 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1654 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 201 "c-.y" /* yacc.c:1646  */
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
#line 1679 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 224 "c-.y" /* yacc.c:1646  */
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
#line 1701 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 242 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1709 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1717 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1725 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 256 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1733 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 260 "c-.y" /* yacc.c:1646  */
    {
							(yyvsp[-2].treeNode)->children[0] = (yyvsp[0].treeNode);
							(yyval.treeNode) = (yyvsp[-2].treeNode);
						}
#line 1742 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 265 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1751 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 270 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1759 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 276 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(VarK);
							(yyval.treeNode)->lineNumber = (yyvsp[0].t).lineNum;
							(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
						}
#line 1769 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 282 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(VarK);
							(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-3].t).lineNum;
							(yyval.treeNode)->isArray = true;
							(yyval.treeNode)->arraySize = (yyvsp[-1].t).intVal;
						}
#line 1781 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 290 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1789 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 294 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1798 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 301 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(VarK);
							(yyval.treeNode)->isStatic = true;
							(yyval.treeNode)->expType = (yyvsp[0].expType);
							if ((yyvsp[0].expType) == Record)
							{
								(yyval.treeNode)->isRecord = true;
							}
						}
#line 1812 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 311 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(VarK);						
							(yyval.treeNode)->expType = (yyvsp[0].expType);
						}
#line 1821 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 318 "c-.y" /* yacc.c:1646  */
    {
							(yyval.expType) = (yyvsp[0].expType);
						}
#line 1829 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 322 "c-.y" /* yacc.c:1646  */
    {	
							(yyval.expType) = Record;
						}
#line 1837 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 328 "c-.y" /* yacc.c:1646  */
    {
							(yyval.expType) = Int;
						}
#line 1845 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 332 "c-.y" /* yacc.c:1646  */
    {
							(yyval.expType) = Bool;
						}
#line 1853 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 336 "c-.y" /* yacc.c:1646  */
    {
							(yyval.expType) = Char;
						}
#line 1861 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 344 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(FuncK);
							(yyval.treeNode)->expType = (yyvsp[-5].expType);
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							// Sets the line number where the function declaration starts.
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum; 
						}
#line 1875 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 354 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewDeclNode(FuncK);
							(yyval.treeNode)->expType = Void;
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							// Sets the line number where the function call starts.
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						}
#line 1889 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 364 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1897 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 368 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1905 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 372 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1913 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 376 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1921 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 380 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1929 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 386 "c-.y" /* yacc.c:1646  */
    { 
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1937 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 389 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1945 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 395 "c-.y" /* yacc.c:1646  */
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
#line 1967 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 413 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 1975 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 417 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 1984 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 422 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 1992 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 428 "c-.y" /* yacc.c:1646  */
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
#line 2014 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 446 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2022 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 452 "c-.y" /* yacc.c:1646  */
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

  case 49:
#line 471 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2053 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 475 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2061 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 479 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2069 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 485 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(ParamK);
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
					}
#line 2078 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 490 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewDeclNode(ParamK);
						(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
						(yyval.treeNode)->isArray = true;
					}
#line 2088 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 496 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NULL;
					}
#line 2097 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 505 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2105 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 509 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2113 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 515 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2121 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 519 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2129 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 523 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2137 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 527 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2145 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 531 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2153 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 535 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2161 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 541 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2169 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 545 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2177 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 551 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewStmtNode(CompK);
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[-1].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-3].t).lineNum;
						}
#line 2189 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 559 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2198 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 564 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2207 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 571 "c-.y" /* yacc.c:1646  */
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
#line 2228 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 587 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2236 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 593 "c-.y" /* yacc.c:1646  */
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
#line 2257 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 609 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2265 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 615 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
#line 2274 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 620 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2283 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 627 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(IfK);
							(yyval.treeNode)->attr.name = (yyvsp[-6].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-4].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[2] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-6].t).lineNum;
						}
#line 2296 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 636 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2304 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 640 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2313 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 645 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2321 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 651 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(IfK);
							(yyval.treeNode)->attr.name = (yyvsp[-6].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-4].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[2] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-6].t).lineNum;
						}
#line 2334 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 661 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(IfK);
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						}
#line 2346 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 669 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2354 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 673 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2363 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 678 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2372 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 685 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(WhileK);
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						}
#line 2384 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 693 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2393 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 698 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2402 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 703 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2410 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 707 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2418 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 713 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewStmtNode(WhileK);
							(yyval.treeNode)->attr.name = (yyvsp[-4].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
							(yyval.treeNode)->lineNumber = (yyvsp[-4].t).lineNum;
						}
#line 2430 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 721 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2439 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 726 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2448 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 733 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewStmtNode(ReturnK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						}
#line 2459 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 740 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewStmtNode(ReturnK);
							(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-2].t).lineNum;
							(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
						}
#line 2471 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 750 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewStmtNode(BreakK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						}
#line 2481 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 760 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2493 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 768 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2505 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 776 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2517 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 784 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2529 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 792 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
					}
#line 2541 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 800 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[0].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
					}
#line 2553 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 808 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NewExprNode(AssignK);
						(yyval.treeNode)->lineNumber = (yyvsp[0].t).lineNum;
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
					}
#line 2565 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 816 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2573 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 820 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2581 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 824 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2589 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 828 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2597 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 832 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2605 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 836 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 2613 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 840 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NULL;
					}
#line 2622 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 845 "c-.y" /* yacc.c:1646  */
    {
						yyerrok;
						(yyval.treeNode) = NULL;
					}
#line 2631 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 852 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						}
#line 2643 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 860 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2651 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 866 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						}
#line 2663 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 874 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2671 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 880 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->isConst = (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[0].treeNode);
						}
#line 2682 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 887 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2690 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 893 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						}
#line 2702 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 901 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2710 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 905 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2718 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 909 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2727 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 916 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2735 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 920 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2743 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 924 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2751 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 928 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2759 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 932 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2767 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 936 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2775 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 942 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NewExprNode(OpK);
							(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
							(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
							(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
							(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
							(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						}
#line 2788 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 951 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2796 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 955 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 2805 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 962 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2813 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 966 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2821 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 972 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						(yyval.treeNode)->children[1] = (yyvsp[0].treeNode);
						(yyval.treeNode)->isConst = (yyvsp[-2].treeNode)->isConst && (yyvsp[0].treeNode)->isConst;
					}
#line 2834 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 981 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2842 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 987 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2850 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 991 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2858 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 995 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2866 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1001 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->lineNumber = (yyvsp[-1].t).lineNum;
						(yyval.treeNode)->children[0] = (yyvsp[0].treeNode);
						(yyval.treeNode)->isConst = (yyvsp[-1].t).isConst && (yyvsp[0].treeNode)->isConst;
					}
#line 2878 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1009 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2886 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1015 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
						(yyval.t).isConst = true;
					}
#line 2895 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1020 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2903 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1024 "c-.y" /* yacc.c:1646  */
    {
						(yyval.t) = (yyvsp[0].t);
					}
#line 2911 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1030 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2919 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1034 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2927 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1040 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(IdK);
						(yyval.treeNode)->attr.name = (yyvsp[0].t).tokenStr;
					}
#line 2936 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1045 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-2].t).tokenStr;
						
						(yyval.treeNode)->children[0] = (yyvsp[-3].treeNode);						
						(yyval.treeNode)->children[1] = (yyvsp[-1].treeNode);
					}
#line 2948 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1053 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(OpK);
						(yyval.treeNode)->attr.name = (yyvsp[-1].t).tokenStr;
						(yyval.treeNode)->children[0] = (yyvsp[-2].treeNode);
						
						TreeNode* t = NewExprNode(IdK);
						t->attr.name = (yyvsp[0].t).tokenStr;
						(yyval.treeNode)->children[1] = t;
					}
#line 2962 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1065 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = (yyvsp[-1].treeNode);
						}
#line 2971 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1070 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2979 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1074 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = (yyvsp[0].treeNode);
						}
#line 2987 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1078 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 2995 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1082 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NULL;
						}
#line 3004 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1089 "c-.y" /* yacc.c:1646  */
    {
							yyerrok;
							(yyval.treeNode) = NewExprNode(CallK);
							(yyval.treeNode)->lineNumber = (yyvsp[-3].t).lineNum;
							(yyval.treeNode)->attr.name = (yyvsp[-3].t).tokenStr;
							(yyval.treeNode)->children[0] = (yyvsp[-1].treeNode);
						}
#line 3016 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1097 "c-.y" /* yacc.c:1646  */
    {
							(yyval.treeNode) = NULL;
						}
#line 3024 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1103 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 3032 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1106 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 3040 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1111 "c-.y" /* yacc.c:1646  */
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
#line 3062 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1129 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 3070 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1133 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NULL;
					}
#line 3078 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1139 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(ConstK);
						(yyval.treeNode)->isConst = true;
						(yyval.treeNode)->attr.value = (yyvsp[0].t).intVal;
						(yyval.treeNode)->expType = Int;
					}
#line 3089 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1146 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(ConstK);
						(yyval.treeNode)->isConst = true;
						(yyval.treeNode)->attr.cValue = (yyvsp[0].t).charVal;
						(yyval.treeNode)->expType = Char;
					}
#line 3100 "c-.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1153 "c-.y" /* yacc.c:1646  */
    {
						(yyval.treeNode) = NewExprNode(ConstK);
						(yyval.treeNode)->isConst = true;
						(yyval.treeNode)->attr.value = (yyvsp[0].t).intVal;
						(yyval.treeNode)->expType = Bool;
					}
#line 3111 "c-.tab.c" /* yacc.c:1646  */
    break;


#line 3115 "c-.tab.c" /* yacc.c:1646  */
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
#line 1161 "c-.y" /* yacc.c:1906  */


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
	
	AttachIOLib(savedTree);
	SemanticAnalysis(savedTree, numErrors, numWarnings);
	
	if (printAnnotatedSyntaxTree)
	{
		PrintSyntaxTree(savedTree, -1, true);
	}
		
	printf("Number of warnings: %d\n", numWarnings);
	printf("Number of errors: %d\n", numErrors);
	
	return 0;
}
