
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

	all->size = get_size(args);
	all->a = ft_calloc(all->size + 1, sizeof(int));
	all->b = ft_calloc(all->size + 1, sizeof(int));
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

	i = 0;
	while (i < all->size)
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
