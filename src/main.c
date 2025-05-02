/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:30:04 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/02 17:24:17 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
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
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_input		in;
	int			parse_result;

	if (argc == 1)
		return (0);
	init_stack(&a);
	init_stack(&b);
	in = normalize_argv(argc, argv);
	if (!in.args || in.count == 0)
		handle_exit(&a, &b);
	parse_result = parse_input(in.args, &a, in.count);
	if (parse_result == -1 || check_duplicates(&a))
	{
		print_error();
		if (in.is_split)
			ft_free_split(in.args);
		handle_exit(&a, &b);
	}
	if (is_sorted(&a))
	{
		if (in.is_split)
			ft_free_split(in.args);
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	assign_index(&a);
	sort_stack(&a, &b);
	if (in.is_split)
		ft_free_split(in.args);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
