%{
#include "c-.tab.h"
#include <cstdio>

%}

%option yylineno
%option noyywrap
 
%%
[\ \t\n]				; // Ignore space, new line, and tab characters.
[0-9]+				{ return NUMCONST; }
true					{ return BOOLCONST; }
false				{ return BOOLCONST; }
'([^'\\\n]|\\.)'		{ return CHARCONST; }
record				{ return RECORD; }
static				{ return STATIC; }
int					{ return INT; }
char					{ return CHAR; }
bool					{ return BOOL; }
if					{ return IF; }
else					{ return ELSE; }
and					{ return AND; }
or					{ return OR; }
not					{ return NOT; }
while 				{ return WHILE; }
return				{ return RETURN; }
"/"					{ return DIV; }
"*"					{ return STAR; }
"+"					{ return ADD; }
"-"					{ return MINUS; }
"%"					{ return PERCENT; }
","					{ return COMMA; }
"="					{ return ASSIGN; }
"*="					{ return MULASS; }
"++"					{ return INC; }
"+="					{ return ADDASS; }
"--"					{ return DEC; }
"-="					{ return SUBASS; }
"/="					{ return DIVASS; }
"<"					{ return LTHAN; }
"<="					{ return LESSEQ; }
"=="					{ return EQ; }
"!="					{ return NOTEQ; }
">"					{ return GTHAN; }
">="					{ return GRTEQ; }
"?"					{ return QMARK; }
"("					{ return LPAREN; }
")"					{ return RPAREN; }
"{"					{ return LCURLY; }
"}"					{ return RCURLY; }
"["					{ return LBRACKET; }
"]"					{ return RBRACKET; }
[a-zA-Z]+[0-9a-zA-Z]*	{ return ID; }
"."					{ return DOT; }
":"					{ return COLON; }
";"					{ return SEMICOLON; }
"//".*				; // Do nothing.
.					{ return ERROR; }
%%