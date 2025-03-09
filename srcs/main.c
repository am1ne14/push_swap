#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (!check_input(av))
		exit_error();
	a = init_stack(ac, av);
	b = NULL;
	if (!is_sorted(a))
	{
		index_stack(&a);
		push_swap(&a, &b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
