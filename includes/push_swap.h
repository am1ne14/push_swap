#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <stdio.h>
#include "stdlib.h"
#include <limits.h>
#include "../libft/libft.h"


typedef struct s_stack
{
    int nbr;
    int index;
    bool above_middle;
    struct s_stack *target_node;
    struct s_stack *next;
} t_stack;

t_stack	*init_stack(int ac, char **av);
char	**parse_input(int ac, char **av);
char	*combine_args(int ac, char **av);
void	append_node(int nbr, t_stack **a);
int	is_digit(char c);
int	check_input(char **av);
int	is_all_digit(char *str);
void	exit_error(void);
void	free_split(char **split);
void	free_stack(t_stack *stack);
void	sort_small_stack(t_stack **a, t_stack **b, int size);
void	sort_three(t_stack **a);
void	small_sort(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack  **b);
void	sort_big_stack(t_stack **a, t_stack **b, int size);
void	init_node_b(t_stack *a, t_stack *b);
void	mov_b_to_a(t_stack **a, t_stack **b);
void	current_index(t_stack *stack);
void	set_target_b(t_stack *a, t_stack *b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char name);
void	min_on_top(t_stack **a);
t_stack *find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int	stack_size(t_stack *a);
int	is_dup(int nbr, t_stack *a);
int	is_sorted(t_stack *a);
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **b, t_stack **a);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
int	find_min_index(t_stack *a);
void	rotate_a_to_position(t_stack **a, int pos, int size);

#endif
