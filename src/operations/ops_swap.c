/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:11:25 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/27 18:30:11 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	silent_swap(t_stack *stack)
{
	int	temp;

	if (is_empty(stack) || stack->size < 2)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
}

void	sa(t_stack *a)
{
	silent_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	silent_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	silent_swap(a);
	silent_swap(b);
	write(1, "ss\n", 3);
}
