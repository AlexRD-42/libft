/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:32:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen
char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	if (c == 0)
		return ((char *) (str + len));
	while (len > 0)
	{
		len--;
		if (str[len] == (unsigned char) c)
			return ((char *) (str + len));
	}
	return (NULL);
}