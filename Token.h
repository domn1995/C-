#ifndef TOKENH
#define TOKENH

#include <string>

class Token
{
	private: 
		int tokenClass;
		int intValue;
		char charValue;
		std::string stringValue;
		std::string tokenString;
		
	public:
		Token();
		Token(int tokClass, char* tokenString);
		Token(int tokClass, int intVal, char* tokenStr);
		Token(int tokClass, char charVal, char* tokenStr);
		Token(int tokClass, char* stringVal, char* tokenStr);
		int GetTokenClass() { return tokenClass; }
		void SetTokenClass(int tokClass) { tokenClass = tokClass; }
		int GetIntValue() { return intValue; }
		void SetIntValue(int intVal) { intValue = intVal; }
		char GetCharValue() { return charValue; }
		void SetCharValue(char charVal) { charValue = charVal; }
		std::string GetStringValue() { return stringValue; }
		void SetStringValue(char* stringVal ) { stringValue = stringVal; }
		std::string GetTokenString() { return tokenString; }
		void SetTokenString(std::string tokenStr) { tokenString = tokenStr; }
};


#endif