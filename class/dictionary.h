#ifndef	DICTIONARY_H
#define DICTIONARY_H

#include "kernelClass/class.h"
#include "class/list.h"



typedef t_list	t_dictionary;

t_class	*Dictionary;



void	setDictionaryClass();
void	dictionaryUpdate(t_dictionary *dictionary, void *key, void *value);



#endif
