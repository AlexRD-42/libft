/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:29:37 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 18:34:49 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

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

// size_t	ft_count_tokens(const char *str, const char *charset, size_t *bytes)
// {
// 	size_t	bytes_local;
// 	size_t	count;
// 	size_t	lookup_table[256 / sizeof(size_t)];
// 	uint8_t	*lut_ptr;

// 	lut_ptr = (uint8_t *) lookup_table;
// 	count = 0;
// 	bytes_local = 0;
// 	while (count < 256 / sizeof(size_t))
// 		lookup_table[count++] = 0UL;
// 	while (*charset != 0)
// 		lut_ptr[*(const uint8_t *) charset++] = 1u;
// 	while (lut_ptr[*(const uint8_t *) str])
// 		str++;
// 	count = (*str != 0);
// 	lut_ptr[0] = 1u;
// 	while (*str != 0)
// 	{
// 		count += lut_ptr[(uint8_t)str[0]] && !lut_ptr[(uint8_t)str[1]];
// 		bytes_local += !lut_ptr[(uint8_t)str[0]];
// 		str++;
// 	}
// 	if (bytes != NULL)
// 		*bytes = bytes_local;
// 	return (count);
// }

size_t	ft_count_tokens(const char *str, const uint8_t *lut, size_t *bytes)
{
	const uint8_t	*ustr = (const uint8_t *) str;
	size_t			bytes_local;
	size_t			count;

	bytes_local = 0;
	while (lut[*ustr] == 1)
		ustr++;
	count = *ustr != 0;
	while (*ustr != 0)
	{
		count += lut[ustr[0]] && !lut[ustr[1]];
		bytes_local += !lut[ustr[0]];
		ustr++;
	}
	if (bytes != NULL)
		*bytes = bytes_local;
	return (count);
}
