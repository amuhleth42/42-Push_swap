/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:19:07 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 22:41:23 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	die(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	quit(t_data *all, char *message)
{
	int	i;

	i = 0;
	while (all->sorts + i)
	{
		if (all->sorts[i].a)
			free(all->sorts[i].a);
		if (all->sorts[i].b)
			free(all->sorts[i].b);
		ft_lstclear(&all->sorts[i].solution, &free);
		i++;
	}
	if (all->sorts)
		free(all->sorts);
	die(message);
}
