#ifndef	KERNELLIST_H
#define KERNELLIST_H

#include "kernelClass/class.h"



typedef struct			s_kernelList
{
	void				*content;
	struct s_kernelList	*next;
}						t_kernelList;

typedef struct	s_string t_string;



t_kernelList	*newKernelList();
void			deallocKernelList(t_kernelList *list);
t_string		*descriptionKernelList(t_kernelList *list);

void			kernelListAddContent(t_kernelList *list, void *content);
void			kernelListRemoveContent(t_kernelList *list, void *content);
int				kernelListContainsContent(t_kernelList *list, void *content);



#endif
