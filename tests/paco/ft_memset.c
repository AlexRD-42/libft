/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:29:32 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/03 08:31:01 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdint.h"
#include "stddef.h"

void	*ft_memset(void *dst_void, const uint8_t byte, size_t length)
{
	char	*dst;
	size_t	word_byte;

	dst = (char *) dst_void;
	if (length >= 16)
	{
		word_byte = (0x0101010101010101 & UINTPTR_MAX) * byte;
		while (((uintptr_t)dst & (sizeof(uintptr_t) - 1)) && length-- > 0)
			*dst++ = byte;
		while (length >= sizeof(uintptr_t))
		{
			*((uintptr_t *)dst) = word_byte;
			dst += sizeof(uintptr_t);
			length -= sizeof(uintptr_t);
		}
	}
	while (length > 0)
	{
		*dst++ = byte;
		length--;
	}
	return (dst_void);
}
