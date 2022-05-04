/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:48:07 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 20:39:24 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	print_stack_a(t_data *all)
{
	int	i;

	ft_printf("A : size:%d\n", all->size_a);
	i = 0;
	while (i < all->size_a)
	{
		ft_printf("%d\n", all->a[i]);
		i++;
	}
}

void	print_stack_b(t_data *all)
{
	int	i;

	ft_printf("B : size:%d\n", all->size_b);
	i = 0;
	while (i < all->size_b)
	{
		ft_printf("%d\n", all->b[i]);
		i++;
	}
}

void	print(t_data *all)
{
	print_stack_a(all);
	print_stack_b(all);
	ft_printf("\n");
}
*/

void	print_winner(t_sort *sort)
{
	ft_printf("Score : %d\n", sort->score);
}

void	process(t_data *all, char **args)
{
	int	i;
	int	score_min;
	int	winner;

	all->sorts = ft_calloc(3, sizeof(t_sort));
	if (!all->sorts)
	{
		//free all
		die("malloc error");
	}
	i = 0;
	while (i++ < 1)
	{
		fill_stack_a(&all->sorts[i], args);
		sort(&all->sorts[i], i);
		if (score_min > all->sorts[i].score)
			winner = i;
	}
	print_winner(&all->sorts[winner]);
}

int	main(int argc, char **argv)
{
	t_data	all;
	char	**argv2;

	ft_bzero(&all, sizeof(all));
	if (argc < 2)
		die("Please enter a list of number");
	if (argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		process(&all, argv2);
		//free argv2
	}
	else
		process(&all, argv + 1);
	return (0);
}
