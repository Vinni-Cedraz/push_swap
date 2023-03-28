/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:50:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/27 21:16:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

# include "sys_headers.h"

typedef struct s_st
{
	int		*stack;
	uint	last_index;
}			t_stack;

#endif
