/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:53 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/01 19:17:15 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dst_void, size_t size)
{
	char	*dst;

	dst = (char *) dst_void;
	if (size >= 16)
	{
		while (((uintptr_t)dst & (sizeof(uintptr_t) - 1)) && size-- > 0)
			*dst++ = 0;
		while (size >= sizeof(uintptr_t))
		{
			*((uintptr_t *)dst) = 0;
			dst += sizeof(uintptr_t);
			size -= sizeof(uintptr_t);
		}
	}
	while (size > 0)
	{
		*dst++ = 0;
		size--;
	}
	return (dst_void);
}
