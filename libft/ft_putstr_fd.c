/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:09:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/03 00:30:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	char	*s_copy;

	s_copy = s;
	while (s_copy && *s_copy)
		ft_putchar_fd(*s_copy++, fd);
	ft_putchar_fd('\n', fd);
	return (s_copy - s);
}
