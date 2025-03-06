/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 404-amine                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:43:46 by 404-amine        #+#    #+#             */
/*   Updated: 2025/03/06 16:43:46 by 404-amine       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		if (!check_int_range(av[i]))
			return (0);
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