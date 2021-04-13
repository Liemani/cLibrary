#include <stdio.h>
#include <string.h>

#include "kernelClass/utils.h"



void	_lmtAlloc(void **argument, size_t size)
{
	*argument = malloc(size);
	if (*argument == NULL)
	{
		printf("malloc error \n");
		exit(-1);
	}
}

char	*_lmtStrdup(char *s1)
{
	if (!s1)
		s1 = "";

	char *string = strdup(s1);
	if (string == NULL)
	{
		printf("strdup error \n");
		exit(-1);
	}

	return (string);
}
