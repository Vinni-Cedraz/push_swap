/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_total_cost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:13:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/07 23:07:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static void	update_last_cost(t_tool *tool);
static void	count_do_rr_do_rrr(t_tool *tool);

int	current_is_cheaper(t_tool *tool)
{
	return (tool->current_total_cost < tool->last_cost);
}

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

// set_do_rr_do_rrr is only called if current_is_cheaper is true
void	set_do_rr_do_rrr(t_tool *tool, int curr_a, int curr_b)
{
	tool->cheapest_to_top_a = curr_a;
	tool->cheapest_to_top_b = curr_b;
	if (tool->which_operation_a == tool->which_operation_b)
		count_do_rr_do_rrr(tool);
	else
	{
		tool->do_rr = 0;
		tool->do_rrr = 0;
	}
	update_last_cost(tool);
}

static void	count_do_rr_do_rrr(t_tool *tool)
{
	if (ROTATE == tool->which_operation)
	{
		if (tool->cost_to_top_b > tool->cost_to_top_a)
			tool->do_rr = tool->cost_to_top_a;
		else
			tool->do_rr = tool->cost_to_top_b;
	}
	else if (REVERSE_ROTATE == tool->which_operation)
	{
		if (tool->cost_to_top_b > tool->cost_to_top_a)
			tool->do_rrr = tool->cost_to_top_a;
		else
			tool->do_rrr = tool->cost_to_top_b;
	}
	else if (NONE == tool->which_operation)
	{
		tool->do_rr = 0;
		tool->do_rrr = 0;
	}
}

static void	update_last_cost(t_tool *tool)
{
	tool->last_cost = tool->current_total_cost;
}
