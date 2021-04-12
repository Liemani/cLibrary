#ifndef	KERNELLIST_H
#define KERNELLIST_H

#include <stdbool.h>

#include "list.h"



typedef t_list	t_kernelList;

t_kernelList	*newKernelList();
void			deallocKernelList(t_kernelList *list);
void			descriptionKernelList(t_kernelList *list);

void			kernelListAddContent(t_kernelList *list, void *content);
void			kernelListRemoveContent(t_kernelList *list, void *content);
bool			kernelListContainsContent(t_kernelList *list, void *content);



#endif
