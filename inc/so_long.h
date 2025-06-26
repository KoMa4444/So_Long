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

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_coin
{
	t_vector2	pos;
}	t_coin;

// matrix utils
void	free_matrix(char ***matrix);
void	print_matrix(char **m);

// error management
void	exit_with_error();
char	**read_map(char *map_path);
void	exit_and_free_matrix(char ***matrix);
#endif
