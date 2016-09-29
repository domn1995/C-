#include <cstdio>
#include <cstdlib>
#include "TreeNode.h"

static int indent = 0;
extern int yylineno;
static int childCount = 0;

void Indent()
{	
	for (int i = 0; i < indent; i++)
	{
		if (i % 4 == 0)
		{
			printf("!");
		}
		else
		{
			printf(" ");
		}
		
	}
}

void PrintTree(TreeNode* tree, int currSibling)
{
	bool printFlag = false;
	if (currSibling == -1)
	{
		currSibling++;
		printFlag = true;
	}
	else
	{
		indent += 4;
	}	
	
	for (TreeNode* t = tree; t != NULL; t = t->sibling)
	{
		Indent();
		
		if (currSibling >= 1)
		{
			int currSiblingCorrection = currSibling - 1;
			printf("Sibling: %d  ", currSiblingCorrection);
		}
		else if (currSibling == 0 && printFlag == false)
		{
			printf("Child: %d  ", childCount);
		}
		
		currSibling++;
		
		if (tree->nodeKind == StmtK)
		{				
			switch (tree->kind.stmt)
			{
				case IfK:
					printf("If ");
					break;
				case WhileK:
					printf("While ");
					break;
				case CompK:
					printf("Compound ");
					break;
				case ReturnK:
					printf("Return ");
					break;
				case BreakK:
					printf("Break ");
					break;
				default:
					printf("ERROR(%d): Unknown StmtKind node.\n", tree->lineNumber);
					break;
			}
		}
		else if (tree->nodeKind == ExpK)
		{
			switch (tree->kind.exp)
			{
				case AssignK:
					printf("Assign: %s ", tree->attr.name);
					break;
				case ConstK:
					printf("Const: ");
					switch (tree->expType)
					{
						case Int:
							printf("%i ", tree->attr.value);
							break;
						case Bool:
							tree->attr.value == 0 ? printf("false ") : printf("true ");
							break;
						case Char:
							printf("'%c' ", tree->attr.cValue);
							break;
						case Record:
							printf("record ");
							break;
						default:
							printf("ERROR(%d): Unknown ExpKind::ConstK node.\n", tree->lineNumber);
							break;
					}
					break;
				case IdK:
					printf("Id: %s ", tree->attr.name);
					break;
				case OpK:
					printf("Op: %s ", tree->attr.name);
					break;
				case CallK:
					printf("Call: %s", tree->attr.name);
					break;
				default:
					printf("ERROR(%s): Unknown ExpKind node.\n", tree->lineNumber);
					break;
			}
		}
		else if (tree->nodeKind == DeclK)
		{
			switch (tree->kind.decl)
			{
				case FuncK:
					printf("Func %s returns type ", tree->attr.name);
					break;
				case VarK:
					if (tree->isArray)
					{
						printf("Var %s is array of type ", tree->attr.name);
					}
					else
					{
						printf("Var %s of type ", tree->attr.name);
					}
					break;
				case ParamK:
					if (tree->isArray)
					{
						printf("Param %s is array of type ", tree->attr.name);
					}
					else
					{
						printf("Param %s of type ", tree->attr.name);
					}
					break;
				default:
					printf("ERROR(%d): Unknown DeclKind node.\n", tree->lineNumber);
					break;
			}
			switch (tree->expType)
			{
				case Void:
					printf("void ");
					break;
				case Int:
					printf("int ");
					break;
				case Bool:
					printf("bool ");
					break;
				case Char:
					printf("char ");
					break;
				case Record:
					printf("record ");
					break;
				default:
					printf("ERROR(%d): Unknown ExpType node.\n", tree->lineNumber);
					break;
			}
		}
		else
		{
			printf("ERROR(%d): Unknown NodeKind.\n", tree->lineNumber);
		}
		
		printf("[line: %d]\n", tree->lineNumber);
		
		for (int i = 0; i < MAXCHILDREN; i++)
		{
			childCount = i;
			PrintTree(t->children[i], 0);
			childCount = 0;
		}		
	}
	
	indent -= 4;
}

void InitializeNodes(TreeNode* treeNode)
{
	for (int i = 0; i < MAXCHILDREN; i++)
	{
		treeNode->children[i] = NULL;
	}
	treeNode->sibling = NULL;
}

TreeNode* NewDeclNode(DeclKind kind)
{
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	if (t == NULL)
	{
		printf("NewDeclNode(): Failed to allocate memory for TreeNode.\n");
	}
	else
	{
		InitializeNodes(t);
		t->nodeKind = DeclK;
		t->kind.decl = kind;
		t->lineNumber = yylineno;
	}
	return t;
}

TreeNode* NewStmtNode(StmtKind kind)
{
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	if (t == NULL)
	{
		printf("NewStmtNode(): Failed to allocate memory for TreeNode.\n");
	}
	else
	{
		InitializeNodes(t);
		t->nodeKind = StmtK;
		t->kind.stmt = kind;
		t->lineNumber = yylineno;
	}	
	return t;
}

TreeNode* NewExprNode(ExpKind kind)
{
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	if (t == NULL)
	{
		printf("NewExprNode(): Failed to allocate memory for TreeNode.\n");
	}
	else
	{
		InitializeNodes(t);
		t->nodeKind = ExpK;
		t->kind.exp = kind;
		t->lineNumber = yylineno;
	}
	return t;
}

