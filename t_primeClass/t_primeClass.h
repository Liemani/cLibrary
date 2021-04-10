#ifndef T_PRIMECLASS_H
#define T_PRIMECLASS_H

#include "utils.h"
#include "t_classList.h"



typedef struct	s_primeClass
{
	t_class		*(*new)();
	void		(*dealloc)(t_class *class);
	void		(*description)(t_class *class);
	t_classList	*classList;
}				t_primeClass;

t_primeClass	*Class;

t_primeClass	*_newPrimeClass();
void			setClass();





void			deallocClassClass();



#endif
