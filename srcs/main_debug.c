/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/22 10:18:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "pushswap_includes.h"

static void	create_stacks(t_stack *a, t_stack *b, t_tool *tool, int len);
static void	read_args(char **argv, t_stack *a, int last_index);
static void	destroy_stacks(t_stack *a, t_stack *b);
static void	push_back_toa(t_stack *a, t_stack *b, t_tool *tool);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_tool	*tool;

	tool = malloc(sizeof(t_tool));
	ft_bzero((char *)tool, sizeof(t_tool));
	tool->lowest_three = malloc(sizeof(int) * 3);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	create_stacks(a, b, tool, argc - 1);
	read_args(argv + 1, a, argc - 2);
	debug_header(a);
	if (argc <= 6)
		small_size_sort(a, b, tool);
	else
	{
		get_lowest_three(tool->lowest_three, a);
		do_first_pushes(a, b, tool);
		while (a->last_index > 2)
			big_size_sort(a, b, tool);
		sort_three(a, b, tool);
		push_back_toa(a, b, tool);
	}
	debug_footer(a);
	destroy_stacks(a, b);
}

static void	create_stacks(t_stack *a, t_stack *b, t_tool *tool, int len)
{
	a->stack = ft_calloc(len, sizeof(int));
	b->stack = ft_calloc(len, sizeof(int));
	a->last_index = len - 1;
	b->last_index = -1;
	tool->stack_a = a;
	tool->stack_b = b;
}

static void	destroy_stacks(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
}

static void	read_args(char **argv, t_stack *a, int last_index)
{
	int	i;
	int	j;
	int	*stack;

	i = last_index;
	j = -1;
	while (++j <= last_index)
		if (!is_valid_number(argv[j]))
			ft_error("invalid number found");
	j = 0;
	stack = a->stack;
	a->last_index = i;
	while (i + 1)
	{
		if (ft_atol(argv[i]) > __INT_MAX__ || ft_atol(argv[i]) < -__INT_MAX__)
			ft_error("a number is too big or too small");
		stack[j] = ft_atol(argv[i]);
		i--;
		j++;
	}
}

static void	push_back_toa(t_stack *a, t_stack *b, t_tool *tool)
{
	int	lowest;
	int	count;

	count = 3;
	tool->which_stack = B;
	lowest = get_smallest(b);
	if (get_index(b, lowest) > b->last_index / 2)
		while (b->stack[0] != lowest)
			exec_pushswap_instruction(a, b, rb, 0);
	else if (get_index(b, lowest) <= b->last_index / 2)
		while (b->stack[0] != lowest)
			exec_pushswap_instruction(a, b, rrb, 0);
	tool->which_stack = A;
	lowest = get_smallest(a);
	while (a->stack[a->last_index] != lowest)
		exec_pushswap_instruction(a, b, rra, 0);
	while (b->last_index != -1)
		exec_pushswap_instruction(a, b, pa, 0);
	while (count--)
		exec_pushswap_instruction(a, b, rra, 0);
}
