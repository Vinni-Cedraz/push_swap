/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations_debug.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:02:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/18 15:53:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	exec_pushswap_instruction(t_stack *a, t_stack *b, t_instruction f,
		int is_simultaneous)
{
	(f)(a, b, is_simultaneous);
	a->counter++;
	check_stacks(a, b);
}

void	do_first_pushes(t_stack *a, t_stack *b, t_tool *tool)
{
	int	top_of_a;
	int	*lowest_three;
	int	a_big;

	a_big = get_biggest(a);
	top_of_a = a->stack[a->last_index];
	lowest_three = tool->lowest_three;
	while (b->last_index != 1)
	{
		if (is_lowest_three(lowest_three, top_of_a) || top_of_a == a_big)
			exec_pushswap_instruction(a, b, ra, 0);
		else if (!is_lowest_three(lowest_three, top_of_a) && top_of_a != a_big)
			exec_pushswap_instruction(a, b, pb, 0);
		top_of_a = a->stack[a->last_index];
		a_big = get_biggest(a);
	}
}
