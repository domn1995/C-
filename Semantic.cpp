#include "Semantic.h"
#include "SymbolTable.h"
#include "Utils.h"
#include <string.h>

SymbolTable symbolTable;
// Tracks whether we entered a function scope in order to handle
// not creating a new scope on the compound statement.
bool enteredFunctionScope = false;
TreeNode* currentFunction = NULL;
bool returnStatementFound = false;
bool insideLoop = false;
int loopDepth = 1;

std::string binaryOps[19] = { "+", "-", "*", "/", "%", "+=", "-=", "*=", "/=",
	"<", ">", "<=", ">=", "==", "!=", "=", "[",
	"and", "or" };

std::string unaryOps[6] = { "++", "--", "-", "not", "*", "?" };

void AttachIOLib(TreeNode*& treeNode)
{
	// The return types, identifiers, and parameter types for the IO functions.
	ExpType funcRetVals[] = { Void,      Void,      Void,      Int,     Bool,     Char,     Void };
	std::string funcIds[] = { "output", "outputb", "outputc", "input", "inputb", "inputc", "outnl" };
	ExpType funcParamVals[] = { Int,       Bool,      Char,      Void,    Void,     Void,     Void };

	TreeNode* nodes[7];

	for (int i = 0; i < 7; i++)
	{
		TreeNode* funcNode = NewDeclNode(FuncK);
		funcNode->lineNumber = -1;
		funcNode->attr.name = strdup(funcIds[i].c_str());
		funcNode->expType = funcRetVals[i];

		// If the param val is not void, it means it has parameters.
		// As such, we need to create some nodes and add point the current function node to it.
		if (funcParamVals[i] != Void)
		{
			TreeNode* paramNode = NewDeclNode(ParamK);
			paramNode->lineNumber = -1;
			paramNode->attr.name = strdup("*dummy*");
			paramNode->expType = funcParamVals[i];
			funcNode->children[0] = paramNode;
		}

		nodes[i] = funcNode;
	}

	for (int i = 0; i < 6; i++)
	{
		nodes[i]->sibling = nodes[i + 1];
	}

	// Points the last IO lib node to the beginning of our syntax tree.
	nodes[6]->sibling = treeNode;

	// The top of the tree is now the first IO lib node.
	treeNode = nodes[0];
}

void SemanticAnalysis(TreeNode* tree, int& numErrors, int& numWarnings)
{
	ScopeAndType(tree, numErrors, numWarnings);
	TreeNode* main = (TreeNode*)symbolTable.lookup("main");

	if (main == NULL)
	{
		Error e;
		e.errorCode = MainUndefined;
		PrintError(e, numErrors, numWarnings);
	}
}

void ScopeAndType(TreeNode* node, int& numErrors, int& numWarnings)
{
	if (node == NULL)
	{
		return;
	}

	switch (node->nodeKind)
	{
	case DeclK:
		ParseDeclNode(node, numErrors, numWarnings);
		break;
	case StmtK:
		ParseStmtNode(node, numErrors, numWarnings);
		break;
	case ExpK:
		ParseExprNode(node, numErrors, numWarnings);
		break;
	default:
		printf("ERROR: Unknown NodeKind\n");
	}

	if (node->sibling != NULL)
	{
		ScopeAndType(node->sibling, numErrors, numWarnings);
	}
}

