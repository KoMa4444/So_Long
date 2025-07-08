#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit_with_error();
	read_map(argv[1]);
}
