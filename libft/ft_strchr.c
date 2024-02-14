/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:48:11 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/15 17:03:18 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	uc;

	uc = (unsigned char)c;
	ptr = (char *)s;
	while (*ptr != uc)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}
