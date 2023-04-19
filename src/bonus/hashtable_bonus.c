/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:08:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/19 20:34:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_instruction	*create_hash_table(void)
{
	t_instruction	*cmd_table;

	cmd_table = ft_calloc(sizeof(t_instruction), 120);
	cmd_table[hash_function("sa")] = &sa;
	cmd_table[hash_function("sb")] = &sb;
	cmd_table[hash_function("ss")] = &ss;
	cmd_table[hash_function("ra")] = &ra;
	cmd_table[hash_function("rb")] = &rb;
	cmd_table[hash_function("rr")] = &rr;
	cmd_table[hash_function("rra")] = &rra;
	cmd_table[hash_function("rrb")] = &rrb;
	cmd_table[hash_function("rrr")] = &rrr;
	cmd_table[hash_function("pa")] = &pa;
	cmd_table[hash_function("pb")] = &pb;
	return (cmd_table);
}

size_t	hash_function(char *str)
{
	size_t	hash;

	hash = 0;
	while (*str != '\n')
	{
		hash = hash ^ *str;
		hash = hash << 1;
		str++;
	}
	return (hash);
}
