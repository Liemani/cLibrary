#include <stdlib.h>

#include "class.h"
#include "list.h"
#include "pair.h"
#include "dictionary.h"

int	program(int argc, char **argv);

typedef void	(*atexitType)(void);

int	main(int argc, char **argv)
{
	setClass();
	setNull();
	setList();
	setPair();
	setDictionary();

	atexit((atexitType)kernelClass.dealloc);

	return (program(argc, argv));
}
