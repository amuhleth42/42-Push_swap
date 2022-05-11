/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:26 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/11 16:55:11 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wheel_pb(t_sort *sort)
{
	if (sort->a[0] < sort->smallest)
		sort->smallest = sort->a[0];
	if (sort->a[0] > sort->biggest)
		sort->biggest = sort->a[0];
	op(sort, "pb");
}

void	do_r(t_sort *sort, t_wheel *info)
{
	while (info->ra && info->rb)
	{
		op(sort, "rr");
		info->ra--;
		info->rb--;
	}
	while (info->ra--)
		op(sort, "ra");
	while (info->rb--)
		op(sort, "rb");
}

void	do_rr(t_sort *sort, t_wheel *info)
{
	while (info->rra && info->rrb)
	{
		op(sort, "rrr");
		info->rra--;
		info->rrb--;
	}
	while (info->rra--)
		op(sort, "rra");
	while (info->rrb--)
		op(sort, "rrb");
}

void	do_mix(t_sort *sort, t_wheel *info)
{
	if (info->ra + info->rrb < info->rra + info->rb)
	{
		while (info->ra--)
			op(sort, "ra");
		while (info->rrb--)
			op(sort, "rrb");
	}
	else
	{
		while (info->rra--)
			op(sort, "rra");
		while (info->rb--)
			op(sort, "rb");
	}
}
