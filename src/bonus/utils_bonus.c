/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:00:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/20 01:35:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

void	create_stacks(t_stack *a, t_stack *b, t_tool *tool, int len)
{
	a->stack = ft_calloc(len, sizeof(int));
	b->stack = ft_calloc(len, sizeof(int));
	a->last_index = len - 1;
	b->last_index = -1;
	tool->stack_a = a;
	tool->stack_b = b;
}

void	destroy_stacks(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
}

void	read_args(char **argv, t_stack *a, int last_index)
{
	int	i;
	int	j;
	int	*stack;

	i = last_index;
	j = -1;
	while (++j <= last_index)
		if (!is_valid_number(argv[j]))
			ft_error("some argument is not a number");
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

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->last_index)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}
