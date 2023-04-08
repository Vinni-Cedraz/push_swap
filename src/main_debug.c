/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/08 15:34:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"
#include "pushswap_includes.h"

static void	create_stacks(t_stack *a, t_stack *b, int len);
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
	create_stacks(a, b, argc - 1);
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

static void	create_stacks(t_stack *a, t_stack *b, int len)
{
	a->stack = ft_calloc(len, sizeof(int));
	b->stack = ft_calloc(len, sizeof(int));
	a->last_index = len - 1;
	b->last_index = -1;
}

static void	read_args(char **argv, t_stack *a, int last_index)
{
	int	i;
	int	j;
	int	*stack;

	i = last_index;
	j = 0;
	stack = a->stack;
	a->last_index = i;
	while (i + 1)
	{
		stack[j] = ft_atoi(argv[i]);
		i--;
		j++;
	}
}

static void	destroy_stacks(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
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
			do_one_stack_operation(a, b, rb, tool);
	else if (get_index(b, lowest) <= b->last_index / 2)
		while (b->stack[0] != lowest)
			do_one_stack_operation(a, b, rrb, tool);
	tool->which_stack = A;
	lowest = get_smallest(a);
	while (a->stack[a->last_index] != lowest)
		do_one_stack_operation(a, b, rra, tool);
	while (b->last_index != -1)
		do_two_stacks_operation(a, b, pa, 0);
	while (count--)
		do_one_stack_operation(a, b, rra, tool);
}
