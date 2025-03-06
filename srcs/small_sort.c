#include "../includes/push_swap.h"


void	sort_small_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		small_sort(a, b);
}

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->nbr;
	mid = (*a)->next->nbr;
	bot = (*a)->next->next->nbr;
	if (top > mid && mid < bot && bot > top)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && bot < top)
		ra(a);
	else if (top < mid && mid > bot && bot > top)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && bot < top)
		rra(a);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	min_index;

	while (stack_size(*a) > 3)
	{
		min_index = find_min_index(*a);
		rotate_a_to_position(a, min_index, stack_size(*a));
		pb(a, b);
	}
	sort_three(a);
}

int	find_min_index(t_stack *a)
{
	int	min_index;
	int	min_value;
	int	current_index;

	min_index = 0;
	min_value = a->nbr;
	current_index = 0;
	while (a)
	{
		if (a->nbr < min_value)
		{
			min_value = a->nbr;
			min_index = current_index;
		}
		a = a->next;
		current_index++;
	}
	return (min_index);
}

void	rotate_a_to_position(t_stack **a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a);
			pos++;
		}
	}
}