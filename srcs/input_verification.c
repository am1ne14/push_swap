#include "../includes/push_swap.h"

/*
int	is_digit(char c);
int	is_all_digit(char *str);
int	check_input(char **av);
*/

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	check_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_all_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_all_digit(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
	{
		str++;
		if (*str == '\0')
			return (0);
	}
	while (*str)
	{
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}
