/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:32:48 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/17 10:48:04 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_winner(t_sort *sort)
{
	print_list(sort);
}

void	process(t_data *all, char **args)
{
	int	i;
	int	winner;

	all->sorts = ft_calloc(5, sizeof(t_sort));
	if (!all->sorts)
		quit(all, "malloc error");
	i = 0;
	while (i < 4)
	{
		fill_stack_a(all, &all->sorts[i], args);
		if (all->sorts[i].size < 6)
		{
			sort_small(&all->sorts[i], all);
			break ;
		}
		sort(&all->sorts[i], i, all);
		if (all->sorts[i].sort_score < all->score_min)
		{
			all->score_min = all->sorts[i].sort_score;
			winner = i;
		}
		i++;
	}
	print_winner(&all->sorts[winner]);
}

int	main(int argc, char **argv)
{
	t_data	all;
	char	**argv2;

	ft_bzero(&all, sizeof(all));
	all.score_min = INT_MAX;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		process(&all, argv2);
		free_split(argv2);
	}
	else
		process(&all, argv + 1);
	if (all.sorts)
		free_sorts(&all);
	return (0);
}
