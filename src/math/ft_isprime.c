/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:21:41 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 13:21:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int64_t	ft_isprime(int64_t number)
{
	int64_t	i;

	if (number <= 1 || number % 2 == 0 || number % 3 == 0)
		return (0);
	if (number == 2 || number == 3)
		return (1);
	i = 5;
	while (i * i <= number)
	{
		if (number % i == 0 || number % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}
