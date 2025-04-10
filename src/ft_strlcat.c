/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:39 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/08 19:44:04 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	char	*odst;

	odst = dst;
	while (dst_size > 0 && *dst != 0)
	{
		dst++;
		dst_size--;
	}
	while (*src != 0 && dst_size > 1) 
	{
		*dst++ = *src++;
		dst_size--;
	}
	if (dst_size != 0)
		*dst = 0;
	while (*src++ != 0)
		dst++;
	return (dst - odst); 
}

// size_t	ft_strlcat2(char *dst, const char *src, size_t dst_size)
// {
// 	size_t	cat_len;

// 	cat_len = 0;
// 	while (cat_len < dst_size && *dst != 0)
// 	{
// 		dst++;
// 		cat_len++;
// 	}
// 	while (*src != 0 && cat_len + 1 < dst_size) 
// 	{
// 		*dst++ = *src++;
// 		cat_len++;
// 	}
// 	while (*src++ != 0)
// 		cat_len++;
// 	if (dst_size != 0)
// 		*dst = 0;
// 	return (cat_len); 
// }