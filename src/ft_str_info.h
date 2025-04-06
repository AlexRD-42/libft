/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:32:46 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/06 21:32:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

// Possible that start exceeds s
char	*ft_strchr(const char *str, int c)
{
	c = (unsigned char) c;
	if (c == 0)
		return ((char *) (str + ft_strlen(str)));
	while (*str != 0)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	char	*match;

	c = (unsigned char) c;
	if (c == 0)
		return ((char *) (str + ft_strlen(str)));
	match = NULL;
	while (*str != 0)
	{
		if (*str == c)
			match = (char *) str;
		str++;
	}
	return (match);
}

// Replace to use strchr
char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	size_t	substr_len;

	str_len = ft_strlen(str);
	substr_len = ft_strlen(substr);
	if (*substr == 0)
		return ((char *) str);
	if (substr_len > str_len || substr_len > len)
		return (NULL);
	if (str_len - substr_len < len)
		len = str_len - substr_len;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i + j] == substr[j] && j < substr_len)
			j++;
		if (j == substr_len)
			return ((char *) (str + i));
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		if (str1[i] == 0 || str2[i] == 0)
			break;
		i++;
	}
	return (0);
}