#ifndef CLASS_H
#define CLASS_H

#include "utils.h"
#include "t_class.h"
#include "t_null.h"



#define classDealloc(argument) __classSubscriptInstance(argument)->dealloc(argument)

#define classDescription(argument) __classSubscriptInstance(argument)->description(argument)



t_class	*Class;



void	___setClass();

t_class	*__classSubscriptInstance(void *instance);
void	___deallocClass();
void	___descriptionClass();



#endif
