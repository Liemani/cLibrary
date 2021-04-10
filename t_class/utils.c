#include <stdio.h>

#include "utils.h"



void	_lmtAlloc(void **argument, size_t size)
{
	*argument = malloc(size);
	if (*argument == NULL)
	{
		printf("malloc error \n");
		exit(-1);
	}
}
