#include "Semantic.h"
#include "SymbolTable.h"
#include <cstring>

SymbolTable symbolTable;
// Tracks whether we entered a function scope in order to handle
// not creating a new scope on the compound statement.
bool enteredFunctionScope = false;
ExpType functionReturnType;
TreeNode* currentFunction = NULL;
bool returnStatementFound = false;
bool insideLoop = false;
int loopDepth = 1;

std::string binaryOps[19] = {"+", "-", "*", "/", "%", "+=", "-=", "*=", "/=", 
	"<", ">", "<=", ">=", "==", "!=", "=", "[",
	"and", "or"};

std::string unaryOps[6] = {"++", "--", "-", "not", "*", "?"};

void SemanticAnalysis(TreeNode* tree, int& numErrors, int& numWarnings)
{
	printf("------ IN SemanticAnalysis() ------ \n");
	
	ScopeAndType(tree, numErrors, numWarnings);
	
	printf("------ OUT ScopeAndType() -------\n");
	
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
		printf("ERROR: Unknown NodeKind '%d'.\n", node->nodeKind);
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
		// Build up the Error struct.
		Error error;
		error.errorCode = SymbolAlreadyDefined;
		error.errorLineNumber = declaration->lineNumber;
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
			}
			else
			{
				// Handle other possible errors if it was a constant.
			}
		}		
		
		// Symbol already defined.
		if (!symbolTable.insert(node->attr.name, node))
		{
			TreeNode* existingNode = (TreeNode*)symbolTable.lookup(node->attr.name);
			Error error;
			error.errorCode = SymbolAlreadyDefined;
			error.errorLineNumber = node->lineNumber;
			error.expressionLineNumber = existingNode->lineNumber;
			PrintError(error, numErrors, numWarnings);
		}
		break;
	case FuncK:
		symbolTable.enter(node->attr.name);
		currentFunction = node;
		enteredFunctionScope = true;
		functionReturnType = node->expType;
		
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
			// Error: didn't find boolean condition.
		}
		if (node->children[0]->isArray)
		{
			// Error: used array in a conditional.
		}
		break;
	case WhileK:
		if (node->children[0]->expType != Bool && !child0error)
		{
			// Error: didn't find boolean condition.
		}
		if (node->children[0]->isArray)
		{
			// Error: used array in a conditional.
		}
		if (loopDepth == symbolTable.depth())
		{
			insideLoop = false;
		}
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
			if ((currentFunction->expType != Void && node->children[0]->expType != Void) && 
					(currentFunction->expType != node->children[0]->expType))
			{
				// Error: Incorrect return type.
			}
		}
		break;
	case BreakK:
		if (!insideLoop)
		{
			// Error: Can only break inside loop.
		}
		break;
	case CompK:
		// Handle function scope special case here on HW4.
		//
		//
		//
		// 
		
		symbolTable.enter("compound");
		
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}
		
		symbolTable.leave();
		break;
	}
}

