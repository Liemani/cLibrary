#ifndef POINTER_H
#define POINTER_H

#include "kernelClass/class.h"



typedef void	t_pointer;

typedef struct	s_class t_class;

t_class			*Pointer;



void		deallocPointer(t_pointer *pointer);
t_string	*descriptionPointer(t_pointer *pointer);
int			equalPointer(t_pointer *lhs, t_pointer *rhs);

void		setPointerClass();

#endif
