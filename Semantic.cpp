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
bool inFunctionCall = false;
int loopDepth = 1;
int globalOffset = 0;
int localOffset = 0;

std::string binaryOps[20] = { "+", "-", "*", "/", "%", "+=", "-=", "*=", "/=",
							  "<", ">", "<=", ">=", "==", "!=", "=", "[", "."
							  "and", "or" };

std::string unaryOps[6] = { "++", "--", "-", "not", "*", "?" };

void AttachIOLib(TreeNode*& treeNode)
{
	// The return types, identifiers, and parameter types for the IO functions.
	ExpType funcRetVals[] =   { Int,	 Void,     Bool,	 Void,      Char,	  Void,      Void };
	std::string funcIds[] =   {"input", "output", "inputb",	"outputb", "inputc", "outputc", "outnl" };
	ExpType funcParamVals[] = { Void,	 Int,      Void,	 Bool,      Void,	  Char,      Void };
	int ioMemSize[] = 		  { -2, 	 -3, 	   -2, 		 -3, 		-2, 	  -3, 		 -2 };

	TreeNode* nodes[7];

	for (int i = 0; i < 7; i++)
	{
		TreeNode* funcNode = NewDeclNode(FuncK);
		funcNode->lineNumber = -1;
		funcNode->attr.name = strdup(funcIds[i].c_str());
		funcNode->expType = funcRetVals[i];
		funcNode->isIO = true;
		funcNode->isGlobal = true;
		funcNode->memSize = ioMemSize[i];
		funcNode->memOffset = 0;

		// If the param val is not void, it means it has parameters.
		// As such, we need to create some nodes and add point the current function node to it.
		if (funcParamVals[i] != Void)
		{
			TreeNode* paramNode = NewDeclNode(ParamK);
			paramNode->lineNumber = -1;
			paramNode->attr.name = strdup("*dummy*");
			paramNode->expType = funcParamVals[i];
			paramNode->isIO = true;
			paramNode->isParam = true;
			paramNode->memSize = 1;
			paramNode->memOffset = -2;
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
	TreeNode* main = static_cast<TreeNode*>(symbolTable.lookup("main"));

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

	if (symbolTable.depth() == 1)
	{
		node->isGlobal = true;
	}
	else
	{
		node->isGlobal = false;
	}	

	// If the node kind is not VarK (we'll handle it later) and we cannot 
	// insert into the symbol table, it means that the symbol was already defined.
	if (node->kind.decl != VarK && !symbolTable.insert(node->attr.name, node))
	{
		declaration = static_cast<TreeNode*>(symbolTable.lookup(node->attr.name));
		Error error;
		error.errorCode = SymbolAlreadyDefined;
		error.errorLineNumber = node->lineNumber;
		error.expressionLineNumber = declaration->lineNumber;
		error.context0 = node->attr.name;
		PrintError(error, numErrors, numWarnings);
	}

	switch (node->kind.decl)
	{
	case ParamK:
		node->isParam = true;		
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}
		node->memSize = 1;
		if (!node->isIO)
		{
			node->memOffset = localOffset;
		}	
		localOffset--;
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
				declaration = static_cast<TreeNode*>(symbolTable.lookup(node->children[0]->attr.name));
			}
			else
			{
				declaration = node->children[0];
			}			
			
			if (declaration->nodeKind == ExpK && (declaration->kind.exp == IdK || declaration->kind.exp == CallK || !declaration->isConst))
			{				
				// Error: Declaration must be initialized with constant.
				Error error;
				error.errorCode = InitializerNotConstant;
				error.errorLineNumber = node->lineNumber;
				error.context0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}
			else
			{	
				if (declaration->expType != node->expType)
				{
					Error error;
					error.errorCode = InitializationTypeMismatch;
					error.errorLineNumber = node->lineNumber;
					error.context0 = node->attr.name;
					error.context1 = ExpTypeToString(node->expType);
					error.context2 = ExpTypeToString(declaration->expType);
					PrintError(error, numErrors, numWarnings);
				}
			}
		}

		// Symbol already defined.
		if (!symbolTable.insert(node->attr.name, node))
		{
			TreeNode* existingNode = static_cast<TreeNode*>(symbolTable.lookup(node->attr.name));
			Error error;
			error.errorCode = SymbolAlreadyDefined;
			error.errorLineNumber = node->lineNumber;
			error.context0 = node->attr.name;
			error.expressionLineNumber = existingNode->lineNumber;
			PrintError(error, numErrors, numWarnings);
		}

		if (node->isArray)
		{
			node->memSize = node->arrayLength + 1;
		}
		else
		{
			node->memSize = 1;
		}

		if (node->isGlobal || node->isStatic)
		{
			if (node->isArray)
			{
				node->memOffset = globalOffset - 1;
			}
			else
			{
				node->memOffset = globalOffset;
			}
			globalOffset -= node->memSize;
		}
		else
		{
			if (node->isArray)
			{
				node->memOffset = localOffset - 1;
			}
			else
			{
				node->memOffset = localOffset;
			}
			localOffset -= node->memSize;
		}

		break;
	case FuncK:
		localOffset = -2;
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
				Error error;
				error.errorCode = MissingReturnStatementWarning;
				error.errorLineNumber = node->lineNumber;
				error.context0 = ExpTypeToString(node->expType);
				error.context1 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}
		}

		symbolTable.leave();
		currentFunction = NULL;
		
		node->memSize = -2;
		TreeNode* t = node->children[1];

		while (t != NULL)
		{
			if (!node->isIO)
			{
				node->memSize = t->memSize;
			}
			
			t = t->children[1];
		}

		if (node->isIO)
		{
			t = node->children[0];

			while (t != NULL)
			{
				node->memSize--;
				t = t->sibling;
			}
		}
		
		node->memOffset = 0;

		break;
	}
}

