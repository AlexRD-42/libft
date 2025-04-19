/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/19 11:54:09 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (dst == src)
		return (dst_void);
	while (n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	return (dst_void);
}

// Reallocates memory to a bigger size, copies old array
// If the old array is NULL, this is effectively just malloc
void	*ft_realloc(void *old_array, size_t old_size, size_t new_size)
{
	void	*new_array;

	new_array = (void *) malloc (new_size);
	if (new_array != NULL && old_array != NULL)
		ft_memcpy(new_array, old_array, old_size);
	free(old_array);
	return (new_array);
}
