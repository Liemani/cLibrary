#include <stdio.h>
#include <stdlib.h>

#include "t_pair.h"
#include "class.h"



static t_pair	*_newPair()
{
	t_pair	*pair;

	lmtAlloc(pair);
	
	classAddInstance(Pair, pair);

	return (pair);
}

static void		_deallocPair(t_pair *pair)
{
	if (!pair)
		return ;

	classRemoveInstance(Pair, pair);

	free(pair);
}

static void		_descriptionPair(t_pair *pair)
{
	if (!pair)
	{
		description(pair);
		return ;
	}

	printf("t_pair: [ key: ");
	description(pair->key);
	printf(", value: ");
	description(pair->value);
	printf(" ]");

}

void			setPair()
{
	if (!Class || classContainsInstance(Class, Pair))
		return ;

	Pair = Class->new();
	Pair->new = (newType)_newPair;
	Pair->dealloc = (deallocType)_deallocPair;
	Pair->description = (descriptionType)_descriptionPair;
}
