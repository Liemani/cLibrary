#include <stdio.h>
#include <stdlib.h>

#include "t_classList.h"
#include "utils.h"



static void	newClassTable()
{
	if (g_classTable)
		return ;

	lmtMalloc(g_classTable);
	g_classTable->class = NULL;
	g_classTable->next = NULL;
}

void		classTableAddInstance(t_class *class, void *instance)
{
	t_classList	*element;

	if (!class || !instance)
		return ;

	newClassTable();

	classAddInstance(class, instance);

	element = g_classTable;
	while ((element = element->next))
		if (element->content == class)
			return ;

	lmtMalloc(element);
	element->class = class;
	element->next = g_classTable->next;
	g_classTable->next = element;
}

void		classTableFreeInstance(void *instance)
{
	t_classList	*element;

	if (!g_classTable || !instance)
		return ;

	element = g_classTable;
	while ((element = element->next))
	{
		if (classContainsInstance(element->class, instance))
		{
			classFreeInstance(element->class, instance);
			break;
		}
	}
}

t_class		*classTableSubscriptInstance(void *instance)
{
	t_classList	*element;

	if (!instance)
		return (NULL);

	element = g_classTable;
	while ((element = element->next))
		if (classContainsInstance(element->class, instance))
			return (element->class);

	return (NULL);
}

void		freeClassTable()
{
	t_classList	*element;
	t_classList	*next;

	if (!g_classTable)
		return ;

	element = g_classTable->next;
	while (element != NULL)
	{
		next = element->next;
		freeClass(element->class);
		free element;
		element = next;
	}
	free(g_classTable);
}

void	descriptionClassTable()
{
	t_classList	*element;

	newClassTable();

	printf("classTable: [ ");
	element = g_classTable->next;
	if (element)
	{
		description(element->class);
		while ((element = element->next))
		{
			printf(", ");
			description(element->class);
		}
	}
	printf(" ]");
}
