/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:58:42 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/04/28 17:14:48 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

static int	calculate_chunk_size(int total)
{
	int	k;

	k = 11;
	if (total % k == 0)
		return (total / k);
	return (total / k + 1);
}

static void	get_chunk_bounds(int chunk, int chunk_size, int *lo, int *hi)
{
	*lo = chunk * chunk_size;
	*hi = *lo + chunk_size - 1;
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	total;
	int	chunk_size;
	int	chunk;
	int	lo;
	int	hi;

	if (!a || !b || a->size <= 5)
		return ;
	total = a->size;
	chunk_size = calculate_chunk_size(total);
	chunk = 0;
	while (chunk < (total / chunk_size + (total % chunk_size != 0)))
	{
		get_chunk_bounds(chunk, chunk_size, &lo, &hi);
		push_chunk_to_b_big(a, b, lo, hi);
		chunk++;
	}
	pull_b_to_a(a, b);
}
