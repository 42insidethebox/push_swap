/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:52:48 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/29 21:57:04 by procha-r         ###   ########.fr       */
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

#endif