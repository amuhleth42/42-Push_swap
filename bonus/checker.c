/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:38:22 by amuhleth          #+#    #+#             */
/*   Updated: 2022/05/11 16:34:41 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_sort *sort, char **args)
{
	int	i;

	sort->size = get_size(args);
	sort->size_a = sort->size;
	sort->a = ft_calloc(sort->size_a + 1, sizeof(int));
	sort->b = ft_calloc(sort->size_a + 1, sizeof(int));
	if (!sort->a || !sort->b)
		die("Malloc error");
	i = 0;
	while (args[i] != NULL)
	{
		sort->a[i] = ft_atol(args[i]);
		if (ft_atol(args[i]) < INT_MIN || INT_MAX < ft_atol(args[i]))
			die("Error");
		if (sort->a[i] == 0 && args[i][0] != '0')
			die("Error");
		if (check_duplicates(sort, i))
			die("Error");
		i++;
	}
}

void	op_checker(t_sort *sort, char *cmd)
{
	if (!ft_strncmp(cmd, "sa", 5))
		sa(sort);
	if (!ft_strncmp(cmd, "sb", 5))
		sb(sort);
	if (!ft_strncmp(cmd, "pa", 5))
		pa(sort);
	if (!ft_strncmp(cmd, "pb", 5))
		pb(sort);
	if (!ft_strncmp(cmd, "ra", 5))
		ra(sort);
	if (!ft_strncmp(cmd, "rb", 5))
		rb(sort);
	if (!ft_strncmp(cmd, "rra", 5))
		rra(sort);
	if (!ft_strncmp(cmd, "rrb", 5))
		rrb(sort);
	if (!ft_strncmp(cmd, "rr", 5))
		rr(sort);
	if (!ft_strncmp(cmd, "rrr", 5))
		rrr(sort);
}

void	checker(char **args)
{
	t_sort	sort;
	char	*cmd;

	ft_bzero(&sort, sizeof(t_sort));
	parsing(&sort, args);
	cmd = ft_strtrim(get_next_line(0), "\n");
	while (cmd)
	{
		op_checker(&sort, cmd);
		free(cmd);
		cmd = ft_strtrim(get_next_line(0), "\n");
	}
	if (is_sorted(&sort) && sort.size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (sort.a)
		free(sort.a);
	if (sort.b)
		free(sort.b);
}

int	main(int argc, char **argv)
{
	char	**argv2;

	if (argc < 2)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		checker(argv2);
		free_split(argv2);
	}
	else
		checker(argv + 1);
	return (0);
}
