/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:09:44 by mkollar           #+#    #+#             */
/*   Updated: 2025/07/10 15:16:54 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move_left_right(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_A)
	{
		if (map->matrix[map->player->pos->y][map->player->pos->x - 1] != '1')
		{
			map->player->pos->x -= 1;
			map->player_image->instances[0].x -= 32;
			ft_printf("moves: %i\n", map->player_moves++);
		}
	}
	else if (keydata.key == MLX_KEY_D)
	{
		if (map->matrix[map->player->pos->y][map->player->pos->x + 1] != '1')
		{
			map->player->pos->x += 1;
			map->player_image->instances[0].x += 32;
			ft_printf("moves: %i\n", map->player_moves++);
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
			ft_printf("moves: %i\n", map->player_moves++);
		}
	}
	else if (keydata.key == MLX_KEY_W)
	{
		if (map->matrix[map->player->pos->y - 1][map->player->pos->x] != '1')
		{
			map->player->pos->y -= 1;
			map->player_image->instances[0].y -= 32;
			ft_printf("moves: %i\n", map->player_moves++);
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
