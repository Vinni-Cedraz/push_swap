/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:00:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/22 11:18:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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

int	read_args(char **argv, t_stack *a, int last_index)
{
	int	i;
	int	j;
	int	*stack;

	if (last_index + 2 == 1)
		return (ft_putstr_fd("Error: no arguments", 2), 0);
	i = last_index;
	j = -1;
	while (++j <= last_index)
		if (!is_valid_number(argv[j]))
			return (ft_putstr_fd("Error: some char is not a number", 2), 0);
	j = 0;
	stack = a->stack;
	a->last_index = i;
	while (i + 1)
	{
		if (ft_atol(argv[i]) > __INT_MAX__ || ft_atol(argv[i]) < -__INT_MAX__)
			return (ft_putstr_fd("Error: number doesn't fit in an int", 2), 0);
		stack[j] = ft_atol(argv[i]);
		i--;
		j++;
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

int	is_sorted(t_stack *a)
{
	int	i;
	int	*arr;

	i = 0;
	arr = a->stack;
	while (i < a->last_index)
	{
		if (arr[i] <= arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
