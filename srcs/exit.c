/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:19:07 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 21:36:56 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	die(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

//to redo
/*
void	quit(t_data *all, char *message)
{
	if (all->a)
		free(all->a);
	if (all->b)
		free(all->b);
	die(message);
}*/