void ParseDeclNode(TreeNode* node, int& numErrors, int& numWarnings)
{
	TreeNode* declaration = NULL;

	// If the node kind is not VarK (we'll handle it later) and we cannot 
	// insert into the symbol table, it means that the symbol was already defined.
	if (node->kind.decl != VarK && !symbolTable.insert(node->attr.name, node))
	{
		declaration = (TreeNode*)symbolTable.lookup(node->attr.name);
		Error error;
		error.errorCode = SymbolAlreadyDefined;
		error.errorLineNumber = node->lineNumber;
		error.expressionLineNumber = declaration->lineNumber;
		error.child0 = node->attr.name;
		PrintError(error, numErrors, numWarnings);
	}

	switch (node->kind.decl)
	{
	case ParamK:
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}
		break;
	case VarK:
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}

		if (node->children[0] != NULL)
		{
			if (node->children[0]->nodeKind == ExpK && (node->kind.exp == IdK && node->children[0]->kind.exp == CallK))
			{
				declaration = (TreeNode*)symbolTable.lookup(node->children[0]->attr.name);
			}
			else
			{
				declaration = node->children[0];
			}

			if (declaration->nodeKind == ExpK && (declaration->kind.exp == IdK || declaration->kind.exp == CallK))
			{
				// Error: Declaration must be initialized with constant.
				Error error;
				error.errorCode = InitializerNotConstant;
				error.errorLineNumber = node->lineNumber;
				error.child0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}
			else
			{
				if (declaration->expType != node->expType)
				{
					Error error;
					error.errorCode = InitializationTypeMismatch;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->attr.name;
					error.child1 = ExpTypeToString(node->expType);
					error.child2 = ExpTypeToString(declaration->expType);
					PrintError(error, numErrors, numWarnings);
				}
			}
		}

		// Symbol already defined.
		if (!symbolTable.insert(node->attr.name, node))
		{
			TreeNode* existingNode = (TreeNode*)symbolTable.lookup(node->attr.name);
			Error error;
			error.errorCode = SymbolAlreadyDefined;
			error.errorLineNumber = node->lineNumber;
			error.child0 = node->attr.name;
			error.expressionLineNumber = existingNode->lineNumber;
			PrintError(error, numErrors, numWarnings);
		}
		break;
	case FuncK:

		symbolTable.enter(node->attr.name);
		currentFunction = node;
		enteredFunctionScope = true;

		for (int i = 0; i < 3; i++)
		{
			if (node->children[i] != NULL)
			{
				ScopeAndType(node->children[i], numErrors, numWarnings);
			}
		}

		if (returnStatementFound)
		{
			returnStatementFound = false;
		}
		else
		{
			if (node->expType != Void && node->lineNumber >= 0)
			{
				// Error: Missing return statement of type expType.
			}
		}

		symbolTable.leave();
		currentFunction = NULL;
		break;

	}
}

