#include <stdio.h>
#include <stdlib.h>

#include "kernelClass/class.h"
#include "class/pair.h"



static t_pair	*newPair()
{
	t_pair	*pair;

	lmtAlloc(pair);
	classAddInstance(Pair, pair);

	return (pair);
}

static void		deallocPair(t_pair *pair)
{
	if (!pair)
		return ;

	classRemoveInstance(Pair, pair);

	free(pair);
}

static t_string	*descriptionPair(t_pair *pair)
{
	t_string	*string;

	string = String->new();

	if (!pair)
	{
		stringMergeString(string, description(pair));
		return (string);
	}

	stringAppendStr(string, "{ \"type\": \"Pair\"");
	stringAppendStr(string, ", \"key\": ");
	stringMergeString(string, description(pair->key));
	stringAppendStr(string, ", \"value\": ");
	stringMergeString(string, description(pair->value));
	stringAppendStr(string, " }");

	return (string);
}

void			setPairClass()
{
	if (!Class || classContainsInstance(Class, Pair))
		return ;

	Pair = Class->new();
	Pair->new = (newType)newPair;
	Pair->dealloc = (deallocType)deallocPair;
	Pair->description = (descriptionType)descriptionPair;
}
