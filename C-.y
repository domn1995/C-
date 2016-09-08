%{
#include <cstdio>

extern int yylex();
extern void yyerror(const char* msg);
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
    int lvalue;
    char* svalue;
    int varindex;
}

%token BOOLCONST NUMCONST ID CHARCONST 
%token RECORD STATIC INT CHAR BOOL
%token IF ELSE AND OR NOT WHILE RETURN
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

declaration 		: NUMCONST 	{ printf("Line %d Token: NUMCONST Value: %s\n", yylineno, yytext); }
				| BOOLCONST	{ printf("Line %d Token: BOOLCONST Value: %s\n", yylineno, yytext); }
				| CHARCONST 	{ printf("Line %d Token: CHARCONST Value: %s\n", yylineno, yytext); }		
				| RECORD		{ printf("Line %d Token: RECORD Value: %s\n", yylineno, yytext); }
				| STATIC		{ printf("Line %d Token: STATIC Value: %s\n", yylineno, yytext); }
				| INT		{ printf("Line %d Token: INT Value: %s\n", yylineno, yytext); }
				| CHAR		{ printf("Line %d Token: CHAR Value: %s\n", yylineno, yytext); }
				| BOOL 		{ printf("Line %d Token: BOOL Value: %s\n", yylineno, yytext); }
				| IF			{ printf("Line %d Token: IF Value: %s\n", yylineno, yytext); }
				| ELSE		{ printf("Line %d Token: ELSE Value: %s\n", yylineno, yytext); }
				| AND		{ printf("Line %d Token: AND Value: %s\n", yylineno, yytext); }
				| OR			{ printf("Line %d Token: OR Value: %s\n", yylineno, yytext); }
				| NOT		{ printf("Line %d Token: NOT Value: %s\n", yylineno, yytext); }
				| WHILE		{ printf("Line %d Token: WHILE Value: %s\n", yylineno, yytext); }
				| RETURN		{ printf("Line %d Token: RETURN Value: %s\n", yylineno, yytext); }
				| DIV		{ printf("Line %d Token: DIV Value: %s\n", yylineno, yytext); }
				| STAR		{ printf("Line %d Token: STAR Value: %s\n", yylineno, yytext); }
				| ADD		{ printf("Line %d Token: ADD Value: %s\n", yylineno, yytext); }
				| MINUS		{ printf("Line %d Token: MINUS Value: %s\n", yylineno, yytext); }
				| PERCENT		{ printf("Line %d Token: PERCENT Value: %s\n", yylineno, yytext); }
				| COMMA		{ printf("Line %d Token: COMMA Value: %s\n", yylineno, yytext); }
				| ASSIGN		{ printf("Line %d Token: ASSIGN Value: %s\n", yylineno, yytext); }
				| MULASS		{ printf("Line %d Token: MULASS Value: %s\n", yylineno, yytext); }
				| INC		{ printf("Line %d Token: INC Value: %s\n", yylineno, yytext); }
				| ADDASS		{ printf("Line %d Token: ADDASS Value: %s\n", yylineno, yytext); }
				| DEC		{ printf("Line %d Token: DEC Value: %s\n", yylineno, yytext); }
				| SUBASS		{ printf("Line %d Token: SUBASS Value: %s\n", yylineno, yytext); }
				| DIVASS		{ printf("Line %d Token: DIVASS Value: %s\n", yylineno, yytext); }
				| LTHAN		{ printf("Line %d Token: LTHAN Value: %s\n", yylineno, yytext); }
				| LESSEQ		{ printf("Line %d Token: LESSEQ Value: %s\n", yylineno, yytext); }
				| EQ			{ printf("Line %d Token: EQ Value: %s\n", yylineno, yytext); }
				| NOTEQ		{ printf("Line %d Token: NOTEQ Value: %s\n", yylineno, yytext); }
				| GTHAN		{ printf("Line %d Token: GTHAN Value: %s\n", yylineno, yytext); }
				| GRTEQ		{ printf("Line %d Token: GRTEQ Value: %s\n", yylineno, yytext); }
				| QMARK		{ printf("Line %d Token: QMARK Value: %s\n", yylineno, yytext); }
				| LPAREN		{ printf("Line %d Token: LPAREN Value: %s\n", yylineno, yytext); }
				| RPAREN		{ printf("Line %d Token: RPAREN Value: %s\n", yylineno, yytext); }
				| LCURLY		{ printf("Line %d Token: LCURLY Value: %s\n", yylineno, yytext); }
				| RCURLY		{ printf("Line %d Token: RCURLY Value: %s\n", yylineno, yytext); }
				| LBRACKET	{ printf("Line %d Token: LBRACKET Value: %s\n", yylineno, yytext); }
				| RBRACKET	{ printf("Line %d Token: RBRACKET Value: %s\n", yylineno, yytext); }				
				| ID     		{ printf("Line %d Token: ID Value: %s\n", yylineno, yytext); }
				| DOT 		{ printf("Line %d Token: DOT Value: %s\n", yylineno, yytext); }	
				| COLON		{ printf("Line %d Token: COLON Value: %s\n", yylineno, yytext); }
				| SEMICOLON	{ printf("Line %d Token: SEMICOLON Value: %s\n", yylineno, yytext); }
				| ERROR 		{ printf("ERROR(%d): Invalid or misplaced input character: \"%c\"\n", yylineno, yytext[0]);										}
				;
%%

int main()
{
	yyparse();
	return 0;
}