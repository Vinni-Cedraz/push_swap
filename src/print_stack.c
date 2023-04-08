/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:16:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/08 17:06:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	print_stack(a, 0);
	ft_putchar('\n');
	print_stack(b, 0);
	ft_putchar('\n');
}

void	print_stack(t_stack *stack, int first_index)
{
	if (stack->last_index == -1)
		return ;
	if (first_index != stack->last_index)
		print_stack(stack, first_index + 1);
	ft_putnbr_fd(stack->stack[first_index], 1);
	ft_putchar('\n');
}
