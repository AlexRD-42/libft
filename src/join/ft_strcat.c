/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:48:53 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 12:48:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char	*odst;

	odst = dst;
	while (*dst != 0)
		dst++;
	while (*src != 0)
		*dst++ = *src++;
	*dst = 0;
	return (odst);
}