/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:30 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:32:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen
char	*ft_strchr(const char *str, int c)
{
	unsigned char	byte;

	if (c == 0)
		return ((char *) (str + ft_strlen(str)));
	byte = (unsigned char) c;
	while (*str != 0)
	{
		if (*str == byte)
			return ((char *) str);
		str++;
	}
	return (NULL);
}