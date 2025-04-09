/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/08 11:50:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen
char	*ft_strrchr(const char *str, int c)
{
	size_t			len;
	unsigned char	byte;

	if (c == 0)
		return ((char *) (str + ft_strlen(str)));
	str += ft_strlen(str) - 1;
	byte = (unsigned char) c;
	while (len > 0)
	{
		if (*str == byte)
			return ((char *) str);
		len--;
		str--;	
	}
	return (NULL);
}