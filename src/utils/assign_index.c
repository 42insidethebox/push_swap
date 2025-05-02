/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:38:06 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/05/02 20:02:47 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	assign_index(t_stack *stack)
{
	int		*values;
	t_node	*current;
	int		i;
	int		j;

	if (!stack || stack->size == 0)
		return ;
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
	quick_sort(values, 0, stack->size - 1);
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
