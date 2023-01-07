/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:51:32 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/07 14:25:53 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

static void	handler(int sig, siginfo_t *info)
{
	static char	c;
	static int	i;
	static int	pid;

	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		c = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			usleep(600);
			kill(pid, SIGUSR1);
		}
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = (void *)handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("server pid: %d\n", getpid());
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
