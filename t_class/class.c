#include <stdio.h>
#include <stdlib.h>

#include "class.h"

static t_class	*__newClass()
{
	t_class	*class;

	class = _newClass();
	classAddInstance(Class, class);

	return (class);
}

static void		__deallocClass(void *class)
{
	if (!class)
		return ;

	classRemoveInstance(Class, class);
	_deallocClass(class);
}

static void		__descriptionClass(void *class)
{
	_descriptionClass(class);
}

void			___setClass()
{
	Class = _newClass();
	Class->new = (newType)__newClass;
	Class->dealloc = __deallocClass;
	Class->description = __descriptionClass;
}

void			___deallocClass()
{
	t_primitiveList	*element;

	if (!Class)
		return ;

	element = Class->instanceList;
	while ((element = element->next))
		Class->dealloc(element->content);
	_deallocClass(Class);

	Class = NULL;
}

void			___descriptionClass()
{
	t_primitiveList	*element;

	printf("Class: [ ");
	if (Class)
	{
		printf("new: %p, dealloc: %p, description: %p, \n", Class->new, Class->dealloc, Class->description);
		printf("         classList: [ ");
		if ((element = Class->instanceList->next))
		{
			Class->description(element->content);
			while ((element = element->next))
			{
				printf(", \n                      ");
				Class->description(element->content);
			}
		}
		else
			_descriptionNull(element);
		printf(" ]");
	}
	else
		_descriptionNull(Class);
	printf(" ]");
}

t_class	*__classSubscriptInstance(void *instance)
{
	t_primitiveList	*element;

	element = Class->instanceList;
	while ((element = element->next))
		if (classContainsInstance(element->content, instance))
			return (element->content);
	return (Null);
}
