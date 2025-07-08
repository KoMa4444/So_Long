#include "../../inc/so_long.h"

void	move_left_right(mlx_key_data_t keydata, t_map *map)
{
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
}

void	move_up_down(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_S)
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
}

void	exit_game(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_the_game(map);
}

void	move_character(mlx_key_data_t keydata, void *map_ptr)
{
	t_map	*map;

	map = (t_map *)map_ptr;
	if (keydata.action != MLX_PRESS)
		return ;
	move_left_right(keydata, map);
	move_up_down(keydata, map);
	exit_game(keydata, map);
}
