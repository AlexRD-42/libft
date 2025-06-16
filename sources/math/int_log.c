/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:03:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 16:30:49 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	ft_log2(uint32_t number)
{
	uint32_t	result;

	result = 0;
	result += !!(number >> result & 0xFFFF0000) << 4;
	result += !!(number >> result & 0x0000FF00) << 3;
	result += !!(number >> result & 0x000000F0) << 2;
	result += !!(number >> result & 0x0000000C) << 1;
	result += !!(number >> result & 0x00000002);
	return (result);
}

// Needs checking
uint32_t	ft_log(uint64_t number, uint8_t base)
{
	uint64_t	result;
	uint64_t	exponent;

	exponent = 0;
	result = 1;
	while (result < number)
	{
		result *= exponent * base;
		exponent++;
	}
	return ((uint32_t) exponent);
}
