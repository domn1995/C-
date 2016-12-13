#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "CodeGen.h"
#include "SymbolTable.h"
#include "EmitCode.h"

FILE* code;

extern int globalOffset;
extern int localOffset;
extern SymbolTable symbolTable;

bool init = false, store = false, opStore = false, opLoad = false, unary = false;
int numStatics = 0, compSize = 0, numParams = 0, tempIndex = 0, breakLocation = 0;
Instruction opCode;
std::string currentOpName;

void GenerateHeader(char* compiledFileName)
{
    std::string fileName(compiledFileName);
    EmitComment("C- compiler version C-F16");
    EmitComment("Built: Nov 13, 2016");
    EmitComment("Author: Robert B. Heckendorn");
    EmitComment("File compiled: " + fileName);
    EmitEmptyLine();
    EmitSkip(1);
}

void GenerateCode(TreeNode* node, char* inFile, char* outFile)
{
    code = fopen(outFile, "w");

    if (code)
    {
        GenerateHeader(inFile);
    }
    else
    {
        printf("Error opening file output file '%s'\n", outFile);
    }

    GenerateIOCode(node);
    GenerateCode(node);
    GenerateInitCode(node);
}

void GenerateIOCode(TreeNode* node)
{
    Instruction io[] =    { IN,    OUT,       INB,    OUTB,   INC,    OUTC,   OUTNL };
    std::string ioStr[] = { "int", "integer", "bool", "bool", "char", "char", "a newline" };

    for (int i = 0; i < 7; ++i)
    {
        node->emitLoc = EmitSkip(0) - 1;
        std::string funcName(node->attr.name);
        EmitComment("FUNCTION " + funcName);
        EmitInstruction(ST, AC, -1, FP, "Store return address");
        if (i % 2 == 0)
        {
            int s = 2;
            std::string c1 = "Grab ";
            std::string c2 = " input";
            if (i == 6)
            {
                s = 3;
                c1 = "Output ";
                c2 = "";
            }
            EmitInstruction(io[i], s, s, s, c1 + ioStr[i] + c2, false);
        }
        else
        {
            EmitInstruction(LD, AC, -2, FP, "Load parameter");
            EmitInstruction(io[i], 3, 3, 3, "Output " + ioStr[i], false);
            EmitInstruction(LDC, RT, 0, 6, "Set return to 0");
        }
        EmitInstruction(LD, AC, -1, FP, "Load return address");
        EmitInstruction(LD, FP, 0, FP, "Adjust fp");
        EmitInstruction(LDA, PC, 0, AC, "Return");
        EmitComment("END FUNCTION " + funcName);
        EmitEmptyLine();
        node = node->sibling;
    }
}

void GenerateCode(TreeNode* node)
{
    if (node == NULL)
    {
        return;
    }

    switch (node->nodeKind)
    {
        case DeclK:
            GenerateDeclCode(node);
            break;
        case ExpK: 
            GenerateExpCode(node);
            break;
        case StmtK:
            GenerateStmtCode(node);
            break;
        default:
            printf("ERROR: Unknown NodeKind in GenerateCode()\n");
            break;
    }

    GenerateCode(node->sibling);
}

