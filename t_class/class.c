#include <stdio.h>
#include <stdlib.h>

#include "t_class/class.h"

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

static void		___deallocClass()
{
	t_primitiveList	*element;
	t_primitiveList *next;

	if (!Class)
		return ;

	next = Class->instanceList->next;
	while ((element = next))
	{
		next = element->next;
		__deallocClass(element->content);
	}
	_deallocClass(Class);

	Class = NULL;
}

static void		___descriptionClass()
{
	t_primitiveList	*element;

	printf("{ \"type\": \"KernelClass\"");
	if (Class)
	{
		printf(", \"new\": ");
		_descriptionNull(Class->new);
		printf(", \"dealloc\": ");
		_descriptionNull(Class->dealloc);
		printf(", \"description\": ");
		_descriptionNull(Class->description);
		printf(", \"classes\": [ ");
		if ((element = Class->instanceList->next))
		{
			__descriptionClass(element->content);
			while ((element = element->next))
			{
				printf(", ");
				__descriptionClass(element->content);
			}
		}
		else
			_descriptionNull(element);
		printf(" ]");
	}
	else
		_descriptionNull(Class);
	printf(" }");
}

void			setClass()
{
	Class = _newClass();
	Class->new = (newType)__newClass;
	Class->dealloc = __deallocClass;
	Class->description = __descriptionClass;

	KernelClass.dealloc = ___deallocClass;
	KernelClass.description = ___descriptionClass;
}

t_class	*__classSubscriptInstance(void *instance)
{
	t_primitiveList	*element;

	if (instance == Class)
		return (&KernelClass);

	element = Class->instanceList;
	while ((element = element->next))
	{
		if (element->content == instance)
			return (Class);
		if (classContainsInstance(element->content, instance))
			return (element->content);
	}
	return (Null);
}