void ParseStmtNode(TreeNode* node, int& numErrors, int& numWarnings)
{
	bool child0error = false, child1error = false, child2error = false;

	if (node->kind.stmt == WhileK)
	{
		if (!insideLoop)
		{
			loopDepth = symbolTable.depth();
		}
		insideLoop = true;
	}

	if (node->kind.stmt != CompK)
	{
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);

			if (node->children[i] != NULL && node->children[i]->expType == Void)
			{
				if (!(node->children[i]->nodeKind == ExpK && node->children[i]->kind.exp == CallK))
				{
					if (i == 0)
					{
						child0error = true;
					}
					else if (i == 1)
					{
						child1error = true;
					}
					else if (i == 2)
					{
						child2error = true;
					}
				}
			}
		}
	}

	switch (node->kind.stmt)
	{
	case IfK:
		if (node->children[0]->expType != Bool && !child0error)
		{
			Error error;
			error.errorCode = ExpectedBooleanCondition;
			error.errorLineNumber = node->lineNumber;
			error.child0 = node->attr.name;
			error.child1 = ExpTypeToString(node->children[0]->expType);
			PrintError(error, numErrors, numWarnings);
		}
		if (node->children[0]->isArray)
		{
			// Error: used array in a conditional.
		}
		break;
	case WhileK:
		if (node->children[0]->expType != Bool && !child0error)
		{
			Error error;
			error.errorCode = ExpectedBooleanCondition;
			error.errorLineNumber = node->lineNumber;
			error.child0 = node->attr.name;
			error.child1 = ExpTypeToString(node->children[0]->expType);
			PrintError(error, numErrors, numWarnings);
		}
		if (node->children[0]->isArray)
		{
			// Error: used array in a conditional.
		}
		if (loopDepth == symbolTable.depth())
		{
			insideLoop = false;
		}
		break;
	case ReturnK:
		if (node->children[0] != NULL)
		{
			if (node->children[0]->isArray)
			{
				Error error;
				error.errorCode = ReturnArray;
				error.errorLineNumber = node->lineNumber;
				PrintError(error, numErrors, numWarnings);
			}
			if (currentFunction == NULL)
			{
				break;
			}
			if (currentFunction->expType != Void && node->children[0]->expType != Void &&
				currentFunction->expType != node->children[0]->expType)
			{
				// Incorrect return type.
				Error error;
				error.errorCode = ReturnTypeMismatch;
				error.errorLineNumber = node->lineNumber;
				error.expressionLineNumber = currentFunction->lineNumber;
				error.child0 = currentFunction->attr.name;
				error.child1 = ExpTypeToString(currentFunction->expType);
				error.child2 = ExpTypeToString(node->children[0]->expType);
				PrintError(error, numErrors, numWarnings);
			}
		}

		returnStatementFound = true;

		if (currentFunction->expType == Void && node->children[0] != NULL)
		{
			// Unexpected return type.
			Error error;
			error.errorCode = UnexpectedReturnType;
			error.errorLineNumber = node->lineNumber;
			error.expressionLineNumber = currentFunction->lineNumber;
			error.child0 = currentFunction->attr.name;
			PrintError(error, numErrors, numWarnings);
		}

		if (currentFunction->expType != Void && node->children[0] == NULL)
		{
			// Expecting a return type, but didn't find one.
			Error error;
			error.errorCode = ExpectedReturnTypeNotPresent;
			error.errorLineNumber = node->lineNumber;
			error.expressionLineNumber = currentFunction->lineNumber;
			error.child0 = currentFunction->attr.name;
			error.child1 = ExpTypeToString(currentFunction->expType);
			PrintError(error, numErrors, numWarnings);
		}

		break;
	case BreakK:
		if (!insideLoop)
		{
			Error error;
			error.errorCode = BreakOutsideOfLoop;
			error.errorLineNumber = node->lineNumber;
			PrintError(error, numErrors, numWarnings);
		}
		break;
	case CompK:
		bool keepScope = !enteredFunctionScope;

		if (keepScope)
		{
			symbolTable.enter("compound");
			node->expType = Void;
		}
		else
		{
			enteredFunctionScope = false;
		}

		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}

		if (keepScope)
		{
			symbolTable.leave();
		}

		break;
	}
}

