/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:25:16 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 09:58:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char	*odst;

	odst = dst;
	while (*src != 0)
		*dst++ = *src++;
	*dst = 0;
	return (odst);
}

char	*ft_strncpy(char *dst, const char *src, size_t length)
{
	char	*odst;

	odst = dst;
	while (*src != 0 && length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	while (length > 0)
	{
		*dst = 0;
		dst++;
		length--;
	}
	return (odst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	const char	*osrc = src;

	while (*src != 0 && dst_size > 1)
	{
		*dst++ = *src++;
		dst_size--;
	}
	if (dst_size != 0)
		*dst = 0;
	while (*src != 0)
		src++;
	return ((size_t)(src - osrc));
}

char	*ft_strdup(const char *src)
{
	const char	*osrc = src;
	char		*str;

	while (*src != 0)
		src++;
	str = (char *) malloc((size_t)(src - osrc + 1));
	if (str == NULL)
		return (NULL);
	str += src - osrc;
	*str = 0;
	while (src > osrc)
		*--str = *--src;
	return (str);
}
