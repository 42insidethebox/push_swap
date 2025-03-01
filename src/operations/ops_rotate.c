/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:16:07 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:20:08 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack *a)
{
	int	val;

	if (is_empty(a) || a->size < 2)
		return ;
	val = pop_stack(a);
	push_stack(a, val);
}

void	rb(t_stack *b)
{
	int	val;

	if (is_empty(b) || b->size < 2)
		return ;
	val = pop_stack(b);
	push_stack(b, val);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
