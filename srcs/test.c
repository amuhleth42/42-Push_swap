
#include "push_swap.h"

void	die(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

int	count_elem(char **nbs)
{
	int	i;

	i = 0;
	while (nbs[i] != NULL)
		i++;
	return (i);
}

void	fill_stack_a(t_data *all, char **nbs)
{
	int	size;
	int	i;

	size = count_elem(nbs);
	all->a = ft_calloc(size + 1, sizeof(int));
	all->b = ft_calloc(size + 1, sizeof(int));
	if (!all->a || !all->b)
		die("error : malloc");
	i = 0;
	while (nbs[i] != NULL)
	{
		all->a[i] = ft_atoi(nbs[i]);
		i++;
	}
	

}

void	print_stack_a(t_data *all)
{
	int	i;

	i = 0;
	while (all->a[i] != 0)
	{
		ft_printf("%d\n", all->a[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	all;

	ft_bzero(&all, sizeof(all));
	if (argc < 2)
		die("Please enter a list of number");
	if (argc == 2)
		fill_stack_a(&all, ft_split(argv[1], ' '));
	else
		fill_stack_a(&all, argv + 1);
	print_stack_a(&all);
	return (0);
}
