/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:29:37 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/15 21:47:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <libft.h>

static inline
char	*h_cpy(char *dst, const char *src, size_t *offset, size_t length)
{
	dst = ft_memcpy(dst + *offset, src, length);
	dst[length] = 0;
	*offset += length + 1;
	return (dst);
}

// Problems: Arena malloc doesn't allow partial frees
char	**ft_split_tokens(const char *str, const char *charset)
{
	char			**array;
	const char		*ostr;
	size_t			offset;
	const size_t	count = ft_count_tokens(str, charset, &offset);
	size_t			index;

	array = malloc(offset + count + (count + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	offset = (count + 1) * sizeof(char *);
	index = 0;
	while (*str != 0)
	{
		while (*str != 0 && ft_ischarset(*str, charset) == 1)
			str++;
		ostr = str;
		while (ft_ischarset(*str, charset) == 0)
			str++;
		if (ostr != str)
			array[index++] = h_cpy((char *) array, ostr, &offset, str - ostr);
	}
	array[index] = 0;
	return (array);
}

#include <stdio.h>
int main()
{
	char **str_array;
	char str[] = "0,12,345,6789";
	char charset[] = ",.";

	str_array = ft_split_tokens(str, charset);
	size_t i = 0;
	// while (str_array[i] != NULL)
	// 	free(str_array[i++]);
	// free(str_array[i]);
	free(str_array);
	return (0);
}