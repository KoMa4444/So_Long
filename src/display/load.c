/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:08:32 by mkollar           #+#    #+#             */
/*   Updated: 2025/07/10 14:08:34 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	mlx_image_t	*img;

	img = map->player_image;
	mlx_image_to_window(map->screen, img, pos->x * 32, pos->y * 32);
}

void	load_exit(t_map *map)
{
	t_vector2	p;

	p = map->exit_pos;
	mlx_image_to_window(map->screen, map->exit_image, p.x * 32, p.y * 32);
}
