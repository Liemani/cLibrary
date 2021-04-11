#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "t_class/class.h"



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
	printf("{ \"type\": \"Class\"");
	if (class)
	{
		printf(", \"new\": ");
		_descriptionNull(class->new);
		printf(", \"dealloc\": ");
		_descriptionNull(class->dealloc);
		printf(", \"description\": ");
		_descriptionNull(class->description);
		printf(", ");
		printf("\"instances\": ");
		_descriptionPrimitiveList(class->instanceList);
	}
	else
		_descriptionNull(class);
	printf(" }");
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
