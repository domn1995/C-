#include <iostream>
#include <string>
#include "c-.tab.h"
#include "Token.h"
using namespace std;

int main()
{
	char* str = "identifier";
	Token t1(ID, str, str);
	Token t2(NUMCONST, 12345, "12345");
	Token t3(CHARCONST, '\'', "\\'");
	Token t4(BOOL, 0, "true");
	
	cout << "t1 Token Class  - " << t1.GetTokenClass() << endl;
	cout << "t1 String Value - " << t1.GetStringValue() << endl;
	cout << "t1 Token String - " << t1.GetTokenString() << endl;
	
	cout << "t2 Token Class  - " << t2.GetTokenClass() << endl;
	cout << "t2 Int Value    - " << t2.GetIntValue() << endl;
	cout << "t2 Token String - " << t2.GetTokenString() << endl;
	
	cout << "t3 Token Class  - " << t3.GetTokenClass() << endl;
	cout << "t3 Char Value   - " << t3.GetCharValue() << endl;
	cout << "t3 Token String - " << t3.GetTokenString() << endl;
	
	cout << "t4 Token Class  - " << t3.GetTokenClass() << endl;
	cout << "t4 Int Value    - " << t3.GetIntValue() << endl;
	cout << "t4 Token String - " << t3.GetTokenString() << endl;
	
	return 0;
}