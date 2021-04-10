#include <stdlib.h>

#include "class.h"
#include "t_list.h"
#include "t_pair.h"

int	program(int argc, char **argv);

typedef void	(*atexitType)(void);

int	main(int argc, char **argv)
{
	setClass();
	setNull();
	setList();
	setPair();

	atexit((atexitType)kernelClass.dealloc);

	return (program(argc, argv));
}
