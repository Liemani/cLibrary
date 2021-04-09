#ifndef T_CLASS_H
#define T_CLASS_H

#include <stdbool.h>

#include "utils.h"
#include "t_instanceList.h"



#define classFree(argument) classTableSubscriptInstance(argument)->free(argument)

#define classDescription(argument) classTableSubscriptInstance(argument)->description(argument)



typedef struct		s_class
{
	void			(*free)(void *instance);
	void			(*description)(void *instance);
	t_instanceList	*instanceList;
}					t_class;



t_class	*newClass(generalFunction free,
		generalFunction description);
void	classAddInstance(t_class *class, void *instance);
void	classFreeInstance(t_class *class, void *instance);
bool	classContainsInstance(t_class *class, void *instance);
void	freeClass(t_class *class);
void	descriptionClass(t_class *class);



#endif
