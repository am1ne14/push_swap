#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;


int		check_input(char **av);
void	exit_error(void);
t_stack	*init_stack(int ac, char **av);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
void	push_swap(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_big(t_stack **a, t_stack **b);
void	get_position(t_stack **stack);
void	get_target_position(t_stack **a, t_stack **b);
int		get_lowest_index_position(t_stack **stack);
void	get_cost(t_stack **a, t_stack **b);
void	do_cheapest_move(t_stack **a, t_stack **b);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	add_to_stack(t_stack **stack, t_stack *new);
t_stack	*create_new_node(int value);
int		get_stack_size(t_stack *stack);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
void	index_stack(t_stack **stack);
int		get_highest_index(t_stack *stack);
int		absolute_value(int nb);
int	check_splitted_numbers(char **splitted_av);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	finish_rotation(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	push_small_elements(t_stack **a, t_stack **b, int size);
void	sort_b_stack(t_stack **a, t_stack **b);
void	final_rotate(t_stack **a);

#endif
