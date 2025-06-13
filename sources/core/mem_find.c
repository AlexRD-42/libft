/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 18:27:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr_void, uint8_t byte, size_t length)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *) ptr_void;
	while (length > 0)
	{
		if (*ptr == byte)
			return ((void *) ptr);
		length--;
		ptr++;
	}
	return (NULL);
}

