#include <stdio.h>

#include "cLibrary.h"



int	program(int argc, char **argv)
{
	t_list	*list;

	list = List->new();

	classDescription(list);
	putchar('\n');
	descriptionClassTable();
	putchar('\n');

	classDealloc(list);

	deallocClassTable();

	return (0);
}
