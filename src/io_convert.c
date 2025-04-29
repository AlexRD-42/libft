/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:30 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/26 11:28:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Performs bitwise manipulation to compute abs of n without overflowing
// array[66] to hold all digits of a 64 bit signed integer with base 2
// Negative sign might not be appropriate for binary or hex
// Mirror changes here to putnbr
char	*ft_itoa(int64_t number)
{
	const int8_t	sign = (number >= 0) - (number < 0);
	char			array[21];
	char			*ptr;

	ptr = array + 20;
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

int64_t	ft_atoi(const char *num_str)
{
	int64_t	number;
	int64_t	sign;

	number = 0;
	sign = -1;
	while (*num_str == 32 || (*num_str >= 9 && *num_str <= 13))
		num_str++;
	if (*num_str == '-')
	{
		num_str++;
		sign = -sign;
	}
	else if (*num_str == '+')
		num_str++;
	while (*num_str >= '0' && *num_str <= '9')
		number = number * 10 - (*num_str++ - '0');
	return (sign * number);
}

char	*ft_itoa_base(const int64_t n, const char *base)
{
	const int64_t	sign = (n >> 63);
	const int64_t	radix = ft_strlen(base);
	char			str[66];
	char			*ptr;
	uint64_t		abs_num;

	if (radix < 2)
		return (NULL);
	abs_num = (uint64_t) ((n ^ sign) - sign);
	ptr = str + 65;
	*ptr = 0;
	if (abs_num == 0)
		*(--ptr) = base[(abs_num % radix)];
	while (abs_num != 0)
	{
		*(--ptr) = base[(abs_num % radix)];
		abs_num /= radix;
	}
	if (sign != 0)
		*(--ptr) = '-';
	return (ft_strdup(ptr));
}

int64_t	ft_atoi_base(const char *str, const char *base)
{
	const char		*start = ft_strpbrk(str, base);
	const int64_t	radix = ft_strlen(base);
	const uint64_t	sign = ((start > str) && (*(start - 1) == '-')) - 1;
	int64_t			number;
	uint8_t			lookup_table[256];

	if (start == NULL || base == NULL || radix < 2)
		return (0);
	ft_memset(lookup_table, 255, 256);
	number = -1;
	while (++number < radix)
		lookup_table[(unsigned char) base[number]] = number;
	number = 0;
	while (*start && lookup_table[(unsigned char) *start] < 255)
		number = number * radix - lookup_table[(unsigned char) *start++];
	return ((number ^ sign) - sign);
}
