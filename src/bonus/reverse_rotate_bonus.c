/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:39:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/08 23:42:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static void	reverse_rotate(t_stack *stack);

void	rra(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

static void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;
	int	*arr;

	arr = stack->stack;
	if (stack->last_index < 1)
		return ;
	temp = arr[0];
	i = -1;
	while (++i < stack->last_index)
		arr[i] = arr[i + 1];
	arr[i] = temp;
}
