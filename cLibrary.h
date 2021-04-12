#include <stdlib.h>

#include "kernelClass/class.h"
#include "class/pair.h"
#include "class/dictionary.h"

int	program(int argc, char **argv);

typedef void	(*atexitType)(void);

int	main(int argc, char **argv)
{
	setClass();
	setPointer();
	setString();
	setList();
	setPair();
	setDictionary();

	atexit((atexitType)KernelClass.dealloc);

	return (program(argc, argv));
}
