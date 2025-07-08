#include "../../inc/so_long.h"

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
