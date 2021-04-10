#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>



#define lmtNew(class, instance) \
	t_ ## instance	*instance; \
	 \
	instance = lmtAlloc(instance); \
	classAddInstance(class, instance)

#define lmtAlloc(argument) _lmtAlloc((void **)&argument, sizeof(*argument))



typedef void	*(*newType)();
typedef void	(*deallocType)(void *);
typedef void	(*descriptionType)(void *);

void	_lmtAlloc(void **argument, size_t size);



#endif
