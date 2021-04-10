#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "class.h"



t_class	*_newClass()
{
	t_class	*class;

	lmtAlloc(class);
	class->instanceList = _newPrimitiveList();

	return (class);
}

void	_deallocClass(t_class *class)
{
	if (!class)
		return ;

	_deallocPrimitiveList(class->instanceList);
	free(class);
}

void	_descriptionClass(t_class *class)
{
	printf("t_class: [ ");
	if (class)
	{
		printf("new: %p, dealloc: %p, description: %p, ", class->new, class->dealloc, class->description);
		_descriptionPrimitiveList(class->instanceList);
	}
	else
		_descriptionNull(class);
	printf(" ]");
}

void	classAddInstance(t_class *class, void *instance)
{
	if (!class)
		return ;

	if (!primitiveListContainsContent(class->instanceList, instance))
		primitiveListAddContent(class->instanceList, instance);
}

void	classRemoveInstance(t_class *class, void *instance)
{
	if (!class)
		return ;

	primitiveListRemoveContent(class->instanceList, instance);
}

bool	classContainsInstance(t_class *class, void *instance)
{
	if (!class)
		return (false);

	return (primitiveListContainsContent(class->instanceList, instance));
}