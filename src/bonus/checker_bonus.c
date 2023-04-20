/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:01:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/20 01:33:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

static void	free_stuff(t_stack *a, t_stack *b, t_tool *tool, int is_error);
static int	pushswap(t_stack *a, t_stack *b, char *ln, t_instruction *hashtab);
static void	init_data(t_stack **a, t_stack **b, t_tool **t, t_instruction **ht);

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	char			*line;
	t_tool			*tool;
	t_instruction	*hash_table;

	init_data(&a, &b, &tool, &hash_table);
	create_stacks(a, b, tool, argc - 1);
	read_args(argv + 1, a, argc - 2);
	if (!a || has_duplicates(a->stack, argc - 1))
		free_stuff(a, b, tool, 1);
	while (1)
	{
		line = ft_gnl(0);
		if (!line)
			break ;
		if (!pushswap(a, b, line, hash_table))
			free_stuff(a, b, tool, 1);
	}
	if ((!line && !is_sorted(a)))
		ft_putstr_fd("KO", 2);
	else if (!line && is_sorted(a))
		ft_putstr_fd("OK", 1);
	free_stuff(a, b, tool, 0);
}

static void	init_data(t_stack **a, t_stack **b, t_tool **t, t_instruction **htb)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	*t = malloc(sizeof(t_tool));
	*htb = create_hash_table();
}

static int	pushswap(t_stack *a, t_stack *b, char *line, t_instruction *hashtab)
{
	if (hashtab[hash_function(line)])
	{
		hashtab[hash_function(line)](a, b, 0);
		return (1);
	}
	return (0);
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
