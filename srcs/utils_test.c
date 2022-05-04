/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:31:54 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 21:34:55 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
