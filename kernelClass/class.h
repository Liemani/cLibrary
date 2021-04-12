#ifndef CLASS_H
#define CLASS_H

#include <stdbool.h>

#include "kernelClass/utils.h"
#include "kernelClass/kernelList.h"
#include "kernelClass/pointer.h"
#include "kernelClass/string.h"



#define _dealloc(argument) _classSubscriptInstance(argument)->dealloc(argument)

#define _description(argument) _classSubscriptInstance(argument)->description(argument)



typedef struct		s_class
{
	void			*(*new)();
	void			(*dealloc)(void *instance);
	void			(*description)(void *instance);
	t_kernelList	*instanceList;
}					t_class;

t_class	KernelClass;
t_class	*Class;



void	setClass();

void	classAddInstance(t_class *class, void *instance);
void	classRemoveInstance(t_class *class, void *instance);
bool	classContainsInstance(t_class *class, void *instance);

t_class	*_classSubscriptInstance(void *instance);



#endif
