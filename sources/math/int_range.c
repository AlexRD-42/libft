/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:59:40 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/18 16:50:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

size_t	ft_i32min(int32_t *array, size_t length)
{
	size_t	i;
	size_t	min;

	min = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] < array[min])
			min = i;
		i++;
	}
	return (min);
}

size_t	ft_i32max(int32_t *array, size_t length)
{
	size_t	i;
	size_t	max;

	max = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] > array[max])
			max = i;
		i++;
	}
	return (max);
}

size_t	ft_i64min(int64_t *array, size_t length)
{
	size_t	i;
	size_t	min;

	min = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] < array[min])
			min = i;
		i++;
	}
	return (min);
}

size_t	ft_i64max(int64_t *array, size_t length)
{
	size_t	i;
	size_t	max;

	max = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] > array[max])
			max = i;
		i++;
	}
	return (max);
}
