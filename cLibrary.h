#include <stdlib.h>

#include "kernelClass/class.h"
#include "class/list.h"
#include "class/pair.h"
#include "class/dictionary.h"

int	program(int argc, char **argv);

int	main(int argc, char **argv)
{
	setClassClass();
	setListClass();
	setPairClass();
	setDictionaryClass();

	return (program(argc, argv));
}
