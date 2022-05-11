/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:44:41 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/11 16:56:38 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		i++;
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

void	wheel_sort(t_sort *sort, t_data *all)
{
	t_wheel	*info;

	normalize_stack(sort, all);
	info = ft_calloc(sort->size, sizeof(t_wheel));
	if (!info)
		quit(all, "malloc error");
	sort->smallest = INT_MAX;
	sort->biggest = INT_MIN;
	wheel_pb(sort);
	wheel_pb(sort);
	while (sort->size_a)
	{
		get_data(sort, info);
		push_best_score(sort, &info[sort->best]);
	}
	while (sort->b[0] != sort->biggest)
		op(sort, "rb");
	while (sort->size_b)
	{
		op(sort, "pa");
	}
	if (info)
		free(info);
}
