/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/22 13:06:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *addr_void, uint8_t byte, size_t n)
{
	const unsigned char	*addr;

	addr = (const unsigned char *) addr_void;
	while (n > 0)
	{
		if (*addr == byte)
			return ((void *) addr);
		n--;
		addr++;
	}
	return (NULL);
}

