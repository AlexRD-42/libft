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

// #include "libft.h"
// // Allocates and returns an array of strings obtained by splitting s using
// // the character c as a delimiter. The array must end with a NULL pointer.

// // Return: NULL on failure
// // Edge Cases: starts or/and ends with separator, str is empty or null,
// // allocation failure in the middle, str only has separators,
// // separator is 0, char is negative, char is not ascii

// static size_t ft_count_words(char const *s, char c)
// {
// 	size_t	count;
// 	char	in_word;

// 	in_word = 0;
// 	count = 0;
// 	while (*s)
// 	{
// 		if (*s == c)
// 			in_word = 0;
// 		else if (!in_word)
// 		{
// 			in_word = 1;
// 			count++;
// 		}
// 		s++;
// 	}
// 	return count;
// }

// static char	*ft_find(char *ptr1, char c)
// {
// 	char	*ptr2;


// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	char	*str;
// 	char	**str_array;

// 	str_array = malloc((ft_count_words(s, c) + 1) * sizeof(char));
// 	if (str_array == NULL)
// 		return (NULL);

// 	while (*s != 0)
// 	{
// 		s = ft_strchr(s, c);
// 		str = ft_strchr(++s, c);
// 		if (str == NULL)
// 			break;

// 		if (s - str >= 1)
// 			*str_array++ = ft_substr(str, 0, s - str);
// 	}

// 	*str_array = 0;
// 	return (str_array);
// }

// /* #include <stdio.h>
// int	main(void)
// {
// 	char *str = "this,is,a,short,,string,";
// 	char c = ',';

// 	printf("%lld", ft_count_words(str, c));
// 	// char **str_array = ft_split(str, c);
// 	// while (*str_array != 0)
// 	// {
// 	// 	printf("%s\n", *str_array);
// 	// 	str_array++;
// 	// }
// } */