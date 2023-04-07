/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:01:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/07 17:20:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static int	get_neighbor(t_stack *b, int value);
static void	push_to_b(t_s *a, t_s *b, t_tool *tool);
static void	move_cheapest_to_top_of_a(t_stack *a, t_stack *b, t_tool *tool);
static void	move_cheapest_to_top_of_b(t_stack *a, t_stack *b, t_tool *tool);

void	big_size_sort(t_stack *a, t_stack *b, t_tool *tool)
{
	int	i;
	int	*arr;
	int	last_cost;
	int	tmp;

	i = -1;
	last_cost = __INT_MAX__;
	arr = a->stack;
	while (++i <= a->last_index)
	{
		if (is_lowest_three(tool->lowest_three, arr[i]))
			continue ;
		if (arr[i] < get_smallest(b) || arr[i] > get_biggest(b))
		{
			get_push_cost(a, b, i, get_index(b, get_biggest(b)), tool);
			tmp = get_biggest(b);
		}
		else
		{
			get_push_cost(a, b, i, get_index(b, get_neighbor(b, arr[i])), tool);
			tmp = get_neighbor(b, arr[i]);
		}
		get_current_total_cost(tool);
		if (current_is_cheaper(tool->current_total_cost, last_cost))
			set_do_rr_do_rrr(tool, &last_cost, arr[i], tmp);
	}
	if (a->last_index > 2)
		push_to_b(a, b, tool);
}

static void	push_to_b(t_stack *a, t_stack *b, t_tool *tool)
{
	if (tool->do_rr < 0)
		tool->do_rr = 0;
	if (tool->do_rrr < 0)
		tool->do_rrr = 0;
	if (tool->do_rr)
		while (tool->do_rr--)
			do_two_stacks_operation(a, b, rr, 1);
	else if (tool->do_rrr)
		while (tool->do_rrr--)
			do_two_stacks_operation(a, b, rrr, 1);
	move_cheapest_to_top_of_a(a, b, tool);
	move_cheapest_to_top_of_b(a, b, tool);
	do_two_stacks_operation(a, b, pb, 0);
}

static void	move_cheapest_to_top_of_a(t_stack *a, t_stack *b, t_tool *tool)
{
	int	*arr;
	int	last_index;
	int normalized_last_index;

	normalized_last_index = a->last_index + (a->last_index & 1);
	arr = a->stack;
	last_index = a->last_index;
	tool->which = A;
	if (tool->cheapest_to_top_a == a->stack[a->last_index])
		return ;
	if (get_index(a, tool->cheapest_to_top_a) >= normalized_last_index / 2)
	{
		while (arr[last_index] != tool->cheapest_to_top_a)
			do_one_stack_operation(a, b, ra, tool);
		return ;
	}
	else
		while (arr[last_index] != tool->cheapest_to_top_a)
			do_one_stack_operation(a, b, rra, tool);
}

static void	move_cheapest_to_top_of_b(t_stack *a, t_stack *b, t_tool *tool)
{
	int	*arr;
	int	last_index;
	int normalized_last_index;

	normalized_last_index = b->last_index + (b->last_index & 1);
	arr = b->stack;
	last_index = b->last_index;
	tool->which = B;
	if (tool->cheapest_to_top_b == b->stack[b->last_index])
		return ;
	if (get_index(b, tool->cheapest_to_top_b) >= normalized_last_index / 2)
	{
		while (arr[last_index] != tool->cheapest_to_top_b)
			do_one_stack_operation(a, b, rb, tool);
		return ;
	}
	else
		while (arr[last_index] != tool->cheapest_to_top_b)
			do_one_stack_operation(a, b, rrb, tool);
}

// among all numbers on stack b that are smaller than "value",
// get the one that is closest to value (smallest positive diff):
static int	get_neighbor(t_stack *b, int value)
{
	int	i;
	int	diff;
	int	smallest_diff;
	int	*arr;
	int	neighbor;

	i = -1;
	diff = 0;
	arr = b->stack;
	smallest_diff = __INT_MAX__;
	while (++i <= b->last_index)
	{
		if (arr[i] < value)
		{
			diff = value - arr[i];
			if (diff < smallest_diff)
			{
				smallest_diff = diff;
				neighbor = arr[i];
			}
		}
	}
	return (neighbor);
}
