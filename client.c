/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:51:30 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/09 13:30:16 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	fill_zeros(int server_pid)
{
	int	j;

	j = -1;
	while (++j < 8)
	{
		if (kill(server_pid, SIGUSR2) != 0)
			exit(1);
		usleep(300);
	}
}

void	send_sig(char *str, int server_pid)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (++j < 8)
		{
			if (str[i] & (1 << j))
			{
				if (kill(server_pid, SIGUSR1) != 0)
					exit(1);
			}
			else
				if (kill(server_pid, SIGUSR2) != 0)
					exit(1);
			usleep(300);
		}
	}
	fill_zeros(server_pid);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid > 0)
			send_sig(argv[2], server_pid);
	}
	return (0);
}
