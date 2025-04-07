/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:32:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Replace to use strchr
// ft_strlen
// Finds the first occurrence of substr in str, up to i < len
// Return: str if substr is empty, NULL if no matches
// Edge Case: str == NULL, substr == NULL

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	str_len;
	size_t	substr_len;

	if (str == NULL || substr == NULL)
		return (NULL);
	if (*substr == 0)
		return ((char *) str);
	str_len = ft_strlen(str);
	substr_len = ft_strlen(substr);
	if (substr_len > str_len)
		return (NULL);
	if (len > str_len - substr_len)
		len = str_len - substr_len;
	while (i < len)
	{
		if (ft_strncmp(str + i, substr, substr_len) == 0)
			return ((char *) (str + i));
		i++;
	}
	return (NULL);
}

/* #include <string.h>
int	main(void)
{
	char *substr = "this is a string, i need to find something like T1293 in";
	char *str = "T1293";
	
	printf("%s", ft_strnstr(str, substr, 100));
	printf("\n%s", strstr(str, substr));
} */