/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:28:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// ft_bzero
void	*ft_calloc(size_t array_size, size_t data_size)
{
	void	*array;

	// need to pass unique info
	if (array_size == 0 || data_size == 0)
		return (NULL);
	array = (void *) malloc (array_size * data_size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, data_size * array_size);
	return (array);
}