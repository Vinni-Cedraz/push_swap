/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/28 13:13:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static void	read_list(char **argv, t_stack *a);
static void	print_stack(t_stack *a, int last_index);
static void	create_stacks(t_stack *a, t_stack *b, int len);
static void	destroy_stacks(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	create_stacks(a, b, argc - 1);
	read_list(argv + 1, a);
	print_stack(a, a->last_index);
	destroy_stacks(a, b);
}

static void	create_stacks(t_stack *a, t_stack *b, int len)
{
	a->stack = ft_calloc(len, sizeof(int));
	b->stack = ft_calloc(len, sizeof(int));
	a->last_index = len - 1;
	a->last_index = len - 1;
}

static void	read_list(char **argv, t_stack *a)
{
	int	i;
	int *stack;

	i = -1;
	stack = a->stack;
	while (argv[++i])
		stack[i] = ft_atoi(argv[i]);
	a->last_index = i - 1;
}

static void	print_stack(t_stack *stack, int last_index)
{
	if (last_index)
		print_stack(stack, last_index - 1);
	ft_putnbr_fd(stack->stack[last_index], 1);
	ft_putchar_fd('\n', 1);
}

static void	destroy_stacks(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
}
