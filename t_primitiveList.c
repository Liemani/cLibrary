#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "t_primitiveList.h"

//	stdio.h
//		printf()
//
//	stdlib.h
//		NULL, free()



t_primitiveList	*newPrimitiveList()
{
	t_primitiveList	*list;

	list = malloc(sizeof(t_primitiveList));
	if (list == NULL)
		return (NULL);

	list->next = NULL;

	return (list);
}

int		appendElement(t_primitiveList *list,
		void *content,
		void (*freeContent)(void **),
		void (*descriptionContent)(void *))
{
	t_primitiveList	*newElement;

	newElement = malloc(sizeof(t_primitiveList));
	if (newElement == NULL)
		return (-1);

	newElement->content = content;
	newElement->freeContent = freeContent;
	newElement->descriptionContent = descriptionContent;
	newElement->next = NULL;

	while (list->next)
		list = list->next;
	list->next = newElement;

	return (0);
}

void	freePrimitiveList(t_primitiveList **list)
{
	t_primitiveList	element;
	t_primitiveList	next;

	element = *list;
	while (element)
	{
		next = element->next;
		element->freeContent(&element->content);
		free(element);
		element = next;
	}
	*list = NULL;
}

bool	containsPrimitiveList(t_primitiveList *list, void *content)
{
	while (list = list->next)
		if (list->content == content)
			return (true);
	return (false);
}

void	descriptionList(t_primitiveList *list)
{
	while (list)
	{
		list->descriptionContent(list->content);
		list = list->next;
		printf(", ");
	}
}
