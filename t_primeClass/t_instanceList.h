#ifndef	T_INSTANCELIST_H
#define T_INSTANCELIST_H

#include <stdbool.h>



typedef struct				s_instanceList
{
	void					*instance;
	struct s_instanceList	*next;
}							t_instanceList;

t_instanceList	*_newInstanceList();





t_instanceList	*newInstanceList();
void			instanceListAddInstance(t_instanceList *list, void *instance);
void			instanceListRemoveInstance(t_instanceList *list, void *instance);
bool			instanceListContainsInstance(t_instanceList *list, void *instance);
void			deallocInstanceList(t_instanceList *list);
void			descriptionInstanceList(t_instanceList *list);



#endif
