/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:00:53 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/28 17:03:11 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

int	contains_in_chunk(t_stack *a, int lo, int hi)
{
	t_node	*cur;

	if (!a || is_empty(a))
		return (0);
	cur = a->top;
	while (cur)
	{
		if (cur->index >= lo && cur->index <= hi)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	find_nearest_pos(t_stack *a, int lo, int hi)
{
	t_node	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if (cur->index >= lo && cur->index <= hi)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

void	rotate_a_to_pos(t_stack *a, int pos)
{
	int	half;

	if (pos < 0)
		return ;
	half = a->size / 2;
	if (pos <= half)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

int	find_max_pos(t_stack *b)
{
	t_node	*cur;
	int		pos;
	int		max;
	int		max_pos;

	if (!b || is_empty(b))
		return (-1);
	cur = b->top;
	pos = 0;
	max = cur->index;
	max_pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

void	rotate_b_to_max(t_stack *b)
{
	int	pos;
	int	half;

	pos = find_max_pos(b);
	if (pos < 0)
		return ;
	half = b->size / 2;
	if (pos <= half)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = b->size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}
