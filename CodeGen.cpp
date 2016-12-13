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
    emitComment("C- compiler version C-F16");
    emitComment("Built: Dec 01, 2016");
    emitComment("Author: Domn Werner");
    emitComment("File compiled: " + fileName);
    emitSkip(1);
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

}

void GenerateIOFuncs(TreeNode* node)
{
    Instruction io[] =     { IN,    OUT,       INB,    OUTB,   INC,    OUTC,   OUTNL };
    std::string ioStr[] = { "int", "integer", "bool", "bool", "char", "char", "a newline" };

    for (int i = 0; i < 7; ++i)
    {
        node->emitLoc = emitSkip(0) - 1;
        std::string name(node->attr.name);
    }
}

