/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:52:48 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/02 17:22:33 by pedroribeir      ###   ########.fr       */
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
int		parse_input(char **args, t_stack *a, int count);
int		safe_atoi(const char *str, int *out);
int		is_sorted(t_stack *stack);
void	assign_index(t_stack *stack);
char	**ft_split(char const *s, char c);
int		ft_count_split(char **split);
void	ft_free_split(char **arr);

typedef struct s_input
{
	char	**args;
	int		count;
	int		is_split;
}	t_input;

t_input normalize_argv(int argc, char **argv);

#endif