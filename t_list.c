#include <stdio.h>
#include <stdlib.h>
#include "t_list.h"

//	stdio.h
//		printf()
//
//	stdlib.h
//		NULL, free()



void	setListList()
{
	
}

void	newList(void (*freeContent)(void **),
		void	(*descriptionContent)(void *))
{
	List->freeContent = freeContent;
	List->descriptionContent = descriptionContent;
}

int		addElement(t_list **list, void *content)
{
	t_list	*newElement;

	newElement = malloc(sizeof(t_list));
	if (newElement == NULL)
		return (-1);
	newElement->content = content;
	newElement->next = *list;
	*list = newElement;
	return (0);
}

void	freeList(t_list **list)
{
	t_list	currentElement;
	t_list	nextElement;

	currentElement = *list;
	while (currentElement)
	{
		nextElement = currentElement->next;
		List->freeContent(&currentElement->content);
		free(currentElement);
		currentElement = nextElement;
	}
	*list = NULL;
}

void	descriptionList(t_list *list)
{
	while (list)
	{
		List->descriptionContent(list->content);
		list = list->next;
		printf(", ");
	}
}
