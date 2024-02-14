/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:14:06 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/07 21:14:06 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*ptr;
	size_t	i;

	if (!s1)
		return ((void *)0);
	i = 0;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ptr = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (ptr == (void *)0)
		return ((void *)0);
	while (size1-- != 0)
		ptr[i++] = *s1++;
	while (size2-- != 0)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
