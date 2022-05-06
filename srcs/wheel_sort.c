
#include "push_swap.h"

void	get_info_for_a(t_sort *sort, t_wheel *info, int i)
{
	if (i <= sort->size_a / 2)
		info->ra = i;
	else
		info->rra = sort->size_a - i;
}

//si je trouve un maniere de faire marcher cette fonction jsuis un giga boss

void	get_info_for_b(t_sort *sort, t_wheel *info)
{
	int	i;
	//int	j;
	if (sort->size_b > 1)
	{
		i = 0;
		while (!(info->value == sort->b[0] + 1))
		{
			ra(sort);
			i++;
		}
		if (i <= sort->size_b / 2)
			info->rb = i;
		else
			info->rrb = sort->size_b - i;
		while (i-- > 0)
			rra(sort);
	}
}

void	get_data(t_sort *sort, t_wheel *info)
{
	int	i;

	i = 0;
	while (i < sort->size_a)
	{
		info[i].value = sort->a[i];
		get_info_for_a(sort, &info[i], i);
		get_info_for_b(sort, &info[i]);
		ft_printf("Value %d : ", info[i].value);
		ft_printf("%d ", info[i].ra);
		ft_printf("%d : ", info[i].rra);
		ft_printf("%d ", info[i].rb);
		ft_printf("%d\n", info[i].rrb);
		//get_info_for_b(sort, &info[i]);
		i++;
	}
}

void	wheel_sort(t_sort *sort)
{
	t_wheel	*info;
	//int	i;

	info = ft_calloc(sort->size, sizeof(t_wheel));
	normalize_stack(sort);
	op(sort, "pb");
	op(sort, "pb");
	//i = 0;
	get_data(sort, info);
	/*while (sort->size_a && i < sort->size_a)
	{
		get_data(sort, info);
		i++;
	}*/
	/*while (sort->size_b)
	{
		op(sort, "pa");
	}*/
}
