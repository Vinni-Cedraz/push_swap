/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:01:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/02 14:24:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"
#include <stdio.h>

static int	get_neigh(t_stack *b, int value);
static void	push_to_b(t_s *a, t_s *b, t_tool *tool);
static void	move_cheapest_to_top_of_a(t_stack *a, t_stack *b, t_tool *tool);
static void	move_cheapest_to_top_of_b(t_stack *a, t_stack *b, t_tool *tool);

void	big_size_sort(t_stack *a, t_stack *b, t_tool *tool)
{
	int	i;
	int	*arr;
	int	placement_cost;
	int	last_cost;
	int	tmp;

	i = -1;
	placement_cost = 0;
	last_cost = __INT_MAX__;
	arr = a->stack;
	while (++i <= a->last_index)
	{
		if (arr[i] < lowest_number(b) || arr[i] > biggest_number(b))
		{
			placement_cost = get_push_cost_case2(a, b, i);
			tmp = biggest_number(b);
		}
		else
		{
			placement_cost = get_push_cost_case1(a, b, i, get_neigh(b, arr[i]));
			tmp = get_neigh(b, arr[i]);
		}
		if (placement_cost < last_cost)
		{
			tool->cheapest_to_top_a = arr[i];
			tool->cheapest_to_top_b = tmp;
		}
		last_cost = placement_cost;
	}
	if (a->last_index > 2)
		push_to_b(a, b, tool);
}

static void	push_to_b(t_stack *a, t_stack *b, t_tool *tool)
{
	move_cheapest_to_top_of_a(a, b, tool);
	move_cheapest_to_top_of_b(a, b, tool);
	printf("stack a size is: %d\n", a->last_index);
	do_two_stacks_operation(a, b, pb, tool);
}

static void	move_cheapest_to_top_of_a(t_stack *a, t_stack *b, t_tool *tool)
{
	int	*arr;
	int	last_index;
	int	cheapest_to_top;

	arr = a->stack;
	last_index = a->last_index;
	cheapest_to_top = tool->cheapest_to_top_a;
	tool->e = A;
	if (get_index(a, cheapest_to_top) > (a->last_index / 2) + 1)
	{
		while (arr[last_index] != cheapest_to_top)
			do_one_stack_operation(a, b, ra, tool);
		return ;
	}
	else
		while (arr[last_index] != cheapest_to_top)
			do_one_stack_operation(a, b, rra, tool);
}

static void	move_cheapest_to_top_of_b(t_stack *a, t_stack *b, t_tool *tool)
{
	int	*arr;
	int	last_index;
	int	cheapest_to_top;

	arr = b->stack;
	last_index = b->last_index;
	cheapest_to_top = tool->cheapest_to_top_b;
	tool->e = B;
	if (get_index(b, cheapest_to_top) > (b->last_index / 2) + 1)
	{
		while (arr[last_index] != cheapest_to_top)
			do_one_stack_operation(a, b, rb, tool);
		return ;
	}
	else
		while (arr[last_index] != cheapest_to_top)
			do_one_stack_operation(a, b, rrb, tool);
}

// among all numbers on stack b that are smaller than "value",
// get the one that is closest to value (smallest positive diff):
static int	get_neigh(t_stack *b, int value)
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
