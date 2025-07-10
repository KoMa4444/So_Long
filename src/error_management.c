/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:09:05 by mkollar           #+#    #+#             */
/*   Updated: 2025/07/10 14:09:07 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_with_error(void)
{
	ft_putstr_fd("Error", 2);
	exit(1);
}

void	exit_and_free_matrix(char ***matrix)
{
	ft_putstr_fd("Error", 2);
	if (*matrix)
		free_matrix(matrix);
	exit(1);
}

void	exit_and_free_map(t_map **map)
{
	t_map	*tmp;

	ft_putstr_fd("Error", 2);
	tmp = *map;
	free_matrix(&tmp->matrix);
	free(tmp->player->pos);
	free(tmp->player);
	free(tmp);
	tmp = NULL;
	*map = tmp;
	exit(1);
}
