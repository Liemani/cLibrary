#include <stdio.h>

#include "cLibrary.h"



#define EXECUTE	test000();

void	test002()
{
	t_dictionary	*dictionary = Dictionary->new();

	_description(dictionary);

	dictionaryUpdate(dictionary, "hi", "there");
	putchar('\n');

	_description(dictionary);
	putchar('\n');
}

void	test001()
{
	t_list	*list = List->new();
	t_pair	*pair = Pair->new();

	pair->key = "hi";
	pair->value = "there";

	listAddElement(list, pair);

	_description(list);
	putchar('\n');
}

void	test000()
{
	t_list	*list;

	_description(Class);
	printf("\n\n");

	printf("list = List->new(); \n\n");
	list = List->new();

	_description(Class);
	printf("\n\n");

	printf("dealloc(list); \n\n");
	_dealloc(list);

	_description(Class);
	printf("\n\n");

	printf("dealloc(Pointer); \n\n");
	_dealloc(Pointer);

	_description(Class);
	printf("\n\n");

	printf("dealloc(List); \n\n");
	_dealloc(List);

	_description(Class);
	printf("\n");
}



int	program(int argc, char **argv)
{
	EXECUTE;

	return (0);
}
