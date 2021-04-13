#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

#include "kernelClass/class.h"



typedef struct	s_string
{
	char		*value;
	size_t		length;
}				t_string;

typedef struct	s_class t_class;

t_class		*String;



t_string	*_newString();

void		setStringClass();

void		setString(t_string *string, char *s1);
t_string	*initString(char *s1);
void		stringAppendStr(t_string *s1, char *s2);
void		stringMergeString(t_string *s1, t_string *s2);
void		stringFlush(t_string *string);
void		stringPrettyFlush(t_string *string);



#endif
