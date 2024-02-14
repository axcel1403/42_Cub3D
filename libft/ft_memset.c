/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:18:27 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/14 23:16:47 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (len > i)
		ptr[i++] = (char)c;
	return (str);
}
