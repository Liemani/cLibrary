#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "kernelClass/class.h"



t_kernelList	*newKernelList()
{
	t_kernelList	*list;

	lmtAlloc(list);
	list->next = NULL;

	return (list);
}

void			deallocKernelList(t_kernelList *list)
{
	t_kernelList	*element;
	t_kernelList	*next;

	if (!list)
		return ;

	next = list->next;
	while ((element = next))
	{
		next = element->next;
		free(element);
	}
	free(list);
}

void			descriptionKernelList(t_kernelList *list)
{
	printf("[ ");
	if ((list = list->next))
	{
		descriptionPointer(list->content);
		while ((list = list->next))
		{
			printf(", ");
			descriptionPointer(list->content);
		}
	}
	else
		descriptionPointer(list);
	printf(" ]");
}

void			kernelListAddContent(t_kernelList *list, void *content)
{
	t_kernelList	*element;

	if (!list)
		return ;

	lmtAlloc(element);
	element->content = content;
	element->next = list->next;
	list->next = element;
}

void			kernelListRemoveContent(t_kernelList *list, void *content)
{
	t_kernelList	*previous;
	t_kernelList	*element;

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

bool			kernelListContainsContent(t_kernelList *list, void *content)
{
	if (!list)
		return (false);

	while ((list = list->next))
		if (list->content == content)
			return (true);
	return (false);
}
