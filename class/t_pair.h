#ifndef	T_PAIR_H
#define T_PAIR_H

#include "class.h"



typedef struct	s_pair
{
	void		*key;
	void		*value;
}				t_pair;

t_class	*Pair;



void	setPair();



#endif
