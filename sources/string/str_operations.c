/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:55:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/15 21:33:19 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
