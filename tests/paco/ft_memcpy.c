/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:29:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/14 17:00:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Could remove the check
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	dst = (char *) dst_void;
	if (dst_void == src_void)
		return (dst_void);
	while (length > sizeof(void*) && ((uintptr_t)dst & (sizeof(void*) - 1)))
	{
		*dst++ = *src++;
		length--;
	}
	while (length >= sizeof(void*))
	{
		*((uintptr_t *)dst) = *((uintptr_t *)src);
		dst += sizeof(void*);
		src += sizeof(void*);
		length -= sizeof(void*);
	}
	while (length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	return (dst_void);
}
