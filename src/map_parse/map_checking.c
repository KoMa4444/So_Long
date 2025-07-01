#include "../../inc/so_long.h"

void	get_special_pos(t_map *map, char c_cell, t_element_num *chk, t_vector2 index)
{
	if (c_cell == 'P')
	{
		map->player = (t_player *)ft_calloc(1, sizeof(t_player));
		map->player->pos = (t_vector2 *)ft_calloc(1, sizeof(t_vector2));
		*map->player->pos = index;
		chk->player++;
	}
	else if (c_cell == 'E')
	{
		map->exit_pos = index;
		chk->exit++;
	}
	else if (c_cell == 'C')
	chk->coins++;
}

void	check_for_elements(t_map *map)
{
	t_element_num	*chk;
	t_vector2	index;

	index.y = -1;
	chk = (t_element_num *)ft_calloc(1, sizeof(t_element_num));
	chk->player = 0;
	chk->exit = 0;
	chk->coins = 0;
	while (map->matrix[++index.y])
	{
		index.x = -1;
		while (map->matrix[index.y][++index.x])
			get_special_pos(map, map->matrix[index.y][index.x], chk, index);
	}
	if (chk->player == 0 || chk->coins == 0 || chk->exit == 0)
		exit_and_free_matrix(&map->matrix);
	map->coin_counter = chk->coins;
}

e_bool	check_all_wall(char *row)
{
	int	i;

	i = -1;
	while (row[++i])
	{
		if (row[i] != '1')
			return (False);
	}
	return (True);
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
		if (matrix[i][0] != '1' || matrix[i][last] != '1')
			exit_and_free_matrix(&matrix);
	}
	ok = check_all_wall(matrix[i]);
	if (ok == False)
		exit_and_free_matrix(&matrix);
}

void	map_check(char **matrix)
{
	t_map	*map;

	check_walls(matrix);
	map = convert_to_map(matrix);
	check_for_elements(map);
	display_from_m(map);
}
