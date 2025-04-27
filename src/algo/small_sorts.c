/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:33:38 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/27 20:11:24 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

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
