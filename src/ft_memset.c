/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:29:32 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:29:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst_void, int c, size_t n)
{
	char	*dst;

	dst = (char *) dst_void;
	while (n > 0)
	{
		n--;
		dst[n] = (unsigned char) c;
	}
	return (dst_void);
}