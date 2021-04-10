#include <stdio.h>

#include "cLibrary.h"



int	program(int argc, char **argv)
{
	t_list	*list;

	description(Class);
	printf("\n\n");

	printf("list = List->new(); \n\n");
	list = List->new();

	description(Class);
	printf("\n\n");

	printf("dealloc(list); \n\n");
	dealloc(list);

	description(Class);
	printf("\n\n");

	printf("dealloc(Null); \n\n");
	dealloc(Null);

	description(Class);
	printf("\n\n");

	printf("dealloc(List); \n\n");
	dealloc(List);

	description(Class);
	printf("\n\n");

	printf("dealloc(Class); \n\n");
	dealloc(Class);

	description(Class);
	printf("\n\n");

	return (0);
}
