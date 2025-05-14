/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:35:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/13 12:42:01 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// Could create another variable to index, like i
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

static void	*ft_memrcpy(void *dst_void, const char *src, size_t length)
{
	char	*dst;

	dst = (char *) dst_void + length - 1;
	while (length > 2 * sizeof(int*) && ((uintptr_t)dst & (sizeof(int*) - 1)))
	{
		*dst-- = *src--;
		length--;
	}
	while (length >= sizeof(uintptr_t))
	{
		*((uintptr_t *)dst) = *((uintptr_t *)src);
		dst -= sizeof(uintptr_t);
		src -= sizeof(uintptr_t);
		length -= sizeof(uintptr_t);
	}
	while (length > 0)
	{
		*dst-- = *src--;
		length--;
	}
	return (dst_void);
}

void	*ft_memmove(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	if ((uintptr_t) dst_void > (uintptr_t) src_void)
		return (ft_memrcpy(dst_void, src + length - 1, length));
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
