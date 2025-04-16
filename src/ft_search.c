/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:31:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 20:31:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *addr_void, uint8_t byte, size_t n)
{
	const unsigned char	*addr;

	addr = (const unsigned char *) addr_void;
	while (n > 0)
	{
		if (*addr == byte)
			return ((void *) addr);
		n--;
		addr++;
	}
	return (NULL);
}

char	*ft_strchr(const char *str, unsigned char c)
{
	if (c == 0)
		return ((char *)(str + ft_strlen(str)));
	while (*str != 0)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *str, unsigned char c)
{
	char	*end;

	end = (char *) (str + ft_strlen(str));
	if (c == 0)
		return (end);
	while (--end >= str)
	{
		if (*end == c)
			return (end);
	}
	return (NULL);
}

char	*ft_strstr(const char *str, const char *substr)
{
	size_t	substr_len;

	if (*substr == 0)
		return ((char *) str);
	substr_len = ft_strlen(substr);
	while (*str != 0)
	{
		if (ft_strncmp(str, substr, substr_len) == 0)
			return ((char *) str);
		str++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	substr_len;
	size_t	str_len;

	if (*substr == 0)
		return ((char *) str);
	substr_len = ft_strlen(substr);
	str_len = ft_strlen(str);
	if (len > str_len)
		len = str_len;
	while (len >= substr_len)
	{
		if (ft_strncmp(str, substr, substr_len) == 0)
			return ((char *) str);
		str++;
		len--;
	}
	return (NULL);
}

char *ft_strpbrk(const char *str, const char *charset)
{
	unsigned char	lookup_table[256];

	ft_memset(lookup_table, 0, 256);
	while (*charset != 0)
		lookup_table[(unsigned char) *charset++] = 1;
	while (*str != 0)
	{
		if (lookup_table[(unsigned char) *str] == 1)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
