/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:39:31 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/17 11:09:09 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_sort *sort)
{
	int	smallest;
	int	i;

	smallest = INT_MAX;
	i = 0;
	while (i < sort->size_a)
	{
		if (sort->a[i] < smallest)
			smallest = sort->a[i];
		i++;
	}
	return (smallest);
}

int	is_sorted(t_sort *sort)
{
	int	i;
	int	j;

	i = 0;
	while (i < sort->size)
	{
		j = i + 1;
		while (j < sort->size)
		{
			if (sort->a[i] > sort->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	normalize_stack(t_sort *sort, t_data *all)
{
	int	*new_stack;
	int	i;
	int	j;
	int	smallest;

	new_stack = ft_calloc(sort->size_a + 1, sizeof(int));
	if (!new_stack)
		quit(all, "malloc error");
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

void	radix(t_sort *sort, t_data *all)
{
	int	i;
	int	j;

	normalize_stack(sort, all);
	i = 0;
	while (!is_sorted(sort))
	{
		j = 0;
		while (j < sort->size)
		{
			if (((sort->a[0] >> i) & 1) == 1)
				op(sort, "ra");
			else
				op(sort, "pb");
			j++;
		}
		while (sort->size_b > 0)
			op(sort, "pa");
		i++;
	}
}

void	sort(t_sort *sort, int i, t_data *all)
{
	if (i == 0)
		radix(sort, all);
	else
	{
		while (--i)
			op(sort, "ra");
		wheel_sort(sort, all);
	}
}