void ParseExprNode(TreeNode* node, int& numErrors, int& numWarnings)
{
	ExpType left = Undefined, right = Undefined, expectedLeft = Undefined,
		expectedRight = Undefined, returnType = Undefined;

	bool isBinary = false, isLeftArray = false, isRightArray = false, oneSidedErrors = false;

	bool leftError = false, rightError = false;

	TreeNode* found = NULL;
	TreeNode* leftNode = NULL;
	TreeNode* rightNode = NULL;

	switch (node->kind.exp)
	{
	case AssignK:
	case OpK:
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}

		leftNode = node->children[0];
		rightNode = node->children[1];

		if (leftNode != NULL)
		{
			if (leftNode->expType != Undefined)
			{
				left = leftNode->expType;
			}

			isLeftArray = leftNode->isArray;

			if (StrEq(node->attr.name, "["))
			{
				if (!leftNode->isArray)
				{
					Error error;
					error.errorCode = IndexNonArrayKnown;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->children[0]->attr.name;
					PrintError(error, numErrors, numWarnings);
				}
			}

			if (StrEq(node->attr.name, "*"))
			{
				if (!leftNode->isArray && rightNode == NULL)
				{
					Error error;
					error.errorCode = ArrayOnlyOperation;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->attr.name;
					PrintError(error, numErrors, numWarnings);
				}
			}

			if (leftNode->nodeKind == ExpK)
			{
				if (leftNode->kind.exp == CallK)
				{
					isLeftArray = false;
				}

				// What if it's const?
			}
		}

		if (rightNode != NULL)
		{
			if (rightNode->expType != Undefined)
			{
				right = rightNode->expType;
			}

			isRightArray = rightNode->isArray;

			if (rightNode->children[0] != NULL)
			{
				isRightArray = false;
			}

			if (rightNode->nodeKind == ExpK)
			{
				if (rightNode->kind.exp == CallK)
				{
					isRightArray = false;
				}

				// What if it's const?
			}

			isBinary = true;
		}

		TypeCheck(node->attr.name, isBinary, oneSidedErrors, expectedLeft, expectedRight, returnType);

		if (left == Void && !(leftNode->nodeKind == ExpK && leftNode->kind.exp == CallK))
		{
			leftError = true;
		}
		if (right == Void && !(rightNode->nodeKind == ExpK && rightNode->kind.exp == CallK))
		{
			rightError = true;
		}

		if (!isBinary && !leftError)
		{

			if (left != expectedLeft && expectedLeft != Undefined)
			{
				Error error;
				error.errorCode = UnaryOperandTypeMismatch;
				error.errorLineNumber = node->lineNumber;
				error.child0 = node->attr.name;
				error.child1 = ExpTypeToString(expectedLeft);
				error.child2 = ExpTypeToString(left);
				PrintError(error, numErrors, numWarnings);
			}

			if (isLeftArray)
			{
				if (!StrEq(node->attr.name, "*"))
				{
					if (left != expectedLeft)
					{
						Error error;
						error.errorCode = UnaryOperandTypeMismatch;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						error.child1 = ExpTypeToString(expectedLeft);
						error.child2 = ExpTypeToString(left);
						PrintError(error, numErrors, numWarnings);
					}
					else
					{
						if (left != expectedLeft)
						{
							Error error;
							error.errorCode = InvalidArrayOperation;
							error.errorLineNumber = node->lineNumber;
							error.child0 = node->attr.name;
							PrintError(error, numErrors, numWarnings);
						}

					}

				}
				else if (StrEq(node->attr.name, "*"))
				{
					if (!symbolTable.lookup(leftNode->attr.name) || !leftNode->isArray)
					{
						Error error;
						error.errorCode = ArrayOnlyOperation;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						PrintError(error, numErrors, numWarnings);
					}
				}

				if (StrEq(node->attr.name, "?"))
				{
					Error error;
					error.errorCode = InvalidArrayOperation;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->attr.name;
					PrintError(error, numErrors, numWarnings);
				}
			}
		}
		else
		{
			//printf("binary op %s; left = %s, right = %s\n", node->attr.name, ExpTypeToString(left), ExpTypeToString(right));
			//printf("left = %s, expectedLeft = %s; right = %s, expectedRight = %s\n", ExpTypeToString(left), ExpTypeToString(expectedLeft), ExpTypeToString(right), ExpTypeToString(expectedRight));
			if (!oneSidedErrors)
			{
				if (left != right && !leftError && !rightError && !StrEq(node->attr.name, "["))
				{
					Error error;
					error.errorCode = BinaryOperandLhsRhsTypeMismatch;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->attr.name;
					error.child1 = ExpTypeToString(leftNode->expType);
					error.child2 = ExpTypeToString(rightNode->expType);
					PrintError(error, numErrors, numWarnings);
				}
				else if (StrEq(node->attr.name, "[") && right != Int)
				{

					if (rightNode->isArray && !StrEq(node->attr.name, "["))
					{
						Error error;
						error.errorCode = ArrayIndexUnindexedArray;
						error.errorLineNumber = node->lineNumber;
						error.child0 = rightNode->attr.name;
						PrintError(error, numErrors, numWarnings);
					}
					else if (right != Int)
					{
						Error error;
						error.errorCode = ArrayIndexTypeNotInt;
						error.errorLineNumber = node->lineNumber;
						error.child0 = leftNode->attr.name;
						error.child1 = ExpTypeToString(right);
						PrintError(error, numErrors, numWarnings);
					}

				}
			}

			if (!(expectedLeft == Undefined || expectedRight == Undefined))
			{
				if (expectedLeft == IntOrChar || expectedRight == IntOrChar)
				{
					// Handle errors on comparisons that take ints or chars.
				}
				else
				{
					if (left != expectedLeft && !leftError)
					{
						Error error;
						error.errorCode = BinaryOperandLhsTypeMismatch;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						error.child1 = ExpTypeToString(expectedLeft);
						error.child2 = ExpTypeToString(left);
						PrintError(error, numErrors, numWarnings);
					}

					if (right != expectedRight && !rightError)
					{
						Error error;
						error.errorCode = BinaryOperandRhsTypeMismatch;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						error.child1 = ExpTypeToString(expectedRight);
						error.child2 = ExpTypeToString(right);
						PrintError(error, numErrors, numWarnings);
					}
				}
			}

			if (isLeftArray || isRightArray)
			{
				// printf("node %s at line %d\n", node->attr.name, node->lineNumber);
				// printf("left = %s, expectedLeft = %s; right = %s, expectedRight = %s\n", ExpTypeToString(left), ExpTypeToString(expectedLeft), ExpTypeToString(right), ExpTypeToString(expectedRight));
				// printf("left is array = %d; right is array = %d\n", leftNode->isArray, rightNode->isArray);


				if (expectedLeft != Undefined)
				{
					if (leftNode != NULL)
					{
						if (!StrEq(node->attr.name, "["))
						{
							// printf("FLAG1\n");
							// printf("child node %s\n", leftNode->attr.name);
							Error error;
							error.errorCode = InvalidArrayOperation;
							error.errorLineNumber = node->lineNumber;
							error.child0 = node->attr.name;
							PrintError(error, numErrors, numWarnings);
						}
					}
					else if (rightNode != NULL)
					{
						if (!StrEq(node->attr.name, "["))
						{
							Error error;
							error.errorCode = InvalidArrayOperation;
							error.errorLineNumber = node->lineNumber;
							error.child0 = node->attr.name;
							PrintError(error, numErrors, numWarnings);
						}
					}
					else if (leftNode == NULL || rightNode == NULL)
					{
						Error error;
						error.errorCode = InvalidArrayOperation;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						PrintError(error, numErrors, numWarnings);
					}
					else if (left != expectedLeft || right != expectedRight)
					{
						if ((left == Int && expectedLeft != IntOrChar) || (right == Int && expectedRight != IntOrChar))
						{
							Error error;
							error.errorCode = InvalidArrayOperation;
							error.errorLineNumber = node->lineNumber;
							error.child0 = node->attr.name;
							PrintError(error, numErrors, numWarnings);
						}

					}
					else if (expectedLeft != Undefined)
					{
						Error error;
						error.errorCode = InvalidArrayOperation;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						PrintError(error, numErrors, numWarnings);
					}
				}

				/* if (expectedLeft != Undefined)
				{
					Error error;
					error.errorCode = InvalidArrayOperation;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->attr.name;
					PrintError(error, numErrors, numWarnings);
				} */

			}
		}

		if (returnType != Undefined)
		{
			node->expType = returnType;
		}
		else
		{
			node->expType = left;
		}
		break;
	case ConstK:
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}
		break;
	case IdK:
		found = (TreeNode*)symbolTable.lookup(node->attr.name);

		if (found == NULL)
		{
			node->expType = Undefined;
			Error error;
			error.errorCode = SymbolUndefined;
			error.errorLineNumber = node->lineNumber;
			error.child0 = node->attr.name;
			PrintError(error, numErrors, numWarnings);
		}
		else
		{
			if (found->expType != Undefined)
			{
				node->expType = found->expType;
			}
			//node->expType = found->expType;
			node->isArray = found->isArray;

			if (found->kind.decl == FuncK)
			{
				Error error;
				error.errorCode = UseFunctionAsVariable;
				error.errorLineNumber = node->lineNumber;
				error.child0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
				break;
			}

			if (node->children[0] != NULL)
			{
				ScopeAndType(node->children[0], numErrors, numWarnings);

				if (node->children[0]->expType == Void &&
					!(node->children[0]->nodeKind == ExpK && node->children[0]->kind.exp == CallK))
				{
					break;
				}

				if (!node->isArray)
				{
					Error error;
					error.errorCode = IndexNonArrayKnown;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->attr.name;
					PrintError(error, numErrors, numWarnings);
				}
				else
				{
					if (node->children[0]->expType != Int)
					{
						Error error;
						error.errorCode = ArrayIndexTypeNotInt;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						error.child1 = ExpTypeToString(node->children[0]->expType);
						PrintError(error, numWarnings, numErrors);
					}

					if (node->children[0]->isArray && node->children[0]->children[0] == NULL)
					{
						Error error;
						error.errorCode = ArrayIndexUnindexedArray;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->children[0]->attr.name;
						PrintError(error, numErrors, numWarnings);
					}
				}
			}
		}
		break;
	case CallK:
		for (int i = 0; i < 3; i++)
		{
			if (node->children[i] != NULL)
			{
				ScopeAndType(node->children[i], numErrors, numWarnings);
			}
		}

		found = (TreeNode*)symbolTable.lookup(node->attr.name);

		if (found == NULL)
		{
			node->expType = Undefined;
			Error error;
			error.errorCode = SymbolUndefined;
			error.errorLineNumber = node->lineNumber;
			error.child0 = node->attr.name;
			PrintError(error, numErrors, numWarnings);
		}
		else
		{

			if (found->kind.decl != FuncK)
			{
				Error error;
				error.errorCode = SimpleVariableCall;
				error.errorLineNumber = node->lineNumber;
				error.child0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}
			else if (found->expType != Undefined)
			{
				node->expType = found->expType;
			}

			// Handle other function call errors.
			// 
			// 
			//
			//
		}
		break;
	}
}

