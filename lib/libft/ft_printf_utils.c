/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:06:09 by mkollar           #+#    #+#             */
/*   Updated: 2024/12/03 15:25:03 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(long long n)
{
	unsigned long long	i;
	unsigned long long	tmp;

	i = 1;
	if (n < 0)
	{
		i++;
		tmp = -n;
	}
	else
		tmp = n;
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

void	ft_intarg(long long arg, char c, int *i)
{
	if (c == 'i' || c == 'd')
	{
		*i += ft_numlen(arg) - 2;
		ft_putnbr_fd(arg, 1);
	}
	else if (c == 'u')
	{
		*i += ft_numlen((unsigned int)arg) - 2;
		ft_putnbr_fd((unsigned int)arg, 1);
	}
	else if (c == 'x')
	{
		ft_puthexa((unsigned int)arg, 1, i);
		(*i)--;
	}
	else
	{
		ft_puthexa((unsigned int)arg, 2, i);
		(*i)--;
	}
}

void	ft_putstrarg(char *str, int *i)
{
	if (str == 0)
	{
		ft_putstrarg("(null)", i);
		return ;
	}
	ft_putstr_fd(str, 1);
	*i += ft_strlen(str) - 2;
}
