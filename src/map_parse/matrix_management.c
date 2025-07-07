
#include "../../inc/so_long.h"

void	free_matrix(char ***matrix)
{
	char **tmp_m;
	int	i;

	i = 0;
	tmp_m = *matrix;
	while (tmp_m[i] != NULL)
	{
		free(tmp_m[i]);
		tmp_m[i] = NULL;
		i++;
	}
	free(tmp_m);
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