/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/08 13:11:26 by adeimlin         ###   ########.fr       */
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

// char *	strnstr(const char *str, const char *substr, size_t len)
// {
// 	char c, sc;
// 	size_t slen;

// 	if ((c = *substr++) != '\0')
// 	{
// 		slen = ft_strlen(substr);
// 		do
// 		{
// 			do
// 			{
// 				if (len-- < 1 || (sc = *str++) == '\0')
// 					return (NULL);
// 			} while (sc != c);
// 			if (len > slen)
// 				return (NULL);
// 		} while (ft_strncmp(str, substr, slen) != 0);
// 		str--;
// 	}
// 	return ((char *)str);
// }

/* #include <string.h>
int	main(void)
{
	char *substr = "this is a string, i need to find something like T1293 in";
	char *str = "T1293";
	
	printf("%s", ft_strnstr(str, substr, 100));
	printf("\n%s", strstr(str, substr));
} */