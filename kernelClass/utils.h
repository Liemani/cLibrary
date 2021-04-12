#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>



#define lmtAlloc(argument) _lmtAlloc((void **)&argument, sizeof(*argument))



typedef void	*(*newType)();
typedef void	(*deallocType)(void *);
typedef void	(*descriptionType)(void *);

void	_lmtAlloc(void **argument, size_t size);



#endif
