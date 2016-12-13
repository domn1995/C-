%{
#include <string>
#include <iostream>
#include <cstdio>
#include <getopt.h>
#include "Token.h"
#include "TreeNode.h"
#include "SymbolTable.h"
#include "PrintTree.h"
#include "Semantic.h"
#include "YyError.h"
#include "CodeGen.h"

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
%}

%union 
{
    Token t;
    TreeNode* treeNode;
    ExpType expType;
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
				andExpression
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
%type <t>			relop
				sumop
				mulop
				unaryop
				
				// Types
%type <expType>	typeSpecifier
				returnTypeSpecifier

%%
program				: 	declarationList
						{
							savedTree = $1;
						}
					;

declarationList		: 	declarationList declaration
						{
							TreeNode* t = $1;
							if (t != NULL)
							{
								while (t->sibling != NULL)
								{
									t = t->sibling;
								}
								t->sibling = $2;
								$$ = $1;
							}
							else
							{
								$$ = $2;
							}
						}
					| 	declaration
						{
							$$ = $1;
						}
					;

declaration 		: 	varDeclaration
						{
							$$ = $1;
						}
					|	funDeclaration
						{
							$$ = $1;
						}
					|	recDeclaration
						{
							$$ = $1;
						}
					|	error
						{
							$$ = NULL;
						}
					;
				
// Variable Declarations

recDeclaration		: 	RECORD ID LCURLY localDeclarations RCURLY
						{
							// We need to add the user-defined type to the global symbol table.
							globalScope.insert($2.tokenStr, static_cast<char*>("recordType"));
						
							$$ = NewDeclNode(VarK);
							$$->lineNumber = $1.lineNum;
							$$->attr.name = $2.tokenStr;
							$$->isRecord = true;
							$$->children[0] = $4;						
						}
					;

varDeclaration		: 	typeSpecifier varDeclList SEMICOLON
						{
							yyerrok;
							TreeNode* t = $2;
							if (t != NULL)
							{
								do
								{
									t->expType = $1;
									t = t->sibling;
								}
								while (t != NULL);
								$$ = $2;
							}
							else
							{
								$$ = NULL;
							}
						}
					|	error varDeclList SEMICOLON
						{
							$$ = NULL;
						}
					|	typeSpecifier error SEMICOLON
						{
							yyerrok;
							$$ = NULL;
						}
					|	error SEMICOLON
						{
							yyerrok;
							$$ = NULL;
						}
					;
				
scopedVarDeclaration:	scopedTypeSpecifier varDeclList SEMICOLON
						{
							yyerrok;
							TreeNode* t = $2;
							if (t != NULL)
							{
								do
								{
									t->expType = $1->expType;
									t->isRecord = $1->isRecord;
									t->isStatic = $1->isStatic;
									t = t->sibling;
								}
								while (t != NULL);
								$$ = $2;
							}
							else
							{
								$$ = NULL;
							}
						}
					|	error
						{
							yyerrok;
							$$ = NULL;
						}
					|	scopedTypeSpecifier error
						{
							$$ = NULL;
						}
					;
				
varDeclList			:	varDeclList COMMA varDeclInitialize 
						{
							yyerrok;
							TreeNode* t = $1;
							if (t != NULL)
							{
								while (t->sibling != NULL)
								{
									t = t->sibling;
								}
								t->sibling = $3;
								$$ = $1;
							}
							else
							{
								$$ = $3;
							}
						}
					|	varDeclInitialize 
						{
							$$ = $1;
						}
					|	varDeclList COMMA error
						{
							$$ = NULL;
						}
					|	error
						{
							$$ = NULL;
						}
					;
				
varDeclInitialize	: 	varDeclId
						{
							$$ = $1;
						}
					|	varDeclId COLON simpleExpression
						{
							$1->children[0] = $3;
							$$ = $1;
						}
					|	error COLON simpleExpression
						{
							yyerrok;
							$$ = NULL;
						}
					|	varDeclId COLON error
						{
							$$ = NULL;
						}
					;
				
varDeclId			:	ID
						{
							$$ = NewDeclNode(VarK);
							$$->lineNumber = $1.lineNum;
							$$->attr.name = $1.tokenStr;
						}
					|	ID LBRACKET NUMCONST RBRACKET
						{
							$$ = NewDeclNode(VarK);
							$$->attr.name = $1.tokenStr;
							$$->lineNumber = $1.lineNum;
							$$->isArray = true;
							$$->arrayLength = $3.intVal;
						}
					|	ID LBRACKET error
						{
							$$ = NULL;
						}
					|	error RBRACKET
						{
							yyerrok;
							$$ = NULL;
						}
					;
				
scopedTypeSpecifier :	STATIC typeSpecifier
						{
							$$ = NewDeclNode(VarK);
							$$->isStatic = true;
							$$->expType = $2;
							if ($2 == Record)
							{
								$$->isRecord = true;
							}
						}
					| 	typeSpecifier
						{
							$$ = NewDeclNode(VarK);						
							$$->expType = $1;
						}
					;
				
typeSpecifier		: 	returnTypeSpecifier
						{
							$$ = $1;
						}
					|	RECTYPE
						{	
							$$ = Record;
						}
					;
				
returnTypeSpecifier :	INT
						{
							$$ = Int;
						}
					|	BOOL
						{
							$$ = Bool;
						}
					|	CHAR
						{
							$$ = Char;
						}
					;
				
// Function Declarations

funDeclaration		:	typeSpecifier ID LPAREN params RPAREN statement
						{
							$$ = NewDeclNode(FuncK);
							$$->expType = $1;
							$$->attr.name = $2.tokenStr;
							$$->children[0] = $4;
							$$->children[1] = $6;
							// Sets the line number where the function declaration starts.
							$$->lineNumber = $2.lineNum; 
						}
					|	ID LPAREN params RPAREN statement
						{
							$$ = NewDeclNode(FuncK);
							$$->expType = Void;
							$$->attr.name = $1.tokenStr;
							$$->children[0] = $3;
							$$->children[1] = $5;
							// Sets the line number where the function call starts.
							$$->lineNumber = $1.lineNum;
						}
					|	typeSpecifier error
						{
							$$ = NULL;
						}
					|	typeSpecifier ID LPAREN error
						{
							$$ = NULL;
						}
					|	typeSpecifier ID LPAREN params RPAREN error
						{
							$$ = NULL;
						}
					|	ID LPAREN error
						{
							$$ = NULL;
						}
					|	ID LPAREN params RPAREN error
						{
							$$ = NULL;
						}
					;
				
params				:	paramList 
						{ 
							$$ = $1;
						}
					|	{
							$$ = NULL;
						}
					;
				
paramList			: 	paramList SEMICOLON paramTypeList
						{
							yyerrok;
							TreeNode* t = $1;
							if (t != NULL)
							{
								while (t->sibling != NULL)
								{
									t = t->sibling;
								}
								t->sibling = $3;
								$$ = $1;
							}
							else
							{
								$$ = $3;
							}
						}
					|	paramTypeList
						{
							$$ = $1;
						}
					|	paramList SEMICOLON error
						{
							yyerrok;
							$$ = NULL;
						}
					|	error
						{
							$$ = NULL;
						}
					;

paramTypeList		: 	typeSpecifier paramIdList
						{
							TreeNode* t = $2;
							if (t != NULL)
							{
								do
								{
									t->expType = $1;
									t = t->sibling;
								}
								while (t != NULL);
								$$ = $2;
							}
							else
							{
								$$ = NULL;
							}
						}
					|	typeSpecifier error
						{
							$$ = NULL;
						}
					;
				
paramIdList		:	paramIdList COMMA paramId
					{
						yyerrok;
						TreeNode* t = $1;
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							
							t->sibling = $3;
							$$ = $1;
						}
						else
						{
							$$ = $3;
						}
					}
				|	paramId
					{
						$$ = $1;
					}
				|	paramIdList COMMA error
					{
						$$ = NULL;
					}
				|	error
					{
						$$ = NULL;
					}
				;
				
