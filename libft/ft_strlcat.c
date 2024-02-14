/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:02:05 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/18 14:45:43 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	j = dstlen;
	if (dstsize < dstlen)
		return (srclen + dstsize);
	else
	{
		while (src[i] && (dstlen + i) < dstsize)
			dst[j++] = src[i++];
		if ((dstlen + i) == dstsize && dstlen < dstsize)
			dst[--j] = '\0';
		else
			dst[j] = '\0';
		return (srclen + dstlen);
	}
}
