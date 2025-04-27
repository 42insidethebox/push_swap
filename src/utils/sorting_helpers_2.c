/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:49:49 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/04/27 16:50:48 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_contains_chunk(t_stack *a, int chunk, int chunk_size)
{
	t_node	*current;
	int		start;
	int		end;

	if (!a || is_empty(a))
		return (0);
	start = chunk * chunk_size;
	end = (chunk + 1) * chunk_size;
	current = a->top;
	while (current)
	{
		if (current->value >= start && current->value < end)
			return (1);
		current = current->next;
	}
	return (0);
}
