/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:27:20 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:53:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int32_t	sign;
	char	str[12];
	char	*ptr;

	if (fd == -1)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
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
	write(fd, ptr, ft_strlen(ptr));
}
