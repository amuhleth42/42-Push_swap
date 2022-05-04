/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:39:31 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 22:15:32 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_sort *sort)
{
	int	smallest;
	int	i;

	smallest = INT_MAX;
	i = 0;
	while (i < sort->size)
	{
		if (sort->a[i] < smallest)
			smallest = sort->a[i];
		i++;
	}
	return (smallest);
}

void	normalize_stack(t_sort *sort)
{
	int	*new_stack;
	int	i;
	int	j;
	int	smallest;

	new_stack = ft_calloc(sort->size_a + 1, sizeof(int));
	if (!new_stack)
	{
		// todo quit clean
		exit(1);
	}
	j = 0;
	while (j < sort->size)
	{
		smallest = get_smallest(sort);
		i = 0;
		while (sort->a[i] != smallest)
			i++;
		new_stack[i] = j;
		sort->a[i] = INT_MAX;
		j++;
	}
	free(sort->a);
	sort->a = new_stack;
}

void	radix(t_sort *sort)
{
	int	max_bits;
	int	i;
	int	j;

	normalize_stack(sort);
	max_bits = 0;
	while (((sort->size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < sort->size)
		{
			if (((sort->a[0] >> i) & 1) == 1)
			{
				ra(sort);
				ft_printf("ra\n");
			}
			else
			{
				pb(sort);
				ft_printf("pb\n");
			}
			j++;
		}
		while (sort->size_b > 0)
		{
			pa(sort);
			ft_printf("pa\n");
		}
		i++;
	}
}

void	sort(t_sort *sort, int i)
{
	if (i == 0)
		radix(sort);
}
