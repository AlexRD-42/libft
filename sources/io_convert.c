/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:30 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 09:43:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

char	*ft_strdup(const char *src);

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
