/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:04:07 by mkollar           #+#    #+#             */
/*   Updated: 2024/09/20 18:44:40 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_num_in_str(char *str, int n, int *i)
{
	unsigned int	num;

	if (n < 0)
	{
		str[0] = '-';
		num = n * -1;
		(*i)++;
	}
	else
		num = n;
	if (num > 9)
	{
		get_num_in_str(str, num / 10, i);
		(*i)++;
	}
	str[*i] = (num % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		i;

	i = 0;
	len = ft_numlen(n) + 1;
	num = (char *)ft_calloc(len, sizeof(char));
	if (!num)
		return (NULL);
	get_num_in_str(num, n, &i);
	return (num);
}
