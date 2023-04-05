/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lowest_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:30:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/05 12:59:31 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	get_lowest_three(int *lowest_three, t_stack *s)
{
	lowest_three[0] = get_smallest(s);
	lowest_three[1] = get_smallest_from_n(s, lowest_three[0]);
	lowest_three[2] = get_smallest_from_n(s, lowest_three[1]);
}

int	is_lowest_three(int *lowest_three, int nb)
{
	if (nb == lowest_three[0] || nb == lowest_three[1] || nb == lowest_three[2])
		return (1);
	return (0);
}
