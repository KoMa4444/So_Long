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

char	**matrix_copy(t_map *map)
{
	int	i;
	int	j;
	char	**m;

	i = -1;
	m = (char **)ft_calloc(map->row, sizeof(char *));
	while (map->matrix[++i])
	{
		j = -1;
		m[i] = (char *)ft_calloc(map->col, sizeof(char));
		while (map->matrix[i][++j])
			m[i][j] = map->matrix[i][j];
		m[i][j] = '\0';
	}
	m[i] = NULL;
	return (m);
}


void	flood_fill(t_map *pos_check, char **map, t_vector2 pos)
{
	if (pos.y > pos_check->row - 1 || pos.x > pos_check->col - 1 || pos.y < 0 || pos.x < 0)
		return ;
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'M')
		return ;
	map[pos.y][pos.x] = 'M';
	pos.x += 1;
	flood_fill(pos_check, map, pos);
	pos.x -= 2;
	flood_fill(pos_check, map, pos);
	pos.x += 1;
	pos.y += 1;
	flood_fill(pos_check, map, pos);
	pos.y -= 2;
	flood_fill(pos_check, map, pos);
	return ;
}

void	check_playeable(t_map *map)
{
	int	i;
	int	j;
	char	**m;
	t_vector2	pos;

	pos.x = map->player->pos->x;
	pos.y = map->player->pos->y;
	m = matrix_copy(map);
	flood_fill(map, m, pos);
	i = -1;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j])
		{
			if (m[i][j] == 'C')
			{
				free_matrix(&m);
				exit_and_free_map(&map);
			}
		}
	}
	free_matrix(&m);
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
	if (chk->player != 1 || chk->coins < 1 || chk->exit != 1)
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
