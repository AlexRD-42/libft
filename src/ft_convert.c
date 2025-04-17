/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:30 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/17 15:52:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Performs bitwise manipulation to compute abs of n without overflowing
// str[66] to hold all digits of a 64 bit signed integer with base 2
// Negative sign might not be appropriate for binary or hex
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

char	*ft_itoa(const int64_t n)
{
	return (ft_itoa_base(n, "0123456789"));
}

int64_t	ft_atoi(const char *num_str)
{
	int64_t	number;
	int64_t	sign;

	number = 0;
	sign = -1;
	while (ft_isspace(*num_str))
		num_str++;
	if (*num_str == '-')
	{
		num_str++;
		sign = -sign;
	}
	else if (*num_str == '+')
		num_str++;
	while (ft_isdigit(*num_str))
		number = number * 10 - (*num_str++ - '0');
	return (sign * number);
}

// init to 0?   
// int64_t	ft_atoi_base(const char *str, const char *base)
// {
// 	const char		*start = ft_strpbrk(str, base);
// 	const int64_t	radix = ft_strlen(base);
// 	const uint64_t	sign = ((start > str) && (*(start - 1) == '-')) - 1;
// 	int64_t			number;
// 	uint8_t			lookup_table[256];

// 	if (start == NULL || base == NULL || radix < 2)
// 		return (0);
// 	ft_memset(lookup_table, 255, 256);
// 	number = -1;
// 	while (++number < radix)
// 		lookup_table[(unsigned char) base[number]] = number;
// 	number = 0;
// 	while (*start && lookup_table[(unsigned char) *start] < 255)
// 		number = number * radix - lookup_table[(unsigned char) *start++];
// 	return ((number ^ sign) - sign);
// }

// int64_t	ft_atoi_base(const char *num_str, const char *base)
// {
// 	int64_t			number;
// 	int8_t			sign;
// 	const int64_t	radix = ft_strlen(base);
// 	int8_t			lookup_table[128];

// 	ft_memset(lookup_table, 0, 128);
// 	number = -1;
// 	while (++number < radix)
// 		lookup_table[(unsigned char) base[number]] = number;
// 	number = 0;
// 	sign = -1;
// 	while (ft_isspace(*num_str))
// 		num_str++;
// 	if (*num_str == '-')
// 	{
// 		num_str++;
// 		sign = -sign;
// 	}
// 	else if (*num_str == '+')
// 		num_str++;
// 	while (*num_str && lookup_table[(unsigned char) *num_str] != 0)
// 		number = number * radix - lookup_table[(unsigned char) *num_str++];
// 	return (sign * number);
// }

// int main()
// {
// 	int x = ft_atoi_base("FFFF", "0123456789ABCDEF");
// }