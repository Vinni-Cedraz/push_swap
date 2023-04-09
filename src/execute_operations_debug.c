/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations_debug.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:02:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/09 21:03:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	do_one_stack_operation(t_stack *a, t_stack *b, t_funct1 f, t_tool *tool)
{
	int	is_two_stacks_op;

	is_two_stacks_op = 0;
	if (tool->which_stack == A)
		(f)(a, is_two_stacks_op);
	if (tool->which_stack == B)
		(f)(b, is_two_stacks_op);
	a->counter++;
	check_stacks(a, b);
}

void	do_two_stacks_operation(t_stack *a, t_stack *b, t_funct2 f, int is_rot)
{
	(f)(a, b, is_rot);
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
			do_one_stack_operation(a, b, ra, tool);
		else if (!is_lowest_three(lowest_three, top_of_a) && top_of_a != a_big)
			do_two_stacks_operation(a, b, pb, 0);
		top_of_a = a->stack[a->last_index];
		a_big = get_biggest(a);
	}
}
