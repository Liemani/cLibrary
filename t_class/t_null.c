#include <stdio.h>

#include "class.h"

static void	*_newNull()
{
	return (NULL);
}

static void	_deallocNull(void *)
{
	return ;
}

static void	_descriptionNull(void *)
{
	printf("NULL");
}

void		setNull()
{
	if(Null)
		return ;

	Null = Class->new();
	Null->new = _newNull;
	Null->dealloc = _deallocNull;
	Null->description = _descriptionNull;
	classAddInstance(nullClass, NULL);
}
