/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:08:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/19 19:30:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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

t_instruction	*init_cmd_table(void)
{
	t_instruction	*cmd_table;

	cmd_table = ft_calloc(sizeof(t_instruction), 12);
	return (cmd_table);
}
