/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:21:40 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 22:09:14 by amuhleth         ###   ########.fr       */
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

void	fill_stack_a(t_sort *sort, char **args)
{
	int	i;

	sort->size = get_size(args);
	sort->size_a = sort->size;
	sort->a = ft_calloc(sort->size_a + 1, sizeof(int));
	sort->b = ft_calloc(sort->size_a + 1, sizeof(int));
	if (!sort->a || !sort->b)
	{
		// todo free all
		ft_printf("error\n");
		//quit(all, "error : malloc");
	}
	i = 0;
	while (args[i] != NULL)
	{
		sort->a[i] = ft_atoi(args[i]);
		if (sort->a[i] == 0 && args[i][0] != '0')
		{
			// todo clean exit
			ft_printf("error\n");
			//quit(all, "Error");
		}
		i++;
	}
}
