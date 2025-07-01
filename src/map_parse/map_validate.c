
#include "../../inc/so_long.h"

int	check_path(char *map_path)
{
	int	fd;
	int	len;
	int	i;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_with_error();
	i = 0;
	len = ft_strlen(map_path);
	while (i < len-4)
		i++;
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
	size_t	len;

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
