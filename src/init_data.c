/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:33:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/18 18:20:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_includes.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	data->tool = malloc(sizeof(t_tool));
	ft_bzero((char *)data->tool, sizeof(t_tool));
	data->tool->lowest_three = malloc(sizeof(int) * 3);
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	data->a->stack = ft_calloc(argc - 1, sizeof(int));
	data->b->stack = ft_calloc(argc - 1, sizeof(int));
	data->a->last_index = argc - 1;
	data->b->last_index = -1;
	data->argv = argv;
	data->argc = argc;
	data->tool->stack_a = data->a;
	data->tool->stack_b = data->b;
	return (data);
}
