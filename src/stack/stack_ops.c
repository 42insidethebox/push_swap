/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:22:13 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/02 17:39:05 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include <stdlib.h>

void	push_stack(t_stack *stack, int val, int index)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = val;
	new_node->index = index;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

t_node	*pop_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}
