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