/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:29:09 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:20:26 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_stack *a)
{
	t_node	*current;
	int		val;

	if (is_empty(a) || a->size < 2)
		return ;
	current = a->top;
	while (current->next->next)
		current = current->next;
	val = current->next->value;
	free(current->next);
	current->next = NULL;
	a->size--;
	push_stack(a, val);
}

void	rrb(t_stack *b)
{
	t_node	*current;
	int		val;

	if (is_empty(b) || b->size < 2)
		return ;
	current = b->top;
	while (current->next->next)
		current = current->next;
	val = current->next->value;
	free(current->next);
	current->next = NULL;
	b->size--;
	push_stack(b, val);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
