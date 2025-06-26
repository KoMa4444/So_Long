/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:41:18 by mkollar           #+#    #+#             */
/*   Updated: 2024/10/07 16:04:15 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_till_c(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_count_words(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	if (s[i] != c)
		word++;
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			word++;
		i++;
	}
	return (word);
}

static void	malloc_error(char **matrix, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(matrix[i]);
	free(matrix);
}

static int	get_word_in_m(char **matrix, const char *s, char c, int j)
{
	int	x;
	int	wordlen;

	x = -1;
	wordlen = ft_count_till_c(s + j, c) + 1;
	*matrix = (char *)ft_calloc(wordlen, sizeof(char));
	if (!*matrix)
		return (0);
	while (++x < (wordlen - 1))
		(*matrix)[x] = s[j++];
	(*matrix)[x] = '\0';
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**matrix;

	i = 0;
	j = 0;
	if (!s || ft_strlen(s) < 1)
		matrix = (char **)ft_calloc(1, sizeof(char *));
	else
		matrix = (char **)ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!matrix)
		malloc_error(matrix, i);
	while (s[j] && matrix)
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			j = get_word_in_m(&matrix[i], s, c, j);
			if (!matrix)
				malloc_error(matrix, i);
			i++;
		}
	}
	return (matrix);
}
