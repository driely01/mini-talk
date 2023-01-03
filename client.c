/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:51:30 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/03 16:28:08 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_sig(char *str, int server_pid)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & (1 << j))
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(300);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(server_pid, SIGUSR2);
		usleep(300);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc == 3)
		send_sig(argv[2], server_pid);
	return (0);
}