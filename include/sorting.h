/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:57:16 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/07 15:09:47 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "stacks.h"

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

void	quick_sort(int *arr, int low, int high);
int		partition(int *arr, int low, int high);

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_max_index(t_stack *stack);

void	push_chunk_to_b_big(t_stack *a, t_stack *b, int lo, int hi);
void	pull_b_to_a(t_stack *a, t_stack *b);

#endif
