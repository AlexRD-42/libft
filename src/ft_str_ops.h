/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinfo.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:11:08 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/06 11:11:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include "ft_str_info.h"
#include "ft_str_create.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = (s[0] != c) && (s[0] != 0);
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**str_array;

	str_array = (char **) malloc(ft_count_words(s, c) + 1);
	if (str_array == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		if ((s[i] == c && s[i] != 0) || (i == 0 && s[i] != c))
		{
			j = ++i;
			while (s[i] != c && s[i] != 0)
				i++;
			if (i != j)
				str_array[k++] = ft_substr(s, j - (j == 1), i - j + (j == 1));
		}
		else
			i++;
	}
	str_array[k] = 0;
	return (str_array);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	str_size;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_size = s1_len + s2_len + 1;
	str = (char *) malloc (str_size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, str_size);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	new_str = (char *) ft_strdup(s);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (new_str[i] != 0)
	{
		new_str[i] = f(i, new_str[i]);
		i++;
	}
	return (new_str);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL)
		return;
	i = 0;
	while (s[i] != 0)
	{
		f(i, s + i);
		i++;
	}
}

