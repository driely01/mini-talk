/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:51:32 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/09 12:36:24 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	reset(unsigned char *c, int *i)
{
	*c = 0;
	*i = 0;
}

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
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
		reset(&c, &i);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = (void *)handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("server pid: %d\n", getpid());
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
