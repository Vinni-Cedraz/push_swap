/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:27:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/09 21:46:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	is_whitespace(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static long	is_valid_number(const char *str)
{
	while (*str && !is_whitespace(*str))
	{
		if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (1);
}

static long	convert_recursively(char *a, unsigned long toi)
{
	long	single_digit;

	if (!*a || is_whitespace(*a))
		return (toi);
	single_digit = *a - '0';
	toi = toi * 10 + single_digit;
	return (convert_recursively(a + 1, toi));
}

long	ft_atoi_long(char *str)
{
	long	sign;

	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (!is_valid_number(str))
		return (0);
	if (*str == '-')
		sign = -1;
	if (sign == -1 || *str == '+')
		str++;
	return (convert_recursively(str, 0) * sign);
}

// #include <assert.h>
// #include <stdio.h>
// int main() {
//     assert(ft_atoi_long("4") == 4);
//     assert(ft_atoi_long("  4") == 4);
//     assert(ft_atoi_long("  4  ") == 4);
//     assert(ft_atoi_long("  4  5") == 4);
//     assert(ft_atoi_long("1235") == 1235);
//     assert(ft_atoi_long("\r1235\n") == 1235);
//     assert(ft_atoi_long("  1235") == 1235);
//     assert(ft_atoi_long("0") == 0);
//     assert(ft_atoi_long("1") == 1);
//     assert(ft_atoi_long("-1") == -1);
//     assert(ft_atoi_long("-101") == -101);
//     assert(ft_atoi_long("-101") == -101);
//     assert(ft_atoi_long("-2147483648") == -2147483648);
//     assert(ft_atoi_long("2147483647") == 2147483647);
//     assert(ft_atoi_long("214748364777") == 214748364777);
//     assert(ft_atoi_long("+123") == 123);
//     assert(ft_atoi_long("  +123") == 123);
//     assert(ft_atoi_long("abc1") == atoi("abc1"));
//     assert(ft_atoi_long("	abc1") == atoi("	abc1"));
//     assert(ft_atoi_long("\n\rabc1") == atoi("\n\rabc1"));
//     printf("All tests passed.");
// }
