#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "t_primeClass.h"



t_instanceList	*_newInstanceList()
{
	t_instanceList	*list;

	lmtAlloc(list);
	list->next = NULL;

	return (list);
}

void			deallocInstanceList(t_instanceList *list)
{
	t_instanceList	*element;
	t_instanceList	*next;

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

void			instanceListAddInstance(t_instanceList *list, void *instance)
{
	t_instanceList	*element;

	if (!list)
		return ;

	lmtAlloc(element);
	element->instance = instance;
	element->next = list->next;
	list->next = element;
}





void			instanceListRemoveInstance(t_instanceList *list, void *instance)
{
	t_instanceList	*previous;
	t_instanceList	*element;

	if (!list || !instance)
		return ;

	previous = list;
	element = previous->next;
	while (element)
	{
		if (element->instance == instance)
		{
			previous->next = element->next;
			dealloc(element);
			break;
		}
		previous = element;
		element = previous->next;
	}
}

bool			instanceListContainsInstance(t_instanceList *list, void *instance)
{
	if (!list || !instance)
		return (false);

	while ((list = list->next))
		if (list->instance == instance)
			return (true);
	return (false);
}

void	descriptionInstanceList(t_instanceList *list)
{
	if (!list)
		return ;

	printf("instanceList: [ ");
	list = list->next;
	if (list)
	{
		printf("%p", list->instance);
		while ((list = list->next))
		{
			printf(", ");
			printf("%p", list->instance);
		}
	}
	printf(" ]");
}
