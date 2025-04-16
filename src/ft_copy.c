/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:41:24 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 20:41:24 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (dst == src)
		return (dst_void);
	while (n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	return (dst_void);
}

void	*ft_memmove(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (n == 0 || dst == src)
		return (dst_void);
	if ((uintptr_t) dst < (uintptr_t) src)
	{
		while (n > 0)
		{
			n--;
			*dst++ = *src++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			dst[n] = src[n];
		}
	}
	return (dst_void);
}

void	*ft_calloc(size_t arr_size, size_t type_size)
{
	void	*array;

	array = (void *) malloc (arr_size * type_size);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, type_size * arr_size);
	return (array);
}
