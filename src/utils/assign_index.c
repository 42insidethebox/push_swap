/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:38:06 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/05/07 14:58:20 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	*extract_values(t_stack *stack)
{
	int		*values;
	t_node	*current;
	int		i;

	values = malloc(sizeof(int) * stack->size);
	if (!values)
		handle_exit(stack, NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	return (values);
}

static void	assign_sorted_indices(t_stack *stack, int *values)
{
	t_node	*current;
	int		j;

	current = stack->top;
	while (current)
	{
		j = 0;
		while (j < stack->size)
		{
			if (current->value == values[j])
			{
				current->index = j;
				break ;
			}
			j++;
		}
		current = current->next;
	}
}

void	assign_index(t_stack *stack)
{
	int		*values;

	if (!stack || stack->size == 0)
		return ;
	values = extract_values(stack);
	quick_sort(values, 0, stack->size - 1);
	assign_sorted_indices(stack, values);
	free(values);
}
