/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:44:41 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/09 16:15:12 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	wheel_pb(t_sort *sort)
{
	if (sort->a[0] < sort->smallest)
		sort->smallest = sort->a[0];
	if (sort->a[0] > sort->biggest)
		sort->biggest = sort->a[0];
	op(sort, "pb");
}

void	get_info_for_a(t_sort *sort, t_wheel *info, int i)
{
	/*if (i <= sort->size_a / 2)
		info->ra = i;
	else
		info->rra = sort->size_a - i;*/
	info->ra = i;
	info->rra = sort->size_a - i;
}

//si je trouve un maniere de faire marcher cette fonction jsuis un giga boss

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
		/*if (i <= sort->size_b / 2)
			info->rb = i;
		else
			info->rrb = sort->size_b - i;*/
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

void	get_data(t_sort *sort, t_wheel *info)
{
	int	i;

	sort->best_score = INT_MAX;
	i = 0;
	while (i < sort->size_a)
	{
		info[i].value = sort->a[i];
		get_info_for_a(sort, &info[i], i);
		get_info_for_b(sort, &info[i]);
		get_score(&info[i]);
		if (info[i].score < sort->best_score)
		{
			sort->best_score = info[i].score;
			sort->best = i;
		}
		//ft_printf("Value %d : ", info[i].value);
		//ft_printf("%d ", info[i].ra);
		//ft_printf("%d : ", info[i].rra);
		//ft_printf("%d ", info[i].rb);
		//ft_printf("%d :", info[i].rrb);
		//ft_printf(" s = %d\n", info[i].score);
		i++;
	}
}

void	do_r(t_sort *sort, t_wheel *info)
{
	while (info->ra && info->rb)
	{
		op(sort, "rr");
		//printf("rr\n");
		info->ra--;
		info->rb--;
	}
	while (info->ra--)
	{
		op(sort, "ra");
		//printf("ra\n");
	}
	while (info->rb--)
	{
		op(sort, "rb");
		//printf("rb\n");
	}
}

void	do_rr(t_sort *sort, t_wheel *info)
{
	while (info->rra && info->rrb)
	{
		op(sort, "rrr");
		//printf("rrr\n");
		info->rra--;
		info->rrb--;
	}
	while (info->rra--)
	{
		//printf("rra\n");
		op(sort, "rra");
	}
	while (info->rrb--)
	{
		//printf("rrb\n");
		op(sort, "rrb");
	}
}

void	do_mix(t_sort *sort, t_wheel *info)
{
	if (info->ra + info->rrb < info->rra + info->rb)
	{
		while (info->ra--)
		{
			//printf("ra\n");
			op(sort, "ra");
		}
		while (info->rrb--)
		{
			//printf("rrb\n");
			op(sort, "rrb");
		}
	}
	else
	{
		while (info->rra--)
		{
			//printf("rra\n");
			op(sort, "rra");
		}
		while (info->rb--)
		{
			//printf("rb\n");
			op(sort, "rb");
		}
	}
}

void	push_best_score(t_sort *sort, t_wheel *info)
{
	if (info->todo == 1)
		do_r(sort, info);
	else if (info->todo == -1)
		do_rr(sort, info);
	else
		do_mix(sort, info);
	wheel_pb(sort);
}

void	wheel_sort(t_sort *sort)
{
	t_wheel	*info;

	info = ft_calloc(sort->size, sizeof(t_wheel));
	normalize_stack(sort);
	sort->smallest = INT_MAX;
	sort->biggest = INT_MIN;
	wheel_pb(sort);
	wheel_pb(sort);
	while (sort->size_a)
	{
		get_data(sort, info);
		//printf("Best: %d, todo: %d, score:%d, ra:%d, rb:%d, rra:%d, rrb:%d\n", sort->best, info[sort->best].todo, info[sort->best].score, info[sort->best].ra, info[sort->best].rb, info[sort->best].rra, info[sort->best].rrb);
		push_best_score(sort, &info[sort->best]);
		//print_stacks(sort);
	}
	while (sort->b[0] != sort->biggest)
		op(sort, "rb");
	while (sort->size_b)
	{
		op(sort, "pa");
	}
	//print_stacks(sort);
}
