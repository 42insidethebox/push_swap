/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:03:06 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:14:15 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

void	sort_big(t_stack *a, t_stack *b)
{
	int	max;
	int	i;
	int	bit;
	int	size;

	max = find_max(a);
	i = 0;
	while ((max >> i) != 0)
	{
		size = a->size;
		while (size--)
		{
			bit = (a->top->value >> i) & 1;
			if (bit == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (!is_empty(b))
			pa(a, b);
		i++;
	}
}
