#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>



#define lmtMalloc(argument) _lmtMalloc((void **)&argument, sizeof(*argument))

#define setClass(argument) \
	if (argument == NULL) \
	{ \
		argument = newClass((generalFunction)free ## argument, \
				(generalFunction)description ## argument) \
		addClassListClass(argument); \
	}

typedef void	(*generalFunction)(void *);

void	_lmtMalloc(void **argument, size_t size);



#endif
