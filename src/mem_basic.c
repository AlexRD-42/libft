/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:41:24 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/03 08:33:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_bzero(void *dst_void, size_t length)
{
	char	*dst;

	dst = (char *) dst_void;
	while (((uintptr_t)dst & (sizeof(void*) - 1)) && length > 0)
	{
		*dst++ = 0;
		length--;
	}
	while (length >= sizeof(void*))
	{
		*((uintptr_t *)dst) = 0;
		dst += sizeof(void*);
		length -= sizeof(void*);
	}
	while (length > 0)
	{
		*dst++ = 0;
		length--;
	}
	return (dst_void);
}

// Maybe remove the length check
void	*ft_memset(void *dst_void, const uint8_t byte, size_t length)
{
	char	*dst;
	size_t	word_byte;

	dst = (char *) dst_void;
	if (length >= 16)
	{
		word_byte = (0x0101010101010101 & UINTPTR_MAX) * byte;
		while (((uintptr_t)dst & (sizeof(void*) - 1)) && length-- > 0)
			*dst++ = byte;
		while (length >= sizeof(void*))
		{
			*((uintptr_t *)dst) = word_byte;
			dst += sizeof(void*);
			length -= sizeof(void*);
		}
	}
	while (length > 0)
	{
		*dst++ = byte;
		length--;
	}
	return (dst_void);
}

int32_t	ft_memcmp(const void *addr1_void, const void *addr2_void, size_t length)
{
	const uint8_t	*addr1 = (const uint8_t *) addr1_void;
	const uint8_t	*addr2 = (const uint8_t *) addr2_void;

	if (addr1_void == addr2_void)
		return (0);
	while (length > 0)
	{
		if (*addr1 != *addr2)
			return (*addr1 - *addr2);
		addr1++;
		addr2++;
		length--;
	}
	return (0);
}

int32_t	ft_memrcmp(const void *addr1_void, const void *addr2_void, size_t length)
{
	const uint8_t	*addr1 = (const uint8_t *) addr1_void + length - 1;
	const uint8_t	*addr2 = (const uint8_t *) addr2_void + length - 1;

	if (addr1_void == addr2_void)
		return (0);
	while (length > 0)
	{
		if (*addr1 != *addr2)
			return (*addr1 - *addr2);
		addr1--;
		addr2--;
		length--;
	}
	return (0);
}
