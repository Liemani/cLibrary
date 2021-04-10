#include <stdio.h>
#include <stdlib.h>

#include "t_primeClass.h"



t_classList	*_newClassList()
{
	t_classList	*list;

	lmtAlloc(list);
	list->next = NULL;

	return (list);
}

void		deallocClassList(t_classList *list)
{
	t_classList	*element;
	t_classList	*next;

	if (!list)
		return ;

	element = list->next;
	while (element)
	{
		next = element->next;
		free(element->instance);
		free(element);
		element = next;
	}
	free(list);
}

void	classListAddClass(t_classList *list, t_class *class)
{
	t_classList	*element;

	if (!list || !class)
		return ;

	lmtAlloc(element);
	element->class = class;
	element->next = list->next;
	list->next = element;
}





void	classListDeallocClass(t_class class)
{
	t_classList	*previous;
	t_classList	*element;

	if (!class)
		return ;

	previous = Class->classList;
	element = previous->next;
	while (element)
	{
		if (element->class == class)
		{
			previous->next = element->next;
			break;
		}
		previous = element;
		element = previous->next;
	}

	_freeClass(class);
}








void		classListAddInstance(t_class *class, void *instance)
{
	t_classList	*element;

	if (!class || !instance)
		return ;

	newClassList();

	classAddInstance(class, instance);

	element = g_classList;
	while ((element = element->next))
		if (element->class == class)
			return ;

	lmtAlloc(element);
	element->class = class;
	element->next = g_classList->next;
	g_classList->next = element;
}

void		classListRemoveInstance(void *instance)
{
	t_classList	*element;

	if (!g_classList || !instance)
		return ;

	element = g_classList;
	while ((element = element->next))
	{
		if (classContainsInstance(element->class, instance))
		{
			classRemoveInstance(element->class, instance);
			break;
		}
	}
}


void	descriptionClassList()
{
	t_classList	*element;

	newClassList();

	printf("classList: [ ");
	element = g_classList->next;
	if (element)
	{
		descriptionClass(element->class);
		while ((element = element->next))
		{
			printf(", ");
			descriptionClass(element->class);
		}
	}
	printf(" ]");
}

t_class		*_classListSubscriptInstance(void *instance)
{
	t_classList	*element;

	if (!instance)
		return (NULL);

	element = g_classList;
	while ((element = element->next))
		if (classContainsInstance(element->class, instance))
			return (element->class);

	return (NULL);
}
