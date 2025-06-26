/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:40:37 by mkollar           #+#    #+#             */
/*   Updated: 2024/10/02 15:40:05 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	if (len > ft_strlen(big))
		len = ft_strlen(big);
	if (!*little || (big == little))
		return ((char *)big);
	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		n = i;
		while (n < len && little[j] && big[n] == little[j])
		{
			n++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + (n - j));
		i++;
	}
	return (NULL);
}
