/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:01:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/08 23:52:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "../libs/libft.h"
# include "structs.h"

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	create_stacks(t_stack *a, t_stack *b, t_tool *tool, int len);
void	read_args(char **argv, t_stack *a, int last_index);
void	destroy_stacks(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
int		is_valid_number(char *str);
int		has_duplicates(int *stack, int size);

#endif
