/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:06:04 by mkollar           #+#    #+#             */
/*   Updated: 2024/12/03 15:24:43 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	c == caracter
	s == string
	i && d == decimales, integer
	x == base hexadecimal
	X == hexadecimal en mayúscula
	P == puntero
	% == imprime %
*/

void	ft_puthexa(unsigned long n, int maxmin, int *i)
{
	static char		hexa[16] = "0123456789ABCDEF";
	unsigned long	num;

	num = n;
	if (num > 15)
	{
		ft_puthexa(num / 16, maxmin, i);
		(*i)++;
	}
	if (maxmin == 1)
		ft_putchar_fd(ft_tolower(hexa[num % 16]), 1);
	else
	{
		ft_putchar_fd(hexa[num % 16], 1);
	}
}

void	ft_putpointer(void *ptr, int *i)
{
	unsigned long	pointer;

	if (!ptr)
	{
		ft_putstrarg("(nil)", i);
		return ;
	}
	pointer = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	(*i) += 1;
	ft_puthexa((unsigned long)pointer, 1, i);
}

void	ft_putarg(va_list args, const char c, int *i)
{
	if (c == '%')
	{
		(*i)--;
		ft_putchar_fd('%', 1);
	}
	else if (c == 'c')
	{
		(*i)--;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (c == 's')
		ft_putstrarg(va_arg(args, char *), i);
	else if (c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X')
		ft_intarg(va_arg(args, int), c, i);
	else if (c == 'p')
		ft_putpointer(va_arg(args, void *), i);
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		tmp_count;
	int		i;

	tmp_count = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_putarg(args, str[i + 1], &tmp_count);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i + tmp_count);
}
