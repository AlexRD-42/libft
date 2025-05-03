/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:35:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/03 08:36:27 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static inline void	ft_fwdcpy(uint8_t *dst, const uint8_t *src, size_t n)
{
	const size_t		words = n / sizeof(uintptr_t);
	const uintptr_t		*src_word;
	uintptr_t			*dst_word;

	n = n % sizeof(uintptr_t) + 1;
	while (--n > 0)
		*dst++ = *src++;
	src_word = (const uintptr_t *) src;
	dst_word = (uintptr_t *) dst;
	while (n++ < words)
		*dst_word++ = *src_word++;
}

static inline void	ft_bwdcpy(uint8_t *dst, const uint8_t *src, size_t n)
{
	const size_t		words = n / sizeof(uintptr_t *);
	const uintptr_t		*src_word;
	uintptr_t			*dst_word;

	n = n % sizeof(uintptr_t *) + 1;
	while (--n > 0)
		*--dst = *--src;
	src_word = (const uintptr_t *) src;
	dst_word = (uintptr_t *) dst;
	while (n++ < words)
		*--dst_word = *--src_word;
}

// 0. If there are less than 16 bytes to be copied, do normal byte copying
// 1. Determine copy direction and word alignment
// 2. Copy byte by byte until aligned
// 3. Copy word by word
// 4. Perform tail copy byte by byte

// Possible to index tail with word copying by and masking the excess and OR the result

static void	*ft_memrcpy(void *dst_void, const char *src, size_t length)
{
	char	*dst;

	dst = (char *) dst_void + length;
	if (length >= 16)
	{
		while (((uintptr_t)dst & (sizeof(uintptr_t) - 1)) && length-- > 0)
			*--dst = *--src;
		while (length >= sizeof(uintptr_t))
		{
			*((uintptr_t *)dst) = *((uintptr_t *)src);
			dst -= sizeof(uintptr_t);
			src -= sizeof(uintptr_t);
			length -= sizeof(uintptr_t);
		}
	}
	while (length > 0)
	{
		*--dst = *--src;
		length--;
	}
	return (dst_void);
}

void	*ft_memcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	dst = (char *) dst_void;
	while (length > 2 * sizeof(int*) && ((uintptr_t)dst & (sizeof(int*) - 1)))
	{
		*dst++ = *src++;
		length--;
	}
	while (length >= sizeof(int*))
	{
		*((uintptr_t *)dst) = *((uintptr_t *)src);
		dst += sizeof(int*);
		src += sizeof(int*);
		length -= sizeof(int*);
	}
	while (length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	return (dst_void);
}

void	*ft_memmove(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	if ((uintptr_t) dst_void > (uintptr_t) src_void)
		return (ft_memrcpy(dst_void, src + length, length));
	dst = (char *) dst_void;
	while (length > 2 * sizeof(int*) && ((uintptr_t)dst & (sizeof(int*) - 1)))
	{
		*dst++ = *src++;
		length--;
	}
	while (length >= sizeof(int*))
	{
		*((uintptr_t *)dst) = *((uintptr_t *)src);
		dst += sizeof(int*);
		src += sizeof(int*);
		length -= sizeof(int*);
	}
	while (length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	return (dst_void);
}