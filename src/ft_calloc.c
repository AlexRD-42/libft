/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/08 13:50:59 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// ft_bzero
void	*ft_calloc(size_t arr_size, size_t type_size)
{
	void	*array;

	array = (void *) malloc (arr_size * type_size + !(arr_size && type_size));
	if (array == NULL)
		return (NULL);
	ft_bzero(array, type_size * arr_size);
	return (array);
}