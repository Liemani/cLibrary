#ifndef T_CLASS_H
#define T_CLASS_H

#include "t_instanceList.h"



typedef struct		s_class
{
	void			*(*new)();
	void			(*dealloc)(void *instance);
	void			(*description)(void *instance);
	t_instanceList	*instanceList;
}					t_class

t_class	*_newClass();





#endif
