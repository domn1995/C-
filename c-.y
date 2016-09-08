%{
#include <cstdio>
#include "Token.h"

extern int yylex();
//extern void yyerror(const char* msg);
extern char* yytext;
extern int yylineno;

#define YYERROR_VERBOSE
void yyerror(const char *msg)
{
    printf(msg);
}
%}

%union 
{
    Token t;
}

%token <t.intVal> NUMCONST
%token BOOLCONST ID CHARCONST 
%token RECORD STATIC INT CHAR BOOL
%token IF ELSE AND OR NOT WHILE BREAK RETURN
%token DIV STAR ADD MINUS PERCENT COMMA
%token ASSIGN MULASS INC ADDASS DEC
%token SUBASS DIVASS LTHAN LESSEQ EQ NOTEQ
%token GTHAN GRTEQ QMARK LPAREN RPAREN
%token LCURLY RCURLY LBRACKET RBRACKET
%token COLON SEMICOLON DOT ERROR

%%
program			: declarationList
				;

declarationList	: declarationList declaration
				| declaration 
				;

declaration 		: NUMCONST 	{ printf("Line %d Token: NUMCONST Value: %d Input: %s\n", yylval.t.lineNum, yylval.t.intVal, yylval.t.tokenStr); }
				| BOOLCONST	{ printf("Line %d Token: BOOLCONST Value: %d Input: %s\n", yylval.t.lineNum, yylval.t.intVal, yylval.t.tokenStr); }
				| CHARCONST 	{ printf("Line %d Token: CHARCONST Value: '%c' Input: %s\n", yylval.t.lineNum, yylval.t.charVal, yylval.t.tokenStr); }		
				| RECORD		{ printf("Line %d Token: RECORD\n", yylval.t.lineNum); }
				| STATIC		{ printf("Line %d Token: STATIC\n", yylval.t.lineNum); }
				| INT		{ printf("Line %d Token: INT\n", yylval.t.lineNum); }
				| CHAR		{ printf("Line %d Token: CHAR\n", yylval.t.lineNum); }
				| BOOL 		{ printf("Line %d Token: BOOL\n", yylval.t.lineNum); }
				| IF			{ printf("Line %d Token: IF\n", yylval.t.lineNum); }
				| ELSE		{ printf("Line %d Token: ELSE\n", yylval.t.lineNum); }
				| AND		{ printf("Line %d Token: AND\n", yylval.t.lineNum); }
				| OR			{ printf("Line %d Token: OR\n", yylval.t.lineNum); }
				| NOT		{ printf("Line %d Token: NOT\n", yylval.t.lineNum); }
				| WHILE		{ printf("Line %d Token: WHILE\n", yylval.t.lineNum); }
				| BREAK		{ printf("Line %d Token: BREAK\n", yylval.t.lineNum); }
				| RETURN		{ printf("Line %d Token: RETURN\n", yylval.t.lineNum); }
				| DIV		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| STAR		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| ADD		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| MINUS		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| PERCENT		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| COMMA		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| ASSIGN		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| MULASS		{ printf("Line %d Token: MULASS\n", yylval.t.lineNum); }
				| INC		{ printf("Line %d Token: INC\n", yylval.t.lineNum); }
				| ADDASS		{ printf("Line %d Token: ADDASS\n", yylval.t.lineNum); }
				| DEC		{ printf("Line %d Token: DEC\n", yylval.t.lineNum); }
				| SUBASS		{ printf("Line %d Token: SUBASS\n", yylval.t.lineNum); }
				| DIVASS		{ printf("Line %d Token: DIVASS\n", yylval.t.lineNum); }
				| LTHAN		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| LESSEQ		{ printf("Line %d Token: LESSEQ\n", yylval.t.lineNum); }
				| EQ			{ printf("Line %d Token: EQ\n", yylval.t.lineNum); }
				| NOTEQ		{ printf("Line %d Token: NOTEQ\n", yylval.t.lineNum); }
				| GTHAN		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| GRTEQ		{ printf("Line %d Token: GRTEQ\n", yylval.t.lineNum); }
				| QMARK		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| LPAREN		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| RPAREN		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| LCURLY		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| RCURLY		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| LBRACKET	{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| RBRACKET	{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }				
				| ID     		{ printf("Line %d Token: ID Value: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| DOT 		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }	
				| COLON		{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| SEMICOLON	{ printf("Line %d Token: %s\n", yylval.t.lineNum, yylval.t.tokenStr); }
				| ERROR 		{ printf("ERROR(%d): Invalid or misplaced input character: \"%c\"\n", yylineno, yytext[0]); }
				;
%%

int main()
{
	yyparse();
	return 0;
}