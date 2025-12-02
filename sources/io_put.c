/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:24:42 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 10:31:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

ssize_t	ft_putstr_fd(char *str, int fd)
{
	ssize_t	bytes;
	size_t	length;

	if (fd < 0 || str == NULL)
		return (-1);
	length = 0;
	while (str[length] != 0)
		length++;
	bytes = write(fd, str, length);
	return (bytes);
}

// Code duplication for itoa, so far unavoidable
// Check if write return is correct
ssize_t	ft_putnbr_fd(int64_t number, int fd)
{
	const int64_t	sign = (number >= 0) - (number < 0);
	char			buffer[32];
	char			*ptr;

	if (fd < 0)
		return (-1);
	ptr = buffer + 31;
	*(ptr) = sign * (number % 10) + '0';
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

void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (fd == -1 || s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
