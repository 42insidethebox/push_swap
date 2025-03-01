/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:25:56 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:17:08 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(const char *arg)
{
	int	i;

	i = 0;
	if (!arg || arg[0] == '\0')
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*runner;

	if (!a || !a->top)
		return (0);
	current = a->top;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (runner->value == current->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	parse_input(int argc, char **argv, t_stack *a)
{
	int		i;
	long	num;

	if (argc < 2)
		return (-1);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
			return (-1);
		num = atol(argv[i]);
		if (num < -2147483648 || num > 2147483647)
			return (-1);
		push_stack(a, (int)num);
		i++;
	}
	if (check_duplicates(a))
		return (-1);
	return (0);
}
