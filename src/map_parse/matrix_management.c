
#include "../../inc/so_long.h"

void	free_matrix(char ***matrix)
{
	while (*matrix)
	{
		free(**matrix);
		**matrix = NULL;
		(*matrix)++;
	}
	free(*matrix);
}

void	print_matrix(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		ft_printf("[*]	%s\n", m[i]);
		i++;
	}
}

int	matrix_len(char **matrix)
{
	int	i;

	if (!matrix)
		exit_with_error();
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}