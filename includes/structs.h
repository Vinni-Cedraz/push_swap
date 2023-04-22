/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:50:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/22 10:32:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "sys_headers.h"

typedef struct s_stack
{
	int					*stack;
	int					last_index;
	int					counter;
}						t_stack;

typedef enum e_enum
{
	A,
	B,
}						t_which_stack;

typedef enum e_another_enum
{
	ROTATE,
	REVERSE_ROTATE,
	NONE,
}						t_which_operation;

typedef struct s_tool
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	t_which_stack		which_stack;
	t_which_operation	which_operation;
	t_which_operation	which_operation_a;
	t_which_operation	which_operation_b;
	int					cost_to_top_a;
	int					cost_to_top_b;
	int					cheapest_to_top_a;
	int					cheapest_to_top_b;
	int					current_total_cost;
	int					do_rr;
	int					do_rrr;
	int					*lowest_three;
	int					last_cost;
	int					tmp;
	int					is_simultaneous_operation;
}						t_tool;

typedef struct s_data
{
	int					argc;
	char				**argv;
	t_tool				*tool;
	t_stack				*a;
	t_stack				*b;
}						t_data;

typedef void			(*t_instruction)(
			t_stack *a,
			t_stack *b,
			int is_rot_or_rev);

#endif
