/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:55:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/18 15:22:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static void	rotate(t_stack *stack);

void	ra(t_stack *a, t_stack *b)
{
	(void)b;
	rotate(a);
}

void	rb(t_stack *a, t_stack *b)
{
	(void)a;
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}

static void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->last_index < 1)
		return ;
	temp = stack->stack[stack->last_index];
	i = stack->last_index;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = temp;
}
