/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_push_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:28:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/31 19:31:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static int	cost_to_make_it_top(t_stack *stack, int index);

// when pos_a would be the lowest in stack b
int	get_push_cost_case1(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int	cost;

	cost = cost_to_make_it_top(b, pos_b);
	cost += cost_to_make_it_top(a, pos_a);
	cost++;
	return (cost);
}

// when pos_a would be the lowest in stack b
int	get_push_cost_case2(t_stack *a, t_stack *b, int pos_a)
{
	int	cost;

	cost = cost_to_make_it_top(a, pos_a);
	cost += cost_to_make_it_top(b, get_index(b, biggest_number(b)));
	cost++;
	return (cost);
}

static int	cost_to_make_it_top(t_stack *stack, int index)
{
	int	cost;

	if (index == stack->last_index)
		cost = 0;
	else if (index > (stack->last_index / 2) + 1)
		cost = ft_abs(stack->last_index - index);
	else
		cost = index + 1;
	return (cost);
}
