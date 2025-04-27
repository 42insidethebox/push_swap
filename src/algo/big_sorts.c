/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:03:06 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/27 21:41:43 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

static int	calculate_max_bits(t_stack *a)
{
	int	max_index;
	int	bits;

	max_index = a->size - 1;
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_stack *a, t_stack *b, int bit_index)
{
	int	size;
	int	bit;

	size = a->size;
	while (size > 0)
	{
		bit = (a->top->index >> bit_index) & 1;
		if (bit == 0)
			pb(a, b);
		else
			ra(a);
		size--;
	}
	while (!is_empty(b))
		pa(a, b);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;

	if (!a)
		return ;
	max_bits = calculate_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, i);
		i++;
	}
}
