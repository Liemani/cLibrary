#ifndef	T_PRIMITIVELIST_H
#define T_PRIMITIVELIST_H

#include <stdbool.h>



typedef struct				s_primitiveList
{
	void					*content;
	struct s_primitiveList	*next;
}							t_primitiveList;

t_primitiveList	*_newPrimitiveList();
void			_deallocPrimitiveList(t_primitiveList *list);
void			_descriptionPrimitiveList(t_primitiveList *list);
void			primitiveListAddContent(t_primitiveList *list, void *content);
void			primitiveListRemoveContent(t_primitiveList *list, void *content);
bool			primitiveListContainsContent(t_primitiveList *list, void *content);



#endif
