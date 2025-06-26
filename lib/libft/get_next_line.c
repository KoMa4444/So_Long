/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:07:59 by mkollar           #+#    #+#             */
/*   Updated: 2024/12/02 15:18:52 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_jump(char *txt, int bytes)
{
	int	i;

	i = -1;
	while (++i < bytes)
	{
		if (txt[i] == '\n')
			return (1);
	}
	return (0);
}

char	*return_line(char *file)
{
	char	*ret_line;
	int		i;
	int		len;

	len = ft_len(file, 2);
	ret_line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret_line)
		return (0);
	i = -1;
	while (++i < len)
		ret_line[i] = file[i];
	ret_line[i] = '\0';
	return (ret_line);
}

char	*get_new_file(char *file)
{
	char	*new_file;
	int		i;
	int		ret_len;
	int		new_len;

	i = -1;
	ret_len = ft_len(file, 2);
	new_len = ft_len(file, 1) - ret_len;
	new_file = (char *)ft_calloc(new_len + 1, sizeof(char));
	if (!new_file)
		return (0);
	while (++i < new_len)
		new_file[i] = file[ret_len + i];
	free(file);
	return (new_file);
}

ssize_t	read_file(char **file, int fd, ssize_t *bytes)
{
	char	*txt;

	txt = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!txt)
		return (0);
	*bytes = BUFFER_SIZE;
	while (find_jump(txt, *bytes) == 0 && *bytes >= BUFFER_SIZE)
	{
		*bytes = read(fd, txt, *bytes);
		if (*bytes == -1)
		{
			free(txt);
			return (*bytes);
		}
		else if (*bytes != 0)
		{
			txt[*bytes] = 0;
			*file = ft_strjoin(*file, txt);
			if (!*file)
				return (free(txt), 0);
		}
	}
	return (free(txt), *bytes);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*ret_line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_error(&file));
	bytes = BUFFER_SIZE;
	if (!file)
		file = (char *)ft_calloc(1, sizeof(char));
	if (!file)
		return (0);
	bytes = read_file(&file, fd, &bytes);
	if (bytes == -1 || (bytes == 0 && !file[0]))
		return (free_error(&file));
	ret_line = return_line(file);
	file = get_new_file(file);
	if (!ret_line)
		return (0);
	return (ret_line);
}

/* 
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char *line;
	int fd;
	fd = open("get_next_line.c", O_RDONLY);

	while (( line = get_next_line(fd)) != NULL)
	{
		printf
		("%s", line);
		free(line);
	}
	return (0);
}
 */