/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:00:23 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/03 21:46:31 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <libc.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long n);
int		ft_strlen(char *str);
int		ft_putnbr_hex(unsigned long long nb, int c);
int		ft_check(const char *fmt, va_list args, int i, int len);
int		ft_printf(const char *fmt, ...);
void	send_sig(char *str, int server_pid);
int		ft_atoi(const char *str);

#endif