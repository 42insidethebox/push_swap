/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:38:06 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/05/01 20:03:34 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	compare_ints(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void	assign_index(t_stack *stack)
{
	int		*values;
	t_node	*current;
	int		i, j;

	if (!stack || stack->size == 0)
		return ;

	// 1️⃣ Allocate and copy values
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

	// 2️⃣ Sort values
	qsort(values, stack->size, sizeof(int), compare_ints);

	// 3️⃣ Assign index to each node based on sorted array
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

	free(values);
}
