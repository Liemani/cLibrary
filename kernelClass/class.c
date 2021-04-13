#include <stdio.h>
#include <stdlib.h>

#include "kernelClass/class.h"



static t_class	*newClass()
{
	t_class	*class;

	lmtAlloc(class);
	class->new = NULL;
	class->dealloc = NULL;
	class->description = NULL;
	class->equal = NULL;
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

static t_string	*descriptionClass(t_class *class)
{
	t_string	*string;

	string = String->new();
	stringAppendStr(string, "{ \"type\": \"Class\"");
	if (class)
	{
		stringAppendStr(string, ", \"new\": ");
		stringMergeString(string, descriptionPointer(class->new));
		stringAppendStr(string, ", \"dealloc\": ");
		stringMergeString(string, descriptionPointer(class->dealloc));
		stringAppendStr(string, ", \"description\": ");
		stringMergeString(string, descriptionPointer(class->description));
		stringAppendStr(string, ", \"instances\": ");
		stringMergeString(string, descriptionKernelList(class->instanceList));
	}
	else
		stringMergeString(string, descriptionPointer(class));
	stringAppendStr(string, " }");

	return (string);
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

static t_string	*_descriptionClass()
{
	t_string		*string;
	t_kernelList	*element;

	if (Class)
		string = String->new();
	else
		string = _newString();

	stringAppendStr(string, "{ \"type\": \"KernelClass\"");
	if (Class)
	{
		stringAppendStr(string, ", \"new\": ");
		stringMergeString(string, descriptionPointer(Class->new));
		stringAppendStr(string, ", \"dealloc\": ");
		stringMergeString(string, descriptionPointer(Class->dealloc));
		stringAppendStr(string, ", \"description\": ");
		stringMergeString(string, descriptionPointer(Class->description));
		stringAppendStr(string, ", \"classes\": [ ");
		if ((element = Class->instanceList->next))
		{
			stringMergeString(string, descriptionClass(element->content));
			while ((element = element->next))
			{
				stringAppendStr(string, ", ");
				stringMergeString(string, descriptionClass(element->content));
			}
		}
		else
			stringMergeString(string, descriptionPointer(element));
		stringAppendStr(string, " ]");
	}
	else
		stringMergeString(string, descriptionPointer(Class));
	stringAppendStr(string, " }");

	return (string);
}

void			setClassClass()
{
	KernelClass.dealloc = _deallocClass;
	KernelClass.description = _descriptionClass;

	lmtAlloc(Class);
	Class->new = (newType)newClass;
	Class->dealloc = (deallocType)deallocClass;
	Class->description = (descriptionType)descriptionClass;
	Class->instanceList = newKernelList();

	setPointerClass();
	setStringClass();
}

void			classAddInstance(t_class *class, t_instance *instance)
{
	if (!class)
		return ;

	if (!kernelListContainsContent(class->instanceList, instance))
		kernelListAddContent(class->instanceList, instance);
}

void			classRemoveInstance(t_class *class, t_instance *instance)
{
	if (!class)
		return ;

	kernelListRemoveContent(class->instanceList, instance);
}

int				classContainsInstance(t_class *class, t_instance *instance)
{
	if (!class)
		return (false);

	return (kernelListContainsContent(class->instanceList, instance));
}

t_class			*class(t_instance *instance)
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

void			dealloc(t_instance *instance)
{
	const deallocType deallocFunction = class(instance)->dealloc;
	if (deallocFunction)
		deallocFunction(instance);
	else
		Pointer->dealloc(instance);
}

t_string		*description(t_instance *instance)
{
	const descriptionType descriptionFunction = class(instance)->description;
	if (descriptionFunction)
		return (descriptionFunction(instance));
	else
		return (Pointer->description(instance));
}

int				equal(t_instance *lhs, t_instance *rhs)
{
	const equalType equalFunction = class(lhs)->equal;
	if (equalFunction)
		return (equalFunction(lhs, rhs));
	else
		return (Pointer->equal(lhs, rhs));
}
