/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:30:04 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/31 08:18:50 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		parse_result;

	init_stack(&a);
	init_stack(&b);
	parse_result = parse_input(argc, argv, &a);
	if (parse_result == -1)
	{
		print_error();
		handle_exit(&a, &b);
	}
	if (a.size <= 3)
		sort_three(&a);
	else if (a.size <= 5)
		sort_five(&a, &b);
	else if (a.size <= 100)
		sort_medium(&a, &b);
	else
		sort_big(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
