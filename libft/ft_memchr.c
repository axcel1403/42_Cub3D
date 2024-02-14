/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:53:50 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/14 23:16:44 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	char	character;
	size_t	i;

	i = 0;
	character = (char)c;
	ptr = (char *)s;
	while (i < n)
	{
		if (*ptr == character)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
