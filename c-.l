%{
#include <stdio.h>
#include "Token.h"
#include "TreeNode.h"
#include "SymbolTable.h"
#include "c-.tab.h"
extern Scope globalScope;

char GetEscapedChar(char* string)
{
	char toReturn;
	if (string[1] == '\\')
	{
		char secondChar = string[2];
		
		switch(secondChar)
		{
			case 'n':
				toReturn = '\n';
				break;
			case 't':
				toReturn = 't';
				break;
			case '0':
				toReturn = '\0';
				break;
			case '\\':
				toReturn = '\\';
				break;
			case '"':
				toReturn = '"';
				break;
			case '\'':
				toReturn = '\'';
			default:
				break;
		}
	}
	else
	{
		toReturn = string[1];
	}
	
	return toReturn;
}
%}

%option yylineno
%option noyywrap
 
%%
[\ \t\n]				; // Ignore space, new line, and tab characters.
[0-9]+				{ 
						yylval.t.tokenClass = NUMCONST;
						yylval.t.lineNum = yylineno;
						yylval.t.intVal = atoi(yytext); 
						yylval.t.tokenStr = strdup(yytext);
						return NUMCONST; 
					}
true					{ 
						yylval.t.tokenClass = BOOLCONST;
						yylval.t.lineNum = yylineno;
						yylval.t.intVal = 1;
						yylval.t.tokenStr = strdup(yytext);
						return BOOLCONST; 
					}
false				{ 
						yylval.t.tokenClass = BOOLCONST;
						yylval.t.lineNum = yylineno;
						yylval.t.intVal = 0;
						yylval.t.tokenStr = strdup(yytext);
						return BOOLCONST; 
					}
'([^'\\\n]|\\.)'		{ 
						yylval.t.tokenClass = BOOLCONST;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return CHARCONST; 
					}
record				{ 
						yylval.t.tokenClass = RECORD;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return RECORD; 
					}
static				{ 
						yylval.t.tokenClass = STATIC;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return STATIC; 
					}
int					{ 
						yylval.t.tokenClass = INT;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return INT;
					}
char					{ 	 
						yylval.t.tokenClass = CHAR;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return CHAR;
					}
bool					{ 
						yylval.t.tokenClass = BOOL;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return BOOL; 
					}
if					{ 
						yylval.t.tokenClass = IF;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return IF; 
					}
else					{ 
						yylval.t.tokenClass = ELSE;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return ELSE; 
					}
and					{ 
						yylval.t.tokenClass = AND;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return AND; 
					}
or					{ 
						yylval.t.tokenClass = OR;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return OR; 
					}
not					{ 
						yylval.t.tokenClass = NOT;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return NOT; 
					}
while 				{ 
						yylval.t.tokenClass = WHILE;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return WHILE; 
					}
break				{ 
						yylval.t.tokenClass = BREAK;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return BREAK; 
					}
return				{ 
						yylval.t.tokenClass = RETURN;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						return RETURN; 
					}
"/"					{ 
						yylval.t.tokenClass = DIV;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return DIV; 
					}
"*"					{ 
						yylval.t.tokenClass = STAR;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return STAR; 
					}
"+"					{ 
						yylval.t.tokenClass = ADD;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return ADD; 
					}
"-"					{ 
						yylval.t.tokenClass = MINUS;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return MINUS; 
					}
"%"					{ 
						yylval.t.tokenClass = PERCENT;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return PERCENT; 
					}
","					{ 
						yylval.t.tokenClass = COMMA;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return COMMA; 
					}
"="					{ 
						yylval.t.tokenClass = ASSIGN;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return ASSIGN; 
					}
"*="					{ 
						yylval.t.tokenClass = MULASS;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return MULASS; 
					}
"++"					{ 
						yylval.t.tokenClass = INC;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return INC; 
					}
"+="					{ 
						yylval.t.tokenClass = ADDASS;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return ADDASS; 
					}
"--"					{ 
						yylval.t.tokenClass = DEC;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return DEC; 
					}
"-="					{ 
						yylval.t.tokenClass = SUBASS;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return SUBASS; 
					}
"/="					{ 
						yylval.t.tokenClass = DIVASS;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return DIVASS; 
					}
"<"					{ 
						yylval.t.tokenClass = LTHAN;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return LTHAN; 
					}
"<="					{ 
						yylval.t.tokenClass = LESSEQ;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return LESSEQ; 
					}
"=="					{ 
						yylval.t.tokenClass = EQ;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return EQ; 
					}
"!="					{ 
						yylval.t.tokenClass = NOTEQ;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return NOTEQ; 
					}
">"					{ 
						yylval.t.tokenClass = GTHAN;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return GTHAN; 
					}
">="					{ 
						yylval.t.tokenClass = GRTEQ;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return GRTEQ; 
					}
"?"					{ 
						yylval.t.tokenClass = QMARK;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return QMARK; 
					}
"("					{ 
						yylval.t.tokenClass = LPAREN;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return LPAREN; 
					}
")"					{ 
						yylval.t.tokenClass = RPAREN;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return RPAREN; 
					}
"{"					{ 
						yylval.t.tokenClass = LCURLY;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return LCURLY; 
					}
"}"					{ 
						yylval.t.tokenClass = RCURLY;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return RCURLY; 
					}
"["					{ 
						yylval.t.tokenClass = LBRACKET;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return LBRACKET; 
					}
"]"					{ 
						yylval.t.tokenClass = RBRACKET;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return RBRACKET; 
					}
[a-zA-Z]+[0-9a-zA-Z]*	{ 
						int tokenType = ID;						
						
						// If this identifier is actually a record type, we should return RECTYPE instead.
						if (static_cast<char*>(globalScope.lookup(yytext)) != NULL && strcmp(static_cast<char*>(globalScope.lookup(yytext)), "recordType") == 0)
						{								
							tokenType = RECTYPE;
						}						
						yylval.t.tokenClass = tokenType;
						yylval.t.lineNum = yylineno;
						yylval.t.tokenStr = strdup(yytext);
						
						return tokenType; 
					}
"."					{ 
						yylval.t.tokenClass = DOT;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return DOT; 
					}
":"					{ 
						yylval.t.tokenClass = COLON;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return COLON; 
					}
";"					{ 
						yylval.t.tokenClass = SEMICOLON;
						yylval.t.lineNum = yylineno;
						yylval.t.charVal = GetEscapedChar(yytext);
						yylval.t.tokenStr = strdup(yytext);
						return SEMICOLON; 
					}
"//".*				; // Do nothing.
.					{ return ERROR; }
%%