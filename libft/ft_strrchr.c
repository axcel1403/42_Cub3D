/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:10:47 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/15 17:03:55 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	uc;

	uc = (unsigned char)c;
	len = 0;
	while (s[len])
		len++;
	while (len >= 0)
	{
		if (s[len] == uc)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
