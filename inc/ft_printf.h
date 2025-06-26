/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:06:13 by mkollar           #+#    #+#             */
/*   Updated: 2024/12/03 15:21:43 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_numlen(long long n);
void	ft_puthexa(unsigned long n, int maxmin, int *i);
void	ft_putstrarg(char *str, int *i);
void	ft_intarg(long long arg, char c, int *i);

#endif