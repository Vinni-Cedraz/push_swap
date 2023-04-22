/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/22 10:14:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

static void	destroy_data(t_data *data);
static void	push_back_toa(t_stack *a, t_stack *b, t_tool *tool);
static int	read_args(t_stack *a, t_data *data);

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv + 1);
	if (!read_args(data->a, data))
		destroy_data(data);
	if (has_duplicates(data->a->stack, argc - 1))
		destroy_data(data);
	if (argc <= 6)
		small_size_sort(data->a, data->b, data->tool);
	else
	{
		get_lowest_three(data->tool->lowest_three, data->a);
		do_first_pushes(data->a, data->b, data->tool);
		while (data->a->last_index > 2)
			big_size_sort(data->a, data->b, data->tool);
		sort_three(data->a, data->b, data->tool);
		push_back_toa(data->a, data->b, data->tool);
	}
	destroy_data(data);
}

static int	read_args(t_stack *a, t_data *d)
{
	int	i;
	int	j;
	int	*stack;

	i = d->argc - 2;
	j = -1;
	while (++j <= d->argc - 2)
		if (!is_valid_number(d->argv[j]))
			return (ft_putstr_fd("Error: non-numeric char found", 2), 0);
	j = 0;
	stack = a->stack;
	a->last_index = i;
	while (i + 1)
	{
		if (ft_atol(d->argv[i]) > __INT_MAX__)
			return (ft_putstr_fd("Error: a number is too big", 2), 0);
		if (ft_atol(d->argv[i]) < -__INT_MAX__)
			return (ft_putstr_fd("Error: a number is too small", 2), 0);
		stack[j] = ft_atol(d->argv[i]);
		i--;
		j++;
	}
	if (is_sorted(a))
		return (0);
	return (1);
}

static void	destroy_data(t_data *data)
{
	free(data->a->stack);
	free(data->b->stack);
	free(data->a);
	free(data->b);
	free(data->tool->lowest_three);
	free(data->tool);
	free(data);
	exit(EXIT_FAILURE);
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
			exec_pushswap_instruction(a, b, rb, 0);
	else if (get_index(b, lowest) <= b->last_index / 2)
		while (b->stack[0] != lowest)
			exec_pushswap_instruction(a, b, rrb, 0);
	tool->which_stack = A;
	lowest = get_smallest(a);
	while (a->stack[a->last_index] != lowest)
		exec_pushswap_instruction(a, b, rra, 0);
	while (b->last_index != -1)
		exec_pushswap_instruction(a, b, pa, 0);
	while (count--)
		exec_pushswap_instruction(a, b, rra, 0);
}
