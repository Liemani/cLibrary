#include <stdio.h>

#include "t_class/class.h"

void	*_newNull()
{
	return (NULL);
}

void	_deallocNull(void *null)
{
	return ;
}

void	_descriptionNull(void *instance)
{
	if (instance)
		printf("\"%p\"", instance);
	else
		printf("null");
}

void		setNull()
{
	if (!Class || classContainsInstance(Class, Null))
		return ;

	Null = Class->new();
	Null->new = _newNull;
	Null->dealloc = _deallocNull;
	Null->description = _descriptionNull;
	classAddInstance(Null, NULL);
}
