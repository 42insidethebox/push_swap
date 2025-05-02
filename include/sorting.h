/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:57:16 by procha-r          #+#    #+#             */
/*   Updated: 2025/05/02 18:27:30 by pedroribeir      ###   ########.fr       */
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
int		find_max_index(t_stack *stack);
int		find_median(t_stack *a, int chunk, int chunk_size);
int		stack_contains_chunk(t_stack *a, int chunk, int chunk_size);
void	quick_sort(int *arr, int low, int high);
int		partition(int *arr, int low, int high);
void	push_chunk_to_b_medium(t_stack *a, t_stack *b, int chunk, \
int chunk_size);

int		contains_in_chunk(t_stack *a, int lo, int hi);
int		find_nearest_pos(t_stack *a, int lo, int hi);
void	rotate_a_to_pos(t_stack *a, int pos);
int		find_max_pos(t_stack *b);
void	rotate_b_to_max(t_stack *b);

void	push_chunk_to_b_big(t_stack *a, t_stack *b, int lo, int hi);

void	pull_b_to_a(t_stack *a, t_stack *b);

void	radix_sort(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);

#endif