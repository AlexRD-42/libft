/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:39 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:30:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen
// dst == null check
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	n;
	size_t	src_size;

	src_size = ft_strlen(src);
	n = 0;
	while (n < dst_size && dst[n] != 0)
		n++;
	if (n == dst_size)
		return (n + src_size);
	i = 0;
	while (i < src_size && (n + i < dst_size))
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = 0;
	return (n + src_size);
}