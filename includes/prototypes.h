/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:04:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/28 15:30:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include "t_stack.h"

typedef enum {
    A,
    B,
} e_which_stack;

// swap
void sa(t_stack *a, int is_ss);
void sb(t_stack *b, int is_ss);
void ss(t_stack *a, t_stack *b);
// push
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);

// rotate
void ra(t_stack *a, int is_rr);
void rb(t_stack *b, int is_rr);
void rr(t_stack *a, t_stack *b, int is_rr);

// reverse rotate
void rra(t_stack *a, int is_rrr);
void rrb(t_stack *b, int is_rrr);
void rrr(t_stack *a, t_stack *b, int is_rrr);

// debug
void print_stack(t_stack *a, int last_index);
void print_stacks(t_stack *a, t_stack *b);

typedef void(t_funct1)(t_stack *stack, int is);
typedef void(t_funct2)(t_stack *a, t_stack *b);

void debug_header(t_stack *a, t_stack *b);
void do_one_stack_operation(t_stack *a, t_stack *b, t_funct1 f, e_which_stack);
void do_two_stacks_operation(t_stack *a, t_stack *b, t_funct2 f);

#endif
