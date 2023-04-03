/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/01 23:10:09 by vcedraz-         ###   ########.fr       */
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

int	lowest_number(t_stack *stack)
{
	int	smallest;
	int *arr = stack->stack;
	int last_index = stack->last_index;
	int	i;

	smallest = arr[0];
	i = -1;
	while (++i <= last_index)
		if (arr[i] < smallest)
			smallest = arr[i];
	return (smallest);
}

int biggest_number(t_stack *stack)
{
	int biggest;
	int i;
	int *arr = stack->stack;
	int last_index = stack->last_index;

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

	i = 0;
	while (i <= a->last_index)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
