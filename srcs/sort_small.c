/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:02:11 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/09 19:10:58 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_sort *sort)
{
	if (!is_sorted(sort))
		op(sort, "ra");
}

void	sort_small(t_sort *sort, t_data *all)
{
	if (sort->size == 2)
		sort2(sort);
	else if (sort->size == 3)
		sort3(sort);
	else if (sort->size == 4)
		sort4(sort);
	else
		sort5(sort);
	quit(all, "");
}
