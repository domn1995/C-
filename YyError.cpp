#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include "YyError.h"

extern int yylineno;
int numErrors = 0, numWarnings = 0;

// // // // // // // // // // // // // // // // // // // // 
//
// Error message printing
//
// Must make messages look nice.  For example:
// msg = "syntax error, unexpected ',', expecting BOOL or CHAR or INT or ID."
// becomes (xx marks important data):
//  0 syntax
//  1 error,
//  2 unexpected
//  3 ',',    xx
//  4 expecting
//  5 BOOL    xx
//  6 or
//  7 CHAR    xx
//  8 or
//  9 INT     xx
// 10 or
// 11 ID.     xx

// assumes a string with breakchar separating each element.
// breakchars will be replaced by null chars: '\0'
// array of pointers to strings is then returned in
// the array strs which must be allocated by the user!
// the number of strings found is returned as a value of
// the function.  This number is always at least 1.
// The array is terminated by a NULL so there must be
// enough room for all the string pointers plus one for the
// sentinal marker.
int Split(char* s, char* strs[], char breakChar)
{
	int num;

	strs[0] = s;
	num = 1;
	for (char *p = s; *p; p++) {
		if (*p == breakChar) {
			strs[num++] = p + 1;
			*p = '\0';
		}
	}
	strs[num] = NULL;

	return num;
}


// trim off the last character
void Trim(char *s)
{
	s[strlen(s) - 1] = '\0';
}



// map from string to char * for storing nice translation of
// internal names for tokens.  Preserves (char *) used by
// bison.
static std::map<std::string, char *> niceTokenNameMap;    // use an ordered map (not as fast as unordered)

														  // WARNING: this routine must be called to initialize mapping of
														  // (strings returned as error message) --> (human readable strings)
														  //
void initErrorProcessing() 
{
	niceTokenNameMap["AND"] = static_cast<char *>("and");
	niceTokenNameMap["OR"] = static_cast<char *>("or");
	niceTokenNameMap["NOT"] = static_cast<char *>("not");
	niceTokenNameMap["NOTEQ"] = static_cast<char *>("'!='");
	niceTokenNameMap["MULASS"] = static_cast<char *>("'*='");
	niceTokenNameMap["INC"] = static_cast<char *>("'++'");
	niceTokenNameMap["ADDASS"] = static_cast<char *>("'+='");
	niceTokenNameMap["DEC"] = static_cast<char *>("'--'");
	niceTokenNameMap["SUBASS"] = static_cast<char *>("'-='");
	niceTokenNameMap["DIVASS"] = static_cast<char *>("'/='");
	niceTokenNameMap["LESSEQ"] = static_cast<char*>("'<='");
	niceTokenNameMap["EQ"] = static_cast<char*>("'=='");
	niceTokenNameMap["GRTEQ"] = static_cast<char*>("'>='");
	niceTokenNameMap["BOOL"] = static_cast<char*>("bool");
	niceTokenNameMap["BREAK"] = static_cast<char*>("break");
	niceTokenNameMap["CHAR"] = static_cast<char*>("char");
	niceTokenNameMap["ELSE"] = static_cast<char*>("else");
	niceTokenNameMap["FOREACH"] = static_cast<char*>("foreach");
	niceTokenNameMap["IF"] = static_cast<char*>("if");
	niceTokenNameMap["IN"] = static_cast<char*>("in");
	niceTokenNameMap["INT"] = static_cast<char*>("int");
	niceTokenNameMap["RECTYPE"] = static_cast<char*>("rectype");
	niceTokenNameMap["RETURN"] = static_cast<char*>("return");
	niceTokenNameMap["STATIC"] = static_cast<char*>("static");
	niceTokenNameMap["WHILE"] = static_cast<char*>("while");
	niceTokenNameMap["BOOLCONST"] = static_cast<char*>("Boolean constant");
	niceTokenNameMap["NUMCONST"] = static_cast<char*>("numeric constant");
	niceTokenNameMap["ID"] = static_cast<char*>("identifier");
	niceTokenNameMap["CHARCONST"] = static_cast<char*>("character constant");
	niceTokenNameMap["STRINGCONST"] = static_cast<char*>("string constant");
	niceTokenNameMap["$end"] = static_cast<char*>("end of input");
}


// looks of pretty printed words for tokens that are
// not already in single quotes.  It uses the niceTokenNameMap table.
char* NiceTokenStr(char* tokenName)
{
	if (tokenName[0] == '\'')
	{
		return tokenName;
	}

	if (niceTokenNameMap.find(tokenName) == niceTokenNameMap.end()) 
	{
		printf("ERROR(SYSTEM): NiceTokenStr fails to find string '%s'\n", tokenName);
		fflush(stdout);
		exit(1);
	}
	return niceTokenNameMap[tokenName];
}


// Is this a message that we need to elaborate with the current parsed token.
// This elaboration is some what of a crap shoot since the token could
// be already overwritten with a look ahead token.   But probably not.
bool Elaborate(char* s)
{
	return (strstr(s, "constant") || strstr(s, "identifier"));
}


// A tiny sort routine for SMALL NUMBERS of
// of char * elements.  num is the total length
// of the array but only every step elements will
// be sorted.  The "up" flag is direction of sort.
// For example:
//    tinySort(str, i, 2, direction);      // sorts even number elements in array
//    tinySort(str+1, i-1, 2, direction);  // sorts odd number elements in array
//    tinySort(str, i, 1, direction);      // sorts all elements in array
//
void TinySort(char* base[], int num, int step, bool up)
{
	for (int i = step; i<num; i += step) {
		for (int j = 0; j<i; j += step) {
			if (up ^ (strcmp(base[i], base[j])>0)) {
				char *tmp;
				tmp = base[i]; base[i] = base[j]; base[j] = tmp;
			}
		}
	}
}


// This is the yyerror called by the bison parser for errors.
// It only does errors and not warnings.   
void yyerror(const char *msg)
{
	char *space;
	char *strs[100];
	int numstrs;

	// make a copy of msg string
	space = strdup(msg);

	// split out components
	numstrs = Split(space, strs, ' ');
	if (numstrs > 4)
	{
		Trim(strs[3]);
	}
	// translate components
	for (int i = 3; i < numstrs; i += 2) 
	{
		strs[i] = NiceTokenStr(strs[i]);
	}

	// print components
	printf("ERROR(%d): Syntax error, unexpected %s", yylineno, strs[3]);
	if (Elaborate(strs[3])) {
		if (yytext[0] == '\'' || yytext[0] == '"') printf(" %s", yytext);
		else printf(" \'%s\'", yytext);
	}

	if (numstrs > 4)
	{
		printf(",");
	}
	// print sorted list of expected
	TinySort(strs + 5, numstrs - 5, 2, true);
	for (int i = 4; i<numstrs; i++) 
	{
		printf(" %s", strs[i]);
	}
	printf(".\n");
	fflush(stdout);   // force a dump of the error

	numErrors++;

	free(space);
}