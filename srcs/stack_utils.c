#include "../inc/push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

// Check if the stack is sorted
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Assign index values to the stack elements
void	index_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;
	int		min;
	int		i;
	int		size;

	size = get_stack_size(*stack);
	i = 0;
	while (i < size)
	{
		min = INT_MAX;
		tmp = *stack;
		while (tmp)
		{
			if (tmp->value < min && tmp->index == -1)
				min = tmp->value;
			tmp = tmp->next;
		}
		current = *stack;
		while (current)
		{
			if (current->value == min && current->index == -1)
			{
				current->index = i;
				break ;
			}
			current = current->next;
		}
		i++;
	}
}
