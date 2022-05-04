/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:51:21 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 19:26:50 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_sort *sort)
{
	int	tmp;
	int	i;

	if (sort->size_a > 1)
	{
		tmp = sort->a[0];
		i = 1;
		while (i < sort->size_a)
		{
			sort->a[i - 1] = sort->a[i];
			i++;
		}
		sort->a[i - 1] = tmp;
	}
}

void	rb(t_sort *sort)
{
	int	tmp;
	int	i;

	if (sort->size_b > 1)
	{
		tmp = sort->b[0];
		i = 1;
		while (i < sort->size_b)
		{
			sort->b[i - 1] = sort->b[i];
			i++;
		}
		sort->b[i - 1] = tmp;
	}
}

void	rr(t_sort *sort)
{
	ra(sort);
	rb(sort);
}