paramId			:	ID
					{
						$$ = NewDeclNode(ParamK);
						$$->attr.name = $1.tokenStr;
					}
				|	ID LBRACKET RBRACKET
					{
						$$ = NewDeclNode(ParamK);
						$$->attr.name = $1.tokenStr;
						$$->isArray = true;
					}
				|	error RBRACKET
					{
						yyerrok;
						$$ = NULL;
					}
				;
				
// Statements

statement			:	matched
						{
							$$ = $1;
						}
					|	unmatched
						{
							$$ = $1;
						}
					;

matched				:	selectionStmtMatched
						{
							$$ = $1;
						}
					|	iterationStmtMatched
						{
							$$ = $1;
						}
					|	expressionStmt
						{
							$$ = $1;
						}
					|	compoundStmt
						{
							$$ = $1;
						}
					|	returnStmt
						{
							$$ = $1;
						}	
					|	breakStmt
						{
							$$ = $1;
						}
					;
				
unmatched			:	selectionStmtUnmatched
						{
							$$ = $1;
						}
					|	iterationStmtUnmatched
						{
							$$ = $1;
						}
					;
				
compoundStmt		:	LCURLY localDeclarations statementList RCURLY
						{
							yyerrok;
							$$ = NewStmtNode(CompK);
							$$->children[0] = $2;
							$$->children[1] = $3;
							$$->lineNumber = $1.lineNum;
						}
					|	LCURLY error statementList RCURLY
						{
							yyerrok;
							$$ = NULL;
						}
					|	LCURLY localDeclarations error RCURLY
						{
							yyerrok;
							$$ = NULL;
						}
					;
			
