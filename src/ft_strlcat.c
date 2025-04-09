/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:39 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/08 19:44:04 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ret 1: how much dst walked + srclen, ret2: how much original dst walked + srclen
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	char	*odst;

	odst = dst;
	while (dst_size > 0 && *dst != 0)
	{
		dst++;
		dst_size--;
	}
	if (dst_size == 0)
		return (dst - odst + ft_strlen(src));
	while (*src != 0 && dst_size > 1) 
	{
		*dst++ = *src++;
		dst_size--;
	}
	*dst = 0;
	return (dst - odst + ft_strlen(src)); 
}

size_t	ft_strlcat2(char *dst, const char *src, size_t dst_size)
{
	char	*odst;

	odst = dst;
	while (dst_size > 0 && *dst != 0)
	{
		dst++;
		dst_size--;
	}
	while (*src != 0 && dst_size > 1) 
	{
		*dst++ = *src++;
		dst_size--;
	}
	if (dst_size != 0)
		*dst = 0;
	while (*src++ != 0)
		dst++;
	return (dst - odst); 
}

size_t	ft_strlcat3(char *dst, const char *src, size_t dst_size)
{
	size_t	cat_len;

	cat_len = 0;
	while (cat_len < dst_size && *dst != 0)
	{
		dst++;
		cat_len++;
	}
	if (dst_size == 0)
		return (cat_len + ft_strlen(src));
	cat_len += ft_strlcpy(dst, src, dst_size - cat_len);
	return (cat_len); 
}

size_t	ft_strlcat4(char *dst, const char *src, size_t dst_size)
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