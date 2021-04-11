#ifndef CLASS_H
#define CLASS_H

#include "t_class/utils.h"
#include "t_class/t_class.h"
#include "t_class/t_null.h"



#define _dealloc(argument) __classSubscriptInstance(argument)->dealloc(argument)

#define _description(argument) __classSubscriptInstance(argument)->description(argument)



t_class	kernelClass;
t_class	*Class;



void	setClass();

t_class	*__classSubscriptInstance(void *instance);



#endif
