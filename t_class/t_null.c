#include <stdio.h>

#include "class.h"

void	*_newNull()
{
	return (NULL);
}

void	_deallocNull(void *null)
{
	return ;
}

void	_descriptionNull(void *null)
{
	printf("NULL");
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
