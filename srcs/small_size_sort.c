/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:00:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/18 15:47:58 by vcedraz-         ###   ########.fr       */
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
				exec_pushswap_instruction(a, b, pb, 0);
			if (a->last_index == 2)
				sort_three(a, b, tool);
		}
		while (b->last_index >= 0)
			exec_pushswap_instruction(a, b, pa, 0);
	}
}

static void	bubbling_up(t_stack *a, t_stack *b, t_tool *tool)
{
	int	lowest;
	int	half;
	int	index;

	lowest = get_smallest(a);
	half = a->last_index / 2;
	index = 0;
	tool->which_stack = A;
	while (a->stack[a->last_index] != lowest)
	{
		if (a->stack[index] == lowest)
		{
			if (index < half)
				while (a->stack[a->last_index] != lowest)
					exec_pushswap_instruction(a, b, rra, 0);
			else
				while (a->stack[a->last_index] != lowest)
					exec_pushswap_instruction(a, b, ra, 0);
		}
		index++;
	}
}
