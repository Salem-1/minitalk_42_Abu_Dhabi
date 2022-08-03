/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 07:57:52 by ahsalem           #+#    #+#             */
/*   Updated: 2022/07/27 08:07:31 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int base, int power)
{
	int	i;
	int	result;

	result = base;
	i = -1;
	while (++i < power - 1)
		result *= base;
	if (power == 0)
		result = 1;
	return (result);
}
