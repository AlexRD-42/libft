/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:55:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/10/15 15:15:54 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_memory.h"
#include <stdlib.h>

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
	new_str = (char *) malloc(end - str + 1);
	if (new_str == NULL)
		return (NULL);
	new_str += end - str;
	*new_str = 0;
	while (end > str)
		*--new_str = *--end;
	return (new_str);
}

size_t	ft_replace(char *str, unsigned char old_char, unsigned char new_char)
{
	size_t	count;

	count = 0;
	while (*str != 0)
	{
		if (*str == old_char)
		{
			*str = new_char;
			count++;
		}
		str++;
	}
	return (count);
}
