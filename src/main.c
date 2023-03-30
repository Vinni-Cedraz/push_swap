/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:39:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/29 21:39:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"
#include <stdio.h>

static void	create_stacks(t_stack *a, t_stack *b, int len);
static void	read_list(char **argv, t_stack *a);
static void	destroy_stacks(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_tool *tool;

	tool = malloc(sizeof(t_tool));
	tool->count = 0;
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	create_stacks(a, b, argc - 1);
	read_list(argv + 1, a);
	debug_header(a, b);
	algorithm(a, b, tool);
	destroy_stacks(a, b);
	printf("%d\n", tool->count);
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
