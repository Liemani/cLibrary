#ifndef T_CLASS_H
#define T_CLASS_H

#include <stdbool.h>
#include "t_class/t_primitiveList.h"



typedef struct		s_class
{
	void			*(*new)();
	void			(*dealloc)(void *instance);
	void			(*description)(void *instance);
	t_primitiveList	*instanceList;
}					t_class;

t_class	*_newClass();
void	_deallocClass(t_class *class);
void	_descriptionClass(t_class *class);
void	classAddInstance(t_class *class, void *instance);
void	classRemoveInstance(t_class *class, void *instance);
bool	classContainsInstance(t_class *class, void *instance);



#endif
