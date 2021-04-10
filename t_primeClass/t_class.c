#include <stdio.h>
#include <stdlib.h>

#include "t_primeClass.h"



t_class	*_newClass()
{
	t_class	*class;

	lmtAlloc(class);
	class->instanceList = _newInstanceList();

	return (class);
}

void	deallocClass(t_class *class)
{
	deallocInstanceList(class->instanceList);
	free(class);
}
