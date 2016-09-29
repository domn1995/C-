%{
#include <cstdio>
#include <getopt.h>
#include "Token.h"
#include "TreeNode.h"
#include "SymbolTable.h"

extern int yylex();
//extern void yyerror(const char* msg);
extern char* yytext;
extern int yylineno;
extern FILE* yyin;
Scope globalScope("global");

#define YYERROR_VERBOSE
void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", yylineno, msg);
}
%}

%union 
{
    Token t;
    TreeNode* treeNode;
}

%token <t> NUMCONST BOOLCONST ID CHARCONST RECTYPE
%token <t> RECORD STATIC INT CHAR BOOL
%token <t> IF ELSE AND OR NOT WHILE BREAK RETURN
%token <t> DIV STAR ADD MINUS PERCENT COMMA
%token <t> ASSIGN MULASS INC ADDASS DEC
%token <t> SUBASS DIVASS LTHAN LESSEQ EQ NOTEQ
%token <t> GTHAN GRTEQ QMARK LPAREN RPAREN
%token <t> LCURLY RCURLY LBRACKET RBRACKET
%token <t> COLON SEMICOLON DOT ERROR

%type <treeNode> 	program
				declaration
				declarationList
				
				// Normal Declarations
				varDeclaration
				scopedVarDeclaration
				scopedTypeSpecifier
				recDeclaration
				localDeclarations
				varDeclList
				varDeclInitialize
				varDeclId
				
				// Function Declarations
				funDeclaration
				params
				paramList
				paramTypeList
				paramIdList
				paramId
				
				// Statements
				statement
				matched
				unmatched
				expressionStmt
				statementList
				compoundStmt
				selectionStmtMatched
				selectionStmtUnmatched
				iterationStmtMatched
				iterationStmtUnmatched
				returnStmt
				breakStmt
				
				// Expressions
				expression
				simpleExpression
				andExpresssion
				unaryRelExpression
				relExpression
				sumExpression
				unaryExpression
				term
				factor
				immutable
				mutable
				call
				args
				argList
				constant
				
				// Operators
%type <string>		relop
				sumop
				mulop
				unaryop
				
				// Types
				typeSpecifier
				returnTypeSpecifier

%%
program			: 	declarationList
					{
				
					}
				;

declarationList	: 	declarationList declaration
					{
					
					}
				| 	declaration
					{
					
					}
				;

declaration 		: 	varDeclaration
					{
					
					}
				|	funDeclaration
					{
					
					}
				|	recDeclaration
					{
					
					}
				;
				
// Variable Declarations

recDeclaration		: 	RECORD ID LCURLY localDeclarations RCURLY
					{
						printf("Adding %s to scope.\n", $2.tokenStr);
						globalScope.insert($2.tokenStr, (char*)"recordType");
					}
				;

varDeclaration		: 	typeSpecifier varDeclList SEMICOLON
					{
						
					}
				;
				
scopedVarDeclaration:	scopedTypeSpecifier varDeclList SEMICOLON
					{
					
					}
				;
				
varDeclList		:	varDeclList COMMA varDeclInitialize 
					{
					
					}
				|	varDeclInitialize 
					{
					
					}
				;
				
varDeclInitialize	: 	varDeclId
					{
					
					}
				|	varDeclId COLON simpleExpression
					{
					
					}
				;
				
varDeclId			:	ID
					{
					
					}
				|	ID LBRACKET NUMCONST RBRACKET
					{
					
					}
				;
				
scopedTypeSpecifier :	STATIC typeSpecifier
					{
					
					}
				| 	typeSpecifier
					{
					
					}
				;
				
typeSpecifier		: 	returnTypeSpecifier
					{
					
					}
				|	RECTYPE
					{
						
					}
				;
				
returnTypeSpecifier :	INT
					{
					
					}
				|	BOOL
					{
					
					}
				|	CHAR
					{
					
					}
				;
				
// Function Declarations

funDeclaration		:	typeSpecifier ID LPAREN params RPAREN statement
					{
					
					}
				|	ID LPAREN params RPAREN statement
					{
					
					}
				;
				
params			:	paramList 
					{ 
					
					}
				|	{
				
					}
				;
				
paramList			: 	paramList SEMICOLON paramTypeList
					{
					
					}
				|	paramTypeList
					{
					
					}
				;

paramTypeList		: 	typeSpecifier paramIdList
					{
					
					}
				;
				
paramIdList		:	paramIdList COMMA paramId
					{
					
					}
				|	paramId
					{
					
					}
				;
				
paramId			:	ID
					{
					
					}
				|	ID LBRACKET RBRACKET
					{
					
					}
				;
				
// Statements

statement			:	matched
					{
					
					}
				|	unmatched
					{
					
					}
				;

matched			:	selectionStmtMatched
					{
					
					}
				|	iterationStmtMatched
					{
					
					}
				|	expressionStmt
					{
					
					}
				|	compoundStmt
					{
					
					}
				|	returnStmt
					{
					
					}
				|	breakStmt
					{
					
					}
				;
				
