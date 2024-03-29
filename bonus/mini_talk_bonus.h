/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:00:23 by del-yaag          #+#    #+#             */
/*   Updated: 2023/01/08 17:49:56 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_BONUS_H
# define MINI_TALK_BONUS_H

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
void	nw_line(int pid, unsigned char c);
void	reset(unsigned char *c, int *i);
int		size_of_bits(unsigned char c);
void	printf_unicode(unsigned char c, siginfo_t *info);

#endif