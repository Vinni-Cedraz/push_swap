/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/16 14:59:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static void	destroy_stacks(t_stack *a, t_stack *b);
static void	push_back_toa(t_stack *a, t_stack *b, t_tool *tool);
static void	create_stacks(t_stack *a, t_stack *b, t_tool *tool, int len);
static void	read_args(char **argv, t_stack *a, t_stack *b, int last_index);

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
	read_args(argv + 1, a, b, argc - 2);
	if (has_duplicates(a->stack, argc - 1))
		ft_error("duplicate detected");
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

static void	read_args(char **argv, t_stack *a, t_stack *b, int last_index)
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
	if (is_sorted(a))
	{
		ft_putstr("");
		destroy_stacks(a, b);
		exit(EXIT_SUCCESS);
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
