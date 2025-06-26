
#include "../inc/so_long.h"

void	exit_with_error()
{
	ft_putstr_fd("Error", 2);
	exit(1);
}

void	exit_and_free_matrix(char ***matrix)
{
	ft_putstr_fd("Error", 2);
	if (*matrix)
		free_matrix(*matrix);
	exit(1);
}