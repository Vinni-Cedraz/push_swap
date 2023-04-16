/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:12:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/16 15:00:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *errormsg)
{
	ft_putstr("Error: ");
	ft_putstr_fd(errormsg, 1);
	exit(EXIT_FAILURE);
}
