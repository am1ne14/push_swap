#include "../includes/push_swap.h"

/*
 * int	is_sorted(t_stack *a);
 * int	is_dup(int nbr, t_stack *a);
 * int	stack_size(t_stack *a);
 * t_stack	*find_min(t_stack *stack);
 *
 * 
 * */

int	is_sorted(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	is_dup(int nbr, t_stack *a)
{
	if (a == NULL)
		return (0);
	while(a->next)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	if (a == NULL)
		return (0);
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}








