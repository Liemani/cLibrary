#ifndef T_NULL_H
#define T_NULL_H



typedef struct	s_null
{
	void		*null;
}				t_null;

t_null	Null;



void	*_newNull();
void	_deallocNull(void *);
void	_descriptionNull(void *);

void	setNull();