localDeclarations	:	localDeclarations scopedVarDeclaration
						{
							TreeNode* t = $1;
							if (t != NULL)
							{
								while (t->sibling != NULL)
								{
									t = t->sibling;
								}
								t->sibling = $2;
								$$ = $1;
							}
							else
							{
								$$ = $2;
							}
						}
					|	{
							$$ = NULL;
						}
					;
				
statementList		:	statementList statement
						{
							TreeNode* t = $1;
							if (t != NULL)
							{
								while (t->sibling != NULL)
								{
									t = t->sibling;
								}
								t->sibling = $2;
								$$ = $1;
							}
							else
							{
								$$ = $2;
							}
						}
					|	{
							$$ = NULL;
						}
					;
			
expressionStmt		:	expression SEMICOLON
						{
							yyerrok;
							$$ = $1;
						}
					|	SEMICOLON
						{
							yyerrok;
							$$ = NULL;
						}
					;
				
selectionStmtMatched:	IF LPAREN simpleExpression RPAREN matched ELSE matched
						{
							$$ = NewStmtNode(IfK);
							$$->attr.name = $1.tokenStr;
							$$->children[0] = $3;
							$$->children[1] = $5;
							$$->children[2] = $7;
							$$->lineNumber = $1.lineNum;
						}
					|	IF LPAREN error	
						{
							$$ = NULL;
						}
					|	IF error RPAREN matched ELSE matched
						{
							yyerrok;
							$$ = NULL;
						}
					|	error
						{
							$$ = NULL;
						}
					;
				
selectionStmtUnmatched:	IF LPAREN simpleExpression RPAREN matched ELSE unmatched
						{
							$$ = NewStmtNode(IfK);
							$$->attr.name = $1.tokenStr;
							$$->children[0] = $3;
							$$->children[1] = $5;
							$$->children[2] = $7;
							$$->lineNumber = $1.lineNum;
						}
					|
						IF LPAREN simpleExpression RPAREN statement
						{
							$$ = NewStmtNode(IfK);
							$$->attr.name = $1.tokenStr;
							$$->children[0] = $3;
							$$->children[1] = $5;
							$$->lineNumber = $1.lineNum;
						}
					|	IF error
						{
							$$ = NULL;
						}
					|	IF error RPAREN statement
						{
							yyerrok;
							$$ = NULL;
						}
					|	IF error RPAREN matched ELSE unmatched
						{
							yyerrok;
							$$ = NULL;
						}
					;
				
iterationStmtMatched:	WHILE LPAREN simpleExpression RPAREN matched
						{
							$$ = NewStmtNode(WhileK);
							$$->attr.name = $1.tokenStr;
							$$->children[0] = $3;
							$$->children[1] = $5;
							$$->lineNumber = $1.lineNum;
						}
					|	WHILE error RPAREN matched
						{
							yyerrok;
							$$ = NULL;
						}
					|	WHILE LPAREN error RPAREN matched
						{
							yyerrok;
							$$ = NULL;
						}
					|	WHILE error
						{
							$$ = NULL;
						}
					|	error
						{
							$$ = NULL;
						}
					;
				
