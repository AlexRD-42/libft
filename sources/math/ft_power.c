/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:32:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/28 22:24:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// Change to square the squares (log n)
int64_t	ft_power(int64_t number, uint64_t power)
{
	const int64_t	base = number;

	if (power == 0)
		return (1);
	while (power > 1)
	{
		number = number * base;
		power--;
	}
	return (number);
}
