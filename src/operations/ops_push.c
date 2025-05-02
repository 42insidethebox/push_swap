/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:56:28 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/02 21:31:19 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = NULL;
	if (is_empty(b))
		return ;
	node = pop_stack(b);
	push_stack(a, node->value, node->index);
	free(node);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (is_empty(a))
		return ;
	node = pop_stack(a);
	push_stack(b, node->value, node->index);
	free(node);
	write(1, "pb\n", 3);
}
