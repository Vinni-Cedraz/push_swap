/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:36:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/18 15:33:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	sa(t_stack *a, t_stack *b, int is_being_called_by_ss)
{
	(void)b;
	if (!is_being_called_by_ss)
		ft_putstr("sa\n");
	if (a->last_index < 1)
		return ;
	a->stack[a->last_index] ^= a->stack[a->last_index - 1];
	a->stack[a->last_index - 1] ^= a->stack[a->last_index];
	a->stack[a->last_index] ^= a->stack[a->last_index - 1];
}

void	sb(t_stack *a, t_stack *b, int is_being_called_by_ss)
{
	(void)a;
	if (!is_being_called_by_ss)
		ft_putstr("sb\n");
	if (b->last_index < 1)
		return ;
	b->stack[b->last_index] ^= b->stack[b->last_index - 1];
	b->stack[b->last_index - 1] ^= b->stack[b->last_index];
	b->stack[b->last_index] ^= b->stack[b->last_index - 1];
}

void	ss(t_stack *a, t_stack *b, int is_ss)
{
	ft_putstr("ss\n");
	sa(a, b, is_ss);
	sb(a, b, is_ss);
}
