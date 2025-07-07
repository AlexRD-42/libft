/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:55:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:38:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_memory.h"
#include "libft_utils.h"
#include "libft_iostream.h"
#include <stdlib.h>

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
			str_array[count++] = ft_substr(ostr, 0, str - ostr);
		if (str_array[count - (count != 0)] == NULL)
			return ((char **) ft_free_array(str_array, count));
	}
	str_array[count] = NULL;
	return (str_array);
}

// Null terminate this you baboon
char	**ft_arena_split(const char *str, const char *charset, size_t *count)
{
	char			**array;
	char			*offset;
	size_t			length;
	uint8_t			lut[256];
	const size_t	words = ft_count_tokens(str, ft_setlut256(lut, charset), &length);

	array = malloc(length + words * (sizeof(char *) + 1));
	if (array == NULL)
		return (NULL);
	offset = (char *) array + words * sizeof(char *);
	*count = 0;
	while (*str != 0)
	{
		while (*str != 0 && ft_ischarset(*str, charset) == 1)
			str++;
		length = 0;
		while (ft_ischarset(str[length], charset) == 0)
			length++;
		if (length == 0)
			break ;
		array[*count] = ft_memcpy(offset, str, length);
		array[(*count)++][length] = 0;
		offset += length + 1;
		str += length;
	}
	return (array);
}

// Change this back to uint32_t once you figured out strtoull
int32_t	*ft_split_numbers(const char *str, const char *charset, size_t *count)
{
	int32_t			*array;
	size_t			length;
	uint8_t			lut[256];
	const uint8_t	*ustr = (const uint8_t *) str;
	const size_t	tokens = ft_count_tokens(str, ft_setlut256(lut, charset), NULL);

	array = malloc(tokens * sizeof(int32_t));
	if (array == NULL)
		return (NULL);
	*count = 0;
	while (*ustr != 0)
	{
		while (lut[*ustr] == 1)
			ustr++;
		length = 0;
		while (lut[ustr[length]] == 0)
			length++;
		if (length == 0)
			break ;
		array[(*count)++] = ft_atoi((const char *) ustr);
		ustr += length;
	}
	return (array);
}
