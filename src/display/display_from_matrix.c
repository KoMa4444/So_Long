

#include "../../inc/so_long.h"

void	load_wall(t_map *map, t_vector2 pos)
{
	mlx_texture_t *texture;
	mlx_image_t *image;

	texture = mlx_load_png("assets/terrain/WALL.png");
	image = mlx_texture_to_image(map->screen, texture);
	mlx_image_to_window(map->screen, image, pos.x * 32, pos.y * 32);
}

void	load_floor(t_map *map, t_vector2 pos)
{
	mlx_texture_t *texture;
	mlx_image_t *image;

	texture = mlx_load_png("assets/terrain/FLOOR.png");
	image = mlx_texture_to_image(map->screen, texture);
	mlx_image_to_window(map->screen, image, pos.x * 32, pos.y * 32);
}

void	load_coin(t_map *map, t_vector2 pos)
{

	mlx_texture_t *texture;
	mlx_image_t *image;

	texture = mlx_load_png("assets/coin/F0000.png");
	image = mlx_texture_to_image(map->screen, texture);
	mlx_image_to_window(map->screen, image, pos.x * 32, pos.y * 32);
}

void	load_player(t_map *map, t_vector2 *pos)
{
	mlx_texture_t *texture;
	
	if (map->player->image)
		mlx_delete_image(map->screen, map->player->image);
	texture = mlx_load_png("assets/player/FRONT.png");
	map->player->image = mlx_texture_to_image(map->screen, texture);
	mlx_image_to_window(map->screen, map->player->image, pos->x * 32, pos->y * 32);
	mlx_delete_texture(texture);
}

e_bool	compare_vectors(t_vector2 *pos1, t_vector2 *pos2)
{
	return (pos1->x == pos2->x && pos1->y == pos2->y);
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
			else
				load_floor(map, i);
		}
	}
}

e_bool	all_coins_taken(t_coin *coins)
{
	t_coin *tmp;

	tmp = coins;
	while (True)
	{
		if (tmp->taken == False)
			return (False);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (True);
}

void	load_exit(t_map *map)
{
	mlx_texture_t *texture;
	mlx_image_t *image;
	
	texture = mlx_load_png("assets/coin/F0003.png");
	image = mlx_texture_to_image(map->screen, texture);
	mlx_image_to_window(map->screen, image, map->exit_pos.x * 32, map->exit_pos.y * 32);
}

void	display_switch(t_map *map)
{
	t_coin *tmp;

	tmp = map->coin_matrix;
	load_player(map, map->player->pos);
	if (compare_vectors(map->player->pos, &tmp->pos))
		tmp->taken = True;
	else if (tmp->taken == True)
		load_floor(map, tmp->pos);
	else if (all_coins_taken(map->coin_matrix))
		load_exit(map);
	else
		load_coin(map, tmp->pos);
}

void	display_elements(t_map *map)
{
	while (True) 
	{
		display_switch(map);
		if (map->coin_matrix->next == NULL)
			break ;
		map->coin_matrix = map->coin_matrix->next;
	}
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
			map->player->pos->x -= 1;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		if (map->matrix[map->player->pos->y][map->player->pos->x + 1] != '1')
			map->player->pos->x += 1;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		if (map->matrix[map->player->pos->y + 1][map->player->pos->x] != '1')
			map->player->pos->y += 1;
	}
	else if (keydata.key == MLX_KEY_W)
	{
		if (map->matrix[map->player->pos->y - 1][map->player->pos->x] != '1')
			map->player->pos->y -= 1;
	}
}

void	main_loop(void *map_ptr)
{
	t_map *map;

	map = (t_map *)map_ptr;
	display_elements(map);
}

void	display_from_m(t_map *map)
{
/*mlx_new_image(); // -> crea una imagen, crea un puntero a donde se encuentra la imagen, hay que pintar sobre ella
	mlx_put_pixel(); // -> pone un pixel en la imagen
	mlx_image_to_window();
	mlx_loop();
	mlx_init(); */
	map->screen = mlx_init(map->col * 32, map->row * 32, "Not_So_Long :3", False);
	set_map(map);
	mlx_loop_hook(map->screen, main_loop, (void *)map);
	mlx_key_hook(map->screen, move_character, (void *)map);
	mlx_loop(map->screen);
}
