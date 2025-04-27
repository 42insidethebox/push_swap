/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:16:13 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/04/27 17:17:18 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->top;
	stack->top = temp->next;
	temp->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = temp;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
