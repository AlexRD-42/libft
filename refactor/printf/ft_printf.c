/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:04:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/11 18:48:47 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static
ssize_t	print_nbr(uint64_t number, const char f, const char *base)
{
	const uint_fast8_t	radix = 16 - 6 * (f == 'd' || f == 'i');
	const uint_fast8_t	sign = (f == 'd' || f == 'i') && (int32_t) number < 0;
	char				buffer[32];
	char				*ptr;

	if (f == 'p' && number == 0)
		return (write(1, "(nil)", 5));
	ptr = buffer + 31;
	if (sign != 0)
		number = (uint32_t)(-(int64_t)number);
	*ptr = 0;
	while (1)
	{
		*(--ptr) = base[(number % radix)];
		number /= radix;
		if (number == 0)
			break ;
	}
	if (sign != 0)
		*(--ptr) = '-';
	else if (f == 'p')
	{
		*(--ptr) = 'x';
		*(--ptr) = '0';
	}
	return (write(1, ptr, 31 - (ptr - buffer)));
}

static
ssize_t	print_str(const char *str)
{
	const char	*ostr = str;

	if (str == NULL)
		return (write(1, "(null)", 7));
	while (*str != 0)
		str++;
	return (write(1, ostr, str - ostr));
}

static
ssize_t	parse(const char f, va_list args)
{
	static const char	base_table[2][16] = {{'0', '1', '2', '3', '4', '5', '6',
		'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'}, {'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}};
	char				c;

	if (f == 's')
		return (print_str((char *) va_arg(args, char *)));
	if (f == 'p')
		return (print_nbr(va_arg(args, uintptr_t), f, base_table[f == 'X']));
	if (f == 'd' || f == 'i' || f == 'u' || f == 'x' || f == 'X')
		return (print_nbr(va_arg(args, unsigned int), f, base_table[f == 'X']));
	if (f == 'c')
	{
		c = (char) va_arg(args, unsigned int);
		return (write(1, &c, 1));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	ssize_t		bytes;
	va_list		args;
	const char	*ostr;

	bytes = 0;
	va_start(args, str);
	while (*str != 0)
	{
		ostr = str;
		while (*str != '%' && *str != 0)
			str++;
		if (*str == '%' && *(str + 1) == '%')
		{
			bytes += write(1, ostr, str - ostr + 1);
			str += 2;
		}
		else
			bytes += write(1, ostr, str - ostr);
		if (*str == '%' && *(str + 1) != '%')
			bytes += parse(*++str, args);
		str++;
	}
	va_end(args);
	return (bytes);
}

#include <limits.h>
#include <stdio.h>

// .0 precision makes it so 0 doesn't show but != 0 shows
// precision lower than 7 makes it so null doesn't show at all
// #define test ("%.6s", NULL)
int main()
{
	ft_printf("ab%%cd%d", 50);
	printf("\n");
	// printf test;
}