/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:10:07 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 13:10:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int64_t	ft_factorial(int64_t number)
{
	static const int64_t factorial_table[21] = {1, 1, 2, 6, 24, 120, 720,
		5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 
		87178291200, 1307674368000,	20922789888000, 355687428096000, 
		6402373705728000, 121645100408832000, 2432902008176640000};

	if (number < 0 || number >= 21)
		return (0);
	return (factorial_table[number]);
}
