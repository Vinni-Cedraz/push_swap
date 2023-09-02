/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:27:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/09 21:46:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c);
static int	is_valid_number(const char *str);
static int	convert_recursively(char *a, unsigned int toi);

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (!is_valid_number(str))
		return (0);
	if (*str == '-')
		sign = -1;
	if (sign == -1 || *str == '+')
		str++;
	return (convert_recursively((char *)str, 0) * sign);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static int	is_valid_number(const char *str)
{
	while (*str && !is_whitespace(*str))
	{
		if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
			return (0);
		if ((*str == '\0'))
			return (0);
		str++;
	}
	return (1);
}

static int	convert_recursively(char *a, unsigned int toi)
{
	int	single_digit;

	if (!*a || is_whitespace(*a))
		return (toi);
	single_digit = *a - '0';
	toi = toi * 10 + single_digit;
	return (convert_recursively(a + 1, toi));
}
