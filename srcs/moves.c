/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:47:51 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 20:31:17 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_sort *sort)
{
	int	tmp;

	if (sort->size_a > 1)
	{
		tmp = sort->a[0];
		sort->a[0] = sort->a[1];
		sort->a[1] = tmp;
	}
}

void	sb(t_sort *sort)
{
	int	tmp;

	if (sort->size_b > 1)
	{
		tmp = sort->b[0];
		sort->b[0] = sort->b[1];
		sort->b[1] = tmp;
	}
}

void	ss(t_sort *sort)
{
	sa(sort);
	sb(sort);
}

void	pa(t_sort *sort)
{
	int	i;

	if (sort->size_b > 0)
	{
		i = sort->size_a;
		while (i > 0)
		{
			sort->a[i] = sort->a[i - 1];
			i--;
		}
		sort->a[0] = sort->b[0];
		i = 1;
		while (i < sort->size_b)
		{
			sort->b[i - 1] = sort->b[i];
			i++;
		}
		sort->b[i - 1] = 0;
		sort->size_a++;
		sort->size_b--;
	}
}

void	pb(t_sort *sort)
{
	int	i;

	if (sort->size_a > 0)
	{
		i = sort->size_b;
		while (i > 0)
		{
			sort->b[i] = sort->b[i - 1];
			i--;
		}
		sort->b[0] = sort->a[0];
		i = 1;
		while (i < sort->size_a)
		{
			sort->a[i - 1] = sort->a[i];
			i++;
		}
		sort->a[i - 1] = 0;
		sort->size_b++;
		sort->size_a--;
	}
}
