#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "TreeNode.h"

extern int yylineno;

void InitializeChildrenNodes(TreeNode* treeNode)
{
	for (int i = 0; i < MAXCHILDREN; i++)
	{
		treeNode->children[i] = NULL;
	}
	treeNode->sibling = NULL;
}

TreeNode* NewDeclNode(DeclKind kind)
{
	TreeNode* t = static_cast<TreeNode*>(malloc(sizeof(TreeNode)));
	
	if (t == NULL)
	{
		printf("NewDeclNode(): Failed to allocate memory for TreeNode.\n");
	}
	else
	{
		InitializeChildrenNodes(t);
		t->nodeKind = DeclK;
		t->kind.decl = kind;
		t->lineNumber = yylineno;
		t->isIO = false;
	}
	
	return t;
}

TreeNode* NewStmtNode(StmtKind kind)
{
	TreeNode* t = static_cast<TreeNode*>(malloc(sizeof(TreeNode)));
	
	if (t == NULL)
	{
		printf("NewStmtNode(): Failed to allocate memory for TreeNode.\n");
	}
	else
	{
		InitializeChildrenNodes(t);
		t->nodeKind = StmtK;
		t->kind.stmt = kind;
		t->lineNumber = yylineno;
		t->isIO = false;
	}	
	
	return t;
}

TreeNode* NewExprNode(ExpKind kind)
{
	TreeNode* t = static_cast<TreeNode*>(malloc(sizeof(TreeNode)));
	
	if (t == NULL)
	{
		printf("NewExprNode(): Failed to allocate memory for TreeNode.\n");
	}
	else
	{
		InitializeChildrenNodes(t);
		t->nodeKind = ExpK;
		t->kind.exp = kind;	
		t->lineNumber = yylineno;
		t->isIO = false;
	}
	
	return t;
}

char* ExpTypeToString(ExpType expType)
{
	switch (expType)
	{
		case Void:
			return strdup("void");
		case Int:
			return strdup("int");
		case Bool:
			return strdup("bool");
		case Char:
			return strdup("char");
		case Record:
			return strdup("record");
		case Undefined:
			return strdup("undefined");
		case IntOrChar:
			return strdup("char or type int");
		default:
			return strdup("UNKNOWN_TYPE");
	}
}