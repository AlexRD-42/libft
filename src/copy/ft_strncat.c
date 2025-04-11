/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:59:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 16:59:19 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*odst;

	odst = dst;
	while (*dst != 0)
		dst++;
	while (*src != 0 && n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = 0;
	return (odst);
}
