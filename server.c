/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 07:57:39 by ahsalem           #+#    #+#             */
/*   Updated: 2022/07/31 20:12:05 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_binary;

/*The binary message are sent in reverse order*/

int	main(void)
{
	int	bit_counter;
	int	type_me;

	ft_printf("%d\n", getpid());
	bit_counter = 0;
	type_me = 0;
	while (1)
	{	
		bit_counter = decoder(bit_counter, type_me);
		type_me++;
		if (type_me % 8 == 0)
		{
			ft_printf("%c", bit_counter);
			bit_counter = 0;
			type_me = 0;
		}
	}
}

void	got_zero_or_one(int sig)
{
	if (sig == SIGUSR1)
		g_binary = 0;
	else if (sig == SIGUSR2)
		g_binary = 1;
	else
		ft_printf("Wrong signal , sig_id = %d\n", sig);
}

int	decoder(int bit_counter, int n)
{
	struct sigaction	sa;

	sa.sa_handler = &got_zero_or_one;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pause();
	bit_counter += power(2, n) * g_binary;
	return (bit_counter);
}
