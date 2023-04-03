/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:49:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/02 19:15:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	sort_three(t_stack *a, t_stack *b, t_tool *tool)
{
	int	*arr;

	arr = a->stack;
	tool->which = A;
	if (is_sorted(a) || a->last_index < 2)
		return ;
	if (arr[2] < arr[1] && arr[1] > arr[0] && arr[2] < arr[0])
	{
		do_one_stack_operation(a, b, rra, tool);
		do_one_stack_operation(a, b, sa, tool);
	}
	else if (arr[2] > arr[1] && arr[1] < arr[0] && arr[2] < arr[0])
		do_one_stack_operation(a, b, sa, tool);
	else if (arr[2] < arr[1] && arr[1] > arr[0] && arr[2] > arr[0])
		do_one_stack_operation(a, b, rra, tool);
	else if (arr[2] > arr[1] && arr[1] < arr[0] && arr[2] > arr[0])
		do_one_stack_operation(a, b, ra, tool);
	else if (arr[2] > arr[1] && arr[1] > arr[0] && arr[2] > arr[0])
	{
		do_one_stack_operation(a, b, sa, tool);
		do_one_stack_operation(a, b, rra, tool);
	}
}
