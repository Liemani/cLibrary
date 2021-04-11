#ifndef	PAIR_H
#define PAIR_H

#include "class.h"



typedef struct	s_pair
{
	void		*key;
	void		*value;
}				t_pair;

t_class	*Pair;



void	setPair();



#endif
