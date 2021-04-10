#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>



#define lmtAlloc(argument) _lmtAlloc((void **)&argument, sizeof(*argument))

#define setClass(class, instance) \
static void	newClass ## class(); \
 \
t_ ## instance		*new ## class() \
{ \
	t_ ## instance	*instance; \
 \
	newClass ## class(); \
 \
	lmtAlloc(instance); \
	init ## class(instance); \
 \
	classTableAddInstance(class, instance); \
 \
	return (instance); \
} \
 \
void		_dealloc ## class(t_ ## instance *instance) \
{ \
	if (!instance) \
		return ; \
 \
	classTableRemoveInstance(instance); \
 \
	dealloc ## class(instance); \
} \
 \
static void	newClass ## class() \
{ \
	if (class) \
		return ; \
 \
	class = Class->new(); \
 \
	class->new = new ## class; \
	class->dealloc = (deallocType)_dealloc ## class; \
	class->description = (descriptionType)description ## class; \
}

typedef void	*(*newType)();
typedef void	(*deallocType)(void *);
typedef void	(*descriptionType)(void *);

void	_lmtAlloc(void **argument, size_t size);



#endif
