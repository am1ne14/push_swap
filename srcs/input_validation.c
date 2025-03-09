#include "../inc/push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicates(char **av)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	while (av[i])
	{
		num1 = ft_atoi(av[i]);
		j = i + 1;
		while (av[j])
		{
			num2 = ft_atoi(av[j]);
			if (num1 == num2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_int_range(char *str)
{
	long	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	check_splitted_numbers(char **splitted_av)
{
	int	j;

	j = 0;
	while (splitted_av[j])
	{
		if (!is_number(splitted_av[j]))
			return (0);
		if (!check_int_range(splitted_av[j]))
			return (0);
		j++;
	}
	return (1);
}

int	check_input(char **av)
{
	char	**splitted_av;
	int		i;

	i = 1;
	while (av[i])
	{
		splitted_av = ft_split(av[i], ' ');
		if (!check_splitted_numbers(splitted_av))
		{
			free(splitted_av);
			return (0);
		}
		free(splitted_av);
		i++;
	}
	if (!check_duplicates(av))
		return (0);
	return (1);
}

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
