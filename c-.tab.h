/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

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
    BOOLCONST = 258,
    NUMCONST = 259,
    ID = 260,
    CHARCONST = 261,
    RECORD = 262,
    STATIC = 263,
    INT = 264,
    CHAR = 265,
    BOOL = 266,
    IF = 267,
    ELSE = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    WHILE = 272,
    RETURN = 273,
    DIV = 274,
    STAR = 275,
    ADD = 276,
    MINUS = 277,
    PERCENT = 278,
    COMMA = 279,
    ASSIGN = 280,
    MULASS = 281,
    INC = 282,
    ADDASS = 283,
    DEC = 284,
    SUBASS = 285,
    DIVASS = 286,
    LTHAN = 287,
    LESSEQ = 288,
    EQ = 289,
    NOTEQ = 290,
    GTHAN = 291,
    GRTEQ = 292,
    QMARK = 293,
    LPAREN = 294,
    RPAREN = 295,
    LCURLY = 296,
    RCURLY = 297,
    LBRACKET = 298,
    RBRACKET = 299,
    COLON = 300,
    SEMICOLON = 301,
    DOT = 302,
    ERROR = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "c-.y" /* yacc.c:1909  */

    int lvalue;
    char* svalue;
    int varindex;

#line 109 "c-.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_H_INCLUDED  */
