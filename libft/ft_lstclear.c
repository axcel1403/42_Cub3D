/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:42:08 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/20 19:14:48 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*x;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		x = *lst;
		*lst = x->next;
		ft_lstdelone(x, del);
	}
	*lst = NULL;
}
