#include <stdio.h>
#include <stdlib.h>

#include "kernelClass/class.h"
#include "class/dictionary.h"
#include "class/pair.h"



static t_dictionary	*newDictionary()
{
	t_dictionary	*dictionary;

	lmtAlloc(dictionary);
	classAddInstance(Dictionary, dictionary);
	
	dictionary->next = NULL;

	return (dictionary);
}

static void		deallocDictionary(t_dictionary *dictionary)
{
	t_dictionary	*element;
	t_dictionary	*next;

	if (!dictionary)
		return ;

	classRemoveInstance(Dictionary, dictionary);

	next = dictionary->next;
	while ((element = next))
	{
		next = element->next;
		_dealloc(element);
	}
	free(dictionary);
}

static void		descriptionDictionary(t_dictionary *dictionary)
{
	t_pair	*pair;

	if (!dictionary)
	{
		_description(dictionary);
		return ;
	}

	printf("[ ");
	if ((dictionary = dictionary->next))
	{
		pair = dictionary->content;
		_description(pair->key);
		printf(": ");
		_description(pair->value);
		while ((dictionary = dictionary->next))
		{
			pair = dictionary->content;
			printf(", ");
			_description(pair->key);
			printf(": ");
			_description(pair->value);
		}
	}
	else
		_description(dictionary);
	printf(" ]");
}

void			setDictionary()
{
	if (!Class || classContainsInstance(Class, Dictionary))
		return ;

	Dictionary = Class->new();
	Dictionary->new = (newType)newDictionary;
	Dictionary->dealloc = (deallocType)deallocDictionary;
	Dictionary->description = (descriptionType)descriptionDictionary;
}

static t_pair	*dictionaryGetPair(t_dictionary *dictionary, void *key)
{
	if (!dictionary)
		return (NULL);

	while ((dictionary = dictionary->next))
	{
		const t_pair	*pair = dictionary->content;
		if (pair->key == key)
			return (dictionary->content);
	}
	return (NULL);
}

void			dictionaryUpdate(t_dictionary *dictionary, void *key, void *value)
{
	if (!dictionary)
		return ;

	t_pair	*pair = dictionaryGetPair(dictionary, key);
	if (pair)
		pair->value = value;
	else
	{
		pair = Pair->new();
		pair->key = key;
		pair->value = value;

		listAddElement(dictionary, pair);
	}
}
