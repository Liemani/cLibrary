#include <stdio.h>
#include <stdlib.h>

#include "class/list.h"



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

static t_string	*descriptionList(t_list *list)
{
	t_string	*string;

	string = String->new();

	if (!list)
	{
		stringMergeString(string, description(list));
		return (string);
	}

	stringAppendStr(string, "[ ");
	if ((list = list->next))
	{
		stringMergeString(string, description(list->content));
		while ((list = list->next))
		{
			stringAppendStr(string, ", ");
			stringMergeString(string, description(list->content));
		}
	}
	else
		stringMergeString(string, description(list));
	stringAppendStr(string, " ]");

	return (string);
}

void			setListClass()
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
