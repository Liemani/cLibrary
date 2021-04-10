#include <stdio.h>

#include "cLibrary.h"



int	program(int argc, char **argv)
{
	t_list	*list;

	___descriptionClass();
	putchar('\n');
	putchar('\n');

	printf("list = List->new(); \n");
	list = List->new();

	___descriptionClass();
	putchar('\n');
	putchar('\n');

	printf("classDealloc(list); \n");
	classDealloc(list);

	___descriptionClass();
	putchar('\n');
	putchar('\n');

	printf("Class->dealloc(Null); \n");
	Class->dealloc(Null);

	___descriptionClass();
	putchar('\n');
	putchar('\n');

	printf("Class->dealloc(List); \n");
	Class->dealloc(List);

	___descriptionClass();
	putchar('\n');
	putchar('\n');

	printf("___deallocClass(); \n");
	___deallocClass();

	___descriptionClass();
	putchar('\n');
	putchar('\n');

	return (0);
}
