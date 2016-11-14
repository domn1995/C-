#include "Utils.h"
#include <string.h>

bool StrEq(const char* str, const char* comp)
{
	if (str == NULL || comp == NULL)
	{
		return false;
	}

	if (strcmp(str, comp) == 0)
	{
		return true;
	}

	return false;
}