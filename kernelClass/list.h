#ifndef	LIST_H
#define LIST_H

#include "kernelClass/class.h"



typedef struct		s_class t_class;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_class	*List;



void	setList();

void	listAddElement(t_list *list, void *content);



#endif
