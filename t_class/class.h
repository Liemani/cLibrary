#ifndef CLASS_H
#define CLASS_H

#include "utils.h"
#include "t_class.h"
#include "t_null.h"



#define classDealloc(argument) __classListSubscriptInstance(argument)->dealloc(argument)

#define classDescription(argument) __classListSubscriptInstance(argument)->description(argument)



t_class	*Class;



void	setClass();

t_class	*__classSubscriptInstance(void *instance);
void	___descriptionClass();



#endif
