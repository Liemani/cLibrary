#include "class.h"
#include "t_list.h"

int	program(int argc, mchar **argv);

int	main(int argc, char **argv)
{
	setClass();
	setNull();
	setList();

	return (program(argc, argv));
}
