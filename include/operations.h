/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:29:26 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/27 17:20:18 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stacks.h"
# include <stdlib.h>
# include <unistd.h>

void	sa(t_stack *a);
void	sb(t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

#endif