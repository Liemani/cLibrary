#include <stdlib.h>

#include "t_class/class.h"
#include "class/list.h"
#include "class/pair.h"
#include "class/dictionary.h"

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
