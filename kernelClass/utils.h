#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

#include "kernelClass/class.h"



#define lmtAlloc(argument) _lmtAlloc((void **)&argument, sizeof(*argument))



typedef struct		s_string t_string;

typedef void		*(*newType)();
typedef void		(*deallocType)(void *);
typedef t_string	*(*descriptionType)(void *);

void				_lmtAlloc(void **argument, size_t size);
char				*_lmtStrdup(char *s1);



#endif
