#ifndef SEMANTICH
#define SEMANTICH
#include "TreeNode.h"
#include <string>

typedef enum
{
	SimpleVariableCall,
	BinaryOperandLhsTypeMismatch,
	BinaryOperandRhsTypeMismatch,
	BinaryOperandLhsRhsTypeMismatch,
	ArrayIndexTypeNotInt,
	ArrayIndexUnindexedArray,
	IndexNonArrayKnown,
	IndexNonArrayUnknown,
	ReturnArray,
	UseFunctionAsVariable,
	SymbolAlreadyDefined,
	SymbolUndefined,
	FunctionUndefined,
	InvalidArrayOperation,
	ArrayOnlyOperation,
	UnaryOperandTypeMismatch,
	ExpectedBooleanCondition,
	ReturnTypeMismatch,
	UnexpectedReturnType,
	ExpectedReturnTypeNotPresent,
	BreakOutsideOfLoop,
	InitializerNotConstant,
	InitializationTypeMismatch,
	MissingReturnStatementWarning,
	FuncCallParamTypeMismatch,
	ExpectingArrayParam,
	NotExpectingArrayParam,
	TooFewCallParams,
	TooManyCallParams,
	ArrayAsTestCondition,
	MainUndefined,
} ErrorCode;

typedef struct Error
{
public:
	ErrorCode errorCode;
	int errorLineNumber;
	int expressionLineNumber;
	char* context0;
	char* context1;
	char* context2;
	char* context3;
} Error;

enum BinaryOp
{
	AddOp,
	SubOp,
	MulOp,
	DivOp,
	ModOp,
	AddAssOp,
	SubAssOp,
	MulAssOp,
	DivAssOp,
	LsThanOp,
	GrThanOp,
	LsEqOp,
	GrtEqOp,
	EqOp,
	NotEqOp,
	AssignOp,
	IndexOp,
	AndOp,
	OrOp,
	UnknownBOp
};

enum UnaryOp
{
	IncOp,
	DecOp,
	NegOp,
	NotOp,
	StarOp,
	QMarkOp,
	UnknownUOp
};

void SemanticAnalysis(TreeNode* tree, int& numErrors, int& numWarnings);
void ScopeAndType(TreeNode* node, int& numErrors, int& numWarnings);
void ParseDeclNode(TreeNode* node, int& numErrors, int& numWarnings);
void ParseStmtNode(TreeNode* node, int& numErrors, int& numWarnings);
void ParseExprNode(TreeNode* node, int& numErrors, int& numWarnings);
void TypeCheck(char* op, bool isBinary, bool& oneSidedErrors, ExpType& left, ExpType& right, ExpType& ret);
BinaryOp BinaryOpStringSwitcher(std::string const str);
UnaryOp UnaryOpStringSwitcher(std::string const str);
void PrintError(Error error, int& numErrors, int& numWarnings);
void AttachIOLib(TreeNode*& treeNode);

#endif