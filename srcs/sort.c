/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:39:31 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 22:56:43 by amuhleth         ###   ########.fr       */
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
	int	i;
	int	j;

	normalize_stack(sort);
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

void	set_chunk(t_sort *sort, t_chunk *c, int size_chunk)
{
	c->size = size_chunk;
	if (!c->last_max)
		c->max = c->size - 1;
	else
	{
		c->min = c->last_max + 1;
		c->max = c->min + c->size - 1;
	}
	while (c->max >= sort->size)
	{
		c->max--;
		c->size--;
	}
	//c->last_max = c->max;
	//c->last_min = c->min;
	//ft_printf("Min : %d\n", c->min);
	//ft_printf("Max : %d\n", c->max);
	//ft_printf("Size : %d\n", c->size);
}

int	is_in_chunk(int nb, t_chunk *c)
{
	return (c->min <= nb && nb <= c->max);
}

int	get_closest(t_sort *sort, t_chunk *c)
{
	int	i;
	int	rot;
	int rrot;

	i = 0;
	while (!is_in_chunk(sort->a[i], c))
		i++;
	rot = i;
	i = 1;
	while (!is_in_chunk(sort->a[sort->size_a - i], c))
		i++;
	rrot = i;
	if (rrot <= rot)
		return (-rrot);
	else
		return (rot);
}

int	chunk_pushed(t_sort *sort, t_chunk *c)
{
	int	i;

	i = 0;
	while (i < sort->size_a)
	{
		if (is_in_chunk(sort->a[i], c))
			return (0);
		i++;
	}
	return (1);
}

void	push_chunk_to_b(t_sort *sort, t_chunk *c)
{
	int	to_do;

	while (!chunk_pushed(sort, c))
	{
		to_do = get_closest(sort, c);
		if (to_do >= 0)
			multi_op(sort, "ra", to_do);
		else
			multi_op(sort, "rra", -to_do);
		op(sort, "pb");
	}
	if (c->last_min)
	{
		while (sort->a[sort->size_a - 1] != c->min - 1)
			op(sort, "rra");
	}
}

int	is_smallest(int n, int a, int b, int c)
{
	return (n <= a && n <= b && n <= c);
}

int	get_closest_to_m(t_sort *sort, t_chunk *c)
{
	int	r_max;
	int rr_max;
	int	r_min;
	int rr_min;

	r_max = 0;
	while (sort->b[r_max] != c->max)
		r_max++;
	rr_max = 1;
	while (sort->b[sort->size_b - rr_max] != c->max)
		rr_max++;
	r_min = 0;
	while (sort->b[r_min] != c->min)
		r_min++;
	rr_min = 1;
	while (sort->b[sort->size_b - rr_min] != c->min)
		rr_min++;

	if (is_smallest(r_min, r_min, rr_max, rr_max) || is_smallest(rr_min, r_max, r_min, rr_max))
	{
		c->min++;
		c->push_min = 1;
		if (is_smallest(r_min, r_min, rr_max, rr_max))
			return (r_min);
		return (-rr_min);
	}
	c->max--;
	if (is_smallest(r_max, r_min, rr_min, rr_max))
		return (r_max);
	return (-rr_max);
}

void	sort_chunk_back(t_sort *sort, t_chunk *c)
{
	int	to_do;

	c->last_max = c->max;
	c->last_min = c->min;
	while (sort->size_b)
	{
		to_do = get_closest_to_m(sort, c);
		if (to_do >= 0)
			multi_op(sort, "rb", to_do);
		else
			multi_op(sort, "rrb", -to_do);
		op(sort, "pa");
		if (c->push_min)
		{
			op(sort, "ra");
			c->push_min = 0;
		}
	}
	while (c->last_min <= sort->a[0] && sort->a[0] <= c->last_max && c->last_max != sort->size - 1)
		op(sort, "ra");
}

void	big_sort(t_sort *sort, int size_chunk)
{
	t_chunk	c;

	ft_bzero(&c, sizeof(t_chunk));
	normalize_stack(sort);
	while (!is_sorted(sort))
	{
		set_chunk(sort, &c, size_chunk);
		//print_stacks(sort);
		push_chunk_to_b(sort, &c);
		//print_stacks(sort);
		sort_chunk_back(sort, &c);
		//print_stacks(sort);
	}
	//print_stacks(sort);

}

void	sort(t_sort *sort, int i)
{
	if (i == 0)
		radix(sort);
	else
		big_sort(sort, i * 5);
}
