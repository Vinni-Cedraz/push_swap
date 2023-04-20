/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:08:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/20 11:46:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_instruction	*create_hash_table(void)
{
	t_instruction	*cmd_table;

	cmd_table = ft_calloc(sizeof(t_instruction), 800);
	cmd_table[hash_function("pa\n")] = &pa;
	cmd_table[hash_function("pb\n")] = &pb;
	cmd_table[hash_function("sa\n")] = &sa;
	cmd_table[hash_function("sb\n")] = &sb;
	cmd_table[hash_function("ss\n")] = &ss;
	cmd_table[hash_function("ra\n")] = &ra;
	cmd_table[hash_function("rb\n")] = &rb;
	cmd_table[hash_function("rr\n")] = &rr;
	cmd_table[hash_function("rra\n")] = &rra;
	cmd_table[hash_function("rrb\n")] = &rrb;
	cmd_table[hash_function("rrr\n")] = &rrr;
	return (cmd_table);
}

unsigned int	hash_function(char *str)
{
	unsigned int	hash;
	short			len;

	hash = 0;
	len = 0;
	while (*str != '\n')
	{
		if (len == 4 || (*str < 'a'))
			return (0);
		hash = hash ^ *str;
		hash = hash << 1;
		str++;
		len++;
	}
	return (hash);
}
