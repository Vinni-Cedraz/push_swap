/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:55:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/22 10:34:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	pa(t_stack *a, t_stack *b, int nil)
{
	(void)nil;
	if (b->last_index < 0)
		return ;
	a->stack[++a->last_index] = b->stack[b->last_index--];
}

void	pb(t_stack *a, t_stack *b, int nil)
{
	(void)nil;
	if (a->last_index < 0)
		return ;
	b->stack[++b->last_index] = a->stack[a->last_index--];
}
