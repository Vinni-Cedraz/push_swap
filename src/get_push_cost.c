/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_push_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:28:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/03 08:58:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"
#include "structs.h"

static int	cost_to_make_it_top(t_stack *stack, int index, t_tool *tool);

// when pos_a would be the lowest in stack b
int	get_push_cost_case1(t_stack *a, t_stack *b, int pos_a, int pos_b,
		t_tool *tool)
{
	int	cost;

	cost = cost_to_make_it_top(a, pos_a, tool);
	cost += cost_to_make_it_top(b, pos_b, tool);
	return (cost + 1);
}

// when pos_a would be the lowest in stack b
int	get_push_cost_case2(t_stack *a, t_stack *b, int pos_a, t_tool *tool)
{
	int	cost;

	cost = cost_to_make_it_top(a, pos_a, tool);
	cost += cost_to_make_it_top(b, get_index(b, biggest_number(b)), tool);
	return (cost + 1);
}

static int	cost_to_make_it_top(t_stack *stack, int index, t_tool *tool)
{
	int	cost;

	if (index == stack->last_index)
	{
		tool->which_operation = NONE;
		cost = 0;
	}
	else if (index > (stack->last_index / 2) + 1)
	{
		cost = ft_abs(stack->last_index - index);
		tool->which_operation = ROTATE;
	}
	else
	{
		cost = index + 1;
		tool->which_operation = REVERSE_ROTATE;
	}
	return (cost);
}
