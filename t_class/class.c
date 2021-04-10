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

static void		___deallocClass()
{
	t_primitiveList	*element;

	if (!Class)
		return ;

	element = Class->instanceList;
	while ((element = element->next))
		__deallocClass(element->content);
	_deallocClass(Class);

	Class = NULL;
}

static void		___descriptionClass()
{
	t_primitiveList	*element;

	printf("Class: [ ");
	if (Class)
	{
		printf("new: %p, dealloc: %p, description: %p, \n", Class->new, Class->dealloc, Class->description);
		printf("         classList: [ ");
		if ((element = Class->instanceList->next))
		{
			__descriptionClass(element->content);
			while ((element = element->next))
			{
				printf(", \n                      ");
				__descriptionClass(element->content);
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

void			setClass()
{
	Class = _newClass();
	Class->new = (newType)__newClass;
	Class->dealloc = __deallocClass;
	Class->description = __descriptionClass;

	kernelClass.dealloc = ___deallocClass;
	kernelClass.description = ___descriptionClass;
}

t_class	*__classSubscriptInstance(void *instance)
{
	t_primitiveList	*element;

	if (instance == Class)
		return (&kernelClass);

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
