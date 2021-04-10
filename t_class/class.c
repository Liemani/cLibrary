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

void			setClass()
{
	Class = _newClass();
	Class->new = __newClass;
	Class->dealloc = __deallocClass;
	Class->description = __descriptionClass;
}

t_class	*__classSubscriptInstance(void *instance)
{
	class = Class->next;
	while ((class = class->next))
		if (classContainsInstance(class, instance))
			return (class);
	return (Null);
}

void			___descriptionClass()
{
	t_class	element;

	if (!Class)
		return ;

	printf("Class: [ ");
	if ((element = Class->next))
	{
		Class->description(element->content);
		while ((element = element->next))
		{
			printf(", ");
			Class->description(element->content);
		}
	}
	else
		Null->description(element);
	printf(" ]");
}
