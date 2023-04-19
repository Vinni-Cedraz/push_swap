/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:01:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/19 20:31:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "../libs/libft.h"
# include "structs.h"

void			sa(t_stack *a, t_stack *b, int stuff);
void			sb(t_stack *a, t_stack *b, int stuff);
void			ss(t_stack *a, t_stack *b, int stuff);
void			pa(t_stack *a, t_stack *b, int stuff);
void			pb(t_stack *a, t_stack *b, int stuff);
void			rra(t_stack *a, t_stack *b, int stuff);
void			rrb(t_stack *a, t_stack *b, int stuff);
void			rrr(t_stack *a, t_stack *b, int stuff);
void			ra(t_stack *a, t_stack *b, int stuff);
void			rb(t_stack *a, t_stack *b, int stuff);
void			rr(t_stack *a, t_stack *b, int stuff);
void			create_stacks(t_stack *a, t_stack *b, t_tool *tool, int len);
void			read_args(char **argv, t_stack *a, int last_index);
void			destroy_stacks(t_stack *a, t_stack *b);
int				is_sorted(t_stack *a);
int				is_valid_number(char *str);
int				has_duplicates(int *stack, int size);
t_instruction	*create_hash_table(void);
size_t			hash_function(char *str);

#endif
