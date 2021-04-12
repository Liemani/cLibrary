#ifndef	PAIR_H
#define PAIR_H

#include "kernelClass/class.h"



typedef struct	s_pair
{
	void		*key;
	void		*value;
}				t_pair;

t_class	*Pair;



void	setPair();



#endif
