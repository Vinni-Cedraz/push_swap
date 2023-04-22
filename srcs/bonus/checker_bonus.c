/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:01:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/22 12:33:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static void	free_stuff_exit(t_stack *a, t_stack *b, t_tool *tool, int is_error);
static int	exec_instruction(t_stack *a, t_stack *b, char *l, t_tool *tool);
static void	init_data(t_stack **a, t_stack **b, t_tool **t);
static void	read_instructions(t_stack *a, t_stack *b, t_tool *tool);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_tool	*tool;

	init_data(&a, &b, &tool);
	create_stacks(a, b, tool, argc - 1);
	if (!read_args(argv + 1, a, argc - 2))
		free_stuff_exit(a, b, tool, 1);
	if (!a || has_duplicates(a->stack, argc - 1))
		free_stuff_exit(a, b, tool, 1);
	read_instructions(a, b, tool);
	if (is_sorted(a))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 2);
	free_stuff_exit(a, b, tool, 0);
}

static void	init_data(t_stack **a, t_stack **b, t_tool **t)
{
	*a = ft_calloc(sizeof(t_stack), 1);
	*b = ft_calloc(sizeof(t_stack), 1);
	*t = ft_calloc(sizeof(t_tool), 1);
	(*t)->line = (char *){0};
	(*t)->instruction_table = create_hash_table();
}

static void	read_instructions(t_stack *a, t_stack *b, t_tool *tool)
{
	while (1)
	{
		tool->line = ft_gnl(0);
		if (!tool->line)
			break ;
		if (!exec_instruction(a, b, tool->line, tool))
			tool->invalid_instruction = 1;
	}
	if (tool->invalid_instruction)
	{
		ft_putstr_fd("Error: invalid instruction", 2);
		free_stuff_exit(a, b, tool, 1);
	}
}

static int	exec_instruction(t_stack *a, t_stack *b, char *ln, t_tool *t)
{
	char	*clean_line;

	clean_line = ft_strtrim(ln, " ");
	free(ln);
	if (t->instruction_table[hash_function(clean_line)])
	{
		t->instruction_table[hash_function(clean_line)](a, b, 0);
		free(clean_line);
		return (1);
	}
	free(clean_line);
	return (0);
}

static void	free_stuff_exit(t_stack *a, t_stack *b, t_tool *tool, int is_error)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	free(tool->line);
	free(tool->instruction_table);
	free(tool);
	if (is_error)
		exit(EXIT_FAILURE);
}
