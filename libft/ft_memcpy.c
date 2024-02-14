/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:15:11 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/14 23:16:45 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptrdest;
	char	*ptrsrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	while (n > i)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}
