/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:55:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/05 22:58:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	pa(t_stack *a, t_stack *b, int is_rot_or_rev)
{
	(void)is_rot_or_rev;
	ft_putstr("pa\n");
	if (b->last_index < 0)
		return ;
	a->stack[++a->last_index] = b->stack[b->last_index--];
}

void	pb(t_stack *a, t_stack *b, int is_rot_or_rev)
{
	(void)is_rot_or_rev;
	ft_putstr("pb\n");
	if (a->last_index < 0)
		return ;
	b->stack[++b->last_index] = a->stack[a->last_index--];
}
