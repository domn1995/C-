#include <cstdio>
#include <cstdlib>
#include "TreeNode.h"

extern int yylineno;

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