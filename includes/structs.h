/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:50:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/02 17:22:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

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
	int					count;
	int					last_pa;
	int					cheapest_to_top_a;
	int					cheapest_to_top_b;
	int					hw_mny_ra;
	int					hw_mny_rb;
	int					hw_mny_rra;
	int					hw_mny_rrb;
}						t_tool;

#endif
