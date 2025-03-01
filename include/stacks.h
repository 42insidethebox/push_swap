/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:44:33 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:17:55 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;

}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);

void	push_stack(t_stack *stack, int val);
int		pop_stack(t_stack *stack);

int		stack_size(t_stack *stack);
int		is_empty(t_stack *stack);
int		peek(t_stack *stack);

#endif