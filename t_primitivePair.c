#include <stdio.h>
#include <stdlib.h>
#include "t_primitivePair.h"

//	stdio.h
//		printf()
//
//	stdlib.h
//		NULL, free()



t_primitivePair	*newPrimitivePair(void *key,
		void *value,
		void (*freeKey)(void **key),
		void (*freeValue)(void **value),
		void (*descriptionKey)(void *key),
		void (*descriptionValue)(void *value))
{
	t_primitivePair	*pair;

	pair = malloc(sizeof(t_primitivePair));
	if (pair == NULL)
		return (NULL);

	pair->key = key;
	pair->value = value;
	pair->freeKey = freeKey;
	pair->freeValue = freeValue;
	pair->descriptionKey = descriptionKey;
	pair->descriptionValue = descriptionValue;

	return (pair);
}

void	freePrimitivePair(t_primitivePair **pair)
{
	(*pair)->freeKey((*pair)->key);
	(*pair)->freeValue((*pair)->value);
	free(*pair);
	*pair = NULL;
}

void	descriptionPair(t_primitivePair *pair)
{
	printf("(");
	pair->descriptionKey(pair->key);
	printf(", ");
	pair->descriptionValue(pair->value);
	printf(")");
}
