/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:33:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/22 12:47:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char	*odst;

	odst = dst;
	while (*dst != 0)
		dst++;
	while (*src != 0)
		*dst++ = *src++;
	*dst = 0;
	return (odst);
}

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*odst;

	odst = dst;
	while (*dst != 0)
		dst++;
	while (*src != 0 && n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = 0;
	return (odst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
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

char	*ft_strjoin(const char *src1, const char *src2)
{
	const char	*osrc1 = src1;
	const char	*osrc2 = src2;
	char		*str;
	size_t		len;

	if (src1 == NULL || src2 == NULL)
		return (NULL);
	while (*src1 != 0)
		src1++;
	while (*src2 != 0)
		src2++;
	len = (src1 - osrc1) + (src2 - osrc2);
	str = (char *) malloc (len + 1);
	if (str == NULL)
		return (NULL);
	str += len;
	*str = 0;
	while (src2 > osrc2)
		*--str = *--src2;
	while (src1 > osrc1)
		*--str = *--src1;
	return (str);
}
