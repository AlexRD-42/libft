/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:42:00 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/06 21:42:00 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <ft_str_create.h>

int	ft_toupper(int c)
{
	c = (unsigned char) c;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_tolower(int c)
{
	c = (unsigned char) c;
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int32_t	ft_atoi(const char *num_str)
{
	int32_t	number;

	number = 0;
	while (*num_str == 20 || (*num_str >= 9 && *num_str <= 13))
		num_str++;
	if (*num_str == '-')
	{
		num_str++;
		while (*num_str >= '0' && *num_str <= '9')
			number = number * 10 - (*num_str++ - '0');
	}
	else
	{
		while (*num_str >= '0' && *num_str <= '9')
			number = number * 10 + (*num_str++ - '0');
	}
	return (number);
}

char *ft_itoa(int32_t n)
{
	int32_t sign;
	char	str[12];
	char	*ptr;

	if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0);
	ptr = str + 11;
	*ptr = 0;
	while (n != 0)
	{
		*(--ptr) = (!sign - sign) * (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		*(--ptr) = '-';
	return (ft_strdup(ptr));
}