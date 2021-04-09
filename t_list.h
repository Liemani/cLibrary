#ifndef	T_LIST_H
#define T_LIST_H



typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list

t_class	*List;

void	newList(void (*freeContent)(void **),
		void (*descriptionContent)(void *));

int		addElement(t_list **list, void *content);
void	freeList(t_list **list, void (*freeContent)(void *content));
void	descriptionList(t_list *list);



#endif
