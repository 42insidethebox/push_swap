/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:56:46 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 21:17:23 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = stack_size(a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;

	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (!is_empty(b))
			pa(a, b);
		i++;
	}
}
