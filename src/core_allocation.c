/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_allocation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:41:24 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/22 13:52:21 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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

// Reallocates memory to a bigger size, copies old array
// If the old array is NULL, this is effectively just malloc
void	*ft_realloc(void *old_array, size_t old_size, size_t new_size)
{
	void	*new_array;

	new_array = (void *) malloc (new_size);
	if (new_array != NULL)
	{
		*((uint8_t *) new_array) = 0;
		if (old_array != NULL)
			ft_memcpy(new_array, old_array, old_size);
	}
	free(old_array);
	return (new_array);
}
