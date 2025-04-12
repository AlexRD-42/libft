/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:25:16 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 20:25:16 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*odst;

	odst = dst;
	while (*src != 0)
		*dst++ = *src++;
	*dst = 0;
	return (odst);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*odst;

	odst = dst;
	while (*src != 0 && n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dst = 0;
		dst++;
		n--;
	}
	return (odst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	char const	*osrc;

	osrc = src;
	while (*src != 0 && dst_size > 1)
	{
		*dst++ = *src++;
		dst_size--;
	}
	if (dst_size != 0)
		*dst = 0;
	while (*src != 0)
		src++;
	return (src - osrc);
}

char	*ft_strdup(const char *str)
{
	size_t	str_size;
	char	*new_str;

	str_size = ft_strlen(str) + 1;
	new_str = (char *) malloc(str_size);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, str, str_size);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= str_len)
		return (ft_strdup(""));
	str_len -= start;
	if (len > str_len)
		len = str_len;
	substr = (char *) malloc (len + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
