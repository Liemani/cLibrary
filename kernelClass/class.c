#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "kernelClass/class.h"



static t_class	*newClass()
{
	t_class	*class;

	lmtAlloc(class);
	class->instanceList = newKernelList();
	classAddInstance(Class, class);

	return (class);
}

static void		deallocClass(t_class *class)
{
	t_kernelList	*element;
	t_kernelList	*next;

	if (!class)
		return ;

	classRemoveInstance(Class, class);

	next = class->instanceList->next;
	while ((element = next))
	{
		next = element->next;
		class->dealloc(element->content);
	}
	deallocKernelList(class->instanceList);
	free(class);
}

static void		descriptionClass(t_class *class)
{
	printf("{ \"type\": \"Class\"");
	if (class)
	{
		printf(", \"new\": ");
		descriptionPointer(class->new);
		printf(", \"dealloc\": ");
		descriptionPointer(class->dealloc);
		printf(", \"description\": ");
		descriptionPointer(class->description);
		printf(", ");
		printf("\"instances\": ");
		descriptionKernelList(class->instanceList);
	}
	else
		descriptionPointer(class);
	printf(" }");
}

static void		_deallocClass()
{
	t_kernelList	*element;
	t_kernelList	*next;

	if (!Class)
		return ;

	next = Class->instanceList->next;
	while ((element = next))
	{
		next = element->next;
		Class->dealloc(element->content);
	}
	deallocKernelList(Class->instanceList);
	free(Class);

	Class = NULL;
}

static void		_descriptionClass()
{
	t_kernelList	*element;

	printf("{ \"type\": \"KernelClass\"");
	if (Class)
	{
		printf(", \"new\": ");
		descriptionPointer(Class->new);
		printf(", \"dealloc\": ");
		descriptionPointer(Class->dealloc);
		printf(", \"description\": ");
		descriptionPointer(Class->description);
		printf(", \"classes\": [ ");
		if ((element = Class->instanceList->next))
		{
			descriptionClass(element->content);
			while ((element = element->next))
			{
				printf(", ");
				descriptionClass(element->content);
			}
		}
		else
			descriptionPointer(element);
		printf(" ]");
	}
	else
		descriptionPointer(Class);
	printf(" }");
}

void			setClass()
{
	KernelClass.dealloc = _deallocClass;
	KernelClass.description = _descriptionClass;

	lmtAlloc(Class);
	Class->new = (newType)newClass;
	Class->dealloc = (deallocType)deallocClass;
	Class->description = (descriptionType)descriptionClass;
	Class->instanceList = newKernelList();
}

void	classAddInstance(t_class *class, void *instance)
{
	if (!class)
		return ;

	if (!kernelListContainsContent(class->instanceList, instance))
		kernelListAddContent(class->instanceList, instance);
}

void	classRemoveInstance(t_class *class, void *instance)
{
	if (!class)
		return ;

	kernelListRemoveContent(class->instanceList, instance);
}

bool	classContainsInstance(t_class *class, void *instance)
{
	if (!class)
		return (false);

	return (kernelListContainsContent(class->instanceList, instance));
}

t_class	*_classSubscriptInstance(void *instance)
{
	t_kernelList	*element;

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
	return (Pointer);
}
