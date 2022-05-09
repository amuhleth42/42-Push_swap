/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:39:54 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/09 18:45:39 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '+' && sign == 1)
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (nb > LONG_MAX / 10)
			return (LONG_MAX);
		nb = (*str - '0') + (nb * 10);
		str++;
	}
	return (nb * sign);
}
