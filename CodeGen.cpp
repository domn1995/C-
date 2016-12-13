#include <string>
#include "CodeGen.h"
#include "SymbolTable.h"

FILE* code;

extern int globalOffset;
extern int localOffset;
extern SymbolTable symbolTable;

void EmitHeader(char* compiledFileName)
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
        EmitHeader(inFile);
    }
    else
    {
        printf("Error opening file output file '%s'\n", outFile);66666666666666666
    }
}