iterationStmtUnmatched:	WHILE LPAREN simpleExpression RPAREN unmatched
						{
							$$ = NewStmtNode(WhileK);
							$$->attr.name = $1.tokenStr;
							$$->children[0] = $3;
							$$->children[1] = $5;
							$$->lineNumber = $1.lineNum;
						}
					|	WHILE error RPAREN unmatched
						{
							yyerrok;
							$$ = NULL;
						}
					|	WHILE LPAREN error RPAREN unmatched
						{
							yyerrok;
							$$ = NULL;
						}
					;
				
returnStmt			:	RETURN SEMICOLON
						{
							yyerrok;
							$$ = NewStmtNode(ReturnK);
							$$->attr.name = $1.tokenStr;
							$$->lineNumber = $1.lineNum;
						}
					|	RETURN expression SEMICOLON
						{
							yyerrok;
							$$ = NewStmtNode(ReturnK);
							$$->attr.name = $1.tokenStr;
							$$->lineNumber = $1.lineNum;
							$$->children[0] = $2;
						}
					;
				
breakStmt			:	BREAK SEMICOLON
						{
							yyerrok;
							$$ = NewStmtNode(BreakK);
							$$->attr.name = $1.tokenStr;
						}
					;
				
// Expressions

expression		: 	mutable ASSIGN expression
					{
						$$ = NewExprNode(AssignK);
						$$->lineNumber = $2.lineNum;
						$$->attr.name = $2.tokenStr;
						$$->children[0] = $1;
						$$->children[1] = $3;
					}
				|	mutable ADDASS expression
					{
						$$ = NewExprNode(AssignK);
						$$->lineNumber = $2.lineNum;
						$$->attr.name = $2.tokenStr;
						$$->children[0] = $1;
						$$->children[1] = $3;
					}
				|	mutable SUBASS expression
					{
						$$ = NewExprNode(AssignK);
						$$->lineNumber = $2.lineNum;
						$$->attr.name = $2.tokenStr;
						$$->children[0] = $1;
						$$->children[1] = $3;
					}
				|	mutable MULASS expression
					{
						$$ = NewExprNode(AssignK);
						$$->lineNumber = $2.lineNum;
						$$->attr.name = $2.tokenStr;
						$$->children[0] = $1;
						$$->children[1] = $3;
					}
				|	mutable DIVASS expression
					{
						$$ = NewExprNode(AssignK);
						$$->lineNumber = $2.lineNum;
						$$->attr.name = $2.tokenStr;
						$$->children[0] = $1;
						$$->children[1] = $3;
					}
				|	mutable INC
					{
						yyerrok;
						$$ = NewExprNode(AssignK);
						$$->lineNumber = $2.lineNum;
						$$->attr.name = $2.tokenStr;
						$$->children[0] = $1;
					}
				|	mutable DEC
					{
						yyerrok;
						$$ = NewExprNode(AssignK);
						$$->lineNumber = $2.lineNum;
						$$->attr.name = $2.tokenStr;
						$$->children[0] = $1;
					}
				|	simpleExpression
					{
						$$ = $1;
					}
				|	error ASSIGN error
					{
						$$ = NULL;
					}
				|	error ADDASS error
					{
						$$ = NULL;
					}
				|	error SUBASS error
					{
						$$ = NULL;
					}
				|	error MULASS error
					{
						$$ = NULL;
					}
				|	error DIVASS error
					{
						$$ = NULL;
					}
				|	error INC
					{
						yyerrok;
						$$ = NULL;
					}
				|	error DEC
					{
						yyerrok;
						$$ = NULL;
					}
				;
				
simpleExpression	:	simpleExpression OR andExpression
						{
							$$ = NewExprNode(OpK);
							$$->attr.name = $2.tokenStr;
							$$->lineNumber = $2.lineNum;
							$$->isConst = $1->isConst && $3->isConst;
							$$->children[0] = $1;
							$$->children[1] = $3;
						}
					|	andExpression
						{
							$$ = $1;
						}
					|	error OR andExpression
						{
							yyerrok;
							$$ = NULL;
						}
					|	simpleExpression OR error
						{
							$$ = NULL;
						}
					|	error OR error
						{
							$$ = NULL;
						}
					;
				
