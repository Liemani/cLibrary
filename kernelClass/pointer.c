#include <stdio.h>

#include "kernelClass/class.h"


void		deallocPointer(t_pointer *pointer)
{
	return ;
}

void		descriptionPointer(t_pointer *pointer)
{
	if (pointer)
		printf("\"%p\"", pointer);
	else
		printf("null");
}

void		setPointer()
{
	if (!Class || classContainsInstance(Class, Pointer))
		return ;

	Pointer = Class->new();
	Pointer->new = NULL;
	Pointer->dealloc = (deallocType)deallocPointer;
	Pointer->description = (descriptionType)descriptionPointer;
}
