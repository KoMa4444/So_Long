/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:37:37 by mkollar           #+#    #+#             */
/*   Updated: 2024/09/25 17:56:00 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		ocurr;

	ocurr = -123;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			ocurr = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	else if (ocurr < 0)
		return (0);
	else
		return ((char *)s + ocurr);
}
