#include "../../inc/so_long.h"

void	check_for_elements(char **matrix)
{
	int	player;
	int	exit;
	int	coin;
	int	i;
	int	j;

	i = -1;
	player = 0;
	exit = 0;
	coin = 0;
	while (matrix[++i][j])
	{
		j = -1;
		while (matrix[i][++j])
		{
			if (matrix[i][j] == 'P')
				player++;
			else if (matrix[i][j] == 'E')
				exit++;
			else if (matrix[i][j] == 'C')
				coin++;
		}
	}
	if (player == 0 || coin == 0 || exit == 0)
		exit_and_free_matrix(&matrix);
}

e_bool	check_all_wall(char *row)
{
	while ()
}

void	check_walls(char **matrix)
{
	int			last;
	int			i;
	e_bool	ok;

	last = ft_strlen(matrix[1]) - 1;
	i = 0;
	ok = check_all_wall(matrix[i]);
	if (ok == False)
		exit_and_free_matrix(&matrix);
	while (matrix[++i + 1])
	{
		if (matrix[i][0] != 1 || matrix[i][last] != 1)
			exit_and_free_matrix(&matrix);
	}
	ok = check_all_wall(matrix[i]);
	if (ok == False)
		exit_and_free_matrix(&matrix);
}

void	map_check(char **matrix)
{
	check_for_elements(matrix);
	check_walls(matrix);
}
