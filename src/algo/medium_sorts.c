/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:55:52 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/27 16:48:30 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

int	*extract_values(t_stack *a, int chunk, int chunk_size, int *count)
{
	int		*values;
	int		i;
	t_node	*current;

	values = malloc(sizeof(int) * chunk_size);
	if (!values)
		return (NULL);
	current = a->top;
	i = 0;
	while (current != NULL && i < chunk_size)
	{
		if (current->value >= chunk * chunk_size
			&& current->value < (chunk + 1) * chunk_size)
		{
			values[i] = current->value;
			i++;
		}
		current = current->next;
	}
	*count = i;
	return (values);
}

int	find_median(t_stack *a, int chunk, int chunk_size)
{
	int		*values;
	int		count;
	int		median;

	values = extract_values(a, chunk, chunk_size, &count);
	if (!values || count == 0)
	{
		free(values);
		return (0);
	}
	quick_sort(values, 0, count - 1);
	median = values[count / 2];
	free(values);
	return (median);
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk, int chunk_size)
{
	int	median;

	median = find_median(a, chunk, chunk_size);
	while (stack_contains_chunk(a, chunk, chunk_size))
	{
		if (a->top->value <= median)
			pb(a, b);
		else
			ra(a);
	}
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	while (!is_empty(b))
	{
		if (b->top->value == find_max(b))
			pa(a, b);
		else
			rb(b);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	total_chunks;
	int	current_chunk;

	if (a == NULL || b == NULL || a->size <= 5)
		return ;
	chunk_size = a->size / 5;
	if (a->size % chunk_size == 0)
		total_chunks = 5;
	else
		total_chunks = 6;
	current_chunk = 0;
	while (current_chunk < total_chunks)
	{
		push_chunk_to_b(a, b, current_chunk, chunk_size);
		current_chunk++;
	}
	move_back_to_a(a, b);
}
