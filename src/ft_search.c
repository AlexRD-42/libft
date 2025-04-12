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

void	*ft_memchr(const void *addr_void, int c, size_t n)
{
	const unsigned char	*addr;
	unsigned char		byte;

	byte = (unsigned char) (c & 0xFF);
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

char	*ft_strchr(const char *str, int c)
{
	unsigned char	byte;

	byte = (unsigned char) (c & 0x7F);
	if (byte == 0)
		return ((char *)(str + ft_strlen(str)));
	while (*str != 0)
	{
		if (*str == byte)
			return ((char *) str);
		str++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	size_t			len;
	unsigned char	byte;

	byte = (unsigned char) (c & 0x7F);
	len = ft_strlen(str);
	if (byte == 0)
		return ((char *)(str + len));
	while (len > 0)
	{
		len--;
		if (str[len] == byte)
			return ((char *) str + len);
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
