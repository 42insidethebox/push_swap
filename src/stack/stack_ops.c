/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:22:13 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:09:39 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "stdlib.h"

void	push_stack(t_stack *stack, int val)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = val;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop_stack(t_stack *stack)
{
	t_node	*temp;
	int		popped_value;

	if (!stack || !stack->top)
		return (0);
	temp = stack->top;
	popped_value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (popped_value);
}
