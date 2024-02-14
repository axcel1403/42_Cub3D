/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:27:13 by gbelange          #+#    #+#             */
/*   Updated: 2022/04/18 14:52:33 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isnegative(long longn)
{
	if (longn < 0)
		return (1);
	else
		return (0);
}

static char	*ft_allofill(long longn, int nums)
{
	char	*str;

	str = malloc(sizeof(char) * (nums) + 1);
	if (!str)
		return (NULL);
	str[nums--] = '\0';
	if (longn == 0)
		str[0] = '0';
	if (ft_isnegative(longn) == 1)
	{
		str[0] = '-';
		longn = longn * -1;
	}
	while (longn > 0)
	{
		str[nums] = 48 + (longn % 10);
		longn = longn / 10;
		nums--;
	}
	return (str);
}

static int	ft_lengthchar(long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		length++;
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	long	longn;
	int		nums;

	longn = n;
	nums = ft_lengthchar(longn);
	return (ft_allofill(longn, nums));
}
