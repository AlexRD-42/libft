/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:41:24 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 17:50:47 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

void	*ft_bzero(void *dst_void, size_t length)
{
	uint8_t	*dst;

	dst = (uint8_t *) dst_void;
	while (((uintptr_t)dst & (sizeof(uintptr_t) - 1)) && length > 0)
	{
		*dst++ = 0u;
		length--;
	}
	while (length >= sizeof(uintptr_t))
	{
		*((uintptr_t *)dst) = 0UL;
		dst += sizeof(uintptr_t);
		length -= sizeof(uintptr_t);
	}
	while (length > 0)
	{
		*dst++ = 0u;
		length--;
	}
	return (dst_void);
}

void	*ft_memset(void *dst_void, const uint8_t byte, size_t length)
{
	uint8_t			*dst;
	const uintptr_t	word_byte = byte * (0x0101010101010101 & UINTPTR_MAX);

	dst = (uint8_t *) dst_void;
	while (((uintptr_t)dst & (sizeof(uintptr_t) - 1)) && length > 0)
	{
		*dst++ = byte;
		length--;
	}
	while (length >= sizeof(uintptr_t))
	{
		*((uintptr_t *)dst) = word_byte;
		dst += sizeof(uintptr_t);
		length -= sizeof(uintptr_t);
	}
	while (length > 0)
	{
		*dst++ = byte;
		length--;
	}
	return (dst_void);
}

// Needs optimization
int64_t	ft_memcmp(const void *ptr1_void, const void *ptr2_void, size_t length)
{
	const uint8_t	*ptr1 = (const uint8_t *) ptr1_void;
	const uint8_t	*ptr2 = (const uint8_t *) ptr2_void;

	if (ptr1_void == ptr2_void)
		return (0);
	while (length > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		length--;
	}
	return (0);
}

int64_t	ft_memrcmp(const void *ptr1_void, const void *ptr2_void, size_t length)
{
	const uint8_t	*ptr1 = (const uint8_t *) ptr1_void + length - 1;
	const uint8_t	*ptr2 = (const uint8_t *) ptr2_void + length - 1;

	if (ptr1_void == ptr2_void)
		return (0);
	while (length > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1--;
		ptr2--;
		length--;
	}
	return (0);
}
