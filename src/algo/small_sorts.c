/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:33:38 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:15:25 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

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
	if (second < first && first < third)
		sa(a);
	else if (third < first && first < second)
		rra(a);
	else if (first < third && third < second)
		ra(a);
	else if (second < third && third < first)
	{
		sa(a);
		ra(a);
	}
	else if (third < second && second < first)
	{
		sa(a);
		rra(a);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->top->value == find_min(a) || \
			a->top->value == find_second_min(a))
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if (b->top->value < a->top->value)
		pa(a, b);
	else
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
}