void GenerateDeclCode(TreeNode* node)
{
    std::string name = node->attr.name;
    switch (node->kind.decl)
    {
        case VarK:
        {
            store = false;
            if ((!node->isStatic && !node->isGlobal) || ((node->isStatic || node->isGlobal) && init))
            {
                if (node->isArray)
                {
                    EmitInstruction(LDC, AC, node->memSize - 1, 6, "load size of array " + name);
                    EmitInstruction(ST, AC, node->memOffset + 1, FP, "save size of array " + name);
                }
                else
                {
                    TreeNode* firstChild = node->children[0];
                    if (firstChild != NULL)
                    {
                        GenerateCode(firstChild);
                        EmitInstruction(ST, AC, node->memOffset, FP, "Store variable " + name);
                    }
                }
            }
            break;
        }            
        case FuncK:
        {
            TreeNode* temp = node->children[0];
            int numParams = 0;

            if (temp != NULL)
            {
                for (numParams; temp != NULL; ++numParams)
                {
                    temp = temp->sibling;
                }

                if (node->children[1] != NULL)
                {
                    if (!(node->children[1]->nodeKind == StmtK && node->children[1]->kind.stmt == CompK))
                    {
                        tempIndex -= (numParams + 2);
                    }
                }                
            }

            node->emitLoc = EmitSkip(0) - 1;

            EmitComment("FUNCTION " + name);
            EmitInstruction(ST, AC, -1, FP, "Store return address.");

            for (int i = 0; i < 3; ++i)
            {
                GenerateCode(node->children[i]);
            }

            EmitComment("Add standard closing in case there is no return statement");
            EmitInstruction(LDC, RT, 0, 6, "Set return value to 0");
            EmitInstruction(LD, AC, -1, FP, "Load return address");
            EmitInstruction(LD, FP, 0, FP, "Adjust fp");
            EmitInstruction(LDA, PC, 0, AC, "Return");

            EmitComment("END FUNCTION " + name);
            tempIndex = 0;
            break;
        }            
        case ParamK:
        {
            for (int i = 0; i < 3; ++i)
            {
                GenerateCode(node->children[i]);
            }
            break;
        }            
        default:
            printf("ERROR: Unknown DeclK node in GenerateDeclCode()\n");
            break;
    }
}

