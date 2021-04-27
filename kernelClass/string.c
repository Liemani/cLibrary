#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kernelClass/class.h"



t_string		*_newString()
{
	t_string	*string;

	lmtAlloc(string);

	string->value = _lmtStrdup("");
	string->length = 0;

	classAddInstance(String, string);

	return (string);
}

static t_string	*newString()
{
	t_string	*string;

	lmtAlloc(string);
	classAddInstance(String, string);

	string->value = _lmtStrdup("");
	string->length = 0;

	return (string);
}

static void		deallocString(t_string *string)
{
	if (!string)
		return ;

	classRemoveInstance(String, string);

	free(string->value);
	free(string);
}

static t_string	*descriptionString(t_string *string)
{
	t_string	*resultString;

	resultString = String->new();

	if (!string)
	{
		stringMergeString(resultString, descriptionPointer(string));
		return (resultString);
	}

	stringAppendStr(resultString, "\"");
	stringAppendStr(resultString, string->value);
	stringAppendStr(resultString, "\"");

	return (resultString);
}

static int		equalString(t_string *lhs, t_instance *rhs)
{
	if (lhs == NULL)
		return (false);

	t_class *rhsClass = class(rhs);
	if (rhsClass == String)
	{
		t_string *rhsAsString = (t_string *)rhs;
		if (lhs->length != rhsAsString->length)
			return (false);

		if (lhs->value == rhsAsString->value)
			return (true);

		if (lhs->value == NULL || rhsAsString->value == NULL)
			return (false);

		return (!strcmp(lhs->value, rhsAsString->value));
	}
	else if (rhsClass == Pointer)
	{
		if (lhs->value == rhs)
			return (true);

		if (lhs->value == NULL || rhs == NULL)
			return (false);

		return (!strcmp(lhs->value, rhs));
	}

	return (false);
}

void			setStringClass()
{
	if (!Class || classContainsInstance(Class, String))
		return ;

	String = Class->new();
	String->new = (newType)newString;
	String->dealloc = (deallocType)deallocString;
	String->description = (descriptionType)descriptionString;
	String->equal = (equalType)equalString;
}

void			setString(t_string *string, char *s1)
{
	if (!string)
		return ;

	free(string->value);
	string->value = _lmtStrdup(s1);
	string->length = strlen(string->value);
}

t_string		*initString(char *s1)
{
	t_string *string = String->new();
	setString(string, s1);

	return (string);
}

void			stringAppendStr(t_string *s1, char *s2)
{
	char	*stringValue;

	if (!s1 || !s2)
		return ;

	const size_t s2Length = strlen(s2);
	_lmtAlloc((void **)&stringValue, s1->length + s2Length + 1);
	strcpy(stringValue, s1->value);
	strcpy(stringValue + s1->length, s2);
	free(s1->value);
	s1->value = stringValue;
	s1->length += s2Length;
}

void			stringMergeString(t_string *s1, t_string *s2)
{
	char	*stringValue;

	if (!s1 || !s2)
		return ;

	_lmtAlloc((void **)&stringValue, s1->length + s2->length + 1);
	strcpy(stringValue, s1->value);
	strcpy(stringValue + s1->length, s2->value);
	free(s1->value);
	s1->value = stringValue;
	s1->length += s2->length;
	deallocString(s2);
}

void			stringFlush(t_string *string)
{
	printf("%s", string->value);
	deallocString(string);
}

static size_t	predictSize(t_string *string)
{
	size_t	size;
	int		indent;
	char	*ptr;
	int		isInQuote;

	size = string->length + 1;
	indent = 0;
	ptr = string->value;
	isInQuote = false;

	while (*ptr)
	{
		if (*ptr == '\"')
			isInQuote = !isInQuote;
		else if (!isInQuote)
		{
			if (*ptr == '{' || *ptr == '[')
			{
				++indent;
				size += indent;
			}
			else if (*ptr == '}' || *ptr == ']')
			{
				--indent;
				size += indent;
			}
			else if (*ptr == ',')
			{
				size += indent;
			}
		}
		++ptr;
	}

	return (size);
}

void			stringPrettyFlush(t_string *string)
{
	char	*stringToPrint;
	int		indent;
	char	*des;
	char	*src;
	int		isInQuote;

	_lmtAlloc((void **)&stringToPrint, predictSize(string));
	indent = 0;
	des = stringToPrint;
	src = string->value;
	isInQuote = false;

	while (*src)
	{
		if (*src == '\"')
		{
			isInQuote = !isInQuote;
			*des++ = *src++;
		}
		else if (!isInQuote)
		{
			if (*src == '{' || *src == '[')
			{
				++indent;
				*des++ = *src++;
				*des++ = '\n';
				++src;
				for (int i = 0; i < indent; ++i)
					*des++ = '\t';
			}
			else if (*src == '}' || *src == ']')
			{
				--indent;
				*(des - 1) = '\n';
				for (int i = 0; i < indent; ++i)
					*des++ = '\t';
				*des++ = *src++;
			}
			else if (*src == ',')
			{
				*des++ = *src++;
				*des++ = '\n';
				++src;
				for (int i = 0; i < indent; ++i)
					*des++ = '\t';
			}
			else
				*des++ = *src++;
		}
		else
			*des++ = *src++;
	}
	*des = '\0';

	printf("%s \n", stringToPrint);

	deallocString(string);
	free(stringToPrint);
}
