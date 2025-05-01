/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:30:04 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/01 19:12:40 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

static void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size > 3 && a->size <= 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		parse_result;

	if (argc == 1)
		return (0);
	init_stack(&a);
	init_stack(&b);
	parse_result = parse_input(argc, argv, &a);
	if (parse_result == -1)
	{
		print_error();
		handle_exit(&a, &b);
	}
	if (is_sorted(&a))
	{
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	assign_index(&a);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
