/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:16:45 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/06 21:40:03 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t l)
{
	int		n;
	int		len;
	char	*cpy;

	if (ft_strlen(src) < l)
		len = ft_strlen(src);
	else
		len = l;
	cpy = (char *)malloc(sizeof(*src) * len + 1);
	if (cpy == NULL)
		return (NULL);
	n = 0;
	while (n < len)
	{
		cpy[n] = src[n];
		n++;
	}
	cpy[n] = '\0';
	return (cpy);
}
