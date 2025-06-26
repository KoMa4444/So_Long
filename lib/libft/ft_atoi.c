/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:37:52 by mkollar           #+#    #+#             */
/*   Updated: 2025/04/01 17:48:55 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

long long	ft_atoi(const char *nptr)
{
	long long	num;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	num = 0;
	while (ft_is_space(nptr[i]) == 1)
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]) == 1)
	{
		num += nptr[i] - '0';
		if (nptr[i + 1] != '\0' && (ft_isdigit(nptr[i + 1]) == 1))
			num *= 10;
		i++;
	}
	return (sign * num);
}