unmatched			:	selectionStmtUnmatched
					{
					
					}
				|	iterationStmtUnmatched
					{
					
					}
				;
				
compoundStmt		:	LCURLY localDeclarations statementList RCURLY
					{
					
					}
				;
			
localDeclarations	:	localDeclarations scopedVarDeclaration
					{
					
					}
				|	{
				
					}
				;
				
statementList		:	statementList statement
					{
					
					}
				|	{
						
					}
				;
			
expressionStmt		:	expression SEMICOLON
					{
					
					}
				|	SEMICOLON
					{
					
					}
				;
				
selectionStmtMatched:	IF LPAREN simpleExpression RPAREN matched ELSE matched
					{
					
					}
				;
				
selectionStmtUnmatched:	IF LPAREN simpleExpression RPAREN matched ELSE unmatched
					{
					
					}
				|
					IF LPAREN simpleExpression RPAREN statement
					{
					
					}
				;
				
iterationStmtMatched:	WHILE LPAREN simpleExpression RPAREN matched
					{
					
					}
				;
				
iterationStmtUnmatched:	WHILE LPAREN simpleExpression RPAREN unmatched
					{
					
					}
				;
				
returnStmt		:	RETURN SEMICOLON
					{
					
					}
				|	RETURN expression SEMICOLON
					{
					
					}
				;
				
breakStmt			:	BREAK SEMICOLON
					{
					
					}
				;
				
// Expressions

expression		: 	mutable ASSIGN expression
					{
					
					}
				|	mutable ADDASS expression
					{
					
					}
				|	mutable SUBASS expression
					{
					
					}
				|	mutable MULASS expression
					{
					
					}
				|	mutable DIVASS expression
					{
					
					}
				|	mutable INC
					{
					
					}
				|	mutable DEC
					{
					
					}
				|	simpleExpression
					{
					
					}
				;
				
simpleExpression	:	simpleExpression OR andExpresssion
					{
					
					}
				|	andExpresssion
					{
					
					}
				;
				
andExpresssion		:	andExpresssion AND unaryRelExpression
					{
					
					}
				|	unaryRelExpression
					{
					
					}
				;
				
unaryRelExpression	:	NOT unaryRelExpression
					{
					
					}
				|	relExpression
					{
					
					}
				;
				
relExpression		:	sumExpression relop sumExpression
					{
					
					}
				|	sumExpression
					{
					
					}
				;
				
relop			:	LESSEQ
					{
					
					}
				|	LTHAN
					{
					
					}
				|	GTHAN
					{
					
					}
				|	GRTEQ
					{
					
					}
				| 	EQ
					{
					
					}
				|	NOTEQ
					{
					
					}
				;
				
sumExpression		:	sumExpression sumop term
					{
					
					}
				|	term
					{
					
					}
				;
				
sumop			:	ADD
					{
					
					}
				|	MINUS
					{
					
					}
				;
				
term				:	term mulop unaryExpression
					{
					
					}
				|	unaryExpression
					{
					
					}
				;
				
mulop			:	STAR
					{
					
					}
				|	DIV
					{
					
					}
				|	PERCENT
					{
					
					}
				;
				
unaryExpression	:	unaryop unaryExpression
					{
					
					}
				|	factor
					{
					
					}
				;
				
unaryop			:	MINUS
					{
					
					}
				|	STAR
					{
					
					}
				|	QMARK
					{
					
					}
				;
				
factor			:	immutable
					{
					
					}
				|	mutable
					{
					
					}
				;

mutable			:	ID
					{
					
					}
				|	mutable LBRACKET expression RBRACKET
					{
					
					}
				|	mutable DOT ID
					{
					
					}
				;
				
immutable			:	LPAREN expression RPAREN
					{
					
					}
				|	call
					{
					
					}
				|	constant
					{
					
					}
				;
				
call				:	ID LPAREN args RPAREN
					{
					
					}
				;
	
args 			:	argList
					{
					
					}
				|	{
				
					}
	
argList			:	argList COMMA expression
					{
					
					}
				|	expression
					{
					
					}
				;
				
constant			:	NUMCONST
					{
					
					}
				|	CHARCONST
					{
					
					}
				|	BOOLCONST
					{
					
					}
				;
				
%%

int main(int argc, char** argv)
{
	int arg;
	
	while ((arg = getopt(argc, argv, "d")) != EOF)
	{
		switch (arg)
		{
			case 'd':
				yydebug = 1;
				break;
			default:
				printf("Invalid argument: %c", arg);
		}
	}
	
	if (argc >= 2)
	{
		FILE* inputFile = fopen(argv[argc - 1], "r");
		
		if (!inputFile)
		{
			printf("File '%s' not found.\n", argv[1]);
			return -1;
		}
		else
		{
			yyin = inputFile;
		}
	}
	
	do 
	{
		yyparse();
	} while (!feof(yyin));
	
	printf("Valid program");
	
	return 0;
}
