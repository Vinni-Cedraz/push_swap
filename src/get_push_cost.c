/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_push_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:28:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/06 21:05:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"
#include "structs.h"

int	cost_to_make_it_top(t_stack *stack, int index, t_tool *tool)
{
	int	cost;
	int normalized_last_index;

	normalized_last_index = stack->last_index + (stack->last_index & 1);
	if (index == stack->last_index)
	{
		tool->which_operation = NONE;
		cost = 0;
	}
	else if (index >= normalized_last_index / 2)
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

void	get_push_cost(
	t_stack *a,
	t_stack *b,
	int pos_a,
	int pos_b,
	t_tool *tool)
{
	tool->cost_to_top_a = cost_to_make_it_top(a, pos_a, tool);
	tool->which_operation_a = tool->which_operation;
	tool->cost_to_top_b = cost_to_make_it_top(b, pos_b, tool);
	tool->which_operation_b = tool->which_operation;
}
