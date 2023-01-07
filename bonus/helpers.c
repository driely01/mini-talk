/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:36:30 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/03 22:14:27 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

int	ft_putchar(char c)
{
	int	len;

	len = 0;
	len = write(1, &c, 1);
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_putnbr(long long n)
{
	int	len;

	len = 0;
	if (n >= 0 && n <= 9)
		len += ft_putchar((n + 48));
	else if (n < 0)
	{
		len += ft_putchar('-');
		len += ft_putnbr((-n));
	}
	else
	{
		len += ft_putnbr((n / 10));
		len += ft_putnbr((n % 10));
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_hex(unsigned long long nb, int c)
{
	char		*base;
	int			len;

	len = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb < (unsigned long long)ft_strlen(base))
	{
		len += ft_putchar(base[nb]);
		return (len);
	}
	else
	{
		len += ft_putnbr_hex((nb / ft_strlen(base)), c);
		len += ft_putchar(base[nb % ft_strlen(base)]);
	}
	return (len);
}
