/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/03 00:32:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	debug_header(t_stack *a)
{
	ft_putstr("---------------\n");
	ft_putstr(" initial stack \n");
	ft_putstr("---------------\n");
	print_stack(a, 0);
	ft_putstr("---------------\n");
}

void	debug_footer(t_stack *a, t_tool *tool)
{
	ft_putstr("---------------\n");
	ft_putstr(" -final stack- \n");
	ft_putstr("---------------\n");
	print_stack(a, 0);
	ft_putstr("---------------\n");
	ft_putstr_fd("total number of operations: ", 1);
	ft_putnbr_fd(tool->count, 1);
}

void do_one_stack_operation(t_stack *a, t_stack *b, t_funct1 f, t_tool *tool)
{
	if (tool->which == A)
		(f)(a, 0);
	if (tool->which == B)
		(f)(b, 0);
	tool->count++;
	ft_putstr("--------\n");
	print_stacks(a, b);
	ft_putstr("--------\n");
	return ;
}

void	do_two_stacks_operation(t_stack *a, t_stack *b, t_funct2 f,
		t_tool *tool)
{
	(f)(a, b);
	if (is_sorted(a))
		tool->last_pa = tool->count;
	ft_putstr("--------\n");
	print_stacks(a, b);
	ft_putstr("--------\n");
	tool->count++;
}
