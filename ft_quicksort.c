/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:45:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/25 22:18:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef unsigned int	t_uc;

static inline void		*aux_ft_memcpy(void *dst, const void *src, size_t n);

static void	ft_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	aux_ft_memcpy(tmp, a, size);
	aux_ft_memcpy(a, b, size);
	aux_ft_memcpy(b, tmp, size);
	free(tmp);
}

static inline void	*aux_ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(((t_uc *)dst) + i) = *(((t_uc *)src) + i);
	return (dst);
}

static int	ft_partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= pivot && i < j)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i < j)
			ft_swap(&arr[i], &arr[j], sizeof(int));
	}
	ft_swap(&arr[low], &arr[j], sizeof(int));
	return (j);
}

static void	ft_insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = -1;
	while (++i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void	ft_quicksort(int *arr, int low, int high)
{
	int	pivot;

	if (high - low < 20)
	{
		ft_insertion_sort(arr + low, high - low + 1);
		return ;
	}
	pivot = ft_partition(arr, low, high);
	ft_quicksort(arr, low, pivot);
	ft_quicksort(arr, pivot + 1, high);
}
