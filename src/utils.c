/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:19:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/30 20:22:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

int	lowest_number(int *arr, int n)
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

int biggest_number(int *arr, int n)
{
	int biggest;
	int i;

	biggest = arr[0];
	i = -1;
	while (++i < n)
		if (arr[i] > biggest)
			biggest = arr[i];
	return (biggest);
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
