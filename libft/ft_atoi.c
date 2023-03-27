/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:27:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/17 14:29:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	how_mny_zeros(int diff);
static inline int	is_whitespace(char c);
static inline int	handle_negative(const char **str);
static inline int	my_strlen(const char *str);

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	len;
	int	sign;

	i = -1;
	res = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	sign = handle_negative(&str);
	len = my_strlen(str);
	if (!len)
		return (0);
	while (++i < len)
		res += ((str[i] - '0') * how_mny_zeros(len - i - 1));
	return (res * sign);
}

static inline int	my_strlen(const char *str)
{
	const char	*end;

	if (!str)
		return (0);
	end = str;
	while (*end && !is_whitespace(*end))
	{
		if ((*end < '0' || *end > '9') && *end != '-' && *end != '+')
			return (0);
		end++;
	}
	return (end - str);
}

static inline int	is_whitespace(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static inline int	how_mny_zeros(int diff)
{
	int	res;

	res = 1;
	while (diff)
	{
		res *= 10;
		diff--;
	}
	return (res);
}

static inline int	handle_negative(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}
// #include <assert.h>
// #include <stdio.h>
//
// int	main(void)
// {
// 	assert(ft_atoi("4") == atoi("4"));
// 	assert(ft_atoi("  4") == atoi("  4"));
// 	assert(ft_atoi("  4  ") == atoi("  4  "));
// 	assert(ft_atoi("  4  5") == atoi("  4  5"));
// 	assert(ft_atoi("1235") == atoi("1235"));
// 	assert(ft_atoi("  1235") == atoi("  1235"));
// 	assert(ft_atoi("0") == atoi("0"));
// 	assert(ft_atoi("1") == atoi("1"));
// 	assert(ft_atoi("-1") == atoi("-1"));
// 	assert(ft_atoi("-101") == atoi("-101"));
// 	assert(ft_atoi("-101") == atoi("-101"));
// 	assert(ft_atoi("-2147483648") == atoi("-2147483648"));
// 	assert(ft_atoi("2147483647") == atoi("2147483647"));
// 	assert(ft_atoi("+123") == atoi("123"));
// 	assert(ft_atoi("  +123") == atoi("123"));
// 	assert(ft_atoi("abc1") == atoi("abc1"));
// 	assert(ft_atoi("") == atoi(""));
// 	ft_putstr_fd("All tests passed.", 1);
// }
