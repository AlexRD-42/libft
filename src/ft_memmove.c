/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:29:05 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:29:05 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src;
	size_t		i;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (n == 0 || dst == src)
		return (dst_void);
	if ((uintptr_t) dst < (uintptr_t) src)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (--n > 0)
			dst[n] = src[n];
		dst[0] = src[0];
	}
	return (dst_void);
}