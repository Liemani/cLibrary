#include <stdio.h>
#include <stdlib.h>

#include "t_primeClass.h"


static void	*_newNULL()
{
	return (NULL);
}

static void	_deallocNULL(void *instance)
{
	return ;
}

static void	_descriptionNULL(void *instance)
{
	printf("NULL");
}

t_primeClass	*_newPrimeClass()
{
	t_primeClass	*primeClass;
	t_class			*class;

	lmtAlloc(primeClass);
	primeClass->classList = _newClassList();

	class = _newClass();
	class->new = _newNULL;
	class->dealloc = _deallocNULL;
	class->description = _descriptionNULL;
	class->instanceList = _newInstanceList();
	instanceListAddInstance(class->instanceList, NULL);

	classListAddClass(primeClass->classList, class);

	return (primeClass);
}

void			deallocPrimeClass()
{
}

static t_class	*newClass()
{

}

static void		deallocClass(t_class *class)
{
}

static void		descriptionClass(t_class *class)
{
}

void			setClass()
{

	Class = _newPrimeClass();
	Class->new = newClass;
	Class->dealloc = deallocClass;
	Class->description = descriptionClass;
	Class->classList = list;
}





void			_newClassClass()
{
	if (Class)
		return ;

	lmtAlloc(Class);

	Class->new = newClass;
	Class->dealloc = deallocClass;
	Class->description = descriptionClass;

	newClassList();
}





static void		deallocClass(t_class *class)
{
	if (!class)
		return ;

	classListDeallocClass(class);
}

static			descriptionClass()
{
	_descriptionClass();
}

void			deallocClassClass()
{
	if (!Class)
		return ;

	deallocClassList();
	dealloc(Class);
}
