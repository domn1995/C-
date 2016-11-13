#pragma once
#ifndef YYERRORH
#define YYERRORH

extern char* yytext;

int Split(char* s, char* strs[], char breakChar);
void InitErrorProcessing();
void yyerror(const char* msg);

#endif