#ifndef SO_LONG_H
#	define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/MLX42/include/MLX42/MLX42_Int.h"
# include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_element_num
{
	int	coins;
	int	player;
	int	exit;
} t_element_num;

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_player
{
	t_vector2		*pos;
}	t_player;

typedef struct s_map
{
	mlx_t	*screen;
	char	**matrix;
	int		row;
	int		col;
	int		coin_counter;
	mlx_image_t	*floor_image;
	mlx_image_t	*coin_image;
	mlx_image_t	*player_image;
	mlx_image_t	*wall_image;
	mlx_image_t	*exit_image;
	t_vector2	exit_pos;
	t_player	*player;
}	t_map;


// display
void	display_from_m(t_map *map);

// matrix utils
void	free_matrix(char ***matrix);
void	print_matrix(char **m);
int	matrix_len(char **matrix);
t_map	*convert_to_map(char **matrix);
void	map_check(char **matrix);
void	exit_and_free_map(t_map **map);
void	check_playeable(t_map *map);

// error management
void	exit_with_error();
void	read_map(char *map_path);
void	exit_and_free_matrix(char ***matrix);
#endif
