#include <stdio.h>
#include <stdlib.h>

#include "kernelClass/class.h"

#define MAX_HEX_ADDRESS_LEN 16
#define HEX_DECIMAL "0123456789abcdef"



static char	*ft_ultox(unsigned long int n)
{
	char	tmp[MAX_HEX_ADDRESS_LEN];
	char	*p_tmp;
	char	*result;
	char	*p_result;

	p_tmp = tmp;
	*p_tmp++ = HEX_DECIMAL[n % 16];
	while ((n /= 16))
		*p_tmp++ = HEX_DECIMAL[n % 16];
	if (!(result = malloc(sizeof(*result) * ((p_tmp - tmp) + 1))))
		return (0);
	p_result = result;
	while (tmp != p_tmp)
		*p_result++ = *(--p_tmp);
	*p_result = '\0';
	return (result);
}

void		deallocPointer(t_pointer *pointer)
{
	return ;
}

t_string	*descriptionPointer(t_pointer *pointer)
{
	t_string	*string;

	string = String->new();
	if (pointer)
	{
		char *hexString = ft_ultox((unsigned long)pointer);
		stringAppendStr(string, "\"0x");
		stringAppendStr(string, hexString);
		stringAppendStr(string, "\"");
		free(hexString);
	}
	else
		stringAppendStr(string, "null");

	return (string);
}

int			equalPointer(t_pointer *lhs, void *rhs)
{
	return (lhs == rhs);
}

void		setPointerClass()
{
	if (!Class || classContainsInstance(Class, Pointer))
		return ;

	Pointer = Class->new();
	Pointer->dealloc = (deallocType)deallocPointer;
	Pointer->description = (descriptionType)descriptionPointer;
	Pointer->equal = (equalType)equalPointer;
}
