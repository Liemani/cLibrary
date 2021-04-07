#include <stdlib.h>
#include "t_classTable.h"
#include "t_primitiveList.h"

//	stdlib.h
//		NULL

int		setClassTable()
{
	t_primitiveList	list;

	list = newPrimitiveList();
	if (list == NULL)
		return (-1);

	g_classTable->list = list;

	return (0);
}

void	freeClassTable()
{
	freePrimitiveList(&g_classTable->list);
}

void	updateClassTable(void *instance, void *class)
{
	t_primitiveList	*elementPair;
	t_primitiveList	*elementInstance;

	element = g_classTable->list;
	while (element = element->next)
	{
		if (element->content->value == class)

	}
}

void	*subscript(void *instance)
{
	t_primitiveList	*elementPair;
	t_primitiveList	*elementInstance;

	elementPair = g_classTable->list;
	while (elementPair = elementPair->next)
	{
		elementInstance = elementPair->content->key;
		while (elementInstance = elementInstance->next)
		{
			if (elementInstance->content == instance)
				return (elementPair->value);
		}
	}

	return (NULL);
}

void	descriptionClassTable(t_classTable table)
{
	table->list->descriptionList(table->list);
}
