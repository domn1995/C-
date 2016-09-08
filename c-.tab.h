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
    NUMCONST = 258,
    BOOLCONST = 259,
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
    BREAK = 273,
    RETURN = 274,
    DIV = 275,
    STAR = 276,
    ADD = 277,
    MINUS = 278,
    PERCENT = 279,
    COMMA = 280,
    ASSIGN = 281,
    MULASS = 282,
    INC = 283,
    ADDASS = 284,
    DEC = 285,
    SUBASS = 286,
    DIVASS = 287,
    LTHAN = 288,
    LESSEQ = 289,
    EQ = 290,
    NOTEQ = 291,
    GTHAN = 292,
    GRTEQ = 293,
    QMARK = 294,
    LPAREN = 295,
    RPAREN = 296,
    LCURLY = 297,
    RCURLY = 298,
    LBRACKET = 299,
    RBRACKET = 300,
    COLON = 301,
    SEMICOLON = 302,
    DOT = 303,
    ERROR = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "c-.y" /* yacc.c:1909  */

    Token t;

#line 108 "c-.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_H_INCLUDED  */
