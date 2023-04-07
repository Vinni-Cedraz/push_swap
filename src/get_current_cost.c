/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:13:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/06 21:39:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	get_current_total_cost(t_tool *tool)
{
	if (tool->which_operation_a != tool->which_operation_b)
		tool->current_total_cost = tool->cost_to_top_a + tool->cost_to_top_b;
	else
	{
		if (tool->cost_to_top_a > tool->cost_to_top_b)
			tool->current_total_cost = tool->cost_to_top_a;
		else
			tool->current_total_cost = tool->cost_to_top_b;
	}
}

void	if_current_is_cheapest_to_top(t_tool *tool,
									int *last_cost,
									int curr_a,
									int curr_b)
{
	if (tool->current_total_cost < *last_cost)
	{
		tool->cheapest_to_top_a = curr_a;
		tool->cheapest_to_top_b = curr_b;
		if (tool->which_operation_a == tool->which_operation_b)
		{
			if (ROTATE == tool->which_operation_b)
			{
				if (tool->cost_to_top_b > tool->cost_to_top_a)
					tool->do_rr = tool->cost_to_top_b;
				else
					tool->do_rr = tool->cost_to_top_a;
			}
			else if (REVERSE_ROTATE == tool->which_operation_b)
			{
				if (tool->cost_to_top_b > tool->cost_to_top_a)
					tool->do_rrr = tool->cost_to_top_b;
				else
					tool->do_rrr = tool->cost_to_top_a;
			}
		}
		(*last_cost) = tool->current_total_cost;
	}
}
