/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:04:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/19 19:53:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "structs.h"

// PUSHSWAP_INSTRUCTIONS //

// swap
void	sa(t_stack *a, t_stack *b, int is_ss);
void	sb(t_stack *a, t_stack *b, int is_ss);
void	ss(t_stack *a, t_stack *b, int is_ss);
// push
void	pa(t_stack *a, t_stack *b, int is);
void	pb(t_stack *a, t_stack *b, int is);
// rotate
void	ra(t_stack *a, t_stack *b, int is_rr);
void	rb(t_stack *a, t_stack *b, int is_rr);
void	rr(t_stack *a, t_stack *b, int is_rr);
// reverse rotate
void	rra(t_stack *a, t_stack *b, int is_rrr);
void	rrb(t_stack *a, t_stack *b, int is_rrr);
void	rrr(t_stack *a, t_stack *b, int is_rrr);
// wrapper for all instructions
void	exec_pushswap_instruction(
			t_stack *a,
			t_stack *b,
			t_instruction f,
			int is_simultaneous);

// COST CHECKERS;
void	get_push_cost(int a_pos, int b_pos, t_tool *tool);
void	get_current_total_cost(t_tool *tool);
int		current_is_cheaper(t_tool *tool);
void	set_do_rr_do_rrr(t_tool *tool, int curr_a, int curr_b);

// SORTING ALGORITHMS;
void	sort_three(t_stack *a, t_stack *b, t_tool *tool);
void	small_size_sort(t_stack *a, t_stack *b, t_tool *tool);
void	big_size_sort(t_stack *a, t_stack *b, t_tool *tool);

// MISC UTILS;
void	do_first_pushes(t_stack *a, t_stack *b, t_tool *tool);
void	get_lowest_three(int *lowest_three, t_stack *s);
int		is_lowest_three(int *lowest_three, int nb);
int		get_smallest_from_n(t_stack *s, int exception);
int		get_index(t_stack *a, int index);
int		get_smallest(t_stack *stack);
int		get_biggest(t_stack *stack);
int		is_sorted(t_stack *a);

// PARSING UTILS
t_data	*init_data(int size, char **argv);
int		has_duplicates(int *stack, int size);
int		is_valid_number(char *str);

// DEBUG UTILS;
void	check_stacks(t_stack *a, t_stack *b);
void	print_stack(t_stack *a, int last_index);
void	print_stacks(t_stack *a, t_stack *b);
void	debug_header(t_stack *a);
void	debug_footer(t_stack *a);

#endif