andExpression		:	andExpression AND unaryRelExpression
						{
							$$ = NewExprNode(OpK);
							$$->lineNumber = $2.lineNum;
							$$->attr.name = $2.tokenStr;
							$$->isConst = $1->isConst && $3->isConst;
							$$->children[0] = $1;
							$$->children[1] = $3;
						}
					|	unaryRelExpression
						{
							$$ = $1;
						}
					|	error AND unaryRelExpression
						{
							yyerrok;
							$$ = NULL;
						}
					|	andExpression AND error
						{
							$$ = NULL;
						}
					|	error AND error
						{
							$$ = NULL;
						}
					;
				
unaryRelExpression	:	NOT unaryRelExpression
						{
							$$ = NewExprNode(OpK);
							$$->attr.name = $1.tokenStr;
							$$->isConst = $2->isConst;
							$$->children[0] = $2;
						}
					|	relExpression
						{
							$$ = $1;
						}
				;
				
relExpression		:	sumExpression relop sumExpression
						{
							$$ = NewExprNode(OpK);
							$$->attr.name = $2.tokenStr;
							$$->lineNumber = $2.lineNum;
							$$->isConst = $1->isConst && $3->isConst;
							$$->children[0] = $1;
							$$->children[1] = $3;
						}
					|	sumExpression
						{
							$$ = $1;
						}
					|	sumExpression relop error
						{
							$$ = NULL;
						}
					|	error relop sumExpression
						{
							yyerrok;
							$$ = NULL;
						}
					|	error relop error
						{
							$$ = NULL;
						}
					;
				
relop			:	LESSEQ
					{
						$$ = $1;
					}
				|	LTHAN
					{
						$$ = $1;
					}
				|	GTHAN
					{
						$$ = $1;
					}
				|	GRTEQ
					{
						$$ = $1;
					}
				| 	EQ
					{
						$$ = $1;
					}
				|	NOTEQ
					{
						$$ = $1;
					}
				;
				
sumExpression		:	sumExpression sumop term
						{
							$$ = NewExprNode(OpK);
							$$->attr.name = $2.tokenStr;
							$$->lineNumber = $2.lineNum;
							$$->isConst = $1->isConst && $3->isConst;
							$$->children[0] = $1;
							$$->children[1] = $3;
						}
					|	term
						{
							$$ = $1;
						}
					|	sumExpression sumop error
						{
							yyerrok;
							$$ = NULL;
						}
					|	error sumop term
						{
							yyerrok;
							$$ = NULL;
						}
					|	error sumop error
						{
							$$ = NULL;
						}
					;
				
sumop			:	ADD
					{
						$$ = $1;
					}
				|	MINUS
					{
						$$ = $1;
					}
				;
				
term				:	term mulop unaryExpression
					{
						$$ = NewExprNode(OpK);
						$$->attr.name = $2.tokenStr;
						$$->lineNumber = $2.lineNum;
						$$->children[0] = $1;
						$$->children[1] = $3;
						$$->isConst = $1->isConst && $3->isConst;
					}
				|	unaryExpression
					{
						$$ = $1;
					}
				;
				
mulop			:	STAR
					{
						$$ = $1;
					}
				|	DIV
					{
						$$ = $1;
					}
				|	PERCENT
					{
						$$ = $1;
					}
				;
				
unaryExpression	:	unaryop unaryExpression
					{
						$$ = NewExprNode(OpK);
						$$->attr.name = $1.tokenStr;
						$$->lineNumber = $1.lineNum;
						$$->children[0] = $2;
						$$->isConst = $1.isConst && $2->isConst;
					}
				|	factor
					{
						$$ = $1;
					}
				;
				
unaryop			:	MINUS
					{
						$$ = $1;
						$$.isConst = true;
					}
				|	STAR
					{
						$$ = $1;
					}
				|	QMARK
					{
						$$ = $1;
					}
				;
				
