/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:17:08 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 10:39:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

void	*ft_memset(void *dst_void, const uint8_t byte, size_t length);

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

// See if there is an efficient overflow handling
void	*ft_calloc(size_t arr_size, size_t type_size)
{
	void			*array;
	const size_t	total_size = arr_size * type_size;

	array = (void *) malloc (total_size);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, total_size);
	return (array);
}
