#include "../../inc/so_long.h"

void	flood_fill(t_map *chk, char **map, t_vector2 pos)
{
	if (pos.y > chk->row - 1 || pos.x > chk->col - 1 || pos.y < 0 || pos.x < 0)
		return ;
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'M')
		return ;
	map[pos.y][pos.x] = 'M';
	pos.x += 1;
	flood_fill(chk, map, pos);
	pos.x -= 2;
	flood_fill(chk, map, pos);
	pos.x += 1;
	pos.y += 1;
	flood_fill(chk, map, pos);
	pos.y -= 2;
	flood_fill(chk, map, pos);
	return ;
}

void	check_playeable(t_map *map)
{
	int			i;
	int			j;
	char		**m;
	t_vector2	pos;

	pos.x = map->player->pos->x;
	pos.y = map->player->pos->y;
	m = matrix_copy(map);
	flood_fill(map, m, pos);
	i = -1;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j])
		{
			if (m[i][j] == 'C')
			{
				free_matrix(&m);
				exit_and_free_map(&map);
			}
		}
	}
	free_matrix(&m);
}

int	check_path(char *map_path)
{
	int	fd;
	int	i;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_with_error();
	i = ft_strlen(map_path)-4;
	if (ft_strncmp(map_path + i, ".ber", 4) != 0)
		exit_with_error();
	return (fd);
}

void	read_map(char *map_path)
{
	char		**matrix;
	char		*line;
	char		*tmp;
	int			fd;
	size_t		len;

	fd = check_path(map_path);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (True)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (ft_strlen(tmp) != len && tmp[len - 1] != '\0')
			exit_with_error();
		line = ft_strjoin(line, tmp);
	}
	matrix = ft_split(line, '\n');
	map_check(matrix);
}
