#include <stdio.h>
#include <stdlib.h>
#include "t_pair.h"

//
//	stdio.h
//		printf()
//
//	stdlib.h
//		NULL, free()



void	setPair(void (*freeKey)(void **),
		void (*freeValue)(void **),
		void (*descriptionKey)(void *key),
		void (*descriptionValue)(void *value))
{
	Pair->freeKey = freeKey;
	Pair->freeValue = freeValue;
	Pair->descriptionKey = descriptionKey;
	Pair->descriptionValue = descriptionValue;
}

t_pair	*newPair(void *key, void *value)
{
	t_pair	*pair;

	pair = malloc(sizeof(*pair));
	if (pair == NULL)
		return (NULL);

	pair->key = key;
	pair->value = value;
	
	return (pair);
}

void	freePair(t_pair **pair)
{
	Pair->freeKey(&(*pair)->key);
	Pair->freeValue(&(*pair)->value);
	free(*pair);
	*pair = NULL;
}

void	descriptionPair(t_pair *pair)
{
	printf("(");
	descriptionKey(pair->key);
	printf(", ");
	descriptionValue(pair->value);
	printf(")");
}
