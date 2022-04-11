

#include "push_swap.h"

void	sa(t_data *all)
{
	int	tmp;

	if (all->size_a > 1)
	{
		tmp = all->a[0];
		all->a[0] = all->a[1];
		all->a[1] = all->a[0];
	}
}

void	sb(t_data *all)
{
	int	tmp;

	if (all->size_b > 1)
	{
		tmp = all->b[0];
		all->b[0] = all->b[1];
		all->b[1] = all->b[0];
	}
}

void	ss(t_data *all)
{
	sa(all);
	sb(all);
}

void	ra(t_data *all)
{
	int	tmp;
	int	i;

	if (all->size_a > 1)
	{
		tmp = all->a[0];
		i = 1;
		while (i < all->size_a)
		{
			all->a[i - 1] = all->a[i];
			i++;
		}
		all->a[i - 1] = tmp;
	}
}

void	rb(t_data *all)
{
	int	tmp;
	int	i;

	if (all->size_b > 1)
	{
		tmp = all->b[0];
		i = 1;
		while (i < all->size_b)
		{
			all->b[i - 1] = all->b[i];
			i++;
		}
		all->b[i - 1] = tmp;
	}
}
