#include <stdio.h>
#include <stdbool.h>

#include "t_class.h"
#include "utils.h"



t_class	*newClass(generalFunction free,
		generalFunction description)
{
	t_class	*class;

	lmtMalloc(class);
	class->free = free;
	class->description = description;
	class->instanceList = newInstanceList();

	return (class);
}

void	classAddInstance(t_class *class, void *instance)
{
	if (!class || !instance)
		return ;

	instanceListAddInstance(class->instanceList, instance);
}

void	classFreeInstance(t_class *class, void *instance)
{
	if (!class || !instance)
		return ;

	instanceListFreeInstance(class->instanceList, instance, class->free);
}

bool	classContainsInstance(t_class *class, void *instance)
{
	if (!class || !instance)
		return ;

	return (instanceListContainsInstance(class->list, instance));
}

void	freeClass(t_class *class)
{
	if (!class)
		return ;

	freeInstanceList(class->instanceList);
	free(class);
}

void	descriptionClass(t_class *class)
{
	if (!class)
		return ;

	printf("class: [ free: %p, description: %p, ", class->free, class->description);
	descriptionInstanceList(class->list, class->description);
	printf(" ]");
}
