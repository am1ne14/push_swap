#include "push_swap.h"

// Rotate: shift all elements up, first element becomes the last
void	ra(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
