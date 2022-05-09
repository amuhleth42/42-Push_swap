/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:21:40 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/09 18:55:20 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int	check_duplicates(t_sort *sort, int i)
{
	int	value;

	value = sort->a[i];
	i--;
	while (i >= 0)
	{
		if (value == sort->a[i])
			return (1);
		i--;
	}
	return (0);
}

void	fill_stack_a(t_data *all, t_sort *sort, char **args)
{
	int	i;

	sort->size = get_size(args);
	sort->size_a = sort->size;
	sort->a = ft_calloc(sort->size_a + 1, sizeof(int));
	sort->b = ft_calloc(sort->size_a + 1, sizeof(int));
	if (!sort->a || !sort->b)
		quit(all, "Malloc error");
	i = 0;
	while (args[i] != NULL)
	{
		sort->a[i] = ft_atol(args[i]);
		if (ft_atol(args[i]) < INT_MIN || INT_MAX < ft_atol(args[i]))
			quit(all, "Error");
		if (sort->a[i] == 0 && args[i][0] != '0')
			quit(all, "Error");
		if (check_duplicates(sort, i))
			quit(all, "Error");
		i++;
	}
}
