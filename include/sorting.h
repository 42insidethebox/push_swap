/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:57:16 by procha-r          #+#    #+#             */
/*   Updated: 2025/01/29 21:59:55 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "stacks.h"

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

void	sort_medium(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

int		find_min(t_stack *stack);
int		find_second_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_median(t_stack *a, int chunk, int chunk_size);
int		stack_contains_chunk(t_stack *a, int chunk, int chunk_size);
void	quicksort(int *arr, int low, int high);
int		partition(int *arr, int low, int high);

#endif