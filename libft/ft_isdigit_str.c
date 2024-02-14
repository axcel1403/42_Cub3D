/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:29:41 by gbelange          #+#    #+#             */
/*   Updated: 2024/02/05 22:13:23 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_str(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}
