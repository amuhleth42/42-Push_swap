

#include "push_swap.h"

void	check_rr(t_sort *sort)
{
	t_list	*tmp;
	t_list	*keep;
	char	*current;
	char	*next;

	keep = sort->solution;
	while (sort->solution->next)
	{
		current = sort->solution->content;
		next = sort->solution->next->content;
		if (!ft_strncmp(current, "ra", 2)
			&& !ft_strncmp(next, "rb", 2))
		{
			current[1] = 'r';
			tmp = sort->solution->next;
			sort->solution->next = sort->solution->next->next;
			ft_lstdelone(tmp, &free);
		}
		else if (!ft_strncmp(current, "ra", 2)
			&& !ft_strncmp(next, "rb", 2))
		{
			current[1] = 'r';
			tmp = sort->solution->next;
			sort->solution->next = sort->solution->next->next;
			ft_lstdelone(tmp, &free);
		}
		sort->solution = sort->solution->next;
	}
	sort->solution = keep;
}

void	optimize_solution(t_sort *sort)
{
	check_rr(sort);
	//check_rrr(sort);
	//check_pa_pb(sort);
}
