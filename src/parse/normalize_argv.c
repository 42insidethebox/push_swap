/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:58:43 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/05/02 17:17:53 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_input	normalize_argv(int argc, char **argv)
{
	t_input	in;

	in.args = NULL;
	in.count = 0;
	in.is_split = 0;
	if (argc == 2)
	{
		in.is_split = 1;
		in.args = ft_split(argv[1], ' ');
		in.count = ft_count_split(in.args);
	}
	else
	{
		in.is_split = 0;
		in.args = &argv[1];
		in.count = argc - 1;
	}
	return (in);
}
