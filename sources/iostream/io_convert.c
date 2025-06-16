/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:30 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 16:22:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libft.h"

// Performs bitwise manipulation to compute abs of n without overflowing
// array[66] to hold all digits of a 64 bit signed integer with base 2
// Negative sign might not be appropriate for binary or hex
// Mirror changes here to putnbr
char	*ft_itoa(int64_t number)
{
	const int8_t	sign = (number >= 0) - (number < 0);
	char			array[32];
	char			*ptr;

	ptr = array + 31;
	*ptr = 0;
	*(--ptr) = sign * (number % 10) + '0';
	number = sign * (number / 10);
	while (number != 0)
	{
		*(--ptr) = (number % 10) + '0';
		number /= 10;
	}
	if (sign == -1)
		*(--ptr) = '-';
	return (ft_strdup(ptr));
}

// Receives and endptr to a buffer guaranteed to hold size of number
char	*ft_itoa_stack(int64_t number, char *ptr)
{
	const int8_t	sign = (number >= 0) - (number < 0);

	*ptr = 0;
	*(--ptr) = sign * (number % 10) + '0';
	number = sign * (number / 10);
	while (number != 0)
	{
		*(--ptr) = (number % 10) + '0';
		number /= 10;
	}
	if (sign == -1)
		*(--ptr) = '-';
	return (ptr);
}

int64_t	ft_atoi(const char *str)
{
	int64_t	number;
	int64_t	sign;

	number = 0;
	sign = -1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -sign;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		number = number * 10 - (*str++ - '0');
	return (sign * number);
}

// Decide on naming and check if strlen is higher than overflow
// Open an issue because of uint8_t *
uint64_t	ft_atoi_hex(const char *str)
{
	uint64_t				number;
	static const uint8_t	lut[256] = {
	['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3, ['4'] = 4,
	['5'] = 5, ['6'] = 6, ['7'] = 7, ['8'] = 8, ['9'] = 9,
	['A'] = 10, ['B'] = 11, ['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15,
	['a'] = 10, ['b'] = 11, ['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15};

	number = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	str += (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) << 1;
	while (lut[*(uint8_t *) str] || *str == '0')
		number = (number << 4) + lut[*(uint8_t *) str++];
	return (number);
}
