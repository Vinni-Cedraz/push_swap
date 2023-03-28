/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/28 15:32:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void debug_header(t_stack *a, t_stack *b) {
    ft_putstr("--------\n");
    ft_putstr("initial stack\n");
    ft_putstr("--------\n");
    print_stacks(a, b);
    ft_putstr("--------\n");
}

void do_one_stack_operation(t_stack *a, t_stack *b, t_funct1 f,
                            e_which_stack e) {
    if (e == A) (f)(a, 0);
    if (e == B) (f)(b, 0);
    ft_putstr("--------\n");
    print_stacks(a, b);
    ft_putstr("--------\n");
    return;
}

void do_two_stacks_operation(t_stack *a, t_stack *b, t_funct2 f) {
    (f)(a, b);
    ft_putstr("--------\n");
    print_stacks(a, b);
    ft_putstr("--------\n");
}