void GenerateExpCode(TreeNode* node)
{
    std::string name;
    Instruction loadInstruction = LDA;
    int pointer = GP;
    int savedIndex = 0;

    if (node->kind.exp != ConstK)
    {
        name = node->attr.name;
    }
    else
    {
        name = "";
    }

    TreeNode* left = node->children[0];
    TreeNode* right = node->children[1];

    if (node->isParam)
    {
        EmitComment("                       Load param " + (numParams + 1));
    }

    switch (node->kind.exp)
    {
        case AssignK:
        {
            currentOpName = name;
            EmitComment("EXPRESSION");
            if ("++" == name || "--" == name)
            {
                opCode = LDA;
            }
            else if ("+=" == name)
            {
                opCode = ADD;
            }
            else if ("-=" == name)
            {
                opCode = SUB;
            }
            else if ("*=" == name)
            {
                opCode = MUL;
            }
            else if ("/=" == name)
            {
                opCode = DIV;
            }

            opStore = false;
            store = false;
            unary = false;
            opLoad = false;

            if (left->isArray)
            {
                if (left->children[0] != NULL)
                {
                    store = false;
                    GenerateCode(left->children[0]);
                    EmitInstruction(ST, AC, compSize + tempIndex, FP, "Save index");
                    tempIndex--;
                }
            }

            currentOpName = name;

            store = opStore = opLoad = unary = false;

            if ("=" == name)
            {
                store = true;
                opStore = false;
            }
            else
            {
                if ("--" == name || "++" == name)
                {
                    unary = true;
                }
                else
                {
                    unary = false;
                }
                store = opStore = opLoad = true;
            }
            
            GenerateCode(left);

            opStore = false;
            currentOpName = name;

            if (left->isArray && left->children[0] != NULL)
            {
                tempIndex++;
            }
            break;
        }
        case OpK:
        {
            store = false;
            loadInstruction = LDA;

            if (left->isArray)
            {
                loadInstruction = LD;
            }

            if (node->isStatic || node->isGlobal)
            {
                pointer = GP;
            }
            else
            {
                pointer = FP;
            }

            if (right == NULL)
            {
                GenerateCode(left);

                if ("*" == name)
                {
                    if (left->memSize == 1)
                    {
                        loadInstruction = LD;                        
                    }
                    EmitInstruction(LD, AC, 1, AC, "Load array size");
                }
                else if ("?" == name)
                {
                    EmitInstruction(RND, AC, AC, 6, "Op ?");
                }
                else if ("!" == name)
                {
                    EmitInstruction(LDC, AC1, 1, 6, "Load 1");
                    EmitInstruction(XOR, AC, AC, AC1, "Op NOT ");
                }
                else if ("-" == name)
                {
                    EmitInstruction(LDC, AC1, 0 , 6, "Load 0");
                    EmitInstruction(SUB, AC, AC1, AC, "Op unary -");
                }
            }
            else
            {
                GenerateCode(left);
                savedIndex = tempIndex;
                tempIndex--;
                EmitInstruction(ST, 3, compSize + savedIndex - numParams, FP, "Save left side");
                GenerateCode(right);
                EmitInstruction(LD, AC1, compSize + savedIndex - numParams, FP, "Load left into ac1");
                tempIndex++;

                if (">" == name)
                {
                    EmitInstruction(TGT, AC, AC1, AC, "Op >");
                }
                else if ("<" == name)
                {
                    EmitInstruction(TLT, AC, AC1, AC, "Op <");
                }
                else if (">=" == name)
                {
                    EmitInstruction(TGE, AC, AC1, AC, "Op >=");
                }
                else if ("<=" == name)
                {
                    EmitInstruction(TLE, AC, AC1, AC, "Op <=");
                }
                else if ("==" == name)
                {
                    EmitInstruction(TEQ, AC, AC1, AC, "Op ==");
                }
                else if ("or" == name)
                {
                    EmitInstruction(OR, AC, AC1, AC, "Op OR");
                }
                else if ("and" == name)
                {
                    EmitInstruction(AND, AC, AC1, AC, "Op AND");
                }
                else if ("+" == name)
                {
                    EmitInstruction(ADD, AC, AC1, AC, "Op +");
                }
                else if ("-" == name)
                {
                    EmitInstruction(SUB, AC, AC1, AC, "Op -");
                }
                else if ("*" == name)
                {
                    EmitInstruction(MUL, AC, AC1, AC, "Op *");
                }
                else if ("/" == name)
                {
                    EmitInstruction(DIV, AC, AC1, AC, "Op /");
                }
                else if ("%" == name)
                {
                    EmitInstruction(DIV, AC2, AC1, AC, "Op %");
                    EmitInstruction(MUL, AC2, AC2, AC, "");
                    EmitInstruction(SUB, AC, AC1, AC2, "");
                }
                break;
            }
            case ConstK:
            {
                GenerateConstCode(node);
                break;
            }
            case IdK:
            {
                if (node->isGlobal || node->isStatic)
                {
                    pointer = 0;
                }
                else
                {
                    pointer = 1;
                }

                if (node->memSize == 1)
                {
                    loadInstruction = LD;
                }

                if (!store)
                {
                    if (node->isArray)
                    {
                        if (left != NULL)
                        {
                            GenerateCode(left);
                            EmitInstruction(loadInstruction, AC1, node->memOffset, pointer, "Load address of base of array " + name);
                            EmitInstruction(SUB, AC, AC1, AC, "Compute offset of value");
                            EmitInstruction(LD, opLoad ? (unary ? AC : AC1) : AC, 0 , AC, opLoad ? "Load LHS value" : "Load the value");                        
                        }
                        else
                        {
                            EmitInstruction(LD, opLoad ? (unary ? AC : AC1) : AC, node->memOffset, pointer, opLoad ? "Load LHS address of base of array " : "Load address of base of array " + name);
                        }
                    }
                    else
                    {
                        EmitInstruction(LD, opLoad ? (unary ? AC : AC1) : AC, node->memOffset, pointer, (opLoad ? "load lhs variable " : "Load variable ") + name);
                    }
                }
                else
                {
                    if (node->isArray)
                    {
                        if (left != NULL)
                        {
                            EmitInstruction(LD, AC1, compSize + tempIndex + 1, FP, "Restore index");
                            EmitInstruction(loadInstruction, AC2, node->memOffset, pointer, "Load address of base of array " + name);
                            EmitInstruction(SUB, AC2, AC2, AC1, "Compute offset of value");

                            if (opStore)
                            {
                                EmitInstruction(LD, opLoad ? (unary ? AC : AC1) : AC, 0 , AC2, "load lhs variable " + name);
                                if ("++" == currentOpName)
                                {
                                    EmitInstruction(LDA, AC, 1, AC, "increment value of " + name);
                                }
                                else if ("--" == currentOpName)
                                {
                                    EmitInstruction(LDA, AC, -1, AC, "decrement value of " + name);
                                }
                                else 
                                {
                                    EmitInstruction(opCode, AC, AC1, AC, "op " + currentOpName);
                                }
                            }
                            EmitInstruction(ST, AC, node->memOffset, pointer, "Store variable " + name);
                        }
                    }
                }
                break;
            }
            case CallK:
            {
                TreeNode* function = static_cast<TreeNode*>(symbolTable.lookup(node->attr.name));
                tempIndex -= 2;
                numParams = 0;
                int params = numParams;
                bool st = store;
                int ti = tempIndex;
                int cs = compSize;
                store = opLoad = false;

                EmitComment("EXPRESSION");
                EmitComment("                       Begin call to " + name);
                EmitInstruction(ST, FP, cs + ti + 2, FP, "Store old fp in ghost frame");

                GenerateCode(left);

                store = st;
                numParams = params;
                compSize = cs;

                EmitComment("                       Jump to " + name);
                EmitInstruction(LDA, FP, compSize + ti + 2, FP, "Load address of new frame");
                EmitInstruction(LDA, AC, FP, PC, "Return address in ac");
                EmitInstruction(LDA, PC, function->emitLoc - EmitSkip(0), PC, "CALL " + name);
                EmitInstruction(LDA, AC, 0 , RT, "Save the result in ac");
                EmitComment("                       End call to " + name);

                tempIndex += 2;
                break;
            }
        }
        if (node->isParam)
        {
            EmitInstruction(ST, AC, compSize - numParams + tempIndex, FP, "Store parameter");
        }
    }
}

