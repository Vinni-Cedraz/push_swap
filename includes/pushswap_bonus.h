/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:01:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/22 10:47:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "../libs/libft.h"

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

typedef void	(*t_instruction)(
			t_stack *a,
			t_stack *b,
			int is_rot_or_rev);

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
	t_instruction		**hash_table;
	char				*line;
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

void					sa(t_stack *a, t_stack *b, int stuff);
void					sb(t_stack *a, t_stack *b, int stuff);
void					ss(t_stack *a, t_stack *b, int stuff);
void					pa(t_stack *a, t_stack *b, int stuff);
void					pb(t_stack *a, t_stack *b, int stuff);
void					rra(t_stack *a, t_stack *b, int stuff);
void					rrb(t_stack *a, t_stack *b, int stuff);
void					rrr(t_stack *a, t_stack *b, int stuff);
void					ra(t_stack *a, t_stack *b, int stuff);
void					rb(t_stack *a, t_stack *b, int stuff);
void					rr(t_stack *a, t_stack *b, int stuff);
void					create_stacks(
							t_stack *a,
							t_stack *b,
							t_tool *tool,
							int len
							);
int						read_args(char **argv, t_stack *a, int last_index);
void					destroy_stacks(t_stack *a, t_stack *b);
int						is_sorted(t_stack *a);
int						is_valid_number(char *str);
int						has_duplicates(int *stack, int size);
t_instruction			*create_hash_table(void);
unsigned int			hash_function(char *str);

#endif
