/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:24:42 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 09:38:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

// Hacky but efficient. Warning: DO NOT USE WITH READ-ONLY
ssize_t	ft_putstr(char *str, int fd, char c)
{
	ssize_t	bytes;
	size_t	length;

	if (fd < 0 || str == NULL)
		return (-1);
	length = 0;
	while (str[length] != 0)
		length++;
	if (c != 0)
	{
		str[length] = c;
		bytes = write(fd, str, length + 1);
		str[length] = 0;
	}
	else
		bytes = write(fd, str, length);
	return (bytes);
}

// Code duplication for itoa, so far unavoidable
// Check if write return is correct
ssize_t	ft_putnbr(int64_t number, int fd, char c)
{
	const int64_t	sign = (number >= 0) - (number < 0);
	char			buffer[32];
	char			*ptr;

	if (fd < 0)
		return (-1);
	ptr = buffer + 31;
	if (c != 0)
		*(--ptr) = c;
	*(--ptr) = sign * (number % 10) + '0';
	number = sign * (number / 10);
	while (number != 0)
	{
		*(--ptr) = (number % 10) + '0';
		number /= 10;
	}
	if (sign < 0)
		*(--ptr) = '-';
	return (write(fd, ptr, 32 - (uintptr_t)(ptr - buffer)));
}
