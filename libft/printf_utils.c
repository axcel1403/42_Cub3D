/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:03:38 by gbelange          #+#    #+#             */
/*   Updated: 2022/05/11 19:45:41 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printf_writechar(char c, int *ptrret)
{
	*ptrret += write(1, &c, 1);
}

void	printf_writestring(char *s, int *ptrret)
{
	size_t	len;

	if (!s)
	{
		*ptrret += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(s);
	*ptrret += write(1, s, len);
}

void	printf_putnbr_base(long nbr, char *base, int *ptrret, char flag)
{
	int		baselength;
	long	nb;

	if (flag == 'u')
		nb = (unsigned int)nbr;
	else
		nb = (int)nbr;
	baselength = 0;
	if (nb < 0)
	{
		*ptrret += write(1, "-", 1);
		nb *= -1;
	}
	while (base[baselength])
		baselength++;
	if (nb < baselength)
		printf_writechar(base[nb], ptrret);
	if (nb >= baselength)
	{
		printf_putnbr_base(nb / baselength, base, ptrret, flag);
		printf_putnbr_base(nb % baselength, base, ptrret, flag);
	}
}

void	printf_writeptr(unsigned long nbr, char *base, int *ptrret)
{
	int	baselength;

	baselength = 0;
	while (base[baselength])
		baselength++;
	if (nbr < (unsigned long)baselength)
		printf_writechar(base[nbr], ptrret);
	if (nbr >= (unsigned long)baselength)
	{
		printf_writeptr(nbr / baselength, base, ptrret);
		printf_writeptr(nbr % baselength, base, ptrret);
	}
}