void ParseStmtNode(TreeNode* node, int& numErrors, int& numWarnings)
{
	bool child0error = false, child1error, child2error = false;

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
		if (node->children[0]->expType != Bool && !child0error && node->children[0]->expType != Undefined)
		{
			Error error;
			error.errorCode = ExpectedBooleanCondition;
			error.errorLineNumber = node->lineNumber;
			error.context0 = node->attr.name;
			error.context1 = ExpTypeToString(node->children[0]->expType);
			PrintError(error, numErrors, numWarnings);
		}
		if (node->children[0]->isArray)
		{
			Error error;
			error.errorCode = ArrayAsTestCondition;
			error.errorLineNumber = node->lineNumber;
			error.context0 = node->attr.name;
			PrintError(error, numErrors, numWarnings);
		}
		break;
	case WhileK:
		if (node->children[0]->expType != Bool && !child0error && node->children[0]->expType != Undefined)
		{
			Error error;
			error.errorCode = ExpectedBooleanCondition;
			error.errorLineNumber = node->lineNumber;
			error.context0 = node->attr.name;
			error.context1 = ExpTypeToString(node->children[0]->expType);
			PrintError(error, numErrors, numWarnings);
		}
		if (node->children[0]->isArray)
		{
			Error error;
			error.errorCode = ArrayAsTestCondition;
			error.errorLineNumber = node->lineNumber;
			error.context0 = node->attr.name;
			PrintError(error, numErrors, numWarnings);
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
				currentFunction->expType != node->children[0]->expType && node->children[0]->expType != Undefined)
			{
				// Incorrect return type.
				Error error;
				error.errorCode = ReturnTypeMismatch;
				error.errorLineNumber = node->lineNumber;
				error.expressionLineNumber = currentFunction->lineNumber;
				error.context0 = currentFunction->attr.name;
				error.context1 = ExpTypeToString(currentFunction->expType);
				error.context2 = ExpTypeToString(node->children[0]->expType);
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
			error.context0 = currentFunction->attr.name;
			PrintError(error, numErrors, numWarnings);
		}

		if (currentFunction->expType != Void && node->children[0] == NULL)
		{
			// Expecting a return type, but didn't find one.
			Error error;
			error.errorCode = ExpectedReturnTypeNotPresent;
			error.errorLineNumber = node->lineNumber;
			error.expressionLineNumber = currentFunction->lineNumber;
			error.context0 = currentFunction->attr.name;
			error.context1 = ExpTypeToString(currentFunction->expType);
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
		int compSize = localOffset;
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

		node->memSize = localOffset;
		localOffset = compSize;

		break;
	}
}

