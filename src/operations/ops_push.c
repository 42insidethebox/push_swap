/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:56:28 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:05:51 by procha-r         ###   ########.fr       */
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
}

void	pb(t_stack *a, t_stack *b)
{
	int	val;

	if (is_empty(a))
		return ;
	val = pop_stack(a);
	push_stack(b, val);
}
