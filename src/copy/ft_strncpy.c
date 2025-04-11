/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:58:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 16:58:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*odst;

	odst = dst;
	while (*src != 0 && n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dst = 0;
		dst++;
		n--;
	}
	return (odst);
}
