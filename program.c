#include <stdio.h>

#include "cLibrary.h"



#define EXECUTE	test001();

void	test001()
{
	t_list	*list = List->new();
	t_pair	*pair = Pair->new();

	pair->key = "hi";
	pair->value = "there";

	listAddElement(list, pair);

	description(list);
	putchar('\n');
}

void	test000()
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
	printf("\n");
}



int	program(int argc, char **argv)
{
	EXECUTE;

	return (0);
}
