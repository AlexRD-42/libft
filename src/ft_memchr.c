/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:29:46 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:29:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *addr_void, int c, size_t n)
{
	const unsigned char	*addr;
	size_t				i;

	c = (unsigned char) c;
	addr = (const unsigned char *) addr_void;
	i = 0;
	while (i < n)
	{
		if (addr[i] == c)
			return ((void *) (addr + i));
		i++;
	}
	return (NULL);
}