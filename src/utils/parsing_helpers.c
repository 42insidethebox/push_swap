/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:03:08 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/04/27 20:16:26 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	safe_atoi(const char *str, int *out)
{
	long	result;
	int		sign;
	int		i;

	if (!str || !out)
		return (0);
	result = 0;
	i = 0;
	sign = handle_sign(str, &i);
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && result > 2147483648))
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}
