/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:19:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/27 18:19:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strcpyrev(char *str, int len)
{
	int		i;
	int		last;
	char	*revcpy;

	i = 0;
	last = len;
	revcpy = malloc((len + 1) * sizeof(char));
	while (len)
		revcpy[i++] = str[--len];
	revcpy[last] = '\0';
	free(str);
	return (revcpy);
}
