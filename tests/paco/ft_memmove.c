/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:29:05 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 18:19:37 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static
void	*ft_memrcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void + length;

	if ((uintptr_t) dst_void == (uintptr_t) src_void)
		return (dst_void);
	dst = ((char *) dst_void) + length;
	while (length > sizeof(uintptr_t) &&\
		(((uintptr_t)dst | (uintptr_t)src) & (sizeof(uintptr_t) - 1)))
	{
		*--dst = *--src;
		length--;
	}
	while (length >= sizeof(uintptr_t))
	{
		dst -= sizeof(uintptr_t);
		src -= sizeof(uintptr_t);
		length -= sizeof(uintptr_t);
		*((uintptr_t *)dst) = *((uintptr_t *)src);
	}
	while (length > 0)
	{
		*--dst = *--src;
		length--;
	}
	return (dst_void);
}

void	*ft_memmove(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	if ((uintptr_t) dst_void >= (uintptr_t) src_void)
		return (ft_memrcpy(dst_void, src_void, length));
	dst = (char *) dst_void;
	while (length > sizeof(uintptr_t) &&\
	(((uintptr_t)dst | (uintptr_t)src) & (sizeof(uintptr_t) - 1)))
	{
		*dst++ = *src++;
		length--;
	}
	while (length >= sizeof(uintptr_t))
	{
		*((uintptr_t *)dst) = *((uintptr_t *)src);
		dst += sizeof(uintptr_t);
		src += sizeof(uintptr_t);
		length -= sizeof(uintptr_t);
	}
	while (length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	return (dst_void);
}

// void	*ft_memmove(void *dst_void, const void *src_void, size_t length)
// {
// 	char		*dst;
// 	const char	*src = (const char *) src_void;

// 	dst = (char *) dst_void;
// 	if ((uintptr_t) dst == (uintptr_t) src)
// 		return (dst_void);
// 	if ((uintptr_t) dst_void < (uintptr_t) src_void)
// 	{
// 		while (length > 2 * sizeof(int*) && ((uintptr_t)dst & (sizeof(int*) - 1)))
// 		{
// 			*dst++ = *src++;
// 			length--;
// 		}
// 		while (length >= sizeof(int*))
// 		{
// 			*((uintptr_t *)dst) = *((uintptr_t *)src);
// 			dst += sizeof(int*);
// 			src += sizeof(int*);
// 			length -= sizeof(int*);
// 		}
// 		while (length > 0)
// 		{
// 			*dst++ = *src++;
// 			length--;
// 		}
// 	}
// 	else
// 	{
// 		src += length;
// 		dst += length;
// 		while (length > 2 * sizeof(int*) && ((uintptr_t)dst & (sizeof(int*) - 1)))
// 		{
// 			*--dst = *--src;
// 			length--;
// 		}
// 		while (length >= sizeof(uintptr_t))
// 		{
// 			dst -= sizeof(uintptr_t);
// 			src -= sizeof(uintptr_t);
// 			length -= sizeof(uintptr_t);
// 			*((uintptr_t *)dst) = *((uintptr_t *)src);
// 		}
// 		while (length > 0)
// 		{
// 			*--dst = *--src;
// 			length--;
// 		}
// 	}
// 	return (dst_void);
// }
