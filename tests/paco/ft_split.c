/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:35:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/15 21:23:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_free_array(void *array, size_t length)
{
	if (array == NULL)
		return (NULL);
	while (length-- > 0)
	{
		free(((void **) array)[length]);
		((void **) array)[length] = NULL;
	}
	free(array);
	return (NULL);
}

size_t	ft_count_words(const char *str, const char c)
{
	size_t	count;

	count = 0;
	while (*str == c && *str != 0)
		str++;
	count = (*str != 0);
	while (*str != 0)
	{
		count += (str[0] == c) && (str[1] != c) && (str[1] != 0);
		str++;
	}
	return (count);
}

char	**ft_split(const char *str, const char c)
{
	char		**str_array;
	const char	*ostr;
	size_t		count;

	count = ft_count_words(str, c);
	str_array = malloc(sizeof(char *) * (count + 1));
	if (str_array == NULL)
		return (NULL);
	count = 0;
	while (*str != 0)
	{
		while (*str == c && *str != 0)
			str++;
		ostr = str;
		while (*str != c && *str != 0)
			str++;
		if (ostr != str)
			str_array[count++] = ft_substr(ostr, 0, str - ostr);
		if (str_array[count - (count != 0)] == NULL)
			return ((char **) ft_free_array(str_array, count));
	}
	str_array[count] = NULL;
	return (str_array);
}
