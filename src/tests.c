/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/07 14:33:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_includes.h"

void	debug_header(t_stack *a)
{
	ft_putstr("---------------\n");
	ft_putstr(" initial stack \n");
	ft_putstr("---------------\n");
	print_stack(a, 0);
	ft_putstr("---------------\n");
}

void	debug_footer(t_stack *a)
{
	ft_putstr("---------------\n");
	ft_putstr(" -final stack- \n");
	ft_putstr("---------------\n");
	print_stack(a, 0);
	ft_putstr("---------------\n");
	ft_putstr_fd("total number of operations: ", 1);
	ft_putchar('\n');
}

void	do_one_stack_operation(t_stack *a, t_stack *b, t_funct1 f, t_tool *tool)
{
	if (tool->which == A)
		(f)(a, 0);
	if (tool->which == B)
		(f)(b, 0);
	ft_putstr("---------------\n");
	print_stacks(a, b);
	ft_putstr("---------------\n");
	return ;
}

void	do_two_stacks_operation(t_stack *a, t_stack *b, t_funct2 f,
		int is_rot_or_rev)
{
	(f)(a, b, is_rot_or_rev);
	ft_putstr("----------------\n");
	print_stacks(a, b);
	ft_putstr("----------------\n");
}

void	do_first_pushes(t_stack *a, t_stack *b, t_tool *tool)
{
	int	top_of_a;
	int	*lowest_three;
	int	a_big;

	a_big = get_biggest(a);
	top_of_a = a->stack[a->last_index];
	lowest_three = tool->lowest_three;
	while (b->last_index != 1)
	{
		if (is_lowest_three(lowest_three, top_of_a) || top_of_a == a_big)
			do_one_stack_operation(a, b, ra, tool);
		else if (!is_lowest_three(lowest_three, top_of_a) && top_of_a != a_big)
			do_two_stacks_operation(a, b, pb, 0);
		top_of_a = a->stack[a->last_index];
		a_big = get_biggest(a);
	}
}

// t_stack *init_stack(int *arr, int arr_size)
// {
// 	int i;
// 	t_stack *s;
//
// 	i = -1;
// 	s = malloc(sizeof(t_stack));
// 	s->last_index = arr_size - 1;
// 	while (++i <= s->last_index)
// 		s->stack[i] = arr[i];
// 	return (s);
// }
