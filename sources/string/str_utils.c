/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:29:37 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 18:30:10 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

size_t	ft_count_words(const char *str, const char *charset)
{
	size_t	count;
	size_t	lookup_table[256 / sizeof(size_t)];
	uint8_t	*lut_ptr;

	lut_ptr = (uint8_t *) lookup_table;
	count = 0;
	while (count < 256 / sizeof(size_t))
		lookup_table[count++] = 0UL;
	while (*charset != 0)
		lut_ptr[*(uint8_t *) charset++] = 1u;
	while (lut_ptr[*(uint8_t *) str])
		str++;
	count = (*str != 0);
	lut_ptr[0] = 1u;
	while (*str != 0)
	{
		count += lut_ptr[(uint8_t)str[0]] && !lut_ptr[(uint8_t)str[1]];
		str++;
	}
	return (count);
}
