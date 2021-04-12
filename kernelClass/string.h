#ifndef STRING_H
#define STRING_H



typedef struct	s_string
{
	char		*value;
}				t_string;

t_class			*String;



t_string	*newString();
void		deallocString(t_string *string);
void		descriptionString(t_string *string);

void		setString();

#endif
