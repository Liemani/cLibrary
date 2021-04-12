#include <stdio.h>
#include <stdlib.h>

#include "kernelClass/class.h"



static t_list	*newList()
{
	t_list	*list;

	lmtAlloc(list);
	classAddInstance(List, list);

	list->next = NULL;

	return (list);
}

static void		deallocList(t_list *list)
{
	t_list	*element;
	t_list	*next;

	if (!list)
		return ;

	classRemoveInstance(List, list);

	next = list->next;
	while ((element = next))
	{
		next = element->next;
		free(element);
	}
	free(list);
}

static void		descriptionList(t_list *list)
{
	if (!list)
	{
		_description(list);
		return ;
	}

	printf("[ ");
	if ((list = list->next))
	{
		_description(list->content);
		while ((list = list->next))
		{
			printf(", ");
			_description(list->content);
		}
	}
	else
		_description(list);
	printf(" ]");
}

void			setList()
{
	if (!Class || classContainsInstance(Class, List))
		return ;

	List = Class->new();
	List->new = (newType)newList;
	List->dealloc = (deallocType)deallocList;
	List->description = (descriptionType)descriptionList;
}

void			listAddElement(t_list *list, void *content)
{
	t_list	*element;

	if (!list)
		return ;

	lmtAlloc(element);
	element->content = content;
	element->next = list->next;
	list->next = element;
}
