/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:03:02 by gbelange          #+#    #+#             */
/*   Updated: 2022/05/16 17:53:39 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overunderlong(long result)
{
	long		maxint;
	double long	maxlong;

	maxint = 2147483647;
	maxlong = 9223372036854775807;
	if ((result > maxint && !(result >= maxlong)) || (result <= -maxlong - 1))
		return (0);
	if (result < -maxint - 1 || (result >= maxlong))
		return (-1);
	return (result);
}

static int	ft_isws(char w)
{
	if (w == ' ' || w == '\n' || w == '\t' || w == '\v' || w == '\f'
		|| w == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		m;

	m = 1;
	i = 0;
	result = 0;
	while (ft_isws(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (ft_overunderlong(result * m));
}
