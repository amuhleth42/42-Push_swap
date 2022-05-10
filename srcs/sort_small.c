/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:02:11 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/10 18:07:47 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort5(t_sort *sort)
{
	(void) sort;
	ft_printf("Broo!\n");
	exit(EXIT_FAILURE);
}

int	sort4(t_sort *sort)
{
	(void) sort;
	ft_printf("Broo!\n");
	exit(EXIT_FAILURE);
}

int	form_3(t_sort *sort, int first, int sec, int last)
{
	if ((first > sec) != (sort->a[0] > sort->a[1]))
		return (0);
	if ((first > last) != (sort->a[0] > sort->a[2]))
		return (0);
	if ((sec > last) != (sort->a[1] > sort->a[2]))
		return (0);
	return (1);
}

void	sort3(t_sort *sort)
{
	if (form_3(sort, 1, 3, 2) || form_3(sort, 2, 1, 3) || form_3(sort, 3, 2, 1))
		op(sort, "sa");
	if (form_3(sort, 2, 3, 1) || form_3(sort, 3, 2, 1))
		op(sort, "rra");
	if (form_3(sort, 1, 3, 2) || form_3(sort, 3, 1, 2))
		op(sort, "ra");
}

void	sort_small(t_sort *sort, t_data *all)
{
	if (sort->size == 2)
	{
		if (!is_sorted(sort))
			op(sort, "ra");
	}
	else if (sort->size == 3)
		sort3(sort);
	else if (sort->size == 4)
		sort4(sort);
	else
		sort5(sort);
	quit(all, "");
}
