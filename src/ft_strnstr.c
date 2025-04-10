/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:32:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strlen
// Finds the first occurrence of substr in str, up to i < len
// Return: str if substr is empty, NULL if no matches
// Edge Case: str == NULL, substr == NULL

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	substr_len;
	size_t	str_len;

	if (*substr == 0)
		return ((char *) str);
	substr_len = ft_strlen(substr);
	str_len = ft_strlen(str);
	if (len > str_len)
		len = str_len;
	while (len >= substr_len)
	{
		if (ft_strncmp(str, substr, substr_len) == 0)
			return ((char *) str);
		str++;
		len--;
	}
	return (NULL);
}
