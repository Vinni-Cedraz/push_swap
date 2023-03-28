/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:39:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/28 15:46:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static void	reverse_rotate(t_stack *stack);

void	rra(t_stack *a, int is_rrr)
{
	if (!is_rrr)
		ft_putstr("rra\n");
	reverse_rotate(a);
}

void	rrb(t_stack *b, int is_rrr)
{
	if (!is_rrr)
		ft_putstr("rrb\n");
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b, int is_rrr)
{
	ft_putstr("rrr\n");
	rra(a, is_rrr);
	rrb(b, is_rrr);
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
