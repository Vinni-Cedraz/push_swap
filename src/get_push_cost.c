/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_push_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:28:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/31 16:10:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static int	cost_to_make_it_top(t_stack *stack, int index);
static int	cost_to_make_it_bottom(t_stack *stack, int index);

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
	int old_lowest;

	old_lowest  = lowest_number(b);
	cost = cost_to_make_it_top(a, pos_a);
	cost += cost_to_make_it_bottom(b, get_index(b, old_lowest));
	cost++;
	return (cost);
}

static int	cost_to_make_it_top(t_stack *stack, int index)
{
	int	cost;

	if (index > stack->last_index / 2)
		cost = ft_abs(stack->last_index - index);
	else
		cost = index + 1;
	return (cost);
}

static int	cost_to_make_it_bottom(t_stack *stack, int index)
{
	int	cost;

	if (index > stack->last_index / 2)
		cost = ft_abs(stack->last_index - index + 1);
	else
		cost = index;
	return (cost);
}
