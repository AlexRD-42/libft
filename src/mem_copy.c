/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/14 09:39:21 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

void	*ft_memrcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = ((const char *) src_void) + length;

	dst = ((char *) dst_void) + length;
	while (length > sizeof(int *) && ((uintptr_t)dst & (sizeof(int *) - 1)))
	{
		*--dst = *--src;
		length--;
	}
	while (length >= sizeof(int *))
	{
		dst -= sizeof(int *);
		src -= sizeof(int *);
		length -= sizeof(int *);
		*((uintptr_t *)dst) = *((uintptr_t *)src);
	}
	while (length > 0)
		*--dst = *--src;
	return (dst_void);
}

void	*ft_memcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	if ((uintptr_t) dst_void > (uintptr_t) src_void)
		return (ft_memrcpy(dst_void, src_void, length));
	else if ((uintptr_t) dst_void < (uintptr_t) src_void)
	{
		dst = (char *) dst_void;
		while (length > sizeof(int *) && ((uintptr_t)dst & (sizeof(int *) - 1)))
		{
			*dst++ = *src++;
			length--;
		}
		while (length >= sizeof(int *))
		{
			*((uintptr_t *)dst) = *((uintptr_t *)src);
			dst += sizeof(int *);
			src += sizeof(int *);
			length -= sizeof(int *);
		}
		while (length-- > 0)
			*dst++ = *src++;
	}
	return (dst_void);
}