void ParseExprNode(TreeNode* node, int& numErrors, int& numWarnings)
{
	ExpType left = Undefined, right = Undefined, expectedLeft = Undefined, 
	expectedRight = Undefined, returnType = Undefined;

	bool isBinary = false, isLeftArray = false, isRightArray = false,
	isLeftIndexed = false, isRightIndexed = false, oneSidedErrors = false;
	
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
			
			if ((leftNode = node->children[0]) != NULL)
			{
				left = leftNode->expType;
				isLeftArray = leftNode->isArray;
				
				if (leftNode->children[0] != NULL)
				{
					// Accessing the array by index.
					isLeftArray = false;
					isLeftIndexed = true;
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
			
			if ((rightNode = node->children[1]) != NULL)
			{
				right = rightNode->expType;
				isRightArray = rightNode->isArray;
				
				if (rightNode->children[0] != NULL)
				{
					isRightArray = false;
					isRightIndexed = true;
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
					if (strcmp(node->attr.name, "*") != 0)
					{
						Error error;
						error.errorCode = InvalidArrayOperation;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						PrintError(error, numErrors, numWarnings);
					}
					else
					{
						Error error;
						error.errorCode = ArrayOnlyOperation;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
					}
				}		
			}
			else
			{
				if (!oneSidedErrors)
				{
					if (left != right && !leftError && !rightError)
					{
						Error error;
						error.errorCode = BinaryOperandLhsRhsTypeMismatch;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						error.child1 = ExpTypeToString(expectedLeft);
						error.child2 = ExpTypeToString(left);
						PrintError(error, numErrors, numWarnings);
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
						}
					}
				}
				
				if (isLeftArray || isRightArray)
				{
					if (expectedLeft != Undefined)
					{
						Error error;
						error.errorCode = InvalidArrayOperation;
						error.errorLineNumber = node->lineNumber;
						error.child0 = node->attr.name;
						PrintError(error, numErrors, numWarnings);
					}
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
				Error error;
				error.errorCode = SymbolUndefined;
				error.errorLineNumber = node->lineNumber;
				error.child0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}
			else
			{
				node->expType = found->expType;
				node->isArray = found->isArray;
				
				if (found->kind.decl == FuncK)
				{
					Error error;
					error.errorCode = UseFunctionAsVariable;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->attr.name;
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
				ScopeAndType(node->children[i], numErrors, numWarnings);
			}
			
			found = (TreeNode*)symbolTable.lookup(node->attr.name);
			
			if (found == NULL)
			{
				Error error;
				error.errorCode = SymbolUndefined;
				error.errorLineNumber = node->lineNumber;
				error.child0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}
			else
			{
				node->expType = found->expType;
				
				if (found->kind.decl != FuncK)
				{
					Error error;
					error.errorCode = SimpleVariableCall;
					error.errorLineNumber = node->lineNumber;
					error.child0 = node->attr.name;
					PrintError(error, numErrors, numWarnings);
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
		printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n",
		e.errorLineNumber, e.child0);
		break;
	case BinaryOperandLhsTypeMismatch:
		printf("Error(%d): '%s' requires operands of %s but lhs is of %s.\n",
		e.errorLineNumber, e.child0, e.child1, e.child2);
		break;
	case BinaryOperandRhsTypeMismatch:
		printf("ERROR(%d): '%s' requires operands of %s but rhs is of %s.\n",
		e.errorLineNumber, e.child0, e.child1, e.child2);
		break;
	case BinaryOperandLhsRhsTypeMismatch:
		printf("ERROR(%d): '%s' requires operands of the same type but lhs is %s and rhs is %s.\n",
		e.errorLineNumber, e.child0, e.child1, e.child2);
		break;
	case ArrayIndexTypeNotInt:
		printf("ERROR(%d): Array '%s' should be indexed by type int but got %s.\n",
		e.errorLineNumber, e.child0, e.child1);
		break;
	case ArrayIndexUnindexedArray:
		printf("ERROR(%d): Array index is the unindexed array '%s'.\n",
		e.errorLineNumber, e.child0);
		break;
	case IndexNonArrayKnown:
		printf("ERROR(%d): Cannot index nonarray '%s'.\n",
		e.errorLineNumber, e.child0);
		break;
	case IndexNonArrayUnknown:
		printf("ERROR(%d): Cannot index nonarray .\n",
		e.errorLineNumber);
		break;
	case ReturnArray:
		printf("ERROR(%d): Cannot return an array.\n",
		e.errorLineNumber);
		break;
	case UseFunctionAsVariable:
		printf("ERROR(%d): Cannot use function '%s' as a variable.\n",
		e.errorLineNumber, e.child0);
		break;
	case SymbolAlreadyDefined:
		printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n",
		e.errorLineNumber, e.child0, e.expressionLineNumber);
		break;
	case SymbolUndefined:
		printf("ERROR(%d): Symbol '%s' is not defined.\n",
		e.errorLineNumber, e.child0);
		break;
	case InvalidArrayOperation:
		printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
		e.errorLineNumber, e.child0);
		break;
	case ArrayOnlyOperation:
		printf("ERROR(%d): The operation '%s' only works with arrays.\n",
		e.errorLineNumber, e.child0);
		break;
	case UnaryOperandTypeMismatch:
		printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given %s.\n");
		break;
	case MainUndefined:
		printf("ERROR(LINKER): Procedure main is not defined.\n");
		break;
	default:
		printf("Unknown error!");
		break;			
	}
}