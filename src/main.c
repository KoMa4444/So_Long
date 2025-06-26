
#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	char	**m;

	if (argc < 2)
		exit_with_error();
	m = read_map(argv[1]);
	display(m);
	(void)m;
}