void GenerateStmtCode(TreeNode* node)
{
    int ifSkip, ifLoc, whileSkip, whileLocation, breakLoc;
    TreeNode* left = node->children[0];
    TreeNode* right = node->children[1];
    TreeNode* last = node->children[2];

    switch (node->kind.stmt)
    {
        case IfK:
        {
            EmitComment("IF");
            store = opLoad = false;
            GenerateCode(left);
            ifLoc = EmitSkip(1);
            EmitComment("THEN");
            EmitComment("EXPRESSION");
            GenerateCode(right);
            ifSkip = EmitSkip(0);

            EmitBackup(ifLoc);

            if (last != NULL)
            {
                ifSkip++;
            }

            EmitInstruction(JZR, AC, ifSkip - EmitSkip(0) - 1, PC, "Jump around the THEN if false [backpatch]");
            EmitRestore();

            if (last != NULL)
            {
                EmitComment("ELSE");
                EmitComment("EXPRESSION");
                ifLoc = EmitSkip(1);
                GenerateCode(last);
                ifSkip = EmitSkip(0);
                EmitBackup(ifLoc);
                EmitInstruction(LDA, PC, ifSkip - EmitSkip(0) - 1, PC, "Jump around the ELSE [backpatch]");
                EmitRestore();
            }

            EmitComment("ENDIF");
            break;
        }
        case WhileK:
        {
            store = opLoad = false;
            whileLocation = EmitSkip(0);
            EmitComment("WHILE");
            GenerateCode(left);
            EmitInstruction(JNZ, AC, 1, PC, "Jump to while part");
            whileSkip = EmitSkip(1);
            breakLoc = breakLocation;
            breakLocation = EmitSkip(0);

            EmitComment("DO");
            GenerateCode(right);

            EmitInstruction(LDA, PC, whileLocation - EmitSkip(0) - 1, PC, "go to beginning of loop");
            whileLocation = EmitSkip(0);
            EmitBackup(whileSkip);
            EmitInstruction(LDA, PC, whileLocation - whileSkip - 1, PC, "Jump past loop [backpatch]");
            EmitRestore();

            breakLocation = breakLoc;
            EmitComment("ENDWHILE");
            break;
        }
        case BreakK:
        {
            EmitComment("BREAK");
            EmitInstruction(LDA, PC, breakLocation - EmitSkip(0) - 2, PC, "break");
            break;
        }
        case ReturnK:
        {
            EmitComment("RETURN");
            store = opLoad = false;
            GenerateCode(left);

            if (left != NULL)
            {
                EmitInstruction(LDA, RT, 0, AC, "Copy result of rt register");
            }

            EmitInstruction(LD, AC, -1, FP, "Load return address");
            EmitInstruction(LD, FP, 0, FP, "Adjust fp");
            EmitInstruction(LDA, PC, 0, AC, "Return");
            break;
        }
        case CompK:
        {
            compSize = node->memSize;
            EmitComment("COMPOUND");
            GenerateCode(left);
            GenerateCode(right);
            GenerateCode(last);
            EmitComment("END COMPOUND");
            break;
        }
        default:
        {
            printf("ERROR: Unknown NodeKind in GenerateStmtCode()\n");
        }
    }
}

