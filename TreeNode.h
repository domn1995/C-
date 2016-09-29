#ifndef TREENODEH
#define TREENODEH

#define MAXCHILDREN 3

typedef enum 
{
	DeclK, StmtK, ExprK
} NodeKind;

typedef enum
{
	FuncK, VarK, ParamK
} DeclKind;

typedef enum 
{
	IfK, ForK, WhileK, CompK, ReturnK, BreakK
} StmtKind;

typedef enum
{
	ConstK, IdK, OpK, AssignK, SimpK, CallK
} ExpKind;

typedef enum
{
	Void, Int, Bool, Char
} ExpType;

typedef struct TreeNode
{
public:	
	TreeNode* children[MAXCHILDREN];
	TreeNode* sibling;

	int lineNumber;
	NodeKind nodeKind;
	
	union
	{
		DeclKind decl;
		StmtKind stmt;
		ExpKind exp;
	} kind;
	
	union
	{
		int value;
		unsigned char cValue;
		char* str;
		char* name;
	} attr;
	
	ExpType expType;
	bool isArray;
	bool isRecord;
	bool isStatic;
} TreeNode;


#endif
