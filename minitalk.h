/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 07:57:33 by ahsalem           #+#    #+#             */
/*   Updated: 2022/07/30 13:27:25 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <signal.h> 
# include <time.h>

int		power(int base, int power);
int		decoder(int bit_counter, int n);
void	encoder(char *argv, int pid);
void	got_zero_or_one(int sig);
void	send_zero(int a, int pid);
int		decimal_to_binary(unsigned char a, int flag, int pid);

#endif
