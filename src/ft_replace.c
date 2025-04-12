/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:51:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 17:51:19 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_replace(char *str, unsigned char to_find, unsigned char c)
{
	size_t	count;

	count = 0;
	while (*str != 0)
	{
		if (*str == to_find)
		{
			*str = c;
			count++;
		}
		str++;
	}
	return (count);
}

void	*ft_memset(void *dst_void, int c, size_t n)
{
	char			*dst;
	unsigned char	byte;

	dst = (char *) dst_void;
	byte = (unsigned char) c;
	while (n > 0)
	{
		*dst = byte;
		dst++;
		n--;
	}
	return (dst_void);
}

void	ft_bzero(void *addr_void, size_t n)
{
	ft_memset(addr_void, 0, n);
}
