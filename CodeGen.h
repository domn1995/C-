#ifndef CODEGENH
#define CODEGENH

#include "TreeNode.h"
#include "SymbolTable.h"

void GenerateHeader(char* compiledFileName);
void GenerateIOFuncs(TreeNode* node);
void GenerateCode(TreeNode* node, char* outFile, char* inFile);
void GenerateCode(TreeNode* node);
void GenerateDecl(TreeNode* node);
void GenerateExp(TreeNode* node);
void GenerateStmt(TreeNode* node);
void GenerateConst(TreeNode* node);
void GenerateGlobalsAndStatics(TreeNode* node);

#endif