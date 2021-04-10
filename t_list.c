#include <stdio.h>
#include <stdlib.h>

#include "cLibrary.h"



static t_list	*_newList()
{
	t_list	*list;

	lmtAlloc(list);
	list->next = NULL;

	classAddInstance(List, list);

	return (list);
}

static void		_deallocList(t_list *list)
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

static void		_descriptionList(t_list *list)
{
	printf("t_list: [ ");
	if ((list = list->next))
	{
		classDescription(list->content);
		while ((list = list->next))
		{
			printf(", ");
			classDescription(list->content);
		}
	}
	else
		classDescription(list);
	printf(" ]");
}

void			setList()
{
	if (List)
		return ;

	List = Class->new();
	List->new = _newList;
	List->dealloc = _deallocList;
	List->description = _descriptionList;
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
