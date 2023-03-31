/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:00:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/30 21:48:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static void	bubbling_up(t_stack *a, t_stack *b, t_tool *tool);
void		sort_three(t_stack *a, t_stack *b, t_tool *tool);

void	small_size_sort(t_stack *a, t_stack *b, t_tool *tool)
{
	if (a->last_index == 2)
		sort_three(a, b, tool);
	else
	{
		while (!is_sorted(a))
		{
			bubbling_up(a, b, tool);
			if (!is_sorted(a))
				do_two_stacks_operation(a, b, pb, tool);
			if (a->last_index == 2)
				sort_three(a, b, tool);
		}
		while (b->last_index >= 0)
			do_two_stacks_operation(a, b, pa, tool);
	}
}

static void	bubbling_up(t_stack *a, t_stack *b, t_tool *tool)
{
	int	lowest;
	int	half;
	int	index;

	lowest = lowest_number(a->stack, a->last_index);
	half = a->last_index / 2;
	index = 0;
	tool->e = A;
	while (a->stack[a->last_index] != lowest)
	{
		if (a->stack[index] == lowest)
		{
			if (index < half)
				while (a->stack[a->last_index] != lowest)
					do_one_stack_operation(a, b, rra, tool);
			else
				while (a->stack[a->last_index] != lowest)
					do_one_stack_operation(a, b, ra, tool);
		}
		index++;
	}
}
