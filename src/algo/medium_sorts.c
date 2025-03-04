/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:55:52 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/02 21:11:11 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

int	find_median(t_stack *a, int chunk, int chunk_size)
{
	int		*values;
	int		i;
	int		median;
	t_node	*current;

	values = malloc(sizeof(int) * chunk_size);
	if (!values)
		return (0);
	current = a->top;
	i = 0;
	while (current && i < chunk_size)
	{
		if (current->value >= chunk * chunk_size \
			&& current->value < (chunk + 1) * chunk_size)
		{
			values[i++] = current->value;
		}
		current = current->next;
	}
	if (i == 0)
	{
		free(values);
		return (0);
	}
	quicksort(values, 0, i - 1);
	median = values[i / 2];
	free(values);
	return (median);
}

int	stack_contains_chunk(t_stack *a, int chunk, int chunk_size)
{
	t_node	*current;

	if (!a || !a->top)
		return (0);
	current = a->top;
	while (current)
	{
		if (current->value >= chunk * chunk_size && \
			current->value < (chunk + 1) * chunk_size)
			return (1);
		current = current->next;
	}
	return (0);
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	total_chunks;
	int	current_chunk;
	int	median;

	if (!a || !b || a->size <= 5)
		return ;
	chunk_size = a->size / 5;
	if (a->size % chunk_size == 0)
		total_chunks = 5;
	else
		total_chunks = 6;
	current_chunk = 0;
	while (current_chunk < total_chunks)
	{
		median = find_median(a, current_chunk, chunk_size);
		while (stack_contains_chunk(a, current_chunk, chunk_size))
		{
			if (a->top->value <= median)
				pb(a, b);
			else
				ra(a);
		}
		current_chunk++;
	}
	while (!is_empty(b))
	{
		if (b->top->value == find_max(b))
			pa(a, b);
		else
			rb(b);
	}
}
