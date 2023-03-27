/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:41:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 19:55:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstpop(t_node **lst)
{
	t_node	*new_tail;

	if (!lst || !(*lst)->next)
		return ;
	new_tail = *lst;
	while (new_tail->next->next)
		new_tail = new_tail->next;
	free(new_tail->next);
	new_tail->next = NULL;
}
