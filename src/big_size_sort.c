/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:01:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/31 18:04:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static int	get_neighbor(t_stack *b, int value);
static void	push_to_b(t_s *a, t_s *b, int to_push, t_tool *tool, int pos);

void	big_size_sort(t_stack *a, t_stack *b, t_tool *tool)
{
	int	i;
	int	*arr;
	int	placement_cost;
	int	last_cost;
	int tmp;

	i = -1;
	placement_cost = 0;
	last_cost = __INT_MAX__;
	arr = a->stack;
	do_two_stacks_operation(a, b, pb, tool);
	do_two_stacks_operation(a, b, pb, tool);
	while (++i < a->last_index)
	{
		if (arr[i] < lowest_number(b))
		{
			placement_cost = get_push_cost_case2(a, b, i);
			tmp = biggest_number(b);
		}
		else if (arr[i] > biggest_number(b))
		{
			placement_cost = get_push_cost_case1(a, b, i, get_index(b, lowest_number(b)));
			tmp = lowest_number(b);
		}
		else
		{
			placement_cost = get_push_cost_case1(a, b, i, get_neighbor(b, arr[i]));
			tmp = get_neighbor(b, arr[i]);
		}
		if (placement_cost < last_cost)
		{
			tool->cheapest_to_top_a = arr[i];
			tool->cheapest_to_top_b = tmp;
		}
		last_cost = placement_cost;
	}
	push_to_b(a, b, tool->cheapest_to_top_a, tool, tool->cheapest_to_top_b);
}

void	push_to_b(t_stack *a, t_stack *b, int to_push, t_tool *tool, int pos_b)
{
	int	i;
	int	pos_a;

	i = 0;
	// is this line being executed?
	ft_putendl_fd("yes", 1);
	pos_a = get_neighbor(a, to_push);
	while (a->stack[a->last_index] != to_push)
		if (pos_a > a->last_index / 2)
			do_one_stack_operation(a, b, ra, tool);
		else
			do_one_stack_operation(a, b, rra, tool);
	if (pos_b > b->last_index / 2)
		while (i++ < b->last_index - pos_b)
			do_one_stack_operation(a, b, rb, tool);
	else
		while (i++ < pos_b)
			do_one_stack_operation(a, b, rrb, tool);
	do_two_stacks_operation(a, b, pb, tool);
}

// among all numbers on stack b that are smaller than "value",
// get the position of the one that is closest to value (smallest positive diff):
static int	get_neighbor(t_stack *b, int value)
{
	int	i;
	int	pos;
	int	diff;
	int	smallest_diff;
	int *arr;

	i = -1;
	pos = -1;
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
				pos = i;
			}
		}
	}
	return (pos);
}
