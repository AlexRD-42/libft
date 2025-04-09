/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/08 19:36:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen
// dst == NULL check
// size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
// {
// 	size_t	i;
// 	size_t	src_size;

// 	src_size = ft_strlen(src);
// 	if (dst_size == 0)
// 		return (src_size);
// 	i = 0;
// 	while (i < src_size && i < dst_size - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = 0;
// 	return (src_size);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	char const	*osrc;

	osrc = src;
	while (*src != 0 && dst_size > 1)
	{
		*dst++ = *src++;
		dst_size--;
	}
	while (*src != 0)
		src++;
	*dst = 0;
	return (src - osrc);
}

size_t	ft_strlcpy2(char *dst, const char *src, size_t dsize)
{
	const char *osrc = src;
	size_t nleft = dsize;

	/* Copy as many bytes as will fit. */
	if (nleft != 0) 
	{
		while (--nleft != 0) 
		{
			if ((*dst++ = *src++) == 0)
				break;
		}
	}
	/* Not enough room in dst, add NUL and traverse rest of src. */
	if (nleft == 0) {
		if (dsize != 0)
			*dst = 0;		/* NUL-terminate dst */
		while (*src++)
			;
	}

	return(src - osrc - 1);	/* count does not include NUL */
}