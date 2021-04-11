#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"
#include "class.h"
#include "list.h"
#include "pair.h"



static t_dictionary	*_newDictionary()
{
	t_dictionary	*dictionary;

	lmtAlloc(dictionary);
	classAddInstance(Dictionary, dictionary);
	
	dictionary->next = NULL;

	return (dictionary);
}

static void		_deallocDictionary(t_dictionary *dictionary)
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

static void		_descriptionDictionary(t_dictionary *dictionary)
{
	if (!dictionary)
	{
		_description(dictionary);
		return ;
	}

	printf("t_dictionary: [ ");
	if ((dictionary = dictionary->next))
	{
		_description(dictionary->content);
		while ((dictionary = dictionary->next))
		{
			printf(", ");
			_description(dictionary->content);
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
	Dictionary->new = (newType)_newDictionary;
	Dictionary->dealloc = (deallocType)_deallocDictionary;
	Dictionary->description = (descriptionType)_descriptionDictionary;
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
