/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:55:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/23 00:59:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**ft_checkstr(char **str_array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (str_array[i] == NULL)
			break ;
		i++;
	}
	if (i == count)
		return (str_array);
	i = 0;
	while (i < count)
	{
		if (str_array[i] != NULL)
			free(str_array[i]);
		i++;
	}
	free(str_array);
	return (NULL);
}

// Malloc with strlen / c occurences
char	**ft_split(const char *s, char c)
{
	char		**str_array;
	int64_t		len;
	size_t		count;

	len = 0;
	count = (s[0] != c && s[0] != 0) || (s[0] == c && s[(*s != 0)] != c);
	while (s[len++] != 0)
		count += s[len] == c && s[len + 1] != c && s[len + 1] != 0;
	str_array = malloc((count + 1) * sizeof(char *));
	count = 0;
	if (str_array == NULL)
		return (NULL);
	while (*s != 0)
	{
		len = ft_strchr(s, c) - s;
		len = (len < 0) * ft_strlen(s) + (len > 0) * len;
		if (len > 0)
			str_array[count++] = ft_substr(s, 0, len);
		s += (s[len] != 0) + len;
	}
	str_array[count] = 0;
	return (ft_checkstr(str_array, count));
}

// (end - 1) to avoid segfault and to not use the null terminator as LUT index
char	*ft_strtrim(const char *str, const char *charset)
{
	char		*new_str;
	const char	*end;
	uint8_t		lookup_table[256];

	ft_memset(lookup_table, 0, 256);
	while (*charset != 0)
		lookup_table[(uint8_t) *charset++] = 1;
	while (lookup_table[(uint8_t) *str] != 0)
		str++;
	end = str;
	while (*end != 0)
		end++;
	while ((end - 1) > str && lookup_table[(uint8_t) *(end - 1)] != 0)
		end--;
	new_str = (char *) malloc(end - str + 1);
	if (new_str == NULL)
		return (NULL);
	new_str += end - str;
	*new_str = 0;
	while (end > str)
		*--new_str = *--end;
	return (new_str);
}