#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "t_instanceList.h"
#include "utils.h"

//	stdio.h
//		printf()
//
//	stdlib.h
//		NULL, free()



t_instanceList	*newInstanceList()
{
	t_instanceList	*list;

	lmtMalloc(list);
	list->instance = NULL;
	list->next = NULL;

	return (list);
}

void			instanceListAddInstance(t_instanceList *list, void *instance)
{
	t_instanceList	*element;

	if (!list || !instance)
		return ;

	lmtMalloc(element);
	element->content = instance;
	element->next = list->next;
	list->next = element;
}

void			instanceListFreeInstance(t_instanceList *list, void *instance, void (*freeInstance)(void *))
{
	t_instance	previous;
	t_instance	element;

	if (!list || !instance || !freeInstance)
		return ;

	previous = list;
	element = previous->next;
	while (element)
	{
		if (list->instance == instance)
		{
			previous->next = element->next;
			freeInstance(instance);
			free(list);
			break;
		}
		previous = element;
		element = previous->next;
	}
}

bool			instanceListConstainsInstance(t_instanceList *list, void *instance)
{
	if (!list || !instance)
		return ;

	while ((list = list->next))
		if (list->instance == instance)
			return (true);
	return (false);
}

void			freeInstanceList(t_instanceList *list)
{
	t_instanceList	*element;
	t_instanceList	*next;

	if (!list)
		return ;

	element = list;
	while (element)
	{
		next = element->next;
		free(element->content);
		free(element);
		element = next;
	}
}

void	descriptionInstanceList(t_instanceList *list, void (*description)(void *))
{
	if (!list || !descriptioin)
		return ;

	printf("instanceList: [ ");
	list = list->next;
	if (list)
	{
		description(list->instance);
		while ((list = list->next))
		{
			printf(", ");
			description(list->instance);
		}
	}
	printf(" ]");
}
