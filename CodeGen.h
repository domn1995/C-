#ifndef CODEGENH
#define CODEGENH

#include "TreeNode.h"
#include "SymbolTable.h"

void GenerateHeader(char* compiledFileName);
void GenerateIOCode(TreeNode* node);
void GenerateCode(TreeNode* node, char* outFile, char* inFile);
void GenerateCode(TreeNode* node);
void GenerateDeclCode(TreeNode* node);
void GenerateExpCode(TreeNode* node);
void GenerateStmtCode(TreeNode* node);
void GenerateConstCode(TreeNode* node);
void GenerateGlobalsAndStaticsCode(TreeNode* node);
void GenerateInitCode(TreeNode* node);
void SkipIONodesAndGenerateCode(TreeNode* node);

#endif