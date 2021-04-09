#ifndef	T_INSTANCELIST_H
#define T_INSTANCELIST_H

#include <stdbool.h>



typedef struct				s_instanceList
{
	void					*instance;
	struct s_instanceList	*next;
}							t_instanceList;



t_instanceList	*newInstanceList();
void			instanceListAddInstance(t_instanceList *list, void *instance);
void			instanceListFreeInstance(t_instanceList *list, void *instance, void (*freeInstance)(void *));
bool			instanceListConstainsInstance(t_instanceList *list, void *instance);
void			freeInstanceList(t_instanceList *list);
void			descriptionInstanceList(t_instanceList *list, void (*description)(void *));



#endif
