/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:52:14 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 20:30:54 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_sort *sort)
{
	int	tmp;
	int	i;

	if (sort->size_a > 1)
	{
		i = sort->size_a - 1;
		tmp = sort->a[i];
		while (i > 0)
		{
			sort->a[i] = sort->a[i - 1];
			i--;
		}
		sort->a[0] = tmp;
	}
}

void	rrb(t_sort *sort)
{
	int	tmp;
	int	i;

	if (sort->size_b > 1)
	{
		i = sort->size_b - 1;
		tmp = sort->b[i];
		while (i > 0)
		{
			sort->b[i] = sort->b[i - 1];
			i--;
		}
		sort->b[0] = tmp;
	}
}

void	rrr(t_sort *sort)
{
	rra(sort);
	rrb(sort);
}
