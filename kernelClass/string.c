#include <stdio.h>
#include <string.h>

#include "kernelClass/class.h"



t_string	*newString()
{
	t_string	*string;

	lmtAlloc(string);
	classAddInstance(String, string);

	return (string);
}

void		deallocString(t_string *string)
{
	if (!string)
		return ;

	classRemoveInstance(String, string);

	free(string->value);
	free(string);
}

void		descriptionString(t_string *string)
{
	if (!string)
	{
		descriptionPointer(string);
		return ;
	}

	if (string->value)
		printf("\"%s\"", string->value);
	else
		descriptionPointer(string->value);
}

void		setString()
{
	if (!Class || classContainsInstance(Class, String))
		return ;

	String = Class->new();
	String->new = (newType)newString;
	String->dealloc = (deallocType)deallocString;
	String->description = (descriptionType)descriptionString;
}

void		initString(t_string *string, char *str)
{
	string->value = strdup(str);
}
