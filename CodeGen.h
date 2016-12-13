#ifndef CODEGENH
#define CODEGENH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EmitCode.h"
#include "TreeNode.h"
#include "SymbolTable.h"

void EmitHeader(char* compiledFileName);
void EmitIOFuncs(TreeNode* node);
void GenerateCode(TreeNode* node, char* outFile, char* inFile);

#endif