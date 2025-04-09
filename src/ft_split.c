// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_split.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/04/07 11:33:34 by adeimlin          #+#    #+#             */
// /*   Updated: 2025/04/07 11:33:34 by adeimlin         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "libft.h"
// Allocates and returns an array of strings obtained by splitting s using
// the character c as a delimiter. The array must end with a NULL pointer.

// Return: NULL on failure
// Edge Cases: starts or/and ends with separator, str is empty or null,
// allocation failure in the middle, str only has separators,
// separator is 0, char is negative, char is not ascii

static size_t ft_count_words(char const *s, char c)
{
	size_t	count;
	char	in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return count;
}

// NULL initialized next to detect first run

// function that receives this (*s == c && *(s + 1) != c)
// and returns a word
// 		if (*s == c && *(s + 1) != c)
// 		{
// 			start = s + 1;
// 			s = ft_strchr(start, c);
// 			str_array[i++] = ft_substr(start, 0, (s == NULL) * ft_strlen(s) + s - start);
// 		}

// char	**ft_split(char const *s, char c)
// {
// 	char const	*next;
// 	char		**str_array;
// 	size_t		i;
// 	size_t		k;

// 	i = 0;
// 	k = 0;
// 	str_array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
// 	while (s[i] != 0)
// 	{
// 		if ((s[i] == c && s[i + 1] != c) || (i == 0 && s[0] != c))
// 		{
// 			next = ft_strchr(s + i + 1, c);
// 			if (next == NULL)
// 				next = s + ft_strlen(s);
// 			str_array[k++] = ft_substr(s, i + (i != 0), next - s - i - (i != 0));
// 			i = next - s;
// 		}
// 		else
// 			i++;
// 	}
// 	str_array[k] = 0;
// 	return(str_array);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char const	*next;
// 	char		**str_array;
// 	size_t		i;

// 	i = 0;
// 	next = NULL;
// 	str_array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
// 	while (*s != 0)
// 	{
// 		if ((*s == c && *(s + 1) != c) || (next == NULL && s[0] != c))
// 		{
// 			next = ft_strchr(s + 1, c);
// 			if (next == NULL)
// 				next = s + ft_strlen(s);
// 			str_array[i++] = ft_substr(s, 0, next - s);
// 		}
// 		else
// 			s++;
// 	}
// 	str_array[i] = 0;
// 	return(str_array);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char		*next;
// 	char		**str_array;
// 	size_t		i;
// 	int64_t		len;

// 	i = 0;
// 	str_array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
// 	while (s != NULL && *s != 0)
// 	{
// 		len = ft_strchr(s + 1, c) - s;
// 		if (len < 0)
// 			str_array[i++] = ft_substr(s, 0, ft_strlen(s));
// 		else if (len > 1)
// 			str_array[i++] = ft_substr(s + (*s == c), 0, len - (*s == c));
// 		s += len;
// 	}
// 	str_array[i] = 0;
// 	return(str_array);
// }


static size_t ft_count_words2(char const *s, char c)
{
	char		*next;
	size_t		count;

	count = (*s != c);
	while (s != NULL)
	{
		next = ft_strchr(s + 1, c);
		if (next - s > 1)
			count++;
		s = next;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		*next;
	char		**str_array;
	size_t		i;

	i = 0;
	str_array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	while (s != NULL && *s != 0)
	{
		next = ft_strchr(s + 1, c);
		if (next == NULL && *(s + 1) != 0)
			str_array[i] = ft_substr(s, (*s == c), ft_strlen(s) - (*s == c));
		else if (next - s > 1)
			str_array[i] = ft_substr(s, (*s == c), next - s - (*s == c));
		s = next;
	}
	str_array[i] = 0;
	return(str_array);
}

#include <stdio.h>
int	main(void)
{
	char *str = "this,is,a,short,,string,";
	char c = ',';

	printf("%lld", ft_count_words2(str, c));
	// char **str_array = ft_split(str, c);
	// while (*str_array != 0)
	// {
	// 	printf("%s\n", *str_array);
	// 	str_array++;
	// }
}