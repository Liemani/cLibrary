#include "t_dictionary.h"
#include "t_list.h"
#include "t_pair.h"



void	newDictionary(void (*freeKey)(void **),
		void (*freeValue)(void **),
		void (*descriptionKey)(void *key),
		void (*descriptionValue)(void *value))
{
	setList(freePair,
			descriptionPair);
	setPair(freeKey,
			freeValue,
			descriptionKey,
			descriptionValue);
}

void	addElement(t_dictionary *dictionary)
{
}

void	freeDictionary(t_dictionary **dictionary)
{
	freeList(&dictionary->list);
}
