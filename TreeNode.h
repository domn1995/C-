#ifndef TREENODEH
#define TREENODEH

#define MAXCHILDREN 3

typedef enum 
{
	DeclK, StmtK, ExpK
} NodeKind;

typedef enum
{
	FuncK, VarK, ParamK
} DeclKind;

typedef enum 
{
	IfK, WhileK, CompK, ReturnK, BreakK
} StmtKind;

typedef enum
{
	AssignK, ConstK, IdK, OpK, CallK
} ExpKind;

typedef enum
{
	Void, Int, Bool, Char, Record, IntOrChar, Undefined
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
	bool isConst;
	bool isGlobal;
	bool isIO;
	int arrayLength;
	int memSize;
	int memOffset;
} TreeNode;

void InitializeChildrenNodes(TreeNode* treeNode);
TreeNode* NewDeclNode(DeclKind kind);
TreeNode* NewStmtNode(StmtKind kind);
TreeNode* NewExprNode(ExpKind kind);
char* ExpTypeToString(ExpType expType);

#endif