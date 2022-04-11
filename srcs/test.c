
#include "push_swap.h"

void	die(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	quit(t_data *all, char *message)
{
	if (all->a)
		free(all->a);
	if (all->b)
		free(all->b);
	die(message);
}

int	get_size(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

void	fill_stack_a(t_data *all, char **args)
{
	int	i;

	all->size_a = get_size(args);
	all->a = ft_calloc(all->size_a + 1, sizeof(int));
	all->b = ft_calloc(all->size_a + 1, sizeof(int));
	if (!all->a || !all->b)
		quit(all, "error : malloc");
	i = 0;
	while (args[i] != NULL)
	{
		all->a[i] = ft_atoi(args[i]);
		if (all->a[i] == 0 && args[i][0] != '0')
			quit(all, "Error");
		i++;
	}
	

}

void	print_stack_a(t_data *all)
{
	int	i;

	ft_printf("A : size:%d\n", all->size_a);
	i = 0;
	while (i < all->size_a)
	{
		ft_printf("%d\n", all->a[i]);
		i++;
	}
}

void	print_stack_b(t_data *all)
{
	int	i;

	ft_printf("B : size:%d\n", all->size_b);
	i = 0;
	while (i < all->size_b)
	{
		ft_printf("%d\n", all->b[i]);
		i++;
	}
}

void	print(t_data *all)
{
	print_stack_a(all);
	print_stack_b(all);
	ft_printf("\n");
}

void	test_moves(t_data *all)
{
	rra(all);
	print(all);
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
	print(&all);
	test_moves(&all);
	return (0);
}
