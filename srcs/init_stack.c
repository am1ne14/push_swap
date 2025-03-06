#include "../includes/push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*a;
	int	nbr;
	int	i;
	char	**splited_input;

	i = 0;
	a = NULL;
	splited_input = parse_input(ac, av);
	while (splited_input[i])
	{
		nbr = ft_atoi(splited_input[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit_error();
		if (is_dup(nbr, a))
			exit_error();
		append_node(nbr, &a);
		i++;
	}
	free_split(splited_input);
	return (a);
}

char	**parse_input(int ac, char **av)
{
	char	**res;
	char	*combined_args;

	if (ac == 2)
	{
		res = ft_split(av[1], ' ');
		if (!res)
			exit_error();
	}
	else
	{
		combined_args = combine_args(ac, av);
		res = ft_split(combined_args, ' ');
		free(combined_args);
		if (!res)
			exit_error();
	}
	return (res);
}

char	*combine_args(int ac, char **av)
{
	size_t	len;
	char	*res;
	int	i;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	res = malloc(len);
	if (!res)
		exit_error();
	res[0] = 0;
	i = 1;
	while (i < ac)
	{
		ft_strlcat(res, av[i], len);
		if (i < ac - 1)
			ft_strlcat(res, " " , len);
		i++;
	}
	return (res);

}

void	append_node(int nbr, t_stack **a)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit_error();
	new_node->nbr = nbr;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}