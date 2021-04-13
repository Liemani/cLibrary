#include <stdlib.h>

#include "kernelClass/class.h"
#include "class/list.h"
#include "class/pair.h"
#include "class/dictionary.h"

int	program(int argc, char **argv);

typedef void	(*atexitType)(void);

int	main(int argc, char **argv)
{
	setClassClass();
	setListClass();
	setPairClass();
	setDictionaryClass();

	atexit((atexitType)KernelClass.dealloc);

	return (program(argc, argv));
}
