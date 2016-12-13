#ifndef CODEGENH
#define CODEGENH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeNode.h"
#include "SymbolTable.h"

void GenerateHeader(char* compiledFileName);
void GenerateIOFuncs(TreeNode* node);
void GenerateCode(TreeNode* node, char* outFile, char* inFile);

#endif