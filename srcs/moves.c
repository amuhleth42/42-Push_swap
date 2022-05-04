/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:47:51 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 22:39:36 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op(t_sort *sort, char *cmd)
{
	if (!ft_strncmp(cmd, "sa", 5))
		sa(sort);
	if (!ft_strncmp(cmd, "sb", 5))
		sb(sort);
	if (!ft_strncmp(cmd, "pa", 5))
		pa(sort);
	if (!ft_strncmp(cmd, "pb", 5))
		pb(sort);
	if (!ft_strncmp(cmd, "ra", 5))
		ra(sort);
	if (!ft_strncmp(cmd, "rb", 5))
		rb(sort);
	if (!ft_strncmp(cmd, "rra", 5))
		rra(sort);
	if (!ft_strncmp(cmd, "rrb", 5))
		rrb(sort);
	ft_lstadd_back(&sort->solution, ft_lstnew(cmd));
	ft_printf("%s\n", cmd);
	sort->score++;
}

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
