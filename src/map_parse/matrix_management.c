/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:09:01 by mkollar           #+#    #+#             */
/*   Updated: 2025/07/10 14:09:02 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_matrix(char ***matrix)
{
	char	**tmp_m;
	int		i;

	i = 0;
	tmp_m = *matrix;
	while (tmp_m[i] != NULL)
	{
		free(tmp_m[i]);
		tmp_m[i] = NULL;
		i++;
	}
	free(tmp_m);
}

char	**matrix_copy(t_map *map)
{
	int		i;
	int		j;
	char	**m;

	i = -1;
	m = (char **)ft_calloc(map->row, sizeof(char *));
	while (map->matrix[++i])
	{
		j = -1;
		m[i] = (char *)ft_calloc(map->col, sizeof(char));
		while (map->matrix[i][++j])
			m[i][j] = map->matrix[i][j];
		m[i][j] = '\0';
	}
	m[i] = NULL;
	return (m);
}

void	print_matrix(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		ft_printf("[*]	%s\n", m[i]);
		i++;
	}
}

int	matrix_len(char **matrix)
{
	int	i;

	if (!matrix)
		exit_with_error();
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