void GenerateConstCode(TreeNode* node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->nodeKind == ExpK && node->kind.exp == ConstK)
    {
        switch (node->expType)
        {
            case Int:
                EmitInstruction(LDC, AC, node->attr.value, 6, "Load integer constant");
                break;
            case Bool:
                EmitInstruction(LDC, AC, node->attr.value, 6, "Load Boolean constant");
                break;
            case Char:
                EmitInstruction(LDC, AC, node->attr.cValue, 6, "Load char constant");
                break;
            default:
                printf("Invalid ConstK type in GenerateConstCode()\n");
                break;
        }
    }
}

void GenerateGlobalsAndStaticsCode(TreeNode* node)
{
    init = true;
    compSize = -2;

    if (node == NULL)
    {
        return;
    }

    if (node->nodeKind == DeclK && node->kind.decl == VarK)
    {
        if (node->isGlobal || node->isStatic)
        {
            std::string nodeName(node->attr.name);
            std::string stat = node->isStatic ? "-" + numStatics : "";

            if (node->isArray)
            {
                EmitInstruction(LDC, AC, node->memSize - 1, 6, "load size of array " + nodeName + stat);
                EmitInstruction(ST, AC, node->memOffset + 1, 0 , "save size of array " + nodeName + stat);
            }
            else
            {
                if (node->children[0] != NULL)
                {
                    GenerateCode(node->children[0]);
                    EmitInstruction(ST, AC, node->memOffset, GP, "Store variable " + nodeName + stat);
                }
            }
            
            if (node->isStatic)
            {
                numStatics++;
            }
        }
    }

    for (int i = 0; i < MAXCHILDREN; ++i)
    {
        GenerateGlobalsAndStaticsCode(node->children[i]);
    }
    GenerateGlobalsAndStaticsCode(node->sibling);
}

void GenerateInitCode(TreeNode* node)
{
    TreeNode* main = static_cast<TreeNode*>(symbolTable.lookup("main"));
    EmitBackup(0);
    EmitInstruction(LDA, PC, EmitSkip(0) - 1, PC, "Jump to init [backpatch]");
    EmitSkip(EmitSkip(0) - 1);
    EmitComment("INIT");
    EmitInstruction(LD, GP, 0, 0, "Set the global pointer");
    EmitInstruction(LDA, FP, globalOffset, GP, "set first frame at end of globals");
    EmitInstruction(ST, FP, 0, FP, "store old fp (point to self)");
    EmitComment("INIT GLOBALS AND STATICS");
    GenerateGlobalsAndStaticsCode(node);
    EmitComment("END INIT GLOBALS AND STATICS");
    EmitInstruction(LDA, AC, FP, PC, "Return address in ac");
    EmitInstruction(LDA, PC, main->emitLoc - EmitSkip(0), PC, "Jump to main");
    EmitInstruction(HALT, 0, 0, 0, "DONE!", false);
    EmitComment("END INIT");
}