/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:36:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/18 15:22:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	sa(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->last_index < 1)
		return ;
	a->stack[a->last_index] ^= a->stack[a->last_index - 1];
	a->stack[a->last_index - 1] ^= a->stack[a->last_index];
	a->stack[a->last_index] ^= a->stack[a->last_index - 1];
}

void	sb(t_stack *a, t_stack *b)
{
	(void)a;
	if (b->last_index < 1)
		return ;
	b->stack[b->last_index] ^= b->stack[b->last_index - 1];
	b->stack[b->last_index - 1] ^= b->stack[b->last_index];
	b->stack[b->last_index] ^= b->stack[b->last_index - 1];
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}
