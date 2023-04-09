/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:01:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/09 00:44:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

static void	free_stuff(t_stack *a, t_stack *b, t_tool *tool, int is_error);

// This function is the second part of the ft_check function.
void	check_instructions_aux(t_stack *a, t_stack *b, char *line)
{
	if (line[2] == 'a')
		rra(a);
	else if (line[2] == 'b')
		rrb(b);
	else if (line[2] == 'r')
		rrr(a, b);
}

// This function reads the line and checks if the command is valid.
// If it is, it executes the command.
int	check_instructions(t_stack *a, t_stack *b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_instructions_aux(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	t_tool	*tool;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	tool = malloc(sizeof(t_tool));
	create_stacks(a, b, tool, argc - 1);
	read_args(argv + 1, a, argc - 2);
	if (!a || has_duplicates(a->stack, argc - 1))
		free_stuff(a, b, tool, 1);
	while (1)
	{
		line = ft_gnl(0);
		if (!line)
			break ;
		if (!check_instructions(a, b, line))
			free_stuff(a, b, tool, 1);
	}
	if ((!line && !is_sorted(a)))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(a))
		write(1, "OK\n", 3);
	free_stuff(a, b, tool, 0);
}

static void	free_stuff(t_stack *a, t_stack *b, t_tool *tool, int is_error)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	free(tool);
	if (is_error)
		ft_error();
}
