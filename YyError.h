#pragma once
#ifndef YYERRORH
#define YYERRORH

extern int line;
extern int numErrors;
extern char* yytext;

int Split(char* s, char* strs[], char breakChar);
void InitErrorProcessing();
void yyerror(const char* msg);

#endif