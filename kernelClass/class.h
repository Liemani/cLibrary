#ifndef CLASS_H
#define CLASS_H

#include <stdbool.h>

#include "kernelClass/utils.h"
#include "kernelClass/kernelList.h"
#include "kernelClass/pointer.h"
#include "kernelClass/string.h"



typedef struct		s_class
{
	void			*(*new)();
	void			(*dealloc)(void *instance);
	t_string		*(*description)(void *instance);
	t_kernelList	*instanceList;
}					t_class;

t_class	KernelClass;
t_class	*Class;



void		setClassClass();

void		classAddInstance(t_class *class, void *instance);
void		classRemoveInstance(t_class *class, void *instance);
bool		classContainsInstance(t_class *class, void *instance);

void		dealloc(void *instance);
t_string	*description(void *instance);



#endif
