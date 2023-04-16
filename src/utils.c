/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/16 15:08:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

int	get_index(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack->stack[i] != index)
		i++;
	return (i);
}

int	get_smallest(t_stack *stack)
{
	int	smallest;
	int	*arr;
	int	last_index;
	int	i;

	arr = stack->stack;
	last_index = stack->last_index;
	smallest = arr[0];
	i = -1;
	while (++i <= last_index)
		if (arr[i] < smallest)
			smallest = arr[i];
	return (smallest);
}

int	get_biggest(t_stack *stack)
{
	int	biggest;
	int	i;
	int	*arr;
	int	last_index;

	arr = stack->stack;
	last_index = stack->last_index;
	biggest = arr[0];
	i = -1;
	while (++i <= last_index)
		if (arr[i] > biggest)
			biggest = arr[i];
	return (biggest);
}

int	is_sorted(t_stack *a)
{
	int	i;
	int	*arr;

	i = 0;
	arr = a->stack;
	while (i < a->last_index)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_smallest_from_n(t_stack *stack, int n)
{
	int	smallest;
	int	*arr;
	int	last_index;
	int	i;

	arr = stack->stack;
	last_index = stack->last_index;
	smallest = __INT_MAX__;
	i = -1;
	while (++i <= last_index)
		if (arr[i] > n && arr[i] < smallest)
			smallest = arr[i];
	if (smallest == __INT_MAX__)
		return (n);
	return (smallest);
}
