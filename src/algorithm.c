/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:00:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/30 11:47:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static int	lowest_number(int arr[], int n)
{
	int	smallest;
	int	i;

	smallest = arr[0];
	i = -1;
	while (++i < n)
		if (arr[i] < smallest)
			smallest = arr[i];
	return (smallest);
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

static int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->last_index)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_three(t_stack *a, t_stack *b, t_tool *tool)
{
	int	*arr;

	arr = a->stack;
	tool->e = A;
	if (is_sorted(a))
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

void	algorithm(t_stack *a, t_stack *b, t_tool *tool)
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
		}
		while (b->last_index >= 0)
			do_two_stacks_operation(a, b, pa, tool);
	}
}
