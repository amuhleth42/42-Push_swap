/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:36:16 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 22:07:44 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_sort
{
	int 	*a;
	int		*b;
	int		size;
	int		size_a;
	int		size_b;
	int		score;
	t_list	*solution;
}			t_sort;

typedef struct s_data
{
	int		size;
	t_sort	*sorts;
}		t_data;

void	sa(t_sort *sort);
void	sb(t_sort *sort);
void	ss(t_sort *sort);
void	ra(t_sort *sort);
void	rb(t_sort *sort);
void	rr(t_sort *sort);
void	rra(t_sort *sort);
void	rrb(t_sort *sort);
void	rrr(t_sort *sort);
void	pa(t_sort *sort);
void	pb(t_sort *sort);

void	die(char *message);
void	quit(t_data *all, char *message);

int		get_size(char **args);
void	fill_stack_a(t_sort *sort, char **args);

void	sort(t_sort *sort, int i);

void	print_stack_a(t_sort *sort);
void	print_stack_b(t_sort *sort);
void	print_stacks(t_sort *sort);

#endif
