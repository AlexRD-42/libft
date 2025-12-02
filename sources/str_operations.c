/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:55:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 09:43:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

void	*ft_memset(void *vdst, const uint8_t byte, size_t length);

// Pointer cast is necessary otherwise caller would need to cast void **
void	**ft_free_array(void *array, size_t length)
{
	if (array == NULL)
		return (NULL);
	while (length-- > 0)
	{
		free(((void **) array)[length]);
		((void **) array)[length] = NULL;
	}
	free(array);
	return (NULL);
}

// Before substr is allocated, it is used as a temp variable to store
// the starting position of (str + start), to limit the max length
char	*ft_substr(const char *str, size_t start, size_t length)
{
	const char	*str_offset = str + start;
	char		*substr;

	if (str == NULL)
		return (NULL);
	while (*str != 0)
		str++;
	if (str_offset > str)
		return (NULL);
	if (str_offset + length > str)
		length = (size_t)(str - str_offset);
	str = str_offset + length;
	substr = (char *) malloc (length + 1);
	if (substr == NULL)
		return (NULL);
	substr += length;
	*substr = 0;
	while (length > 0)
	{
		*--substr = *--str;
		length--;
	}
	return (substr);
}

// (end - 1) to avoid segfault and to not use the null terminator as LUT index
char	*ft_strtrim(const char *str, const char *charset)
{
	char		*new_str;
	const char	*end;
	uint8_t		lookup_table[256];

	ft_memset(lookup_table, 0, 256);
	while (*charset != 0)
		lookup_table[*(const uint8_t *) charset++] = 1;
	while (lookup_table[*(const uint8_t *) str] != 0)
		str++;
	end = str;
	while (*end != 0)
		end++;
	while ((end - 1) > str && lookup_table[(uint8_t) *(end - 1)] != 0)
		end--;
	new_str = (char *) malloc((size_t)(end - str + 1));
	if (new_str == NULL)
		return (NULL);
	new_str += end - str;
	*new_str = 0;
	while (end > str)
		*--new_str = *--end;
	return (new_str);
}

size_t	ft_count_words(const char *str, const char c)
{
	size_t	count;

	count = 0;
	while (*str == c && *str != 0)
		str++;
	count = (*str != 0);
	while (*str != 0)
	{
		count += (str[0] == c) && (str[1] != c) && (str[1] != 0);
		str++;
	}
	return (count);
}

char	**ft_split(const char *str, const char c)
{
	char		**str_array;
	const char	*ostr;
	size_t		count;

	count = ft_count_words(str, c);
	str_array = malloc(sizeof(char *) * (count + 1));
	if (str_array == NULL)
		return (NULL);
	count = 0;
	while (*str != 0)
	{
		while (*str == c && *str != 0)
			str++;
		ostr = str;
		while (*str != c && *str != 0)
			str++;
		if (ostr != str)
			str_array[count++] = ft_substr(ostr, 0, (size_t)(str - ostr));
		if (str_array[count - (count != 0)] == NULL)
			return ((char **) ft_free_array(str_array, count));
	}
	str_array[count] = NULL;
	return (str_array);
}
