/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:52:48 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/27 21:38:42 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "stacks.h"
# include "operations.h"
# include "sorting.h"

void	print_error(void);
void	handle_exit(t_stack *stack_a, t_stack *stack_b);

int		is_valid_int(const char *arg);
int		check_duplicates(t_stack *a);
int		parse_input(int argc, char **argv, t_stack *a);
int		safe_atoi(const char *str, int *out);
int		is_sorted(t_stack *stack);
void	assign_index(t_stack *stack);
#endif