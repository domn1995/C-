#include "Token.h"
#include <string>

Token::Token()
{
	tokenClass = 0;
	intValue = 0;
	tokenString = "NULL";
}

Token::Token(int tokClass, int intVal, char* tokenStr)
{
	tokenClass = tokClass;
	tokenString = tokenStr;
	intValue = intVal;
}

Token::Token(int tokClass, char charVal, char* tokenStr)
{
	tokenClass = tokClass;
	tokenString = tokenStr;
	charValue = charVal;
}

Token::Token(int tokClass, char* stringVal, char* tokenStr)
{
	tokenClass = tokClass;
	tokenString = tokenStr;
	stringValue = stringVal;
}