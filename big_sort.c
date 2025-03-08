#include "push_swap.h"

void	sort_big(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(*a);
	push_small_elements(a, b, size);
	sort_three(a);
	sort_b_stack(a, b);
	final_rotate(a);
}

static void	push_small_elements(t_stack **a, t_stack **b, int size)
{
	int	pushed;

	pushed = 0;
	while (size > 6 && pushed < size - 3)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b, 1);
			rb(b, 1);
			pushed++;
		}
		else if ((*a)->index <= pushed + (size / 6))
		{
			pb(a, b, 1);
			pushed++;
		}
		else
			ra(a, 1);
	}
	while (size - pushed > 3)
	{
		pb(a, b, 1);
		pushed++;
	}
}

static void	sort_b_stack(t_stack **a, t_stack **b)
{
	while (*b)
	{
		get_position(a);
		get_position(b);
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
}

static void	final_rotate(t_stack **a)
{
	int	i;

	get_position(a);
	i = get_lowest_index_position(a);
	if (i <= get_stack_size(*a) / 2)
	{
		while (i-- > 0)
			ra(a, 1);
	}
	else
	{
		i = get_stack_size(*a) - i;
		while (i-- > 0)
			rra(a, 1);
	}
}