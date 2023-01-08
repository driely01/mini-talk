/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:51:32 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/08 17:59:44 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

static void	handler(int sig, siginfo_t *info)
{
	static unsigned char	c;
	static int				i;
	static int				pid;

	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		reset(&c, &i);
	}
	if (sig == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (!(c & (1 << 7)))
			nw_line(pid, c);
		else
			printf_unicode(c, info);
		reset(&c, &i);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = (void *)handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("The server pid is:\t%d\n", getpid());
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}
