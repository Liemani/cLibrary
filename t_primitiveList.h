#ifndef	T_PRIMITIVELIST_H
#define T_PRIMITIVELIST_H

#include <stdbool.h>



typedef struct		s_primitiveList t_primitiveList;
typedef struct		s_primitiveList
{
	void			*content;
	void			(*freeContent)(void **content);
	void			(*descriptionContent)(void *content);
	t_primitiveList	*next;
};



t_primitiveList	*newPrimitiveList();
int		appendElement(t_primitiveList *list,
		void *content,
		void (*freeContent)(void **),
		void (*descriptionContent)(void *));
void	freePrimitiveList(t_primitiveList **list);
bool	containsPrimitiveList(t_primitiveList *list, void *content);
void	descriptionList(t_primitiveList *list);



#endif
