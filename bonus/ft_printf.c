/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:36:12 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/03 22:14:23 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

int	ft_check(const char *fmt, va_list args, int i, int len)
{
	len = 0;
	if (fmt[i] == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (fmt[i] == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (fmt[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (fmt[i] == '%')
		len += ft_putchar('%');
	else if (fmt[i] == 'u')
		len += ft_putnbr(va_arg(args, unsigned int));
	else if (fmt[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (fmt[i] == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 'X');
	else if (fmt[i] == 'x')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 'x');
	else if (fmt[i] == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_hex(va_arg(args, unsigned long long), 'p');
	}
	else
		len += ft_putchar(fmt[i]);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 0)
				break ;
			len += ft_check(fmt, args, i, len);
		}
		else
			len += ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	if (len < 0)
		return (-1);
	return (len);
}
