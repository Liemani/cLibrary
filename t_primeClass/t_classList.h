#ifndef T_CLASSLIST_H
#define T_CLASSLIST_H

#include "t_class.h"



typedef struct			s_classList
{
	t_class				*class;
	struct s_classList	*next;
}						t_classList;

t_classList	*classList;

t_classList	*_newClassList();
void		setClassList();





#define classDealloc(argument) _classListSubscriptInstance(argument)->dealloc(argument)

#define classDescription(argument) _classListSubscriptInstance(argument)->description(argument)

void	classListAddInstance(t_class *class, void *instance);
void	classListRemoveInstance(void *instance);



void	deallocClassList();
void	descriptionClassList();

t_class	*_classListSubscriptInstance(void *instance);



#endif
