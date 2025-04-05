/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:46:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/05 14:46:54 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\includes\libft.h"



void	*ft_memcpy(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src;
	size_t		i;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (n == 0 || dst == src)
		return (dst_void);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst_void);
}

void	*ft_memmove(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src;
	size_t		i;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (n == 0 || dst == src)
		return (dst_void);
	if ((unsigned long) dst < (unsigned long) src)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (--n > 0)
			dst[n] = src[n];
		dst[0] = src[0];
	}
	return (dst_void);
}

void	*ft_memchr(const void *addr_void, int c, size_t n)
{
	const char	*addr;
	size_t		i;

	addr = (const char *) addr_void;
	i = 0;
	while (i < n)
	{
		if (addr[i] == (unsigned char) c)
			return ((void *) (addr + i));
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *addr1_void, const void *addr2_void, size_t n)
{
	const char	*addr1;
	const char	*addr2;
	size_t	i;

	addr1 = (const char *) addr1_void;
	addr2 = (const char *) addr2_void;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (addr1[i] != addr2[i])
			return ((unsigned char) addr1[i] - (unsigned char) addr2[i]);
		i++;
	}
	return (0);
}

void	*ft_memset(void *dst_void, int c, size_t n)
{
	char	*dst;
	size_t	i;

	dst = (char *) dst_void;
	i = 0;
	while (i < n)
	{
		dst[i] = (unsigned char) c;
		i++;
	}
	return(dst_void);
}

// --------------------------------------------------------------------------------
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

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

char	*ft_strdup(const char *str)
{
	size_t	str_size;
	char	*new_str;

	str_size = ft_strlen(str) + 1;
	new_str = (char *) malloc(str_size);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, str, str_size);
	return (new_str);
}

// --------------------------------------------------------------------------------

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

char	*ft_strchr(const char *str, int c)
{
	while (*str != 0)
	{
		if (*str == (unsigned char) c)
			return (str);
		str++;
	}
	if ((unsigned char) c == 0)
		return ((char *) str);
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{

}

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

void	ft_bzero(void *addr_void, size_t n)
{
	char *addr;

	addr = (char *) addr_void;
	while (n > 0)
		addr[--n] = 0;
}

// --------------------------------------------------------------------------------

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	str_size;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_size = s1_len + s2_len + 1;
	str = malloc (str_size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, str_size);
	return (str);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = (s[0] != c) && (s[0] != 0);
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**str_array;

	str_array = (char **) malloc(ft_count_words(s, c) + 1);
	if (str_array == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		if ((s[i] == c && s[i] != 0) || (i == 0 && s[i] != c))
		{
			j = ++i;
			while (s[i] != c && s[i] != 0)
				i++;
			if (i != j)
				str_array[k++] = ft_substr(s, j - (j == 1), i - j + (j == 1));
		}
		else
			i++;
	}
	str_array[k] = 0;
	return (str_array);
}


#include <stdio.h>
int	main(void)
{
	char *s = ",123,#4564,4444@,";
	char *c = ",#@";
	printf("%s", ft_strtrim(s, c));
}