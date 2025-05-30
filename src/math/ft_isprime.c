/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:21:41 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/29 09:44:52 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/libft.h"
#include <stdint.h>

uint8_t	ft_isprime(uint64_t number)
{
	uint64_t	factor;

	if (number <= 1 || number % 2 == 0 || number % 3 == 0)
		return (number == 2 || number == 3);
	factor = 5;
	while (factor * factor <= number)
	{
		if (number % factor == 0 || number % (factor + 2) == 0)
			return (0);
		factor += 6;
	}
	return (1);
}

#include <stdio.h>
int	main(void)
{
	for (int i=0; i < 1024; i++)
	{
		if (ft_isprime(i))
			printf("%d, ", i);
	}
}