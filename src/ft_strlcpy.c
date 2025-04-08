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
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dst_size == 0)
		return (src_size);
	i = 0;
	while (i < src_size && i < dst_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_size);
}

// size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
// {
// 	const char	*osrc;

// 	osrc = src;
// 	if (dst_size == 0)
// 		return (ft_strlen(src));
// 	while (*src != 0 && --dst_size > 0)
// 	{
// 		*dst = *src;
// 		dst++;
// 		src++;
// 	}
// 	*dst = 0;
// 	return (src - osrc);
// }