void TypeCheck(char* op, bool isBinary, bool& oneSidedErrors, ExpType& left, ExpType& right, ExpType& ret)
{
	std::string opStr(op);
	oneSidedErrors = false;

	if (isBinary)
	{
		switch (BinaryOpStringSwitcher(opStr))
		{
			/* Left, Right: ReturnType */
			// Int, Int: Int
		case AddOp:
		case SubOp:
		case MulOp:
		case DivOp:
		case ModOp:
		case AddAssOp:
		case SubAssOp:
		case MulAssOp:
		case DivAssOp:
			left = right = ret = Int;
			oneSidedErrors = true;
			break;
			// Bool, Bool: Bool
		case AndOp:
		case OrOp:
			left = right = ret = Bool;
			oneSidedErrors = true;
			break;
			// Undefined, Undefined: Undefined
		case AssignOp:
			left = right = ret = Undefined;
			break;
			// Undefined, Undefined: Bool
		case EqOp:
		case NotEqOp:
			left = right = Undefined;
			ret = Bool;
			break;
		case LsThanOp:
		case GrThanOp:
		case LsEqOp:
		case GrtEqOp:
			left = right = IntOrChar;
			ret = Bool;
			break;
		case IndexOp:
			left = Undefined;
			right = Int;
			ret = Undefined;
			break;
		}
	}
	else
	{
		switch (UnaryOpStringSwitcher(opStr))
		{
		case IncOp:
		case DecOp:
		case NegOp:
		case QMarkOp:
			left = right = ret = Int;
			break;
		case NotOp:
			left = right = ret = Bool;
			break;
		case StarOp:
			left = right = Undefined;
			ret = Int;
			break;
		}
	}
}

