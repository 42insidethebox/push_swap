/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:18:08 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/07 15:19:21 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	stack_size(t_stack *stack)
{
	return (stack->size);
}

int	is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (stack->size == 0);
}
