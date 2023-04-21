/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/09 21:13:14 by vcedraz-         ###   ########.fr       */
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

void	debug_footer(t_stack *a)
{
	ft_putstr(" -final stack- \n");
	ft_putstr("---------------\n");
	print_stack(a, 0);
	ft_putchar('\n');
	ft_putstr("------------------------\n");
	ft_putstr(" operations counter: ");
	ft_putnbr_fd(a->counter, 1);
	ft_putstr("\n------------------------\n");
}

void	check_stacks(t_stack *a, t_stack *b)
{
	ft_putstr("---------------\n");
	print_stacks(a, b);
	ft_putstr("---------------\n");
}
