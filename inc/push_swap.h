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


int		check_input(char **av);	//check argv for dups or non numerics

void	exit_error(void);		//exit in error write "Error"

t_stack	*init_stack(int ac, char **av);	// put all arguments in stack a and NULL in stack b

void	free_stack(t_stack *stack);

int		is_sorted(t_stack *stack); //loop over the list and is its all sorted 

void	push_swap(t_stack **a, t_stack **b); //get the stack size if and call big sort if size > 3

int	check_splitted_numbers(char **splitted_av); //check if all the argument are only numbers

void	sort_three(t_stack **a); // sort three

t_stack	*create_new_node(int value); //alocate and crete a new node 

int		absolute_value(int nb); //valeur absolue

int		get_stack_size(t_stack *stack); //stack size

void	index_stack(t_stack **stack);//loope over stack and give each element an index from small to big smallest = 0
										//biggest = size

void	sa(t_stack **a, int print); // Swap the first two elements of stack a

void	sb(t_stack **b, int print); // Swap the first two elements of stack b

void	ss(t_stack **a, t_stack **b, int print); // sa and sb aty the same time

void	pa(t_stack **a, t_stack **b, int print); //// Push the first element from stack b to stack a

void	pb(t_stack **a, t_stack **b, int print); // Push the first element from stack a to stack b

void	ra(t_stack **a, int print); //first element in stack a become last and shift and shift up the others 

void	rb(t_stack **b, int print); //first element in stack b become last and shift up the others 

void	rr(t_stack **a, t_stack **b, int print); //ra and rb at the same time 

void	rra(t_stack **a, int print); // Reverse rotate: shift all elements down, last element becomes the first

void	rrb(t_stack **b, int print); // Reverse rotate: shift all elements down, last element becomes the first

void	rrr(t_stack **a, t_stack **b, int print); //rra and rrb at the same time

void	get_position(t_stack **stack); // Update the position field for all elements in the stack

void	get_target_position(t_stack **a, t_stack **b);
int		get_lowest_index_position(t_stack **stack);
void	get_cost(t_stack **a, t_stack **b);
void	do_cheapest_move(t_stack **a, t_stack **b);
void	add_to_stack(t_stack **stack, t_stack *new);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
int		get_highest_index(t_stack *stack);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	finish_rotation(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	sort_big(t_stack **a, t_stack **b);
void	push_small_elements(t_stack **a, t_stack **b, int size);
void	sort_b_stack(t_stack **a, t_stack **b);
void	final_rotate(t_stack **a);

#endif
