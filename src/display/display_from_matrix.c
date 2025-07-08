#include "../../inc/so_long.h"

e_bool	compare_vectors(t_vector2 *pos1, t_vector2 pos2)
{
	return (pos1->x == pos2.x && pos1->y == pos2.y);
}

void	delete_catched(t_map *map)
{
	int			i;
	int			j;
	int			count;
	t_vector2	*c_pos;

	count = 0;
	c_pos = map->player->pos;
	i = -1;
	while (map->matrix[++i])
	{
		j = -1;
		while (map->matrix[i][++j])
		{
			if (map->matrix[i][j] == 'C' || map->matrix[i][j] == 'T')
			{
				if (c_pos->x == j && c_pos->y == i)
					map->coin_image->instances[count].enabled = false;
				count++;
			}
		}
	}
}

void	display_switch(t_map *map)
{
	t_vector2	*p_pos;

	p_pos = map->player->pos;
	if (map->matrix[p_pos->y][p_pos->x] == 'C')
	{
		delete_catched(map);
		map->coin_counter--;
		map->matrix[p_pos->y][p_pos->x] = 'T';
	}
	if (map->coin_counter == 0)
		load_exit(map);
	if (map->matrix[p_pos->y][p_pos->x] == 'E' && map->coin_counter == 0)
		exit_the_game(map);
}

void	main_loop(void *map_ptr)
{
	t_map	*map;

	map = (t_map *)map_ptr;
	display_switch(map);
}

void	display_from_m(t_map *map)
{
	init_images(map);
	set_map(map);
	check_playeable(map);
	print_matrix(map->matrix);
	load_player(map, map->player->pos);
	mlx_loop_hook(map->screen, main_loop, (void *)map);
	mlx_key_hook(map->screen, move_character, (void *)map);
	mlx_loop(map->screen);
}
