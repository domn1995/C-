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

    GenerateIOFuncs(node);
    GenerateCode(node);
    GenerateInitCode(node);
}

void GenerateIOFuncs(TreeNode* node)
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
    }

    GenerateCode(node->sibling);
}



void GenerateDeclCode(TreeNode* node)
{

}

void GenerateExpCode(TreeNode* node)
{

}

void GenerateStmtCode(TreeNode* node)
{

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