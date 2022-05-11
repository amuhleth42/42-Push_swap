/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:49:22 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/11 16:50:33 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_info_for_a(t_sort *sort, t_wheel *info, int i)
{
	info->ra = i;
	info->rra = sort->size_a - i;
}

int	right_place(t_sort *sort, t_wheel *info)
{
	if (sort->b[0] < info->value && info->value < sort->b[sort->size_b - 1])
		return (1);
	else if (info->value < sort->smallest && sort->b[0] == sort->biggest)
		return (1);
	else if (info->value > sort->biggest && sort->b[0] == sort->biggest)
		return (1);
	else
		return (0);
}

void	get_info_for_b(t_sort *sort, t_wheel *info)
{
	int	i;

	if (sort->size_b > 1)
	{
		i = 0;
		while (!right_place(sort, info))
		{
			rb(sort);
			i++;
		}
		info->rb = i;
		info->rrb = sort->size_b - i;
		while (i-- > 0)
			rrb(sort);
	}
}

void	get_score(t_wheel *info)
{
	int	commun_r;
	int	commun_rr;

	info->todo = 0;
	if (info->ra > info->rb)
		commun_r = info->rb;
	else
		commun_r = info->ra;
	if (info->rra > info->rrb)
		commun_rr = info->rrb;
	else
		commun_rr = info->rra;
	info->score = info->ra + info->rrb;
	if (info->score > (info->rra + info->rb))
		info->score = info->rra + info->rb;
	if (info->score > (info->rra + info->rrb - commun_rr))
	{
		info->score = info->rra + info->rrb - commun_rr;
		info->todo = -1;
	}
	if (info->score > (info->ra + info->rb - commun_r))
	{
		info->score = info->ra + info->rb - commun_r;
		info->todo = 1;
	}
}
