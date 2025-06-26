/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:40:58 by mkollar           #+#    #+#             */
/*   Updated: 2024/10/07 15:42:28 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_allocneeded(size_t size, size_t start, size_t len, size_t type)
{
	if (size <= start)
		return ((void *)ft_calloc(1, type));
	else if ((size - start) > len)
		return ((void *)ft_calloc(len, type));
	else
		return ((void *)ft_calloc(size - start, type));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_substr;
	size_t	i;

	i = 0;
	if (start == 0 && ft_strlen(s) < len)
		new_substr = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	else
		new_substr = ft_allocneeded(
				ft_strlen(s) + 1, start, len + 1, sizeof(char));
	if (!new_substr)
		return (NULL);
	if (ft_strlen(s) < start)
		return (new_substr);
	while (i < len && s[i])
	{
		new_substr[i] = s[i +(size_t)start];
		i++;
	}
	new_substr[i + (size_t)start] = '\0';
	return (new_substr);
}
