/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:48:07 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 21:39:13 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_winner(t_sort *sort)
{
	ft_printf("Score : %d\n", sort->score);
}

void	process(t_data *all, char **args)
{
	int	i;
	int	score_min;
	int	winner;

	score_min = INT_MAX;
	all->sorts = ft_calloc(3, sizeof(t_sort));
	if (!all->sorts)
	{
		//free all
		die("malloc error");
	}
	i = 0;
	while (i < 1)
	{
		fill_stack_a(&all->sorts[i], args);
		sort(&all->sorts[i], i);
		if (score_min > all->sorts[i].score)
			winner = i;
		i++;
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
