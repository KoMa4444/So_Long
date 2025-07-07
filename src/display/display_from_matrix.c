

#include "../../inc/so_long.h"

void	load_wall(t_map *map, t_vector2 pos)
{
	mlx_image_to_window(map->screen, map->wall_image, pos.x * 32, pos.y * 32);
}

void	load_floor(t_map *map, t_vector2 pos)
{
	mlx_image_to_window(map->screen, map->floor_image, pos.x * 32, pos.y * 32);
}

void	load_coin(t_map *map, t_vector2 pos)
{
	mlx_image_to_window(map->screen, map->coin_image, pos.x * 32, pos.y * 32);
}

void	load_player(t_map *map, t_vector2 *pos)
{
	mlx_image_to_window(map->screen, map->player_image, pos->x * 32, pos->y * 32);
}

e_bool	compare_vectors(t_vector2 *pos1, t_vector2 pos2)
{
	return (pos1->x == pos2.x && pos1->y == pos2.y);
}

t_map	*convert_to_map(char **matrix)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	map->matrix = matrix;
	map->col = ft_strlen(*matrix);
	map->row = matrix_len(matrix);
	return (map);
}

void	set_map(t_map *map)
{
	t_vector2	i;

	i.y = -1;
	while (map->matrix[++i.y])
	{
		i.x = -1;
		while (map->matrix[i.y][++i.x])
		{
			if (map->matrix[i.y][i.x] == '1')
				load_wall(map, i);
			else if (map->matrix[i.y][i.x] == 'C')
			{
				load_floor(map, i);
				load_coin(map, i);
			}
			else
				load_floor(map, i);
		}
	}
}

void	load_exit(t_map *map)
{
	mlx_image_to_window(map->screen, map->exit_image, map->exit_pos.x * 32, map->exit_pos.y * 32);
}

void	delete_catched(t_map *map)
{
	int	i;
	int	j;
	int	count;
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
	if (map->matrix[map->player->pos->y][map->player->pos->x] == 'C')
	{
		delete_catched(map);
		map->coin_counter--;
		map->matrix[map->player->pos->y][map->player->pos->x] = 'T';
	}
	if (map->coin_counter == 0)
		load_exit(map);
	if (map->matrix[map->player->pos->y][map->player->pos->x] == 'E' && map->coin_counter == 0)
		mlx_close_window(map->screen);
}

void	move_character(mlx_key_data_t keydata, void *map_ptr)
{
	t_map	*map;

	map = (t_map *)map_ptr;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_A)
	{
		if (map->matrix[map->player->pos->y][map->player->pos->x - 1] != '1')
		{
			map->player->pos->x -= 1;
			map->player_image->instances[0].x -= 32;
		}
	}
	else if (keydata.key == MLX_KEY_D)
	{
		if (map->matrix[map->player->pos->y][map->player->pos->x + 1] != '1')
		{
			map->player->pos->x += 1;
			map->player_image->instances[0].x += 32;
		}
	}
	else if (keydata.key == MLX_KEY_S)
	{
		if (map->matrix[map->player->pos->y + 1][map->player->pos->x] != '1')
		{
			map->player->pos->y += 1;
			map->player_image->instances[0].y += 32;
		}
	}
	else if (keydata.key == MLX_KEY_W)
	{
		if (map->matrix[map->player->pos->y - 1][map->player->pos->x] != '1')
		{
			map->player->pos->y -= 1;
			map->player_image->instances[0].y -= 32;
		}
	}
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->screen);
		// mlx_terminate(map->screen);
}

void	main_loop(void *map_ptr)
{
	t_map *map;
	map = (t_map *)map_ptr;
	display_switch(map);
}

void	display_from_m(t_map *map)
{
	mlx_texture_t *texture;

 	map->screen = mlx_init(map->col * 32, map->row * 32, "Not_So_Long :3", False);
 	texture = mlx_load_png("assets/terrain/FLOOR.png");
	map->floor_image = mlx_texture_to_image(map->screen, texture);
	free(texture);
 	texture = mlx_load_png("assets/terrain/WALL.png");
	map->wall_image = mlx_texture_to_image(map->screen, texture);
	free(texture);
 	texture = mlx_load_png("assets/coin/F0000.png");
	map->coin_image = mlx_texture_to_image(map->screen, texture);
	free(texture);
 	texture = mlx_load_png("assets/player/FRONT.png");
	map->player_image = mlx_texture_to_image(map->screen, texture);
	free(texture);
	texture = mlx_load_png("assets/coin/F0003.png");
	map->exit_image = mlx_texture_to_image(map->screen, texture);
	free(texture);

	set_map(map);
	check_playeable(map);
	print_matrix(map->matrix);
	//BIEN
	load_player(map, map->player->pos);
	mlx_loop_hook(map->screen, main_loop, (void *)map);
	mlx_key_hook(map->screen, move_character, (void *)map);
	mlx_loop(map->screen);
}
