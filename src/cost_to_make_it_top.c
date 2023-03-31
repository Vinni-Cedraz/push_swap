/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_make_it_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:28:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/30 21:57:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static int	cost_to_make_it_top(t_stack *stack, int index);

int	get_push_cost(t_stack *a, t_stack *b, int a_pos, int b_pos)
{
	int	cost;

	cost = cost_to_make_it_top(b, b_pos);
	cost += cost_to_make_it_top(a, a_pos);
	cost++;
	return (cost);
}

static int	cost_to_make_it_top(t_stack *stack, int index)
{
	int	cost;

	if (index > stack->last_index / 2)
		cost = stack->last_index - index;
	else
		cost = index + 1;
	return (cost);
}
