/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:08:05 by mkollar           #+#    #+#             */
/*   Updated: 2025/07/10 14:09:38 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	exit_the_game(t_map *map)
{
	mlx_close_window(map->screen);
	free_matrix(&map->matrix);
	free(map->player->pos);
	free(map->player);
	free(map);
	mlx_terminate(map->screen);
	exit(EXIT_SUCCESS);
}
