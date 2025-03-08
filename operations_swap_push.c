#include "push_swap.h"

// Swap the first two elements of stack
void	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

// Push the first element from stack b to stack a
void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

// Push the first element from stack a to stack b
void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
