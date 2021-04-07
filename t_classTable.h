#ifndef T_CLASSTABLE_H
#define T_CLASSTABLE_H

#include "t_primitiveList.h"



typedef struct		s_classTable t_classTable;
typedef struct		s_classTable
{
	t_primitiveList	*list;
};



t_classTable	g_classTable;

int		setClassTable();
void	freeClassTable();

void	updateClassTable(void *instance, void *class);
void	*subscript(void *instance);
void	descriptionClassTable(t_classTable table);



#endif
