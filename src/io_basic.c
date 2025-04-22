/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:24:42 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 21:24:42 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr(char *str, int fd)
{
	const char	*ostr = str;

	if (fd == -1 || str == NULL)
		return ;
	while (*str != 0)
		str++;
	write(fd, ostr, str - ostr);
}

// Code duplication for itoa, so far unavoidable
void	ft_putnbr(int64_t n, int fd)
{
	const int8_t	sign = (n >= 0) - (n < 0);
	char			array[21];
	char			*ptr;

	if (fd == -1)
		return ;
	ptr = array + 20;
	*ptr = 0;
	*(--ptr) = sign * (n % 10) + '0';
	n = sign * (n / 10);
	while (n != 0)
	{
		*(--ptr) = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		*(--ptr) = '-';
	write(fd, ptr, array + 20 - ptr);
}
