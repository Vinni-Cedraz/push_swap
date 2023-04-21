/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:49:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/18 15:55:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	sort_three(t_stack *a, t_stack *b, t_tool *tool)
{
	int	*arr;

	arr = a->stack;
	tool->which_stack = A;
	if (is_sorted(a) || a->last_index < 2)
		return ;
	if (arr[2] < arr[1] && arr[1] > arr[0] && arr[2] < arr[0])
	{
		exec_pushswap_instruction(a, b, rra, 0);
		exec_pushswap_instruction(a, b, sa, 0);
	}
	else if (arr[2] > arr[1] && arr[1] < arr[0] && arr[2] < arr[0])
		exec_pushswap_instruction(a, b, sa, 0);
	else if (arr[2] < arr[1] && arr[1] > arr[0] && arr[2] > arr[0])
		exec_pushswap_instruction(a, b, rra, 0);
	else if (arr[2] > arr[1] && arr[1] < arr[0] && arr[2] > arr[0])
		exec_pushswap_instruction(a, b, ra, 0);
	else if (arr[2] > arr[1] && arr[1] > arr[0] && arr[2] > arr[0])
	{
		exec_pushswap_instruction(a, b, sa, 0);
		exec_pushswap_instruction(a, b, rra, 0);
	}
}
