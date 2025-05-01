/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:01:41 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 19:53:31 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

void	push_chunk_to_b_big(t_stack *a, t_stack *b, int lo, int hi)
{
	int	pos;

	while (contains_in_chunk(a, lo, hi))
	{
		pos = find_nearest_pos(a, lo, hi);
		rotate_a_to_pos(a, pos);
		pb(a, b);
		if (b->top && b->top->index < (lo + hi) / 2)
			rb(b);
	}
}

void	pull_b_to_a(t_stack *a, t_stack *b)
{
	int	max;

	while (!is_empty(b))
	{
		max = find_max_index(b);
		while (b->top->index != max)
		{
			if (find_max_pos(b) <= b->size / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}
