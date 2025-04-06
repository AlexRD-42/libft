/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_create.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:37:32 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/06 21:37:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include "ft_str_info.h"
#include <stdlib.h>

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

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	n;
	size_t	src_size;

	src_size = ft_strlen(src);
	n = 0;
	while (n < dst_size && dst[n] != 0)
		n++;
	if (n == dst_size)
		return (n + src_size);
	i = 0;
	while (i < src_size && (n + i < dst_size))
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = 0;
	return (n + src_size);
}

// check if strlcpy is fine
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
	size_t	i;

	i = 0;
	while (s[i + start] != 0 && i < len)
		i++;
	substr = (char *) malloc (i + 1);
	if (substr == NULL)
		return (NULL);
	substr[i] = 0;
	while (i > 0)
	{
		i--;
		substr[i] = s[i + start];
	}
	return (substr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;
	char	*new_str;

	i = 0;
	count = 0;
	while (s1[i] != 0)
	{
		if (ft_strchr(set, s1[i]) != NULL)
			count++;
		i++;
	}
	new_str = (char *) malloc (i - count + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*s1 != 0)
	{
		if (ft_strchr(set, *s1) == NULL)
			new_str[i++] = *s1;
		s1++;
	}
	new_str[i] = 0;
	return (new_str);
}