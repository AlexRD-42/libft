/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:31:25 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:32:49 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory and returns a substring from the string s
// Substring starts at index start and has a maximum length of len
// Return: NULL if the allocation fails
// Edge Case: Start > strlen, s == NULL, len > str_len
// Do i need to return a null that can be freed?
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= str_len)
		return (ft_strdup(""));
	str_len -= start;
	if (len > str_len)
		len = str_len;
	substr = (char *) malloc (len + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
