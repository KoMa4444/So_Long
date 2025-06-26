/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:24:50 by mkollar           #+#    #+#             */
/*   Updated: 2024/09/24 15:40:30 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nxt;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		nxt = tmp->next;
		(del)(tmp->content);
		free(tmp);
		tmp = nxt;
	}
	*lst = NULL;
}
