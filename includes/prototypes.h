/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:04:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/02 17:00:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "structs.h"

typedef				void(t_funct1)(t_stack *stack, int is);
typedef				void(t_funct2)(t_stack *a, t_stack *b);

// debug
void				print_stack(t_stack *a, int last_index);
void				print_stacks(t_stack *a, t_stack *b);
void				debug_header(t_stack *a, t_stack *b);
void				do_one_stack_operation(t_stack *a, t_stack *b, t_funct1 f,
						t_tool *tool);
void				do_two_stacks_operation(t_stack *a, t_stack *b, t_funct2 f,
						t_tool *tool);

// swap
void				sa(t_stack *a, int is_ss);
void				sb(t_stack *b, int is_ss);
void				ss(t_stack *a, t_stack *b);
// push
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

// rotate
void				ra(t_stack *a, int is_rr);
void				rb(t_stack *b, int is_rr);
void				rr(t_stack *a, t_stack *b, int is_rr);

// reverse rotate
void				rra(t_stack *a, int is_rrr);
void				rrb(t_stack *b, int is_rrr);
void				rrr(t_stack *a, t_stack *b, int is_rrr);

// sorting algos;
void				big_size_sort(t_stack *a, t_stack *b, t_tool *tool);
void				small_size_sort(t_stack *a, t_stack *b, t_tool *tool);
void				sort_three(t_stack *a, t_stack *b, t_tool *tool);

// utils
int					lowest_number(t_stack *stack);
int					biggest_number(t_stack *stack);
int					is_sorted(t_stack *a);
int					get_push_cost_case1(t_stack *a, t_stack *b, int a_pos, int b_pos, t_tool *tool);
int					get_push_cost_case2(t_stack *a, t_stack *b, int a_pos, t_tool *tool);
int					get_index(t_stack *a, int index);

#endif
