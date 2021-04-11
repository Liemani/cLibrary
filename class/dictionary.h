#ifndef	DICTIONARY_H
#define DICTIONARY_H

#include "t_class/class.h"
#include "class/list.h"



typedef t_list	t_dictionary;

t_class	*Dictionary;



void	setDictionary();
void	dictionaryUpdate(t_dictionary *dictionary, void *key, void *value);



#endif
