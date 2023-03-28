/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:00:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/28 18:04:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

int	lowest_number(int arr[], int n)
{
	int	smallest;

	smallest = arr[0];
	for (int i = 1; i <= n; i++)
		if (arr[i] < smallest)
			smallest = arr[i];
	return (smallest);
}

void	bubbling_up(t_stack *a, t_stack *b, t_tool *tool)
{
	int	lowest;
	int	half;
	int	index;

	lowest = lowest_number(a->stack, a->last_index);
	half = a->last_index / 2;
	index = 0;
	while (a->stack[a->last_index] != lowest)
	{
		if (a->stack[index] == lowest)
		{
			if (index <= half)
				while (a->stack[a->last_index] != lowest)
				{
					tool->e = A;
					do_one_stack_operation(a, b, ra, tool);
				}
			else
				while (a->stack[a->last_index] != lowest)
				{
					tool->e = B;
					do_one_stack_operation(a, b, rra, tool);
				}
		}
		index++;
	}
	do_two_stacks_operation(a, b, pb, tool);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->last_index)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	shitty_algorithm(t_stack *a, t_stack *b, t_tool *tool)
{
	if (!is_sorted(a))
	{
		bubbling_up(a, b, tool);
		shitty_algorithm(a, b, tool);
	}
	else
		while (b->last_index >= 0)
			do_two_stacks_operation(a, b, pa, tool);
}
