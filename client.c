/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 07:57:45 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/01 20:28:03 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
SIGUSR1 -> 0
SIGUSR2 -> 1
Time for testing the workflow for minitalk, after this inshalla can submit
*/

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	j;

	j = -1;
	i = -1;
	if (argc != 3)
	{
		ft_printf("incorrect number of arguments\nclosing the program .......\n");
		return (1);
	}
	while (argv[1][++j] == '0')
		;
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("PID has non numeric characters :(\n");
			return (2);
		}
	}
	pid = ft_atoi(argv[1] + j);
	encoder(argv[2], pid);
}

void	encoder(char *argv, int pid)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		decimal_to_binary(argv[i], 1, pid);
		send_zero(7 - decimal_to_binary(argv[i], 0, pid), pid);
	}
	send_zero(8, pid);
}

int	decimal_to_binary(unsigned char a, int flag, int pid)
{
	int	i;
	int	bin;

	i = -1;
	while (a > 0)
	{
		bin = a % 2;
		if (flag == 1)
		{
			if (bin == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
		}
		usleep(500);
		a /= 2;
		i++;
	}
	return (i);
}

void	send_zero(int a, int pid)
{
	while (a > 0)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		a--;
	}	
}	
