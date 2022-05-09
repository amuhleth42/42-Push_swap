/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:19:07 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/09 17:15:10 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	die(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **argv2)
{
	int	i;

	i = 0;
	if (!argv2)
		return ;
	while (argv2[i])
	{
		free(argv2[i]);
		argv2[i] = NULL;
		i++;
	}
	free(argv2);
	argv2 = NULL;
}

void	quit(t_data *all, char *message)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (all->sorts[i].a)
		{
			free(all->sorts[i].a);
			all->sorts[i].a = NULL;
		}
		if (all->sorts[i].b)
		{
			free(all->sorts[i].b);
			all->sorts[i].b = NULL;
		}
		ft_lstclear(&all->sorts[i].solution, &free);
		i++;
	}
	if (all->sorts)
	{
		free(all->sorts);
		all->sorts = NULL;
	}
	die(message);
}
