#ifndef T_NULL_H
#define T_NULL_H



typedef struct	s_null
{
	void		*null;
}				t_null;

t_class	*Null;



void	*_newNull();
void	_deallocNull(void *null);
void	_descriptionNull(void *null);

void	setNull();

#endif
