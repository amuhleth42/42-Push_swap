/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:34:38 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/09 17:34:58 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_sort *sort)
{
	t_list	*tmp;

	tmp = sort->solution;
	while (sort->solution)
	{
		ft_printf("%s\n", sort->solution->content);
		sort->solution = sort->solution->next;
	}
	sort->solution = tmp;
}

void	print_stack_a(t_sort *sort)
{
	int	i;

	ft_printf("A : size:%d\n", sort->size_a);
	i = 0;
	while (i < sort->size_a)
	{
		ft_printf("%d\n", sort->a[i]);
		i++;
	}
}

void	print_stack_b(t_sort *sort)
{
	int	i;

	ft_printf("B : size:%d\n", sort->size_b);
	i = 0;
	while (i < sort->size_b)
	{
		ft_printf("%d\n", sort->b[i]);
		i++;
	}
}

void	print_stacks(t_sort *sort)
{
	print_stack_a(sort);
	print_stack_b(sort);
	ft_printf("\n");
}
