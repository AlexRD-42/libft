/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/08 19:36:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	char const	*osrc;

	osrc = src;
	while (*src != 0 && dst_size > 1)
	{
		*dst++ = *src++;
		dst_size--;
	}
	while (*src != 0)
		src++;
	*dst = 0;
	return (src - osrc);
}
