/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 404-amine                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:42:10 by 404-amine        #+#    #+#             */
/*   Updated: 2025/03/06 16:42:10 by 404-amine       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Calculate the cost of moving each element to its target position
void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		// Cost to move to top of B
		if (tmp_b->pos <= size_b / 2)
			tmp_b->cost_b = tmp_b->pos;
		else
			tmp_b->cost_b = -(size_b - tmp_b->pos);
		
		// Cost to move target position to top of A
		if (tmp_b->target_pos <= size_a / 2)
			tmp_b->cost_a = tmp_b->target_pos;
		else
			tmp_b->cost_a = -(size_a - tmp_b->target_pos);
		tmp_b = tmp_b->next;
	}
}

// Find the element with the lowest cost to move
void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		cost;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		cost = absolute_value(tmp->cost_a) + absolute_value(tmp->cost_b);
		if (cost < cheapest)
		{
			cheapest = cost;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)

{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b, 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b, 1);
		cost_a++;
		cost_b++;
	}
	finish_rotation(a, b, cost_a, cost_b);
	pa(a, b, 1);
}
void	finish_rotation(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		ra(a, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a, 1);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b, 1);
		cost_b++;
	}
}

// void	sort_big(t_stack **a, t_stack **b)
// {
// 	int	size;
// 	int	pushed;
// 	int	i;

// 	size = get_stack_size(*a);
// 	pushed = 0;
// 	i = 0;
// 	while (size > 6 && pushed < size - 3)
// 	{
// 		if ((*a)->index <= pushed)
// 		{
// 			pb(a, b, 1);
// 			rb(b, 1);
// 			pushed++;
// 		}
// 		else if ((*a)->index <= pushed + (size / 6))
// 		{
// 			pb(a, b, 1);
// 			pushed++;
// 		}
// 		else
// 			ra(a, 1);
// 	}
// 	while (size - pushed > 3)
// 	{
// 		pb(a, b, 1);
// 		pushed++;
// 	}
// 	sort_three(a);
// 	while (*b)
// 	{
// 		get_position(a);
// 		get_position(b);
// 		get_target_position(a, b);
// 		get_cost(a, b);
// 		do_cheapest_move(a, b);
// 	}
// 	get_position(a);
// 	i = get_lowest_index_position(a);
// 	if (i <= get_stack_size(*a) / 2)
// 	{
// 		while (i-- > 0)
// 			ra(a, 1);
// 	}
// 	else
// 	{
// 		i = get_stack_size(*a) - i;
// 		while (i-- > 0)
// 			rra(a, 1);
// 	}
// }

// Sort 3 elements in the stack
void	sort_three(t_stack **a)
{
	int		highest;

	if (is_sorted(*a))
		return;

	highest = get_highest_index(*a);
	
	if ((*a)->index == highest)
		ra(a, 1);
	else if ((*a)->next->index == highest)
		rra(a, 1);

	if ((*a)->index > (*a)->next->index)
		sa(a, 1);
}

// Main push_swap function
void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else
		sort_big(a, b);
}
