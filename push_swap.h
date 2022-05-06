/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:36:16 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/04 22:35:20 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_wheel
{
	int	value;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	score;
}		t_wheel;

typedef struct s_chunk
{
	int	size;
	int	max;
	int min;
	int	last_max;
	int	last_min;
	int	push_min;
	int	push_min_count;
}		t_chunk;

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

void	op(t_sort *sort, char *cmd);
void	multi_op(t_sort *sort, char *cmd, int nb);
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
void	fill_stack_a(t_data *all, t_sort *sort, char **args);

void	sort(t_sort *sort, int i);

void	print_stack_a(t_sort *sort);
void	print_stack_b(t_sort *sort);
void	print_stacks(t_sort *sort);
void	print_list(t_sort *sort);

void	normalize_stack(t_sort *sort);
void	optimize_solution(t_sort *sort);

void	wheel_sort(t_sort *sort);
#endif
