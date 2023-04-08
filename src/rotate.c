/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:55:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/08 15:30:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static void	rotate(t_stack *stack);

void	ra(t_stack *a, int is_being_called_by_rr)
{
	if (!is_being_called_by_rr)
		ft_putstr("ra\n");
	rotate(a);
}

void	rb(t_stack *b, int is_being_called_by_rr)
{
	if (!is_being_called_by_rr)
		ft_putstr("rb\n");
	rotate(b);
}

void	rr(t_stack *a, t_stack *b, int is_rr)
{
	ft_putstr("rr\n");
	ra(a, is_rr);
	rb(b, is_rr);
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
