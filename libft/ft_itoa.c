/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:11:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/30 11:49:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	numlen(int n);
static void	build_str(int nbr, char *str, char **end);
static int	handle_negative(int nbr, char **end);

char	*ft_itoa(int nbr)
{
	int		strlen;
	char	*str;
	char	*end;

	strlen = numlen(nbr);
	str = malloc(sizeof(char) * strlen);
	end = str;
	nbr = handle_negative(nbr, &end);
	build_str(nbr, str, &end);
	*end = '\0';
	if (nbr == __INT_MAX__)
		str[strlen - 1] = '8';
	return (str);
}

static int	handle_negative(int nbr, char **end)
{
	if (nbr < 0)
	{
		*(*end) = '-';
		nbr *= -1;
		(*end)++;
	}
	return (nbr);
}

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	build_str(int nbr, char *str, char **end)
{
	if (nbr > 9)
		build_str(nbr / 10, str, end);
	*(*end)++ = (nbr % 10) + '0';
}

// // ------------TESTS ---------------
//
// #include <assert.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
//
// int	main(void)
// {
// 	char	*test;
//
// 	test = ft_itoa(1234);
// 	assert(!strcmp("1234", test));
// 	free(test);
// 	test = ft_itoa(87);
// 	assert(!strcmp("87", test));
// 	free(test);
// 	test = ft_itoa(9);
// 	assert(!strcmp("9", test));
// 	free(test);
// 	test = ft_itoa(0);
// 	assert(!strcmp("0", test));
// 	free(test);
// 	test = ft_itoa(-12);
// 	assert(!strcmp("-12", test));
// 	free(test);
// 	test = ft_itoa(-122);
// 	assert(!strcmp("-122", test));
// 	free(test);
// 	test = ft_itoa(-12999812);
// 	assert(!strcmp("-12999812", test));
// 	free(test);
// 	test = ft_itoa(-__INT_MAX__);
// 	assert(!strcmp("-2147483648", test));
// 	free(test);
// 	printf("all tests passed!");
// }
