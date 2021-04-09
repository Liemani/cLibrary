#ifndef T_CLASSLIST_H
#define T_CLASSLIST_H

#include "t_class.h"



typedef struct			s_classList
{
	t_class				*class;
	struct s_classList	*next;
}						t_classList

t_classList				*g_classTable;



void	classTableAddInstance(t_class *class, void *instance);
void	classTableFreeInstance(void *instance);
t_class	*classTableSubscriptInstance(void *instance)
void	freeClassTable();
void	descriptionClassTable();



#endif
