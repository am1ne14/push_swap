#include "../inc/push_swap.h"

// Find the lowest index in the stack
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	sort_three(t_stack **a)
{
	int		highest;

	if (is_sorted(*a))
		return ;
	highest = get_highest_index(*a);
	if ((*a)->index == highest)
		ra(a, 1);
	else if ((*a)->next->index == highest)
		rra(a, 1);
	if ((*a)->index > (*a)->next->index)
		sa(a, 1);
}

// Utility function for absolute value
int	absolute_value(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}