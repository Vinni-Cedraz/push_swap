/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_push_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:28:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/05 23:04:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"
#include "structs.h"

int	cost_to_make_it_top(t_stack *stack, int index, t_tool *tool)
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

int	get_push_cost(
	t_stack *a,
	t_stack *b,
	int pos_a,
	int pos_b,
	t_tool *tool)
{
	int					cost_a;
	int					cost_b;
	t_which_operation	which_operation_on_a;
	t_which_operation	which_operation_on_b;

	cost_a = cost_to_make_it_top(a, pos_a, tool);
	which_operation_on_a = tool->which_operation;
	cost_b = cost_to_make_it_top(b, pos_b, tool);
	which_operation_on_b = tool->which_operation;
	if (which_operation_on_a == which_operation_on_b)
	{
		if (ROTATE == which_operation_on_a)
		{
			if (cost_a > cost_b)
				tool->do_rr = cost_b;
			else
				tool->do_rr = cost_a;
		}
		else
		{
			if (cost_a > cost_b)
				tool->do_rrr = cost_b;
			else
				tool->do_rrr = cost_a;
		}
	}
	else
	{
		tool->do_rr = 0;
		tool->do_rrr = 0;
	}
	return (cost_a + cost_b);
}
