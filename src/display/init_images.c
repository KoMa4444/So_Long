#include "../../inc/so_long.h"

void	chk_valid(t_map **map, mlx_texture_t *texture)
{
	if (texture == NULL)
		exit_and_free_map(map);
}

void	init_images(t_map *map)
{
	mlx_texture_t	*texture;

	map->screen = mlx_init(map->col * 32, map->row * 32, "so_long", False);
	texture = mlx_load_png("assets/terrain/FLOOR.png");
	map->floor_image = mlx_texture_to_image(map->screen, texture);
	chk_valid(&map, texture);
	free(texture);
	texture = mlx_load_png("assets/terrain/WALL.png");
	map->wall_image = mlx_texture_to_image(map->screen, texture);
	chk_valid(&map, texture);
	free(texture);
	texture = mlx_load_png("assets/coin/F0000.png");
	map->coin_image = mlx_texture_to_image(map->screen, texture);
	chk_valid(&map, texture);
	free(texture);
	texture = mlx_load_png("assets/player/FRONT.png");
	map->player_image = mlx_texture_to_image(map->screen, texture);
	chk_valid(&map, texture);
	free(texture);
	texture = mlx_load_png("assets/coin/F0003.png");
	map->exit_image = mlx_texture_to_image(map->screen, texture);
	chk_valid(&map, texture);
	free(texture);
}
