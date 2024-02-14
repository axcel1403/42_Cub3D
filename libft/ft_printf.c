/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:13:01 by gbelange          #+#    #+#             */
/*   Updated: 2022/05/11 19:45:23 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printf_vartypefinder(char c, va_list args, int *ptrret)
{
	if (c == 'c')
		printf_writechar(va_arg(args, int), ptrret);
	else if (c == 's')
		printf_writestring(va_arg(args, char *), ptrret);
	else if (c == 'd' || c == 'i')
		printf_putnbr_base(va_arg(args, int), DEC_BASE, ptrret, 'i');
	else if (c == 'u')
		printf_putnbr_base(va_arg(args, unsigned int), DEC_BASE, ptrret, 'u');
	else if (c == 'x')
		printf_putnbr_base(va_arg(args, unsigned int), X_BASE, ptrret, 'u');
	else if (c == 'X')
		printf_putnbr_base(va_arg(args, unsigned int), XX_BASE, ptrret, 'u');
	else if (c == 'p')
	{
		*ptrret += write(1, "0x", 2);
		printf_writeptr(va_arg(args, unsigned long), X_BASE, ptrret);
	}
	else if (c == '%')
		*ptrret += write(1, &c, 1);
}

int	ft_printf(const char *toprint, ...)
{
	va_list	args;
	size_t	i;
	int		*ptrret;
	int		ret;

	ret = 0;
	ptrret = &ret;
	va_start(args, toprint);
	i = 0;
	while (toprint[i])
	{
		if (toprint[i] == '%')
		{
			printf_vartypefinder(toprint[i + 1], args, ptrret);
			i += 2;
		}
		else
		{
			ret += write(1, &toprint[i], 1);
			i++;
		}
	}
	return (ret);
}
