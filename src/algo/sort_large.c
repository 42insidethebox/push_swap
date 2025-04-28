/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:58:42 by pedroribeir       #+#    #+#             */
/*   Updated: 2025/04/28 10:58:43 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <you@domain>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/04/28 12:00:00 by assistant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "operations.h"

/**
 * Returns 1 if any node in A has index between lo..hi
 */
static int contains_in_chunk(t_stack *a, int lo, int hi)
{
    t_node *cur;

    if (!a || is_empty(a))
        return (0);
    cur = a->top;
    while (cur)
    {
        if (cur->index >= lo && cur->index <= hi)
            return (1);
        cur = cur->next;
    }
    return (0);
}

/**
 * Finds the first position of a node in A whose index is in lo..hi.
 * Returns -1 if none.
 */
static int find_nearest_pos(t_stack *a, int lo, int hi)
{
    t_node *cur = a->top;
    int     pos = 0;

    while (cur)
    {
        if (cur->index >= lo && cur->index <= hi)
            return (pos);
        cur = cur->next;
        pos++;
    }
    return (-1);
}

/**
 * Rotates A (ra/rra) to bring position pos to top
 */
static void rotate_a_to_pos(t_stack *a, int pos)
{
    int half;

    if (pos < 0)
        return ;
    half = a->size / 2;
    if (pos <= half)
    {
        while (pos-- > 0)
            ra(a);
    }
    else
    {
        pos = a->size - pos;
        while (pos-- > 0)
            rra(a);
    }
}

/**
 * Finds the position of the max-index in B
 */
static int find_max_pos(t_stack *b)
{
    t_node *cur;
    int     pos, max, max_pos;

    if (!b || is_empty(b))
        return (-1);
    cur = b->top;
    pos = 0;
    max = cur->index;
    max_pos = 0;
    while (cur)
    {
        if (cur->index > max)
        {
            max = cur->index;
            max_pos = pos;
        }
        cur = cur->next;
        pos++;
    }
    return (max_pos);
}

/**
 * Rotates B (rb/rrb) to bring the max-index to top
 */
static void rotate_b_to_max(t_stack *b)
{
    int pos = find_max_pos(b);
    int half;

    if (pos < 0)
        return ;
    half = b->size / 2;
    if (pos <= half)
    {
        while (pos-- > 0)
            rb(b);
    }
    else
    {
        pos = b->size - pos;
        while (pos-- > 0)
            rrb(b);
    }
}

/**
 * Main chunk-based sort for large stacks (N > 100)
 */
void sort_large(t_stack *a, t_stack *b)
{
    int total = a->size;
    int k = 11;                         // number of chunks
    int chunk_size = total / k + (total % k != 0);
    int chunk = 0;

    if (!a || !b || total <= 5)
        return ;

    // 1️⃣ Push each chunk from A to B
    while (chunk < k)
    {
        int lo = chunk * chunk_size;
        int hi = lo + chunk_size - 1;
        while (contains_in_chunk(a, lo, hi))
        {
            int pos = find_nearest_pos(a, lo, hi);
            rotate_a_to_pos(a, pos);
            pb(a, b);
            // Balance B: rotate smaller half to bottom
            if (b->top->index < lo + (chunk_size / 2))
                rb(b);
        }
        chunk++;
    }

    // 2️⃣ Pull back all from B to A in descending order
    while (!is_empty(b))
    {
        rotate_b_to_max(b);
        pa(a, b);
    }
}
