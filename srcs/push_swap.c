#include "../includes/push_swap.h"

void	push_swap(t_stack **a, t_stack  **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 5)
		sort_small_stack(a, b, size);
	else
		sort_big_stack(a, b, size);
}

void	sort_big_stack(t_stack **a, t_stack **b, int size)
{
	while (size > 3 && !is_sorted(*a))
	{
		pb(b, a);
		size--;
	}
	if (size <= 3)
		sort_three(a);
	while (*b)
	{
		init_node_b(*a, *b);
		mov_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
// void	sort_big_stack(t_stack **a, t_stack **b, int size)
// {
// 	int chunk_size;
// 	int i;
// 	t_stack *min_node;

// 	chunk_size = 30; // Adaptive chunking (adjust for better performance)
// 	i = 0;
// 	while (*a && i < size)
// 	{
// 		if ((*a)->index <= i)
// 		{
// 			pb(b, a);
// 			rb(b);
// 			i++;
// 		}
// 		else if ((*a)->index <= i + chunk_size)
// 		{
// 			pb(b, a);
// 			i++;
// 		}
// 		else
// 			ra(a);
// 	}
// 	while (*b)
// 	{
// 		init_node_b(*a, *b);
// 		mov_b_to_a(a, b);
// 	}
// 	min_node = find_min(*a);
// 	prep_for_push(a, min_node, 'a');
// }


void	init_node_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b); 
	set_target_b(a, b);
}

void	mov_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	current_index(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		stack = stack->next;
		i++;
	}
}
// void	mov_b_to_a(t_stack **a, t_stack **b)
// {
// 	prep_for_push(a, (*b)->target_node, 'a');
// 	pa(a, b);
// }


void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
// void	set_target_b(t_stack *a, t_stack *b)
// {
// 	t_stack	*current_a;
// 	t_stack	*best_match;
// 	long	best_value;

// 	while (b)
// 	{
// 		best_value = LONG_MAX;
// 		best_match = NULL;
// 		current_a = a;
// 		while (current_a)
// 		{
// 			if (current_a->nbr > b->nbr && current_a->nbr < best_value)
// 			{
// 				best_value = current_a->nbr;
// 				best_match = current_a;
// 			}
// 			current_a = current_a->next;
// 		}
// 		if (!best_match)
// 			b->target_node = find_min(a);
// 		else
// 			b->target_node = best_match;
// 		b = b->next;
// 	}
// }



void	prep_for_push(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_middle)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_middle)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

// void	prep_for_push(t_stack **stack, t_stack *top_node, char name)
// {
// 	while (*stack != top_node)
// 	{
// 		if (name == 'a')
// 		{
// 			if (top_node->above_middle)
// 				ra(stack);
// 			else
// 				rra(stack);
// 		}
// 		else if (name == 'b')
// 		{
// 			if (top_node->above_middle)
// 				rb(stack);
// 			else
// 				rrb(stack);
// 		}
// 	}
// }


void	min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_middle)
			ra(a);
		else
			rra(a);
	}
}
// void	min_on_top(t_stack **a)
// {
// 	t_stack *min_node;

// 	min_node = find_min(*a);
// 	prep_for_push(a, min_node, 'a');
// }


t_stack *find_max(t_stack *stack)
{
    if (!stack)
        return NULL;

    t_stack *max_node = stack;
    while (stack)
    {
        if (stack->nbr > max_node->nbr)
            max_node = stack;
        stack = stack->next;
    }
    return max_node;
}

//void	current_index(t_stack *stack)
// {
// 	int	i;
// 	int	middle;

// 	i = 0;
// 	if (!stack)
// 		return ;
// 	middle = stack_size(stack) / 2;
// 	while (stack)
// 	{
// 		stack->index = i;
// 		stack->above_middle = (i <= middle);
// 		stack = stack->next;
// 		i++;
// 	}
// }
