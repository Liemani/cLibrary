#ifndef CLASS_H
#define CLASS_H

#include "kernelClass/utils.h"
#include "kernelClass/kernelList.h"
#include "kernelClass/pointer.h"
#include "kernelClass/string.h"



typedef struct		s_class
{
	t_instance		*(*new)();
	void			(*dealloc)(t_instance *instance);
	t_string		*(*description)(t_instance *instance);
	int				(*equal)(t_instance *lhs, void *rhs);
	t_kernelList	*instanceList;
}					t_class;

t_class	KernelClass;
t_class	*Class;



void		setClassClass();

void		classAddInstance(t_class *class, t_instance *instance);
void		classRemoveInstance(t_class *class, t_instance *instance);
int			classContainsInstance(t_class *class, t_instance *instance);

t_class		*class(t_instance *instance);
void		dealloc(t_instance *instance);
t_string	*description(t_instance *instance);
int			equal(t_instance *lhs, t_instance *rhs);



#endif
