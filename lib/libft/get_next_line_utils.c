/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:44:00 by mkollar           #+#    #+#             */
/*   Updated: 2024/12/02 15:18:13 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

ssize_t	ft_len(const char *str, int con)
{
	ssize_t	i;

	i = 0;
	if (con == 1)
	{
		while (str[i])
			i++;
		return (i);
	}
	else if (con == 2)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
		return (i);
	}
	else
		return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	ssize_t		i;
	ssize_t		j;
	ssize_t		lens1;
	ssize_t		lens2;
	char		*new_str;

	if (!s1 || !s2)
		return (NULL);
	j = -1;
	i = -1;
	lens1 = ft_len(s1, 1);
	lens2 = ft_len(s2, 1);
	new_str = (char *)ft_calloc(lens1 + lens2 + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	while (++i < lens1)
		new_str[i] = s1[i];
	while (++j < lens2)
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	return (free(s1), new_str);
}

char	*free_error(char	**file)
{
	if (*file)
	{
		free(*file);
		*file = NULL;
	}
	return ((char *)0);
}
