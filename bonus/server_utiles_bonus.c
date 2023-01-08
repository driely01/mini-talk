/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utiles_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:47:38 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/08 17:55:43 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

void	printf_unicode(unsigned char c, siginfo_t *info)
{
	static unsigned int	p;
	static int			size;
	static int			j;
	static int			pid;

	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		p = 0;
	}
	if (p == 0)
	{
		size = size_of_bits(c);
		j = 0;
	}
	p |= c << (j * 8);
	j++;
	if (j == size)
	{
		write(1, &p, size);
		p = 0;
	}
}

int	size_of_bits(unsigned char c)
{
	c = c >> 4;
	if (c == 0b1111)
		return (4);
	else if (c == 0b1110)
		return (3);
	else if (c == 0b1100)
		return (2);
	return (1);
}

void	reset(unsigned char *c, int *i)
{
	*c = 0;
	*i = 0;
}

void	nw_line(int pid, unsigned char c)
{
	if (c == 0)
	{
		write(1, "\n", 1);
		usleep(600);
		kill(pid, SIGUSR1);
	}
	write(1, &c, 1);
}
