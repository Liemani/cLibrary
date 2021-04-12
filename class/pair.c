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

static void		descriptionPair(t_pair *pair)
{
	if (!pair)
	{
		_description(pair);
		return ;
	}

	printf("{ \"type\": \"Pair\"");
	printf(", \"key\": ");
	_description(pair->key);
	printf(", \"value\": ");
	_description(pair->value);
	printf(" }");
}

void			setPair()
{
	if (!Class || classContainsInstance(Class, Pair))
		return ;

	Pair = Class->new();
	Pair->new = (newType)newPair;
	Pair->dealloc = (deallocType)deallocPair;
	Pair->description = (descriptionType)descriptionPair;
}
