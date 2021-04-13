#include <stdio.h>

#include "cLibrary.h"



#define EXECUTE	test005();

void	test005()
{
	t_dictionary *dictionary = Dictionary->new();

	dictionaryUpdate(dictionary, initString("hi"), initString("there!"));
	dictionaryUpdate(dictionary, initString("nice"), initString("to meet you!"));

	stringFlush(description(dictionarySubscript(dictionary, "hi")));

	printf("\n\n");

	stringFlush(description(dictionarySubscript(dictionary, "nice")));

	printf("\n\n");

	stringFlush(description(dictionarySubscript(dictionary, "hello")));

	printf("\n");
}

void	test004()
{
	t_dictionary	*dictionary = Dictionary->new();

	t_string		*key = initString("hi!");
	t_string		*value = initString("there!");

	dictionaryUpdate(dictionary, key, value);

	stringPrettyFlush(description(dictionary));
	printf("\n\n");

	stringPrettyFlush(description(String));
	printf("\n\n");

	stringPrettyFlush(description(Dictionary));
	printf("\n\n");

	stringPrettyFlush(description(Class));
	printf("\n");
}

void	test003()
{
	t_string *string = String->new();

	setString(string, "hi");
	stringFlush(description(string));
}

void	test002()
{
	t_dictionary	*dictionary = Dictionary->new();

	stringFlush(description(dictionary));

	dictionaryUpdate(dictionary, "hi", "there");

	stringFlush(description(dictionary));
}

void	test001()
{
	t_list	*list = List->new();
	t_pair	*pair = Pair->new();

	pair->key = "hi";
	pair->value = "there";

	listAddElement(list, pair);

	stringFlush(description(list));
	putchar('\n');
}

void	test000()
{
	t_list	*list;

	stringFlush(description(Class));
	printf("\n\n");

	printf("list = List->new(); \n\n");
	list = List->new();

	stringFlush(description(Class));
	printf("\n\n");

	printf("dealloc(list); \n\n");
	stringFlush(description(list));
	printf("\n\n");

	stringFlush(description(Class));
	printf("\n\n");

	printf("dealloc(Pointer); \n\n");
	stringFlush(description(Pointer));
	printf("\n\n");

	stringFlush(description(Class));
	printf("\n\n");

	printf("dealloc(List); \n\n");
	stringFlush(description(list));
	printf("\n\n");

	stringFlush(description(Class));
	printf("\n");
}



int	program(int argc, char **argv)
{
	EXECUTE;

	return (0);
}
