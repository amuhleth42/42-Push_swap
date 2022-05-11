/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:36:16 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/11 17:27:17 by amuhleth         ###   ########.fr       */
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
	int	todo;
}		t_wheel;

typedef struct s_chunk
{
	int	size;
	int	max;
	int	min;
	int	last_max;
	int	last_min;
	int	push_min;
	int	push_min_count;
}		t_chunk;

typedef struct s_sort
{
	int		*a;
	int		*b;
	int		size;
	int		size_a;
	int		size_b;
	int		smallest;
	int		biggest;
	int		best;
	int		best_score;
	int		sort_score;
	t_list	*solution;
}			t_sort;

typedef struct s_data
{
	int		size;
	int		score_min;
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
void	free_split(char **argv2);
void	free_sorts(t_data *all);

int		get_size(char **args);
int		check_duplicates(t_sort *sort, int i);
void	fill_stack_a(t_data *all, t_sort *sort, char **args);

void	sort(t_sort *sort, int i, t_data *all);
int		is_sorted(t_sort *sort);
int		get_smallest(t_sort *sort);

void	print_stack_a(t_sort *sort);
void	print_stack_b(t_sort *sort);
void	print_stacks(t_sort *sort);
void	print_list(t_sort *sort);

void	normalize_stack(t_sort *sort, t_data *all);
void	optimize_solution(t_sort *sort);

void	wheel_sort(t_sort *sort, t_data *all);

void	get_info_for_a(t_sort *sort, t_wheel *info, int i);
int		right_place(t_sort *sort, t_wheel *info);
void	get_info_for_b(t_sort *sort, t_wheel *info);
void	get_score(t_wheel *info);

void	wheel_pb(t_sort *sort);
void	do_r(t_sort *sort, t_wheel *info);
void	do_rr(t_sort *sort, t_wheel *info);
void	do_mix(t_sort *sort, t_wheel *info);

long	ft_atol(const char *str);

void	sort_small(t_sort *sort, t_data *all);

#endif
