/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:51:32 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/03 16:26:46 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void handler(int sig)
{
	static char c;
	static int i;

	if (sig == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int main(void)
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	ft_printf("server pid: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		// signal(SIGUSR2, &handler);
		// signal(SIGUSR1, &handler);
		pause();
	}
	return (0);
}