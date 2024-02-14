/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:26:17 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/14 23:17:00 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	end;
	char	*ptr;

	if (!s1)
		return (NULL);
	i = 0;
	end = ft_strlen(s1);
	while (s1[i] && ft_search(s1[i], set))
		i++;
	while (end > i && ft_search(s1[end - 1], set))
		end--;
	ptr = (char *)malloc(end - i + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while (s1[i + j] && i + j < end)
	{
		ptr[j] = s1[i + j];
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}
