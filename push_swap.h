

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_data
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_data;

void	sa(t_data *all);
void	sb(t_data *all);
void	ss(t_data *all);
void	ra(t_data *all);
void	rb(t_data *all);
void	rr(t_data *all);
void	rra(t_data *all);
void	rrb(t_data *all);
void	rrr(t_data *all);

#endif