BinaryOp BinaryOpStringSwitcher(std::string const str)
{
	if (str == "+") return AddOp;
	if (str == "-") return SubOp;
	if (str == "*") return MulOp;
	if (str == "/") return DivOp;
	if (str == "%") return ModOp;
	if (str == "+=") return AddAssOp;
	if (str == "-=") return SubAssOp;
	if (str == "*=") return MulAssOp;
	if (str == "/=") return DivAssOp;
	if (str == "<") return LsThanOp;
	if (str == ">") return GrThanOp;
	if (str == "<=") return LsEqOp;
	if (str == ">=") return GrtEqOp;
	if (str == "==") return EqOp;
	if (str == "!=") return NotEqOp;
	if (str == "=") return AssignOp;
	if (str == "and") return AndOp;
	if (str == "or") return OrOp;
	if (str == "[") return IndexOp;
	return UnknownBOp;
}

UnaryOp UnaryOpStringSwitcher(std::string const str)
{
	if (str == "++") return IncOp;
	if (str == "--") return DecOp;
	if (str == "-") return NegOp;
	if (str == "*") return StarOp;
	if (str == "?") return QMarkOp;
	if (str == "not") return NotOp;
	return UnknownUOp;
}

void PrintError(Error e, int& numErrors, int& numWarnings)
{
	numErrors++;
	switch (e.errorCode)
	{
		case SimpleVariableCall:
			printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n", e.errorLineNumber, e.child0);
			break;
		case BinaryOperandLhsTypeMismatch:
			printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", e.errorLineNumber, e.child0, e.child1, e.child2);
			break;
		case BinaryOperandRhsTypeMismatch:
			printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", e.errorLineNumber, e.child0, e.child1, e.child2);
			break;
		case BinaryOperandLhsRhsTypeMismatch:
			printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is type %s.\n", e.errorLineNumber, e.child0, e.child1, e.child2);
			break;
		case ArrayIndexTypeNotInt:
			printf("ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", e.errorLineNumber, e.child0, e.child1);
			break;
		case ArrayIndexUnindexedArray:
			printf("ERROR(%d): Array index is the unindexed array '%s'.\n", e.errorLineNumber, e.child0);
			break;
		case IndexNonArrayKnown:
			printf("ERROR(%d): Cannot index nonarray '%s'.\n", e.errorLineNumber, e.child0);
			break;
		case IndexNonArrayUnknown:
			printf("ERROR(%d): Cannot index nonarray .\n", e.errorLineNumber);
			break;
		case ReturnArray:
			printf("ERROR(%d): Cannot return an array.\n", e.errorLineNumber);
			break;
		case UseFunctionAsVariable:
			printf("ERROR(%d): Cannot use function '%s' as a variable.\n", e.errorLineNumber, e.child0);
			break;
		case SymbolAlreadyDefined:
			printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", e.errorLineNumber, e.child0, e.expressionLineNumber);
			break;
		case SymbolUndefined:
			printf("ERROR(%d): Symbol '%s' is not defined.\n", e.errorLineNumber, e.child0);
			break;
		case InvalidArrayOperation:
			printf("ERROR(%d): The operation '%s' does not work with arrays.\n", e.errorLineNumber, e.child0);
			break;
		case ArrayOnlyOperation:
			printf("ERROR(%d): The operation '%s' only works with arrays.\n", e.errorLineNumber, e.child0);
			break;
		case UnaryOperandTypeMismatch:
			printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", e.errorLineNumber, e.child0, e.child1, e.child2);
			break;
		case ExpectedBooleanCondition:
			printf("ERROR(%d): Expecting Boolean test condition in %s statement but got type %s.\n", e.errorLineNumber, e.child0, e.child1);
			break;
		case ReturnTypeMismatch:
			printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but instead returns type %s.\n", e.errorLineNumber, e.child0, e.expressionLineNumber, e.child1, e.child2);
			break;
		case UnexpectedReturnType:
			printf("ERROR(%d): Function '%s' at line %d is expecting no return value, but return has return value.\n", e.errorLineNumber, e.child0, e.expressionLineNumber);
			break;
		case ExpectedReturnTypeNotPresent:
			printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but return has no return value.\n", e.errorLineNumber, e.child0, e.expressionLineNumber, e.child1);
			break;
		case BreakOutsideOfLoop:
			printf("ERROR(%d): Cannot have a break statement out of loop.\n", e.errorLineNumber);
			break;
		case InitializerNotConstant:
			printf("ERROR(%d): Initializer for variable '%s' is not a constant expression.\n", e.errorLineNumber, e.child0);
			break;
		case InitializationTypeMismatch:
			printf("ERROR(%d): Variable '%s' is of type %s but is being initialized with an expression of type %s.\n", e.errorLineNumber, e.child0, e.child1, e.child2);
			break;
		case MainUndefined:
			printf("ERROR(LINKER): Procedure main is not defined.\n");
			break;
		default:
			printf("Unknown error!\n");
			break;
	}
}