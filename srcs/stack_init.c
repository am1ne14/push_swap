#include "../inc/push_swap.h"

t_stack	*create_new_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new;
	char	**splitted_av;
	int		i;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		splitted_av = ft_split(av[i], ' ');
		while (*splitted_av)
		{
			new = create_new_node((int)ft_atoi(*splitted_av));
			if (!new)
			{
				free_stack(stack);
				exit_error();
			}
			add_to_stack(&stack, new);
			splitted_av++;
		}
		free(splitted_av);
		i++;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
