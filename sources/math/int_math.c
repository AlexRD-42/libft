/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:56:46 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 13:25:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int64_t	ft_sqrt(int64_t number)
{
	int64_t	i;

	i = 1;
	if (number <= 0)
		return (0);
	else if (number == 1)
		return (1);
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (0);
}

int64_t	ft_factorial(int64_t number)
{
	static const int64_t	factorial_table[21] = {1, 1, 2, 6, 24, 120, 720,
		5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800,
		87178291200, 1307674368000,	20922789888000, 355687428096000,
		6402373705728000, 121645100408832000, 2432902008176640000};

	if (number < 0 || number >= 21)
		return (0);
	return (factorial_table[number]);
}

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
