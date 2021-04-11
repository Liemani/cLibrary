#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "t_class/class.h"



t_primitiveList	*_newPrimitiveList()
{
	t_primitiveList	*list;

	lmtAlloc(list);
	list->next = NULL;

	return (list);
}

void			_deallocPrimitiveList(t_primitiveList *list)
{
	t_primitiveList	*element;
	t_primitiveList	*next;

	if (!list)
		return ;

	next = list->next;
	while ((element = next))
	{
		next = element->next;
		free(element->content);
		free(element);
	}
	free(list);
}

void			_descriptionPrimitiveList(t_primitiveList *list)
{
	printf("[ ");
	if ((list = list->next))
	{
		_descriptionNull(list->content);
		while ((list = list->next))
		{
			printf(", ");
			_descriptionNull(list->content);
		}
	}
	else
		_descriptionNull(list);
	printf(" ]");
}

void			primitiveListAddContent(t_primitiveList *list, void *content)
{
	t_primitiveList	*element;

	if (!list)
		return ;

	lmtAlloc(element);
	element->content = content;
	element->next = list->next;
	list->next = element;
}

void			primitiveListRemoveContent(t_primitiveList *list, void *content)
{
	t_primitiveList	*previous;
	t_primitiveList	*element;

	if (!list)
		return ;

	previous = list;
	while ((element = previous->next))
	{
		if (element->content == content)
		{
			previous->next = element->next;
			free(element);
			return ;
		}
		previous = element;
	}
}

bool			primitiveListContainsContent(t_primitiveList *list, void *content)
{
	if (!list)
		return (false);

	while ((list = list->next))
		if (list->content == content)
			return (true);
	return (false);
}
