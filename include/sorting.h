/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:57:16 by procha-r          #+#    #+#             */
/*   Updated: 2025/04/28 10:57:19 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "stacks.h"

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

void	sort_medium(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);

int		find_min(t_stack *stack);
int		find_second_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_median(t_stack *a, int chunk, int chunk_size);
int		stack_contains_chunk(t_stack *a, int chunk, int chunk_size);
void	quick_sort(int *arr, int low, int high);
int		partition(int *arr, int low, int high);

#endif