#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
#include "TreeNode.h"

static int indent = 0;
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

void PrintMemInfo(TreeNode* node)
{
	if (node->nodeKind == StmtK && node->kind.stmt != CompK)
	{
		// There's no mem info to print for statements or calls.
		return;
	}
	else if (node->nodeKind == ExpK)
	{
		switch (node->kind.exp)
		{
			// There's no mem info for the following expression types:
			case AssignK:
			case CallK:
			case ConstK:
			case OpK:
				return;
		}
	}

	printf("[ref: ");

	if (node->nodeKind == DeclK && node->kind.decl == ParamK)
	{		
		printf("Param, ");		
	}
	else if (node->nodeKind == ExpK && node->kind.exp == CallK || node->nodeKind == StmtK && node->kind.stmt == CompK)	
	{
		printf("None, ");
	}
	else if (node->isStatic)
	{
		printf("Static, ");
	}
	else
	{
		printf(node->isGlobal ? "Global, " : "Local, ");
	}

	printf("size: %d, loc: %d] ", node->memSize, node->memOffset);
}

void PrintSyntaxTree(TreeNode* t, int currSibling, bool annotated)
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
	
	for (TreeNode* tree = t; tree != NULL; tree = tree->sibling)
	{
		Indent();
		
		if (currSibling >= 1)
		{			
			printf("Sibling: %d  ", currSibling - 1);
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
					printf("If  ");
					break;
				case WhileK:
					printf("While  ");
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
					if (tree->isArray)
					{
						printf("is array ");
					}
					break;
				case OpK:
					printf("Op: %s ", tree->attr.name);
					break;
				case CallK:
					printf("Call: %s ", tree->attr.name);
					break;
				default:
					printf("ERROR(%d): Unknown ExpKind node.\n", tree->lineNumber);
					break;
			}
		}
		else if (tree->nodeKind == DeclK)
		{
			switch (tree->kind.decl)
			{
				case FuncK:
					printf("Func %s ", tree->attr.name);
					break;
				case VarK:
					if (tree->isRecord)
					{
						printf("Record %s ", tree->attr.name);
					}
					else if (tree->isArray)
					{
						printf("Var: %s is array ", tree->attr.name);
					}
					else
					{
						printf("Var: %s ", tree->attr.name);
					}

					break;
				case ParamK:
					if (tree->isArray)
					{
						printf("Param %s is array ", tree->attr.name);
					}
					else
					{
						printf("Param %s ", tree->attr.name);
					}

					break;
				default:
					printf("ERROR(%d): Unknown DeclKind node.\n", tree->lineNumber);
					break;
			}
			// switch (tree->expType)
			// {
			// 	case Void:
			// 		if (!tree->isRecord)
			// 		{
			// 			printf("void ");
			// 		}					
			// 		break;
			// 	case Int:
			// 		printf("int ");
			// 		break;
			// 	case Bool:
			// 		printf("bool ");
			// 		break;
			// 	case Char:
			// 		printf("char ");
			// 		break;
			// 	case Record:
			// 		printf("record ");
			// 		break;
			// 	default:
			// 		printf("ERROR(%d): Unknown ExpType node.\n", tree->lineNumber);
			// 		break;
			// }
		}
		else
		{
			printf("ERROR(%d): Unknown NodeKind.\n", tree->lineNumber);
		}

		PrintMemInfo(tree);
		
		if (annotated)
		{
			if (tree->expType == Undefined)
			{
				printf("[undefined type] ");
			}
			else
			{
				printf("[type %s] ", ExpTypeToString(tree->expType));
			}			
		}
		
		printf("[line: %d]\n", tree->lineNumber);
		
		for (int i = 0; i < MAXCHILDREN; i++)
		{
			childCount = i;
			PrintSyntaxTree(tree->children[i], 0, annotated);
			childCount = 0;
		}
	}
	
	indent -= 4;
}