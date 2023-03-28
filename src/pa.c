/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:55:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->last_index < 0)
		return ;
	a->stack[++a->last_index] = b->stack[b->last_index--];
}