factor			:	immutable
					{
						$$ = $1;
					}
				|	mutable
					{
						$$ = $1;
					}
				;

mutable			:	ID
					{
						$$ = NewExprNode(IdK);
						$$->attr.name = $1.tokenStr;
					}
				|	mutable LBRACKET expression RBRACKET
					{
						$$ = NewExprNode(OpK);
						$$->attr.name = $2.tokenStr;
						
						$$->children[0] = $1;						
						$$->children[1] = $3;
					}
				|	mutable DOT ID
					{
						$$ = NewExprNode(OpK);
						$$->attr.name = $2.tokenStr;
						$$->children[0] = $1;
						
						TreeNode* t = NewExprNode(IdK);
						t->attr.name = $3.tokenStr;
						$$->children[1] = t;
					}
				;
				
immutable			:	LPAREN expression RPAREN
						{
							yyerrok;
							$$ = $2;
						}
					|	call
						{
							$$ = $1;
						}
					|	constant
						{
							$$ = $1;
						}
					|	LPAREN error
						{
							$$ = NULL;
						}
					|	error RPAREN
						{
							yyerrok;
							$$ = NULL;
						}
					;
				
call				:	ID LPAREN args RPAREN
						{
							yyerrok;
							$$ = NewExprNode(CallK);
							$$->lineNumber = $1.lineNum;
							$$->attr.name = $1.tokenStr;
							$$->children[0] = $3;
						}
					|	error LPAREN
						{
							$$ = NULL;
						}
					;
	
args 			:	argList
					{
						$$ = $1;
					}
				|	{
						$$ = NULL;
					}
	
argList			:	argList COMMA expression
					{
						yyerrok;
						TreeNode* t = $1;
						if (t != NULL)
						{
							while (t->sibling != NULL)
							{
								t = t->sibling;
							}
							t->sibling = $3;
							$$ = $1;
						}
						else
						{
							$$ = $3;
						}
					}
				|	expression
					{
						$$ = $1;
					}
				|	argList COMMA error
					{
						$$ = NULL;
					}
				;
				
constant			:	NUMCONST
						{
							$$ = NewExprNode(ConstK);
							$$->isConst = true;
							$$->attr.value = $1.intVal;
							$$->expType = Int;
						}
					|	CHARCONST
						{
							$$ = NewExprNode(ConstK);
							$$->isConst = true;
							$$->attr.cValue = $1.charVal;
							$$->expType = Char;
						}
					|	BOOLCONST
						{
							$$ = NewExprNode(ConstK);
							$$->isConst = true;
							$$->attr.value = $1.intVal;
							$$->expType = Bool;
						}
					;
				
%%

int main(int argc, char** argv)
{
	int arg;
	bool argFound;
	
	bool printAbstractSyntaxTree = false;
	bool printAnnotatedSyntaxTree = false;	

	char* inFilePath = NULL;
	char* outFilePath = NULL;

	InitErrorProcessing();
	
	while ((arg = getopt(argc, argv, "dpPo:0")) != EOF)
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
			case 'o':
				outFilePath = optarg;
				break;
			case '0': // Case '0' does nothing.
				break;
			default:
				printf("Invalid argument: %s", argv[optind]);
				return -1;
		}
	}	
	
	if (argc >= 2)
	{
		FILE* inputFile = fopen(argv[argc - 1], "r");
		inFilePath = argv[argc - 1];
		
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
			printf("Offset for end of global space: %d\n", globalOffset);
		}		
	}	
	
	printf("Number of warnings: %d\n", numWarnings);
	printf("Number of errors: %d\n", numErrors);

	if (numErrors == 0)
	{
		std::string outFile;
		if (outFilePath == NULL)
		{
			outFile = inFilePath;
			// Handles files in another directory.
			while (outFile.find("/", 0) != std::string::npos)
			{
				outFile = outFile.substr(outFile.find("/", 0) + 1, outFile.length());
			}
			// Removes "c-" extension and appends "tm".
			outFile = outFile.substr(0, outFile.length() - 2);
			outFile += "tm";
		}
		else
		{
			outFile = outFilePath;
		}
		GenerateCode(savedTree, inFilePath, (char*)outFile.c_str());
	}
	
	return 0;
}