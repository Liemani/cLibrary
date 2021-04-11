#include <stdio.h>
#include <stdlib.h>

#include "class/list.h"
#include "t_class/class.h"



static t_list	*_newList()
{
	t_list	*list;

	lmtAlloc(list);
	classAddInstance(List, list);

	list->next = NULL;

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
	if (!list)
	{
		_description(list);
		return ;
	}

	printf("t_list: [ ");
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
	List->new = (newType)_newList;
	List->dealloc = (deallocType)_deallocList;
	List->description = (descriptionType)_descriptionList;
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