void TypeAndCheck(TreeNode* opNode, int& numErrors, int& numWarnings)
{
	if (opNode == NULL)
	{
		return;
	}

	if (opNode->children[0] != NULL & opNode->children[1] != NULL)
	{
		TypeAndCheckBinaryOp(opNode, numErrors, numWarnings);
	}
	else
	{
		TypeAndCheckUnaryOp(opNode, numErrors, numWarnings);
	}
}

void TypeAndCheckBinaryOp(TreeNode* opNode, int& numErrors, int& numWarnings)
{
	if (opNode == NULL)
	{
		return;
	}

	TreeNode* leftOperand = opNode->children[0];
	TreeNode* rightOperand = opNode->children[1];

	// Prevents cascading errors.
	/*if (leftOperand->expType == Undefined || rightOperand->expType == Undefined)
	{
		printf("Skipping binary op node '%s' on line %d\n", opNode->attr.name, opNode->lineNumber);
		opNode->expType = Undefined;
		return;
	}*/

	

	std::string opStr(opNode->attr.name);

	switch(BinaryOpStringSwitcher(opStr))
	{
	case AddOp:
	case SubOp:
	case MulOp:
	case DivOp:
	case ModOp:
	case AddAssOp:
	case SubAssOp:
	case MulAssOp:
	case DivAssOp:
		// If no errors are raised, the result will be of type int.
		opNode->expType = Int;		

		if (leftOperand->expType != Int || rightOperand->expType != Int)
		{
			/*if (leftOperand->expType != Int && rightOperand->expType != Int)
			{
				Error error;
				error.errorCode = BinaryOperandLhsRhsTypeMismatch;
				error.errorLineNumber = opNode->lineNumber;
				error.context0 = opNode->attr.name;
				error.context1 = ExpTypeToString(leftOperand->expType);
				error.context2 = ExpTypeToString(rightOperand->expType);
				PrintError(error, numErrors, numWarnings);
				opNode->expType = Undefined;
			}
			else */
			if (leftOperand->expType != Int && leftOperand->expType != Undefined)
			{
				Error error;
				error.errorCode = BinaryOperandLhsTypeMismatch;
				error.errorLineNumber = opNode->lineNumber;
				error.context0 = opNode->attr.name;
				error.context1 = ExpTypeToString(Int);
				error.context2 = ExpTypeToString(leftOperand->expType);
				PrintError(error, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}
			
			if (rightOperand->expType != Int && rightOperand->expType != Undefined)
			{
				Error error;
				error.errorCode = BinaryOperandRhsTypeMismatch;
				error.errorLineNumber = opNode->lineNumber;
				error.context0 = opNode->attr.name;
				error.context1 = ExpTypeToString(Int);
				error.context2 = ExpTypeToString(rightOperand->expType);
				PrintError(error, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}
		}

		if (leftOperand->isArray || rightOperand->isArray)
		{
			Error error;
			error.errorCode = InvalidArrayOperation;
			error.errorLineNumber = opNode->lineNumber;
			error.context0 = opNode->attr.name;
			PrintError(error, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		break;
	case AndOp:
	case OrOp:
		// If no errors are raised, the result will be of type bool.
		opNode->expType = Bool;

		if (leftOperand->expType != Bool && leftOperand->expType != Undefined)
		{			
			Error error;
			error.errorCode = BinaryOperandLhsTypeMismatch;
			error.errorLineNumber = opNode->lineNumber;
			error.context0 = opNode->attr.name;
			error.context1 = ExpTypeToString(Bool);
			error.context2 = ExpTypeToString(leftOperand->expType);
			PrintError(error, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		if (rightOperand->expType != Bool && rightOperand->expType != Undefined)
		{
			Error error;
			error.errorCode = BinaryOperandRhsTypeMismatch;
			error.errorLineNumber = opNode->lineNumber;
			error.context0 = opNode->attr.name;
			error.context1 = ExpTypeToString(Bool);
			error.context2 = ExpTypeToString(rightOperand->expType);
			PrintError(error, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}


		if (leftOperand->isArray || rightOperand->isArray)
		{
			Error error;
			error.errorCode = InvalidArrayOperation;
			error.errorLineNumber = opNode->lineNumber;
			error.context0 = opNode->attr.name;
			PrintError(error, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		break;
	case AssignOp:
		// If no errors are raised, the result will be the type of the left operand.
		opNode->expType = leftOperand->expType;

		if (leftOperand->expType != rightOperand->expType && leftOperand->expType != Undefined && rightOperand->expType != Undefined)
		{
			Error error;
			error.errorCode = BinaryOperandLhsRhsTypeMismatch;
			error.errorLineNumber = opNode->lineNumber;
			error.context0 = opNode->attr.name;
			error.context1 = ExpTypeToString(leftOperand->expType);
			error.context2 = ExpTypeToString(rightOperand->expType);
			PrintError(error, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		// If either operand is an array we need to check further.
		if (leftOperand->isArray || rightOperand->isArray)
		{
			// If no errors are raised, the result will be the type of the left operand.
			opNode->isArray = leftOperand->isArray;

			// If one is an array and the other isn't.
			if (leftOperand->isArray ^ rightOperand->isArray)
			{
				Error error;
				error.errorCode = BothOrNeitherArrayRequired;
				error.errorLineNumber = opNode->lineNumber;
				error.context0 = opNode->attr.name;
				PrintError(error, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}
		}

		break;
	case EqOp:
	case NotEqOp:
		// If no errors are raised, the result will be of type bool.
		opNode->expType = Bool;

		if (leftOperand->expType != rightOperand->expType)
		{
			Error error;
			error.errorCode = BinaryOperandLhsRhsTypeMismatch;
			error.errorLineNumber = opNode->lineNumber;
			error.context0 = opNode->attr.name;
			error.context1 = ExpTypeToString(leftOperand->expType);
			error.context2 = ExpTypeToString(rightOperand->expType);
			PrintError(error, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		// If either operand is an array we need to check further.
		if (leftOperand->isArray || rightOperand->isArray)
		{
			// If one is an array and the other isn't.
			if (leftOperand->isArray ^ rightOperand->isArray)
			{
				Error error;
				error.errorCode = BothOrNeitherArrayRequired;
				error.errorLineNumber = opNode->lineNumber;
				error.context0 = opNode->attr.name;
				PrintError(error, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}
		}

		break;
	case LsThanOp:
	case GrThanOp:
	case LsEqOp:
	case GrtEqOp:
		// If no errors are raised, the result will be of type bool.
		opNode->expType = Bool;	

		{
			bool raiseSameTypeError = true;

			if (leftOperand->expType != Int && leftOperand->expType != Char && leftOperand->expType != Undefined)
			{
				raiseSameTypeError = false;
				Error error;
				error.errorCode = BinaryOperandLhsTypeMismatch;
				error.errorLineNumber = opNode->lineNumber;
				error.context0 = opNode->attr.name;
				error.context1 = ExpTypeToString(IntOrChar);
				error.context2 = ExpTypeToString(leftOperand->expType);
				PrintError(error, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}

			if (rightOperand->expType != Int && rightOperand->expType != Char && rightOperand->expType != Undefined)
			{
				raiseSameTypeError = false;
				Error error;
				error.errorCode = BinaryOperandRhsTypeMismatch;
				error.errorLineNumber = opNode->lineNumber;
				error.context0 = opNode->attr.name;
				error.context1 = ExpTypeToString(IntOrChar);
				error.context2 = ExpTypeToString(rightOperand->expType);
				PrintError(error, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}

			// We only raise this error if both the previous two haven't been raised.
			if (leftOperand->expType != rightOperand->expType && raiseSameTypeError && leftOperand->expType != Undefined && rightOperand->expType != Undefined)
			{
				Error error;
				error.errorCode = BinaryOperandLhsRhsTypeMismatch;
				error.errorLineNumber = opNode->lineNumber;
				error.context0 = opNode->attr.name;
				error.context1 = ExpTypeToString(leftOperand->expType);
				error.context2 = ExpTypeToString(rightOperand->expType);
				PrintError(error, numErrors, numWarnings);
				//opNode->expType = Undefined;
				//break;
			}
		}

		if (leftOperand->isArray || rightOperand->isArray)
		{
			Error error;
			error.errorCode = InvalidArrayOperation;
			error.errorLineNumber = opNode->lineNumber;
			error.context0 = opNode->attr.name;
			PrintError(error, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		break;
	case IndexOp:
		// If no errors are raised, the result will be the type of the left operand.
		opNode->expType = leftOperand->expType;		

		if (rightOperand->expType != Int && rightOperand->expType != Undefined)
		{
			Error e;
			e.errorCode = ArrayIndexTypeNotInt;
			e.errorLineNumber = opNode->lineNumber;
			e.context0 = leftOperand->attr.name;
			e.context1 = ExpTypeToString(rightOperand->expType);			
			PrintError(e, numErrors, numWarnings);			
		}

		if (rightOperand->isArray)
		{
			if (rightOperand->kind.exp != IdK)
			{
				Error e;
				e.errorCode = ArrayIndexUnindexedArrayUnknown;
				e.errorLineNumber = opNode->lineNumber;
				PrintError(e, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}
			else
			{
				Error e;
				e.errorCode = ArrayIndexUnindexedArray;
				e.errorLineNumber = opNode->lineNumber;
				e.context0 = rightOperand->attr.name;
				PrintError(e, numErrors, numWarnings);
			}			
		}

		if (!leftOperand->isArray)
		{
			if (leftOperand->kind.exp != IdK)
			{
				Error e;
				e.errorCode = IndexNonArrayUnknown;
				e.errorLineNumber = opNode->lineNumber;
				PrintError(e, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}
			else
			{
				Error e;
				e.errorCode = IndexNonArrayKnown;
				e.errorLineNumber = opNode->lineNumber;
				e.context0 = leftOperand->attr.name;
				PrintError(e, numErrors, numWarnings);
				//opNode->expType = Undefined;
			}
		}
		
		// We just indexed the array, therefore it is no longer an array.
		//leftOperand->isArray = false;

		break;
	case DotOp:
		break;
	case UnknownBOp:
		printf("Unknown binary op detected: '%s'.\n", opNode->attr.name);
		break;
	default:
		printf("Default case of binary op check hit.\n");
	}
}

void TypeAndCheckUnaryOp(TreeNode* opNode, int& numErrors, int& numWarnings)
{
	if (opNode == NULL)
	{
		return;
	}

	TreeNode* operand = opNode->children[0];

	// Prevent cascading errors.
	/*if (operand->expType == Undefined)
	{
		printf("Skipping binary op node '%s' on line %d\n", opNode->attr.name, opNode->lineNumber);
		opNode->expType = Undefined;
		return;
	}*/

	std::string opStr(opNode->attr.name);

	switch (UnaryOpStringSwitcher(opStr))
	{
	case IncOp:
	case DecOp:
	case NegOp:
	case QMarkOp:
		// If no errors are raised, the op gets type int.
		opNode->expType = Int;

		if (operand->expType != Int && operand->expType != Undefined)
		{
			Error e;
			e.errorCode = UnaryOperandTypeMismatch;
			e.errorLineNumber = opNode->lineNumber;
			e.context0 = opNode->attr.name;
			e.context1 = ExpTypeToString(Int);
			e.context2 = ExpTypeToString(operand->expType);
			PrintError(e, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		if (operand->isArray)
		{
			Error e;
			e.errorCode = InvalidArrayOperation;
			e.errorLineNumber = opNode->lineNumber;
			e.context0 = opNode->attr.name;
			PrintError(e, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		break;
	case StarOp:
		// If no errors are raised, the op gets type int.
		opNode->expType = Int;

		if (!operand->isArray && operand->expType != Undefined)
		{
			Error e;
			e.errorCode = ArrayOnlyOperation;
			e.errorLineNumber = opNode->lineNumber;
			e.context0 = opNode->attr.name;
			PrintError(e, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		break;

	case NotOp:
		// If no errors are raised, the op gets type bool.
		opNode->expType = Bool;
		
		if (operand->expType != Bool && operand->expType != Undefined)
		{
			Error e;
			e.errorCode = UnaryOperandTypeMismatch;
			e.errorLineNumber = opNode->lineNumber;
			e.context0 = opNode->attr.name;
			e.context1 = ExpTypeToString(Bool);
			e.context2 = ExpTypeToString(operand->expType);
			PrintError(e, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		if (operand->isArray)
		{
			Error e;
			e.errorCode = InvalidArrayOperation;
			e.errorLineNumber = opNode->lineNumber;
			e.context0 = opNode->attr.name;
			PrintError(e, numErrors, numWarnings);
			//opNode->expType = Undefined;
		}

		break;
	case UnknownUOp:
		printf("Unknown unary op detected: '%s'.\n", opNode->attr.name);
		break;
	default:
		printf("Default case of unary op check hit.\n");
	}
}

void ParseExprNode(TreeNode* node, int& numErrors, int& numWarnings)
{

	TreeNode* found = NULL;

	switch (node->kind.exp)
	{
	case AssignK:
	case OpK:
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}
		
		TypeAndCheck(node, numErrors, numWarnings);
		
		break;
	case ConstK:
		for (int i = 0; i < 3; i++)
		{
			ScopeAndType(node->children[i], numErrors, numWarnings);
		}
		break;
	case IdK:
		found = static_cast<TreeNode*>(symbolTable.lookup(node->attr.name));

		if (found == NULL)
		{
			node->expType = Undefined;
			Error error;
			error.errorCode = SymbolUndefined;
			error.errorLineNumber = node->lineNumber;
			error.context0 = node->attr.name;
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
			node->isParam = found->isParam;
			node->memSize = found->memSize;
			node->memOffset = found->memOffset;
			node->isGlobal = found->isGlobal;
			node->isStatic = found->isStatic;

			if (found->kind.decl == FuncK)
			{
				Error error;
				error.errorCode = UseFunctionAsVariable;
				error.errorLineNumber = node->lineNumber;
				error.context0 = node->attr.name;
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
					error.context0 = node->attr.name;
					PrintError(error, numErrors, numWarnings);
				}
				else
				{
					if (node->children[0]->expType != Int)
					{
						Error error;
						error.errorCode = ArrayIndexTypeNotInt;
						error.errorLineNumber = node->lineNumber;
						error.context0 = node->attr.name;
						error.context1 = ExpTypeToString(node->children[0]->expType);
						PrintError(error, numWarnings, numErrors);
					}

					if (node->children[0]->isArray && node->children[0]->children[0] == NULL)
					{
						Error error;
						error.errorCode = ArrayIndexUnindexedArray;
						error.errorLineNumber = node->lineNumber;
						error.context0 = node->children[0]->attr.name;
						PrintError(error, numErrors, numWarnings);
					}
				}
			}
		}
		break;
	case CallK:
		inFunctionCall = true;
		for (int i = 0; i < 3; i++)
		{
			if (node->children[i] != NULL)
			{
				ScopeAndType(node->children[i], numErrors, numWarnings);
			}
		}
		inFunctionCall = false;

		found = static_cast<TreeNode*>(symbolTable.lookup(node->attr.name));

		if (found == NULL)
		{
			node->expType = Undefined;
			Error error;
			error.errorCode = FunctionUndefined;
			error.errorLineNumber = node->lineNumber;
			error.context0 = node->attr.name;
			PrintError(error, numErrors, numWarnings);
		}
		else
		{
			node->expType = found->expType;
			node->memSize = found->memSize;
			node->memOffset = found->memOffset;
			node->isArray = found->isArray;
			node->isStatic = found->isStatic;
			node->isGlobal = found->isGlobal;

			if (found->kind.decl != FuncK)
			{
				Error error;
				error.errorCode = SimpleVariableCall;
				error.errorLineNumber = node->lineNumber;
				error.context0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}
			else if (found->expType != Undefined)
			{				
				node->expType = found->expType;
			}

			// Handle other function call errors.
			TreeNode* callParams = node->children[0];
			TreeNode* declParams = found->children[0];
			bool callIsArray = false, declIsArray = false;
			// Keeps track of which parameter currently being checked.
			int paramNum = 1;

			while (callParams != NULL && declParams != NULL)
			{
				if (callParams->kind.exp == IdK && callParams->expType == Void)
				{
					callParams = callParams->sibling;
					declParams = declParams->sibling;
					callIsArray = declIsArray = false;
					paramNum++;
					continue;
				}

				if (declParams->isArray)
				{
					declIsArray = true;
					if (declParams->children[0] != NULL)
					{
						declIsArray = false;
					}
				}

				if (callParams->isArray)
				{
					callIsArray = true;
					if (callParams->children[0] != NULL)
					{
						callIsArray = false;
					}
				}

				if (callParams->expType != declParams->expType && callParams->expType != Undefined)
				{
					Error error;
					error.errorCode = FuncCallParamTypeMismatch;
					error.errorLineNumber = node->lineNumber;
					error.expressionLineNumber = found->lineNumber;
					char paramNumStr[2];
					sprintf(paramNumStr, "%d", paramNum);
					error.context0 = ExpTypeToString(declParams->expType);
					error.context1 = paramNumStr;
					error.context2 = node->attr.name;
					error.context3 = ExpTypeToString(callParams->expType);
					PrintError(error, numErrors, numWarnings);
				}

				if (callIsArray && !declIsArray)
				{
					Error error;
					error.errorCode = NotExpectingArrayParam;
					error.errorLineNumber = node->lineNumber;
					error.expressionLineNumber = found->lineNumber;
					char paramNumStr[2];
					sprintf(paramNumStr, "%d", paramNum);
					error.context0 = paramNumStr;
					error.context1 = node->attr.name;
					PrintError(error, numErrors, numWarnings);
				}

				if (!callIsArray && declIsArray)
				{
					Error error;
					error.errorCode = ExpectingArrayParam;
					error.errorLineNumber = node->lineNumber;
					error.expressionLineNumber = found->lineNumber;
					char paramNumStr[2];
					sprintf(paramNumStr, "%d", paramNum);
					error.context0 = paramNumStr;
					error.context1 = node->attr.name;
					PrintError(error, numErrors, numWarnings);
				}

				callParams = callParams->sibling;
				declParams = declParams->sibling;
				paramNum++;
				callIsArray = declIsArray = false;
			}

			// If we run out of call params, but there are still declaration params,
			// then there are too few call params.
			if (callParams == NULL && declParams != NULL)
			{
				Error error;
				error.errorCode = TooFewCallParams;
				error.errorLineNumber = node->lineNumber;
				error.expressionLineNumber = found->lineNumber;
				error.context0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}

			// if we run out of declaration params, but there are still call params,
			// then there are too many call params.
			if (callParams != NULL && declParams == NULL)
			{
				Error error;
				error.errorCode = TooManyCallParams;
				error.errorLineNumber = node->lineNumber;
				error.expressionLineNumber = found->lineNumber;
				error.context0 = node->attr.name;
				PrintError(error, numErrors, numWarnings);
			}

		}
		break;
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
	if (str == ".") return DotOp;
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
			printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n", e.errorLineNumber, e.context0);
			break;
		case BinaryOperandLhsTypeMismatch:
			printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", e.errorLineNumber, e.context0, e.context1, e.context2);
			break;
		case BinaryOperandRhsTypeMismatch:
			printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", e.errorLineNumber, e.context0, e.context1, e.context2);
			break;
		case BinaryOperandLhsRhsTypeMismatch:
			printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is type %s.\n", e.errorLineNumber, e.context0, e.context1, e.context2);
			break;
		case ArrayIndexTypeNotInt:
			printf("ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", e.errorLineNumber, e.context0, e.context1);
			break;
		case ArrayIndexUnindexedArray:
			printf("ERROR(%d): Array index is the unindexed array '%s'.\n", e.errorLineNumber, e.context0);
			break;
		case ArrayIndexUnindexedArrayUnknown:
			printf("ERROR(%d): Array index is an unindexed array.\n", e.errorLineNumber);
			break;
		case IndexNonArrayKnown:
			printf("ERROR(%d): Cannot index nonarray '%s'.\n", e.errorLineNumber, e.context0);
			break;
		case IndexNonArrayUnknown:
			printf("ERROR(%d): Cannot index nonarray.\n", e.errorLineNumber);
			break;
		case ReturnArray:
			printf("ERROR(%d): Cannot return an array.\n", e.errorLineNumber);
			break;
		case UseFunctionAsVariable:
			printf("ERROR(%d): Cannot use function '%s' as a variable.\n", e.errorLineNumber, e.context0);
			break;
		case SymbolAlreadyDefined:
			printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", e.errorLineNumber, e.context0, e.expressionLineNumber);
			break;
		case SymbolUndefined:
			printf("ERROR(%d): Symbol '%s' is not defined.\n", e.errorLineNumber, e.context0);
			break;
		case FunctionUndefined:
			printf("ERROR(%d): Function '%s' is not defined.\n", e.errorLineNumber, e.context0);
			break;
		case InvalidArrayOperation:
			printf("ERROR(%d): The operation '%s' does not work with arrays.\n", e.errorLineNumber, e.context0);
			break;
		case ArrayOnlyOperation:
			printf("ERROR(%d): The operation '%s' only works with arrays.\n", e.errorLineNumber, e.context0);
			break;
		case UnaryOperandTypeMismatch:
			printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", e.errorLineNumber, e.context0, e.context1, e.context2);
			break;
		case ExpectedBooleanCondition:
			printf("ERROR(%d): Expecting Boolean test condition in %s statement but got type %s.\n", e.errorLineNumber, e.context0, e.context1);
			break;
		case ReturnTypeMismatch:
			printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but instead returns type %s.\n", e.errorLineNumber, e.context0, e.expressionLineNumber, e.context1, e.context2);
			break;
		case UnexpectedReturnType:
			printf("ERROR(%d): Function '%s' at line %d is expecting no return value, but return has return value.\n", e.errorLineNumber, e.context0, e.expressionLineNumber);
			break;
		case ExpectedReturnTypeNotPresent:
			printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but return has no return value.\n", e.errorLineNumber, e.context0, e.expressionLineNumber, e.context1);
			break;
		case BreakOutsideOfLoop:
			printf("ERROR(%d): Cannot have a break statement outside of loop.\n", e.errorLineNumber);
			break;
		case InitializerNotConstant:
			printf("ERROR(%d): Initializer for variable '%s' is not a constant expression.\n", e.errorLineNumber, e.context0);
			break;
		case InitializationTypeMismatch:
			printf("ERROR(%d): Variable '%s' is of type %s but is being initialized with an expression of type %s.\n", e.errorLineNumber, e.context0, e.context1, e.context2);
			break;
		case MissingReturnStatementWarning:
			printf("WARNING(%d): Expecting to return type %s but function '%s' has no return statement.\n", e.errorLineNumber, e.context0, e.context1);
			numErrors--;
			numWarnings++;
			break;
		case FuncCallParamTypeMismatch:
			printf("ERROR(%d): Expecting type %s in parameter %s of call to '%s' defined on line %d but got type %s.\n", e.errorLineNumber, e.context0, e.context1, e.context2, e.expressionLineNumber, e.context3);
			break;
		case ExpectingArrayParam:
			printf("ERROR(%d): Expecting array in parameter %s of call to '%s' defined on line %d.\n", e.errorLineNumber, e.context0, e.context1, e.expressionLineNumber);
			break;
		case NotExpectingArrayParam:
			printf("ERROR(%d): Not expecting array in parameter %s of call to '%s' defined on line %d.\n", e.errorLineNumber, e.context0, e.context1, e.expressionLineNumber);
			break;
		case TooFewCallParams:
			printf("ERROR(%d): Too few parameters passed for function '%s' defined on line %d.\n", e.errorLineNumber, e.context0, e.expressionLineNumber);
			break;
		case TooManyCallParams:
			printf("ERROR(%d): Too many parameters passed for function '%s' defined on line %d.\n", e.errorLineNumber, e.context0, e.expressionLineNumber);
			break;
		case ArrayAsTestCondition:
			printf("ERROR(%d): Cannot use array as test condition in %s statement.\n", e.errorLineNumber, e.context0);
			break;
		case BothOrNeitherArrayRequired:
			printf("ERROR(%d): '%s' requires that either both or neither operands be arrays.\n", e.errorLineNumber, e.context0);
			break;
		case MainUndefined:
			printf("ERROR(LINKER): Procedure main is not defined.\n");
			break;
		default:
			printf("Unknown error!\n");
			break;
	}
}