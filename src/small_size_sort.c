/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:00:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/31 07:51:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static int	lowest_number(int arr[], int n);
static void	bubbling_up(t_stack *a, t_stack *b, t_tool *tool);
static void	sort_three(t_stack *a, t_stack *b, t_tool *tool);
int			is_sorted(t_stack *a);

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

static int	lowest_number(int arr[], int last_index)
{
	int	lowest;
	int	i;

	lowest = arr[0];
	i = -1;
	while (++i <= last_index)
		if (arr[i] < lowest)
			lowest = arr[i];
	return (lowest);
}

static void	bubbling_up(t_stack *a, t_stack *b, t_tool *tool)
{
	int	lowest;
	int	half;
	int	index;

	half = a->last_index / 2;
	index = 0;
	tool->e = A;
	lowest = lowest_number(a->stack, a->last_index);
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

int	is_sorted(t_stack *a)
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
