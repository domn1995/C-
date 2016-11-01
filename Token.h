#ifndef TOKENH
#define TOKENH

#include <string.h>

typedef struct Token
{
	int tokenClass;
	char* tokenStr;
	int lineNum;
	int intVal;
	char charVal;
} Token;
	
/* class Token 
{
private:
	char* tokenString;
	int lineNumber;
	int intValue;
	char charValue;
	char* strValue;
public:
	char* GetTokenString() { return tokenString; }
	void SetTokenString(char* tokenStr) { tokenString = strdup(tokenStr); }
	int GetLineNumber() { return lineNumber; }
	void SetLineNumber(int lineNum) { lineNumber = lineNum; }
	int GetIntValue() { return intValue; }
	void SetIntValue(int intVal) { intValue = intVal; }
	char GetCharValue() { return charValue; }
	void SetCharValue(char charVal) { charValue = charVal; }
	char* GetStrValue() { return strValue; }
	void SetStrValue(char* strVal) { strValue = strdup(strVal); }
}; */

#endif