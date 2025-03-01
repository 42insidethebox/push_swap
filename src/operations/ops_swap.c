/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:11:25 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:06:14 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_stack*a)
{
	int	temp;

	if (is_empty(a) || a->size < 2)
		return ;
	temp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (is_empty(b) || b->size < 2)
		return ;
	temp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
