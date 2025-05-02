/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:33:38 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/02 21:15:03 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (2147483647);
	current = stack->top;
	min = current->value;
	current = current->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_position(t_stack *a, int val)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = a->top;
	while (current)
	{
		if (current->value == val)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first < second && second < third)
		return ;
	if (first < third && third < second)
	{
		sa(a);
		ra(a);
	}
	else if (second < first && first < third)
		sa(a);
	else if (third < first && first < second)
		rra(a);
	else if (second < third && third < first)
		ra(a);
	else if (third < second && second < first)
	{
		sa(a);
		rra(a);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	while (a->size > 3)
	{
		min = find_min(a);
		pos = find_position(a, min);
		if (pos <= a->size / 2)
		{
			while (a->top->value != min)
				ra(a);
		}
		else
		{
			while (a->top->value != min)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (!is_empty(b))
		pa(a, b);
}
