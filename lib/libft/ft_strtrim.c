/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:55:29 by mkollar           #+#    #+#             */
/*   Updated: 2024/10/02 17:48:55 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *set)
{
	char	*new_str;
	int		i;
	int		len;

	if (!s1)
		return (NULL);
	else if (!set || s1[0] == '\0')
	{
		new_str = ft_strdup(s1);
		return (new_str);
	}
	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (len && ft_strchr(set, s1[len]))
		len--;
	new_str = ft_substr(s1, i, len - i + 1);
	if (!new_str)
		return (NULL);
	return (new_str);
}
