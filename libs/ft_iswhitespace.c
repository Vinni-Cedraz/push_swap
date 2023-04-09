/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:15:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/09 21:25:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

// #include <assert.h>
// #include <stdio.h>
// int	main(void)
// {
// 	assert(ft_iswhitespace('a') == 0);
// 	assert(ft_iswhitespace(53) == 0);
// 	assert(ft_iswhitespace(' ') == 1);
// 	assert(ft_iswhitespace('\n') == 1);
// 	assert(ft_iswhitespace('\t') == 1);
// 	assert(ft_iswhitespace('\v') == 1);
// 	assert(ft_iswhitespace('\f') == 1);
// 	assert(ft_iswhitespace('\r') == 1);
// 	printf("all tests passed!\n");
// }
