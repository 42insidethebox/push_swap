/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:56:28 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/27 17:46:26 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_stack *a, t_stack *b)
{
	int	val;

	if (is_empty(b))
		return ;
	val = pop_stack(b);
	push_stack(a, val);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	val;

	if (is_empty(a))
		return ;
	val = pop_stack(a);
	push_stack(b, val);
	write(1, "pb\n", 3);
}
