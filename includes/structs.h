/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:50:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/06 19:18:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "sys_headers.h"

typedef struct s_st
{
	int					*stack;
	int					last_index;
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
	t_which_stack		which;
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
}						t_tool;

#endif
