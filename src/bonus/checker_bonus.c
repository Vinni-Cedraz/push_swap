/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:01:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/18 18:08:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

static void	free_stuff(t_stack *a, t_stack *b, t_tool *tool, int is_error);
static void	check_instructions_aux(t_stack *a, t_stack *b, char *line);
static int	check_instructions(t_stack *a, t_stack *b, char *line);

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
		ft_putstr_fd("KO", 2);
	else if (!line && is_sorted(a))
		ft_putstr_fd("OK", 1);
	free_stuff(a, b, tool, 0);
}

static int	check_instructions(t_stack *a, t_stack *b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a, b);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(a, b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a, b);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(a, b);
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

static void	check_instructions_aux(t_stack *a, t_stack *b, char *line)
{
	if (line[2] == 'a')
		rra(a, b);
	else if (line[2] == 'b')
		rrb(a, b);
	else if (line[2] == 'r')
		rrr(a, b);
}

size_t	hash_function(char *str)
{
	size_t	hash;

	hash = 0;
	while (*str)
	{
		hash = hash ^ *str;
		hash = hash << 1;
		str++;
	}
	return (hash);
}

static void	free_stuff(t_stack *a, t_stack *b, t_tool *tool, int is_error)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	free(tool);
	if (is_error)
		exit(EXIT_FAILURE);
}
