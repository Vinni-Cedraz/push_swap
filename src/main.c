/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/02 15:38:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"
#include <stdio.h>

static void	create_stacks(t_stack *a, t_stack *b, int len);
static void	read_list(char **argv, t_stack *a);
static void	destroy_stacks(t_stack *a, t_stack *b);
static void	push_back_toa(t_stack *a, t_stack *b, t_tool *tool);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_tool	*tool;

	tool = malloc(sizeof(t_tool));
	tool->count = 0;
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	create_stacks(a, b, argc - 1);
	read_list(argv + 1, a);
	debug_header(a, b);
	do_two_stacks_operation(a, b, pb, tool);
	do_two_stacks_operation(a, b, pb, tool);
	if (argc <= 6)
		small_size_sort(a, b, tool);
	else
	{
		while (a->last_index > 2)
			big_size_sort(a, b, tool);
		sort_three(a, b, tool);
		push_back_toa(a, b, tool);
	}
	print_stack(a, 0);
	destroy_stacks(a, b);
	printf("counter at end: %d\n", tool->count);
}

static void	create_stacks(t_stack *a, t_stack *b, int len)
{
	a->stack = ft_calloc(len, sizeof(int));
	b->stack = ft_calloc(len, sizeof(int));
	a->last_index = len - 1;
	b->last_index = -1;
}

static void	read_list(char **argv, t_stack *a)
{
	int	i;
	int	*stack;

	i = -1;
	stack = a->stack;
	while (argv[++i])
		stack[i] = ft_atoi(argv[i]);
	a->last_index = i - 1;
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
	int count;

	count = 3;
	tool->e = B;
	lowest = lowest_number(b);
	while (b->stack[0] != lowest)
		do_one_stack_operation(a, b, rb, tool);
	tool->e = A;
	lowest = lowest_number(a);
	while (a->stack[a->last_index] != lowest)
		do_one_stack_operation(a, b, rra, tool);
	while (b->last_index != -1)
		do_two_stacks_operation(a, b, pa, tool);
	while (count--)
		do_one_stack_operation(a, b, rra, tool);
}
