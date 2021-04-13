#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>



#define true	1
#define false	0

#define lmtAlloc(argument) _lmtAlloc((void **)&argument, sizeof(*argument))



typedef struct		s_string t_string;

typedef void		t_instance;

typedef t_instance	*(*newType)();
typedef void		(*deallocType)(t_instance *);
typedef t_string	*(*descriptionType)(t_instance *);
typedef int			(*equalType)(t_instance *, void*);



void				_lmtAlloc(void **argument, size_t size);
char				*_lmtStrdup(char *s1);



#endif
