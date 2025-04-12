/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_average.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:46:03 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 17:46:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

float	ft_average(float *array, uint32_t size)
{
	float		sum;
	uint32_t	i;

	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += *array;
		array++;
		i++;
	}
	return (sum / size);
}
