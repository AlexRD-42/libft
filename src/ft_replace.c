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

size_t	ft_replace(char *str, unsigned char old_char, unsigned char new_char)
{
	size_t	count;

	count = 0;
	while (*str != 0)
	{
		if (*str == old_char)
		{
			*str = new_char;
			count++;
		}
		str++;
	}
	return (count);
}

// Memset is int because of word copying
void	*ft_memset(void *dst_void, uint8_t byte, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *) dst_void;
	while (n > 0)
	{
		*dst = byte;
		dst++;
		n--;
	}
	return (dst_void);
}
