/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:39 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:30:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen
// dst == null check
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	n;
	size_t	src_len;

	src_len = ft_strlen(src);
	n = 0;
	while (n < dst_size && dst[n] != 0)
		n++;
	if (n == dst_size)
		return (n + src_len);
	i = 0;
	while (i < src_len && (n + i < dst_size))
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = 0;
	return (n + src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	while (dst_size > 0 && *dst != 0)
	{
		dst_size--;
		dst++;
	}
	if (dst_size == 0)
		return (src_len);
	while (*src != 0 && --dst_size > 0)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return (src_len);
}

size_t	strlcat(char *dst, const char *src, size_t dst_size)
{
	const char	*odst;
	size_t		n;
	size_t		src_len;
	size_t		dst_len;

	odst = dst;
	src_len = ft_strlen(src);
	n = dst_size;
	while (n-- != 0 && *dst != 0)
		dst++;
	dst_len = dst - odst;
	n = dst_size - dst_len;
	if (n == 0)
		return(dst_len + src_len);
	while (*src != 0 && --n > 0)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = 0;
	return(dst_len + src_len);
}