/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:38:06 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/04/27 21:39:42 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	*copy_stack_values(t_stack *stack, int size)
{
	int		*values;
	t_node	*current;
	int		i;

	values = malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	return (values);
}

static int	find_index(int *array, int size, int target)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_index(t_stack *stack)
{
	int		*sorted_values;
	t_node	*current;
	int		size;
	int		index;

	if (!stack)
		return ;
	size = stack->size;
	sorted_values = copy_stack_values(stack, size);
	if (!sorted_values)
		handle_exit(stack, NULL);
	quick_sort(sorted_values, 0, size - 1);
	current = stack->top;
	while (current)
	{
		index = find_index(sorted_values, size, current->value);
		current->index = index;
		current = current->next;
	}
	free(sorted_values);
}
