/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:25:56 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/02 17:34:35 by pedroribeir      ###   ########.fr       */
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

int	parse_input(char **args, t_stack *a, int count)
{
	int	i;
	int	num;

	if (!args || count < 1)
		return (-1);
	i = count - 1;
	while (i >= 0)
	{
		if (!is_valid_int(args[i]) || !safe_atoi(args[i], &num))
			return (-1);
		push_stack(a, num, -1);
		i--;
	}
	return (0);
}
