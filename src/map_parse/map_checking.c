#include "../../inc/so_long.h"

void	get_special_pos(t_map *map, char cell, t_element_num *ck, t_vector2 i)
{
	if (cell == 'P')
	{
		map->player = (t_player *)ft_calloc(1, sizeof(t_player));
		map->player->pos = (t_vector2 *)ft_calloc(1, sizeof(t_vector2));
		*map->player->pos = i;
		ck->player++;
	}
	else if (cell == 'E')
	{
		map->exit_pos = i;
		ck->exit++;
	}
	else if (cell == 'C')
		ck->coins++;
}

void	check_for_elements(t_map *map)
{
	t_element_num	*ck;
	t_vector2		i;

	i.y = -1;
	ck = (t_element_num *)ft_calloc(1, sizeof(t_element_num));
	ck->player = 0;
	ck->exit = 0;
	ck->coins = 0;
	while (map->matrix[++i.y])
	{
		i.x = -1;
		while (map->matrix[i.y][++i.x])
			get_special_pos(map, map->matrix[i.y][i.x], ck, i);
	}
	if (ck->player != 1 || ck->coins < 1 || ck->exit != 1)
		exit_and_free_matrix(&map->matrix);
	map->coin_counter = ck->coins;
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
	e_bool		ok;

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
