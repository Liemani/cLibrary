#include <stdio.h>
#include <stdlib.h>

#include "kernelClass/class.h"
#include "class/dictionary.h"
#include "class/list.h"
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
		dealloc(element);
	}
	free(dictionary);
}

static t_string	*descriptionDictionary(t_dictionary *dictionary)
{
	t_string	*string;
	t_pair		*pair;

	string = String->new();

	if (!dictionary)
	{
		stringMergeString(string, description(dictionary));
		return (string);
	}

	stringAppendStr(string, "[ ");
	if ((dictionary = dictionary->next))
	{
		pair = dictionary->content;
		stringMergeString(string, description(pair->key));
		stringAppendStr(string, ": ");
		stringMergeString(string, description(pair->value));
		while ((dictionary = dictionary->next))
		{
			pair = dictionary->content;
			stringAppendStr(string, ", ");
			stringMergeString(string, description(pair->key));
			stringAppendStr(string, ": ");
			stringMergeString(string, description(pair->value));
		}
	}
	else
		stringMergeString(string, description(dictionary));
	stringAppendStr(string, " ]");

	return (string);
}

void			setDictionaryClass()
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
		const t_pair *pair = dictionary->content;
		if (pair->key == key)
			return (dictionary->content);
	}
	return (NULL);
}

void			dictionaryUpdate(t_dictionary *dictionary, void *key, void *value)
{
	if (!dictionary)
		return ;

	t_pair *pair = dictionaryGetPair(dictionary, key);
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

void			*dictionarySubscript(t_dictionary *dictionary, void *key)
{
	t_dictionary	*element;
	t_pair			*pair;

	element = dictionary;
	while ((element = element->next))
	{
		pair = element->content;
		if (equal(pair->key, key))
			return (pair->value);
	}

	return (NULL);
}
