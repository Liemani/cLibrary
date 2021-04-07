#ifndef	T_LIST_H
#define T_LIST_H



typedef struct		s_List
{
	void			(*freeContent)(void **content);
	void			(*descriptionContent)(void *content);
}					t_List

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list



t_List	List;

void	newList(void (*freeContent)(void **),
		void (*descriptionContent)(void *));

int		addElement(t_list **list, void *content);
void	freeList(t_list **list, void (*freeContent)(void *content));
void	descriptionList(t_list *list);



#endif
